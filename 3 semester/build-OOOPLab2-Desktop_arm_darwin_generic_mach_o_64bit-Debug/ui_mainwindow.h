/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *Interface;
    QHBoxLayout *Buttons;
    QPushButton *continueTimerButton;
    QPushButton *setTimerButton;
    QPushButton *pauseTimerButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *Timers;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *alarms;
    QLabel *nearestTimerText;
    QLabel *timers;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *Alarms;
    QListWidget *alarmsList;
    QVBoxLayout *verticalLayout;
    QWidget *nearestTimer;
    QSpacerItem *verticalSpacer_2;
    QPushButton *doNotDisturb;
    QVBoxLayout *regularTimers;
    QListWidget *timersList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 589);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(1100, 0));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        Interface = new QVBoxLayout();
        Interface->setObjectName("Interface");
        Buttons = new QHBoxLayout();
        Buttons->setObjectName("Buttons");
        continueTimerButton = new QPushButton(centralwidget);
        continueTimerButton->setObjectName("continueTimerButton");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(continueTimerButton->sizePolicy().hasHeightForWidth());
        continueTimerButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Montserrat")});
        font.setPointSize(36);
        font.setBold(true);
        continueTimerButton->setFont(font);

        Buttons->addWidget(continueTimerButton);

        setTimerButton = new QPushButton(centralwidget);
        setTimerButton->setObjectName("setTimerButton");
        sizePolicy.setHeightForWidth(setTimerButton->sizePolicy().hasHeightForWidth());
        setTimerButton->setSizePolicy(sizePolicy);
        setTimerButton->setFont(font);

        Buttons->addWidget(setTimerButton);

        pauseTimerButton = new QPushButton(centralwidget);
        pauseTimerButton->setObjectName("pauseTimerButton");
        sizePolicy.setHeightForWidth(pauseTimerButton->sizePolicy().hasHeightForWidth());
        pauseTimerButton->setSizePolicy(sizePolicy);
        pauseTimerButton->setFont(font);

        Buttons->addWidget(pauseTimerButton);


        Interface->addLayout(Buttons);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        Interface->addItem(verticalSpacer);

        Timers = new QHBoxLayout();
        Timers->setObjectName("Timers");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        alarms = new QLabel(centralwidget);
        alarms->setObjectName("alarms");
        sizePolicy.setHeightForWidth(alarms->sizePolicy().hasHeightForWidth());
        alarms->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Montserrat")});
        font1.setPointSize(24);
        alarms->setFont(font1);
        alarms->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(alarms);

        nearestTimerText = new QLabel(centralwidget);
        nearestTimerText->setObjectName("nearestTimerText");
        sizePolicy.setHeightForWidth(nearestTimerText->sizePolicy().hasHeightForWidth());
        nearestTimerText->setSizePolicy(sizePolicy);
        nearestTimerText->setFont(font1);
        nearestTimerText->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(nearestTimerText);

        timers = new QLabel(centralwidget);
        timers->setObjectName("timers");
        sizePolicy.setHeightForWidth(timers->sizePolicy().hasHeightForWidth());
        timers->setSizePolicy(sizePolicy);
        timers->setFont(font1);
        timers->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(timers);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Alarms = new QVBoxLayout();
        Alarms->setObjectName("Alarms");
        Alarms->setSizeConstraint(QLayout::SetDefaultConstraint);
        Alarms->setContentsMargins(-1, -1, 0, -1);
        alarmsList = new QListWidget(centralwidget);
        alarmsList->setObjectName("alarmsList");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(alarmsList->sizePolicy().hasHeightForWidth());
        alarmsList->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("JetBrains Mono NL")});
        font2.setPointSize(20);
        alarmsList->setFont(font2);
        alarmsList->setAutoScrollMargin(16);
        alarmsList->setTabKeyNavigation(true);
        alarmsList->setProperty("showDropIndicator", QVariant(false));
        alarmsList->setDragEnabled(false);
        alarmsList->setDragDropOverwriteMode(false);
        alarmsList->setDragDropMode(QAbstractItemView::NoDragDrop);
        alarmsList->setDefaultDropAction(Qt::MoveAction);
        alarmsList->setAlternatingRowColors(false);
        alarmsList->setSelectionMode(QAbstractItemView::MultiSelection);
        alarmsList->setProperty("isWrapping", QVariant(false));
        alarmsList->setSpacing(0);
        alarmsList->setItemAlignment(Qt::AlignCenter);

        Alarms->addWidget(alarmsList);


        horizontalLayout->addLayout(Alarms);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        nearestTimer = new QWidget(centralwidget);
        nearestTimer->setObjectName("nearestTimer");
        sizePolicy.setHeightForWidth(nearestTimer->sizePolicy().hasHeightForWidth());
        nearestTimer->setSizePolicy(sizePolicy);
        nearestTimer->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(nearestTimer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        doNotDisturb = new QPushButton(centralwidget);
        doNotDisturb->setObjectName("doNotDisturb");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Montserrat")});
        font3.setPointSize(24);
        font3.setBold(true);
        doNotDisturb->setFont(font3);
        doNotDisturb->setCheckable(true);

        verticalLayout->addWidget(doNotDisturb);


        horizontalLayout->addLayout(verticalLayout);

        regularTimers = new QVBoxLayout();
        regularTimers->setObjectName("regularTimers");
        regularTimers->setContentsMargins(0, -1, -1, -1);
        timersList = new QListWidget(centralwidget);
        timersList->setObjectName("timersList");
        sizePolicy1.setHeightForWidth(timersList->sizePolicy().hasHeightForWidth());
        timersList->setSizePolicy(sizePolicy1);
        timersList->setFont(font2);
        timersList->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        timersList->setTabKeyNavigation(true);
        timersList->setProperty("showDropIndicator", QVariant(false));
        timersList->setDragEnabled(true);
        timersList->setDragDropOverwriteMode(true);
        timersList->setDragDropMode(QAbstractItemView::DragDrop);
        timersList->setDefaultDropAction(Qt::MoveAction);
        timersList->setSelectionMode(QAbstractItemView::MultiSelection);
        timersList->setSelectionBehavior(QAbstractItemView::SelectRows);
        timersList->setItemAlignment(Qt::AlignCenter);
        timersList->setSortingEnabled(true);

        regularTimers->addWidget(timersList);


        horizontalLayout->addLayout(regularTimers);


        verticalLayout_2->addLayout(horizontalLayout);


        Timers->addLayout(verticalLayout_2);


        Interface->addLayout(Timers);


        gridLayout->addLayout(Interface, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1100, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setAutoFillBackground(false);
        statusbar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TimerX", nullptr));
        continueTimerButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\320\273\321\226", nullptr));
        setTimerButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270", nullptr));
        pauseTimerButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\203\320\267\320\260", nullptr));
        alarms->setText(QCoreApplication::translate("MainWindow", "\320\221\321\203\320\264\320\270\320\273\321\214\320\275\320\270\320\272\320\270:", nullptr));
        nearestTimerText->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\320\261\320\273\320\270\320\266\321\207\320\270\320\271 \321\202\320\260\320\271\320\274\320\265\321\200:", nullptr));
        timers->setText(QCoreApplication::translate("MainWindow", "\320\242\320\260\320\271\320\274\320\265\321\200\320\270:", nullptr));
        doNotDisturb->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265 \321\202\321\203\321\200\320\261\321\203\320\262\320\260\321\202\320\270 \360\237\230\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
