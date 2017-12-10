#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void AddObligor(QString person);

    void AddBorrowedThing(QTreeWidgetItem *parent, QString name);

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_viewButton_clicked();

    void on_addTypeButton_clicked();

    void on_deleteTypeButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
