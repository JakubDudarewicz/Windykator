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

    ui->whoBox->clear();
    ui->commentEdit->clear();
}

void MainWindow::on_addButton_clicked()
{
    ui->treeWidget->setColumnCount(3);
    AddObligor(ui->whoBox->text(), ui->commentEdit->toPlainText(), ui->calendarWidget->selectedDate());
}

void MainWindow::on_editButton_clicked()
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

         description = ui->treeWidget->currentItem()->child(0)->text(1);
         date = ui->treeWidget->currentItem()->child(0)->text(2);
         _date = QDate::fromString(date,"dd.MM.yyyy");

         ui->calendarWidget->setSelectedDate(_date);
         ui->whoBox->setText(person);
         ui->commentEdit->setText(description);
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

         description = ui->treeWidget->currentItem()->child(0)->text(1);
         date = ui->treeWidget->currentItem()->child(0)->text(2);
         _date = QDate::fromString(date,"dd.MM.yyyy");

         ui->calendarWidget->setSelectedDate(_date);
         ui->whoBox->setText(person);
         ui->commentEdit->setText(description);
    }
}

void MainWindow::on_saveButton_clicked()
{
   QTreeWidgetItem *item = ui->treeWidget->currentItem();

   if(item->parent() != NULL){
       item->parent()->setText(0, ui->whoBox->text());
       item->setText(0, ui->typeList->selectedItems().at(0)->text());
       item->setText(1, ui->commentEdit->toPlainText());
       item->setText(2, ui->calendarWidget->selectedDate().toString("dd.MM.yyyy"));
   }else{
       item->setText(0, ui->whoBox->text());
       item->child(0)->setText(0, ui->typeList->selectedItems().at(0)->text());
       item->child(0)->setText(1, ui->commentEdit->toPlainText());
       item->child(0)->setText(2, ui->calendarWidget->selectedDate().toString("dd.MM.yyyy"));
   }


}




