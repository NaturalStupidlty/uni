/********************************************************************************
** Form generated from reading UI file 'addmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMENU_H
#define UI_ADDMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddMenu
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelTimerName;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *alarmButton;
    QPushButton *timerButton;
    QPushButton *backButton;

    void setupUi(QDialog *AddMenu)
    {
        if (AddMenu->objectName().isEmpty())
            AddMenu->setObjectName("AddMenu");
        AddMenu->resize(524, 274);
        gridLayout = new QGridLayout(AddMenu);
        gridLayout->setObjectName("gridLayout");
        frame_2 = new QFrame(AddMenu);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(500, 250));
        frame_2->setMaximumSize(QSize(16777215, 250));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        labelTimerName = new QLabel(frame_2);
        labelTimerName->setObjectName("labelTimerName");
        QFont font;
        font.setFamilies({QString::fromUtf8("Montserrat")});
        font.setPointSize(36);
        font.setBold(false);
        labelTimerName->setFont(font);
        labelTimerName->setTabletTracking(false);
        labelTimerName->setFocusPolicy(Qt::ClickFocus);
        labelTimerName->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTimerName);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        frame = new QFrame(frame_2);
        frame->setObjectName("frame");
        frame->setMaximumSize(QSize(600, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        alarmButton = new QPushButton(frame);
        alarmButton->setObjectName("alarmButton");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(alarmButton->sizePolicy().hasHeightForWidth());
        alarmButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Montserrat")});
        font1.setPointSize(24);
        alarmButton->setFont(font1);

        horizontalLayout->addWidget(alarmButton);

        timerButton = new QPushButton(frame);
        timerButton->setObjectName("timerButton");
        sizePolicy.setHeightForWidth(timerButton->sizePolicy().hasHeightForWidth());
        timerButton->setSizePolicy(sizePolicy);
        timerButton->setFont(font1);

        horizontalLayout->addWidget(timerButton);


        horizontalLayout_5->addWidget(frame);


        verticalLayout->addLayout(horizontalLayout_5);

        backButton = new QPushButton(frame_2);
        backButton->setObjectName("backButton");
        sizePolicy.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy);
        backButton->setFont(font1);

        verticalLayout->addWidget(backButton);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout->addWidget(frame_2, 0, 0, 1, 1);


        retranslateUi(AddMenu);

        QMetaObject::connectSlotsByName(AddMenu);
    } // setupUi

    void retranslateUi(QDialog *AddMenu)
    {
        AddMenu->setWindowTitle(QCoreApplication::translate("AddMenu", "Dialog", nullptr));
#if QT_CONFIG(whatsthis)
        labelTimerName->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        labelTimerName->setText(QCoreApplication::translate("AddMenu", "\320\242\320\270\320\277 \321\202\320\260\320\271\320\274\320\265\321\200\320\260", nullptr));
        alarmButton->setText(QCoreApplication::translate("AddMenu", "\320\221\321\203\320\264\320\270\320\273\321\214\320\275\320\270\320\272", nullptr));
        timerButton->setText(QCoreApplication::translate("AddMenu", "\320\222\321\226\320\264\320\273\321\226\320\272", nullptr));
        backButton->setText(QCoreApplication::translate("AddMenu", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddMenu: public Ui_AddMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMENU_H
