#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void AddObligor(QString person, QString description, QDate date, QString type);

    void AddBorrowedThing(QTreeWidgetItem *parent, QString name);

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_viewButton_clicked();

    void on_addTypeButton_clicked();

    void on_deleteTypeButton_clicked();

    void on_deleteButton_clicked();

    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_saveButton_clicked();

    void on_treeWidget_clicked(const QModelIndex &index);

    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
    QString findText;
};

#endif // MAINWINDOW_H
