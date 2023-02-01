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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
    QSpacerItem *verticalSpacer;
    QFrame *additionalSettings;
    QVBoxLayout *verticalLayout_2;
    QLabel *additionalSettingsText;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *executeProgram;
    QWidget *executeProgramWidget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *executeProgramPath;
    QPushButton *findProgramButton;
    QCheckBox *openDocument;
    QWidget *openDocumentWidget;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *openDocumentPath;
    QPushButton *findDocumentButton;
    QPushButton *backButton;

    void setupUi(QDialog *AddMenu)
    {
        if (AddMenu->objectName().isEmpty())
            AddMenu->setObjectName("AddMenu");
        AddMenu->resize(577, 428);
        gridLayout = new QGridLayout(AddMenu);
        gridLayout->setObjectName("gridLayout");
        frame_2 = new QFrame(AddMenu);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(500, 250));
        frame_2->setMaximumSize(QSize(16777215, 400));
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

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        additionalSettings = new QFrame(frame_2);
        additionalSettings->setObjectName("additionalSettings");
        additionalSettings->setFrameShape(QFrame::StyledPanel);
        additionalSettings->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(additionalSettings);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        additionalSettingsText = new QLabel(additionalSettings);
        additionalSettingsText->setObjectName("additionalSettingsText");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Montserrat")});
        font2.setPointSize(20);
        additionalSettingsText->setFont(font2);
        additionalSettingsText->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_2->addWidget(additionalSettingsText);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        executeProgram = new QCheckBox(additionalSettings);
        executeProgram->setObjectName("executeProgram");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Montserrat")});
        font3.setPointSize(18);
        executeProgram->setFont(font3);

        verticalLayout_2->addWidget(executeProgram);

        executeProgramWidget = new QWidget(additionalSettings);
        executeProgramWidget->setObjectName("executeProgramWidget");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Montserrat")});
        font4.setPointSize(14);
        executeProgramWidget->setFont(font4);
        horizontalLayout_2 = new QHBoxLayout(executeProgramWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        executeProgramPath = new QLineEdit(executeProgramWidget);
        executeProgramPath->setObjectName("executeProgramPath");
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(executeProgramPath->sizePolicy().hasHeightForWidth());
        executeProgramPath->setSizePolicy(sizePolicy1);
        executeProgramPath->setMinimumSize(QSize(0, 30));
        executeProgramPath->setMaximumSize(QSize(16777215, 30));
        executeProgramPath->setFont(font4);
        executeProgramPath->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_2->addWidget(executeProgramPath);

        findProgramButton = new QPushButton(executeProgramWidget);
        findProgramButton->setObjectName("findProgramButton");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(findProgramButton->sizePolicy().hasHeightForWidth());
        findProgramButton->setSizePolicy(sizePolicy2);
        findProgramButton->setMaximumSize(QSize(16777215, 35));
        findProgramButton->setFont(font4);
        findProgramButton->setAutoRepeatInterval(0);

        horizontalLayout_2->addWidget(findProgramButton);


        verticalLayout_2->addWidget(executeProgramWidget);

        openDocument = new QCheckBox(additionalSettings);
        openDocument->setObjectName("openDocument");
        openDocument->setFont(font3);

        verticalLayout_2->addWidget(openDocument);

        openDocumentWidget = new QWidget(additionalSettings);
        openDocumentWidget->setObjectName("openDocumentWidget");
        horizontalLayout_3 = new QHBoxLayout(openDocumentWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        openDocumentPath = new QLineEdit(openDocumentWidget);
        openDocumentPath->setObjectName("openDocumentPath");
        sizePolicy1.setHeightForWidth(openDocumentPath->sizePolicy().hasHeightForWidth());
        openDocumentPath->setSizePolicy(sizePolicy1);
        openDocumentPath->setMinimumSize(QSize(0, 30));
        openDocumentPath->setMaximumSize(QSize(16777215, 30));
        openDocumentPath->setFont(font4);

        horizontalLayout_3->addWidget(openDocumentPath);

        findDocumentButton = new QPushButton(openDocumentWidget);
        findDocumentButton->setObjectName("findDocumentButton");
        findDocumentButton->setMaximumSize(QSize(16777215, 35));
        findDocumentButton->setFont(font4);

        horizontalLayout_3->addWidget(findDocumentButton);


        verticalLayout_2->addWidget(openDocumentWidget);


        verticalLayout->addWidget(additionalSettings);

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
        additionalSettingsText->setText(QCoreApplication::translate("AddMenu", "\320\224\320\276\320\264\320\260\321\202\320\272\320\276\320\262\321\226 \320\274\320\276\320\266\320\273\320\270\320\262\320\276\321\201\321\202\321\226:", nullptr));
        executeProgram->setText(QCoreApplication::translate("AddMenu", "    \320\227\320\260\320\277\321\203\321\201\320\272 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\270", nullptr));
        findProgramButton->setText(QCoreApplication::translate("AddMenu", "\320\227\320\275\320\260\320\271\321\202\320\270", nullptr));
        openDocument->setText(QCoreApplication::translate("AddMenu", "    \320\222\321\226\320\264\320\272\321\200\320\270\321\202\321\202\321\217 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\321\203", nullptr));
        findDocumentButton->setText(QCoreApplication::translate("AddMenu", "\320\227\320\275\320\260\320\271\321\202\320\270", nullptr));
        backButton->setText(QCoreApplication::translate("AddMenu", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddMenu: public Ui_AddMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMENU_H
