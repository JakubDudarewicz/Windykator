#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

void MainWindow::AddObligor(QString person, QString description, QDate date)
{
    QTreeWidgetItem *Obligor = new QTreeWidgetItem(ui->treeWidget);
    Obligor->setText(0, person);
    QList<QString> stringList;
    stringList.append(ui->typeList->selectedItems().at(0)->text());
    stringList.append(description);
    stringList.append(date.toString("dd.MM.yyyy"));
    QTreeWidgetItem *Item = new QTreeWidgetItem(Obligor, stringList, 0);
}

void MainWindow::on_addButton_clicked()
{
    ui->treeWidget->setColumnCount(3);
    AddObligor(ui->whoBox->text(), ui->commentEdit->toPlainText(), ui->calendarWidget->selectedDate());
}
