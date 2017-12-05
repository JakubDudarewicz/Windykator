#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(1);
    QList<QTreeWidgetItem *> items;
    items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("Kowalski"))));
    items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("Nowak"))));
    items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("Paprocka"))));
    ui->treeWidget->insertTopLevelItems(0, items);
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
