#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    findText = "";
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(3);
    QFile *file = new QFile("data.txt");
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox *box = new QMessageBox(NULL);
        box->setText("something went horribly wrong, there is no file");
        box->exec();
        return;
    }
    QTextStream stream(file);
    QString string = stream.readAll();
    QStringList stringList = string.split("\n", QString::SkipEmptyParts);
    QList<QStringList> list;
    for(int i = 0; i < stringList.length(); i++)
    {
        list.append(stringList.at(i).split(";", QString::KeepEmptyParts));
    }
    for(int i = 0; i < list.length(); i++)
    {
        QString person = list.at(i).at(0);
        QStringList debtsList;
        for(int j = 1; j < list.at(i).length(); j++)
        {
            debtsList = list.at(i).at(j).split(",");
            QString description = debtsList.at(0);
            QString dateString = debtsList.at(2);
            QStringList dateList = dateString.split(".", QString::KeepEmptyParts);
            QDate date(dateList.at(2).toInt(),
                       dateList.at(1).toInt(),
                       dateList.at(0).toInt());
            QString type = debtsList.at(1);
            AddObligor(person, description, date, type);
        }
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
    QString builder;
    builder += item->text(0);
    builder += " owes me:\n";
    for(int i = 0; i < item->childCount(); i++)
    {
        builder += item->child(i)->text(0);
        builder += " ";
        builder += item->child(i)->text(1);
        builder += " ";
        builder += item->child(i)->text(2);
    }
    box.setText(builder);
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
    QTreeWidgetItemIterator iterator(ui->treeWidget);
    QTreeWidgetItem *Obligor;
    QList<QString> stringList;
    stringList.append(type);
    stringList.append(description);
    stringList.append(date.toString("dd.MM.yyyy"));

    while(*iterator) {
        if ((*iterator)->text(0) == person)
        {
            new QTreeWidgetItem(*iterator, stringList, 0);
            return;
        }
        ++iterator;
    }
    Obligor = new QTreeWidgetItem(ui->treeWidget);
    Obligor->setText(0, person);
    new QTreeWidgetItem(Obligor, stringList, 0);
}

void MainWindow::on_addButton_clicked()
{
    AddObligor(ui->whoBox->text(),
               ui->commentEdit->toPlainText(),
               ui->calendarWidget->selectedDate(),
               ui->typeList->selectedItems().at(0)->text());

    ui->commentEdit->clear();
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
        for(int j = 0; j < ui->treeWidget->topLevelItem(i)->childCount(); j++)
        {
            string += ";";
            string += ui->treeWidget->topLevelItem(i)->child(j)->text(0);
            string += ",";
            string += ui->treeWidget->topLevelItem(i)->child(j)->text(1);
            string += ",";
            string += ui->treeWidget->topLevelItem(i)->child(j)->text(2);
        }
        string += "\n";
    }
    stream << string;
}

void MainWindow::on_searchButton_clicked()
{
    QString itemText =ui->searchEdit->text();
    QTreeWidgetItemIterator iterator(ui->treeWidget);
    while(*iterator) {
        if ((*iterator)->text(0) == itemText)
            (*iterator)->setTextColor(0,QColor( "red" ));
        else
            (*iterator)->setTextColor(0,QColor( "black" ));
        ++iterator;
    }
}

void MainWindow::on_editButton_clicked()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();

    if(item->parent() != NULL){
        item->parent()->setText(0, ui->whoBox->text());
        item->setText(0, ui->typeList->selectedItems().at(0)->text());
        item->setText(1, ui->commentEdit->toPlainText());
        item->setText(2, ui->calendarWidget->selectedDate().toString("dd.MM.yyyy"));
    }else{
        item->setText(0, ui->whoBox->text());
        /*item->child(0)->setText(0, ui->typeList->selectedItems().at(0)->text());
        item->child(0)->setText(1, ui->commentEdit->toPlainText());
        item->child(0)->setText(2, ui->calendarWidget->selectedDate().toString("dd.MM.yyyy"));*/
    }
}

void MainWindow::on_treeWidget_clicked(const QModelIndex &index)
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();

     QString person;
     QString description;
     QString date;
     QDate _date;

    if(item->parent() != NULL){
        person = item->parent()->text(0);

        description = item->text(1);
        date = item->text(2);
        _date = QDate::fromString(date,"dd.MM.yyyy");

        ui->calendarWidget->setSelectedDate(_date);
        ui->whoBox->setText(person);
        ui->commentEdit->setText(description);
    }else{
         person = ui->treeWidget->currentItem()->text(0);

         ui->commentEdit->clear();
         /*description = ui->treeWidget->currentItem()->child(0)->text(1);
         date = ui->treeWidget->currentItem()->child(0)->text(2);
         _date = QDate::fromString(date,"dd.MM.yyyy");

         ui->calendarWidget->setSelectedDate(_date);
         ui->whoBox->setText(person);
         ui->commentEdit->setText(description);*/
    }
}





