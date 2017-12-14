#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(3);
    QFile *file = new QFile("data.txt");
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox *box = new QMessageBox(NULL);
        box->setText("something went horribly wrong");
        return;
    }
    QTextStream stream(file);
    QString string = stream.readAll();
    QStringList stringList = string.split("\n", QString::SkipEmptyParts);
    QList<QStringList> list;
    for(int i = 0; i < stringList.length(); i++)
    {
        list.append(stringList.at(i).split(",", QString::KeepEmptyParts));
    }
    for(int i = 0; i < list.length(); i++)
    {
        QString person = list.at(i).at(0);
        QString description = list.at(i).at(1);
        QString dateString = list.at(i).at(3);
        QStringList dateList = dateString.split(".", QString::KeepEmptyParts);
        QDate date(dateList.at(0).toInt(),
                   dateList.at(1).toInt(),
                   dateList.at(2).toInt());
        QString type = list.at(i).at(2);
        AddObligor(person, description, date, type);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_viewButton_clicked()
{
    QMessageBox box;
    QList<QTreeWidgetItem *> items = ui->treeWidget->selectedItems();
    QTreeWidgetItem *item = items.at(0);
    box.setText(QString(item->text(0).append(" owes me")));
    box.exec();
}

void MainWindow::on_addTypeButton_clicked()
{
    QString category = ui->typeNameEdit->text();
    ui->typeList->addItem(category);
}

void MainWindow::on_deleteTypeButton_clicked()
{
    QList<QListWidgetItem *> items = ui->typeList->selectedItems();
    QListWidgetItem *item=items.at(0);
    delete item;
}

void MainWindow::on_deleteButton_clicked()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();
    int index = ui->treeWidget->indexOfTopLevelItem(item);
    item = ui->treeWidget->takeTopLevelItem(index);
    if(item)
        delete item;
}

void MainWindow::AddObligor(QString person, QString description, QDate date, QString type)
{
    QTreeWidgetItem *Obligor = new QTreeWidgetItem(ui->treeWidget);
    Obligor->setText(0, person);
    QList<QString> stringList;
    stringList.append(type);
    stringList.append(description);
    stringList.append(date.toString("dd.MM.yyyy"));
    QTreeWidgetItem *Item = new QTreeWidgetItem(Obligor, stringList, 0);
}

void MainWindow::on_addButton_clicked()
{
    AddObligor(ui->whoBox->text(),
               ui->commentEdit->toPlainText(),
               ui->calendarWidget->selectedDate(),
               ui->typeList->selectedItems().at(0)->text());
}

void MainWindow::on_saveButton_clicked()
{
    QFile *file = new QFile("data.txt");
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox *box = new QMessageBox(NULL);
        box->setText("something went horribly wrong");
        return;
    }
    QTextStream stream(file);
    QString string;
    for(int i = 0; i < ui->treeWidget->topLevelItemCount(); i++)
    {
        string += ui->treeWidget->topLevelItem(i)->text(0);
        string += ",";
        string += ui->treeWidget->topLevelItem(i)->child(0)->text(0);
        string += ",";
        string += ui->treeWidget->topLevelItem(i)->child(0)->text(1);
        string += ",";
        string += ui->treeWidget->topLevelItem(i)->child(0)->text(2);
        string += "\n";
    }
   stream << string;
}
