/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *treeWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *editButton;
    QPushButton *viewButton;
    QSpacerItem *verticalSpacer;
    QLineEdit *searchEdit;
    QPushButton *searchButton;
    QPushButton *saveButton;
    QVBoxLayout *verticalLayout_2;
    QCalendarWidget *calendarWidget;
    QLineEdit *reminderEdit;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *whoBox;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *typeList;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addTypeButton;
    QLineEdit *typeNameEdit;
    QPushButton *deleteTypeButton;
    QHBoxLayout *horizontalLayout;
    QTextEdit *commentEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 460);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(700, 460));
        MainWindow->setMaximumSize(QSize(800, 800));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(treeWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setMaximumSize(QSize(50, 16777215));

        verticalLayout->addWidget(addButton);

        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setMaximumSize(QSize(50, 16777215));

        verticalLayout->addWidget(deleteButton);

        editButton = new QPushButton(centralWidget);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setMaximumSize(QSize(50, 16777215));

        verticalLayout->addWidget(editButton);

        viewButton = new QPushButton(centralWidget);
        viewButton->setObjectName(QStringLiteral("viewButton"));
        viewButton->setMaximumSize(QSize(50, 16777215));

        verticalLayout->addWidget(viewButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        searchEdit = new QLineEdit(centralWidget);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));
        sizePolicy.setHeightForWidth(searchEdit->sizePolicy().hasHeightForWidth());
        searchEdit->setSizePolicy(sizePolicy);
        searchEdit->setMaximumSize(QSize(50, 16777215));

        verticalLayout->addWidget(searchEdit);

        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setMaximumSize(QSize(50, 16777215));

        verticalLayout->addWidget(searchButton);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy1);
        saveButton->setMinimumSize(QSize(0, 50));
        saveButton->setMaximumSize(QSize(50, 16777215));

        verticalLayout->addWidget(saveButton);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setMinimumSize(QSize(0, 0));
        calendarWidget->setMaximumSize(QSize(500, 183));

        verticalLayout_2->addWidget(calendarWidget);

        reminderEdit = new QLineEdit(centralWidget);
        reminderEdit->setObjectName(QStringLiteral("reminderEdit"));

        verticalLayout_2->addWidget(reminderEdit);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        whoBox = new QLineEdit(centralWidget);
        whoBox->setObjectName(QStringLiteral("whoBox"));

        verticalLayout_2->addWidget(whoBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        typeList = new QListWidget(centralWidget);
        new QListWidgetItem(typeList);
        new QListWidgetItem(typeList);
        new QListWidgetItem(typeList);
        typeList->setObjectName(QStringLiteral("typeList"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(typeList->sizePolicy().hasHeightForWidth());
        typeList->setSizePolicy(sizePolicy2);
        typeList->setMinimumSize(QSize(0, 50));
        typeList->setMaximumSize(QSize(16777215, 100));

        horizontalLayout_3->addWidget(typeList);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        addTypeButton = new QPushButton(centralWidget);
        addTypeButton->setObjectName(QStringLiteral("addTypeButton"));

        verticalLayout_3->addWidget(addTypeButton);

        typeNameEdit = new QLineEdit(centralWidget);
        typeNameEdit->setObjectName(QStringLiteral("typeNameEdit"));

        verticalLayout_3->addWidget(typeNameEdit);

        deleteTypeButton = new QPushButton(centralWidget);
        deleteTypeButton->setObjectName(QStringLiteral("deleteTypeButton"));

        verticalLayout_3->addWidget(deleteTypeButton);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        commentEdit = new QTextEdit(centralWidget);
        commentEdit->setObjectName(QStringLiteral("commentEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(commentEdit->sizePolicy().hasHeightForWidth());
        commentEdit->setSizePolicy(sizePolicy3);
        commentEdit->setMinimumSize(QSize(0, 100));

        horizontalLayout->addWidget(commentEdit);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "WINDYKATOR 9000", Q_NULLPTR));
        addButton->setText(QApplication::translate("MainWindow", "ADD", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("MainWindow", "DELETE", Q_NULLPTR));
        editButton->setText(QApplication::translate("MainWindow", "EDIT", Q_NULLPTR));
        viewButton->setText(QApplication::translate("MainWindow", "VIEW", Q_NULLPTR));
        searchButton->setText(QApplication::translate("MainWindow", "SEARCH", Q_NULLPTR));
        saveButton->setText(QApplication::translate("MainWindow", "SAVE", Q_NULLPTR));
        reminderEdit->setPlaceholderText(QApplication::translate("MainWindow", "reminder", Q_NULLPTR));
        whoBox->setPlaceholderText(QApplication::translate("MainWindow", "Jan Kowalski", Q_NULLPTR));

        const bool __sortingEnabled = typeList->isSortingEnabled();
        typeList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = typeList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Book", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = typeList->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "Money", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = typeList->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "Movie", Q_NULLPTR));
        typeList->setSortingEnabled(__sortingEnabled);

        addTypeButton->setText(QApplication::translate("MainWindow", "ADD", Q_NULLPTR));
        deleteTypeButton->setText(QApplication::translate("MainWindow", "DELETE", Q_NULLPTR));
        commentEdit->setPlaceholderText(QApplication::translate("MainWindow", "rower g\303\263rski, czerwony", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
