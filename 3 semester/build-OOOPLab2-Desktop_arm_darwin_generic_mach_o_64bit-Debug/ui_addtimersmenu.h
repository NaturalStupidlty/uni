/********************************************************************************
** Form generated from reading UI file 'addtimersmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTIMERSMENU_H
#define UI_ADDTIMERSMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addTimersMenu
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *setTime;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_6;
    QSpinBox *spinBoxHours;
    QLabel *labelHours;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout_7;
    QSpinBox *spinBoxMinutes;
    QLabel *labelMinutes;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_8;
    QSpinBox *spinBoxSeconds;
    QLabel *labelSeconds;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_9;
    QSpinBox *spinBoxMiliseconds;
    QLabel *labelMiliseconds;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelTimerName;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *timerName;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *backButton;
    QPushButton *startTimersButton;

    void setupUi(QDialog *addTimersMenu)
    {
        if (addTimersMenu->objectName().isEmpty())
            addTimersMenu->setObjectName("addTimersMenu");
        addTimersMenu->resize(513, 337);
        addTimersMenu->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("Montserrat")});
        addTimersMenu->setFont(font);
        gridLayout = new QGridLayout(addTimersMenu);
        gridLayout->setObjectName("gridLayout");
        frame_3 = new QFrame(addTimersMenu);
        frame_3->setObjectName("frame_3");
        frame_3->setMaximumSize(QSize(16777215, 500));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_3);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName("frame_5");
        frame_5->setMaximumSize(QSize(16777215, 150));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_5);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        setTime = new QLabel(frame_5);
        setTime->setObjectName("setTime");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Montserrat")});
        font1.setPointSize(36);
        font1.setBold(false);
        setTime->setFont(font1);
        setTime->setTabletTracking(false);
        setTime->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(setTime);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        frame = new QFrame(frame_5);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(500, 0));
        frame->setMaximumSize(QSize(500, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        frame_6 = new QFrame(frame);
        frame_6->setObjectName("frame_6");
        frame_6->setLayoutDirection(Qt::RightToLeft);
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_6);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        spinBoxHours = new QSpinBox(frame_6);
        spinBoxHours->setObjectName("spinBoxHours");
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBoxHours->sizePolicy().hasHeightForWidth());
        spinBoxHours->setSizePolicy(sizePolicy);
        spinBoxHours->setMinimumSize(QSize(75, 0));
        spinBoxHours->setMaximumSize(QSize(75, 16777215));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Montserrat")});
        font2.setPointSize(24);
        spinBoxHours->setFont(font2);

        verticalLayout_6->addWidget(spinBoxHours);

        labelHours = new QLabel(frame_6);
        labelHours->setObjectName("labelHours");
        labelHours->setFont(font);
        labelHours->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(labelHours);


        horizontalLayout_2->addWidget(frame_6);

        frame_7 = new QFrame(frame);
        frame_7->setObjectName("frame_7");
        frame_7->setLayoutDirection(Qt::RightToLeft);
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_7);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        spinBoxMinutes = new QSpinBox(frame_7);
        spinBoxMinutes->setObjectName("spinBoxMinutes");
        sizePolicy.setHeightForWidth(spinBoxMinutes->sizePolicy().hasHeightForWidth());
        spinBoxMinutes->setSizePolicy(sizePolicy);
        spinBoxMinutes->setMinimumSize(QSize(75, 0));
        spinBoxMinutes->setMaximumSize(QSize(75, 16777215));
        spinBoxMinutes->setFont(font2);

        verticalLayout_7->addWidget(spinBoxMinutes);

        labelMinutes = new QLabel(frame_7);
        labelMinutes->setObjectName("labelMinutes");
        labelMinutes->setFont(font);
        labelMinutes->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(labelMinutes);


        horizontalLayout_2->addWidget(frame_7);

        frame_8 = new QFrame(frame);
        frame_8->setObjectName("frame_8");
        frame_8->setLayoutDirection(Qt::RightToLeft);
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_8);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        spinBoxSeconds = new QSpinBox(frame_8);
        spinBoxSeconds->setObjectName("spinBoxSeconds");
        sizePolicy.setHeightForWidth(spinBoxSeconds->sizePolicy().hasHeightForWidth());
        spinBoxSeconds->setSizePolicy(sizePolicy);
        spinBoxSeconds->setMinimumSize(QSize(75, 0));
        spinBoxSeconds->setMaximumSize(QSize(75, 16777215));
        spinBoxSeconds->setFont(font2);

        verticalLayout_8->addWidget(spinBoxSeconds);

        labelSeconds = new QLabel(frame_8);
        labelSeconds->setObjectName("labelSeconds");
        labelSeconds->setFont(font);
        labelSeconds->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(labelSeconds);


        horizontalLayout_2->addWidget(frame_8);

        frame_9 = new QFrame(frame);
        frame_9->setObjectName("frame_9");
        frame_9->setLayoutDirection(Qt::RightToLeft);
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        verticalLayout_9 = new QVBoxLayout(frame_9);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        spinBoxMiliseconds = new QSpinBox(frame_9);
        spinBoxMiliseconds->setObjectName("spinBoxMiliseconds");
        sizePolicy.setHeightForWidth(spinBoxMiliseconds->sizePolicy().hasHeightForWidth());
        spinBoxMiliseconds->setSizePolicy(sizePolicy);
        spinBoxMiliseconds->setMinimumSize(QSize(100, 0));
        spinBoxMiliseconds->setMaximumSize(QSize(100, 16777215));
        spinBoxMiliseconds->setFont(font2);

        verticalLayout_9->addWidget(spinBoxMiliseconds);

        labelMiliseconds = new QLabel(frame_9);
        labelMiliseconds->setObjectName("labelMiliseconds");
        labelMiliseconds->setFont(font);

        verticalLayout_9->addWidget(labelMiliseconds);


        horizontalLayout_2->addWidget(frame_9);


        horizontalLayout->addWidget(frame);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addWidget(frame_5);


        verticalLayout_5->addLayout(verticalLayout);

        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName("frame_4");
        frame_4->setMaximumSize(QSize(16777215, 200));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_4);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        labelTimerName = new QLabel(frame_4);
        labelTimerName->setObjectName("labelTimerName");
        labelTimerName->setFont(font1);
        labelTimerName->setTabletTracking(false);
        labelTimerName->setFocusPolicy(Qt::ClickFocus);
        labelTimerName->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(labelTimerName);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        timerName = new QLineEdit(frame_4);
        timerName->setObjectName("timerName");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(timerName->sizePolicy().hasHeightForWidth());
        timerName->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Montserrat")});
        font3.setPointSize(18);
        timerName->setFont(font3);
        timerName->setInputMask(QString::fromUtf8(""));
        timerName->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(timerName);


        verticalLayout_4->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName("frame_2");
        frame_2->setMaximumSize(QSize(500, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        backButton = new QPushButton(frame_2);
        backButton->setObjectName("backButton");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy2);
        backButton->setFont(font2);

        horizontalLayout_3->addWidget(backButton);

        startTimersButton = new QPushButton(frame_2);
        startTimersButton->setObjectName("startTimersButton");
        sizePolicy2.setHeightForWidth(startTimersButton->sizePolicy().hasHeightForWidth());
        startTimersButton->setSizePolicy(sizePolicy2);
        startTimersButton->setFont(font2);

        horizontalLayout_3->addWidget(startTimersButton);


        horizontalLayout_5->addWidget(frame_2);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_5->addWidget(frame_4);


        gridLayout_2->addLayout(verticalLayout_5, 0, 0, 1, 1);


        gridLayout->addWidget(frame_3, 0, 0, 1, 1);


        retranslateUi(addTimersMenu);

        QMetaObject::connectSlotsByName(addTimersMenu);
    } // setupUi

    void retranslateUi(QDialog *addTimersMenu)
    {
        addTimersMenu->setWindowTitle(QCoreApplication::translate("addTimersMenu", "Add timers or alarms", nullptr));
        setTime->setText(QCoreApplication::translate("addTimersMenu", "\320\247\320\260\321\201", nullptr));
        labelHours->setText(QCoreApplication::translate("addTimersMenu", " \320\263\320\276\320\264", nullptr));
        labelMinutes->setText(QCoreApplication::translate("addTimersMenu", " \321\205\320\262", nullptr));
        labelSeconds->setText(QCoreApplication::translate("addTimersMenu", " \321\201\320\265\320\272", nullptr));
        labelMiliseconds->setText(QCoreApplication::translate("addTimersMenu", "    \320\274\321\201\320\265\320\272", nullptr));
#if QT_CONFIG(whatsthis)
        labelTimerName->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        labelTimerName->setText(QCoreApplication::translate("addTimersMenu", "\320\235\320\260\320\267\320\262\320\260", nullptr));
        timerName->setText(QCoreApplication::translate("addTimersMenu", "\320\242\320\260\320\271\320\274\320\265\321\200", nullptr));
        backButton->setText(QCoreApplication::translate("addTimersMenu", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        startTimersButton->setText(QCoreApplication::translate("addTimersMenu", "\320\237\321\203\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addTimersMenu: public Ui_addTimersMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTIMERSMENU_H
