#include "addmenu.h"
#include "ui_addmenu.h"
#include "addtimersmenu.h"
#include "addalarmsmenu.h"

#include <QFileDialog>

AddMenu::AddMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMenu)
{
    this->ui->setupUi(this);

    this->ui->executeProgramWidget->hide();
    this->ui->openDocumentWidget->hide();

    this->timerName = new QLabel;

    // колір фону - чорний
    this->setStyleSheet("background-color: black;");

    // alarmButton - додати будильник
    connect(this->ui->alarmButton, SIGNAL(clicked()), this, SLOT(addAlarm()));
    // timerButton - додати відлік
    connect(this->ui->timerButton, SIGNAL(clicked()), this, SLOT(addTimer()));
    // backButton - вихід
    connect(this->ui->backButton, SIGNAL(clicked()), this, SLOT(close()));
    // Показати введення шляху
    connect(this->ui->executeProgram, SIGNAL(stateChanged(int)), this, SLOT(showHideExecuteProgramPath(int)));
    connect(this->ui->openDocument, SIGNAL(stateChanged(int)), this, SLOT(showHideOpenDocumentPath(int)));

    // Обрати шлях
    connect(this->ui->findProgramButton, SIGNAL(clicked()), this, SLOT(findProgram()));
    connect(this->ui->findDocumentButton, SIGNAL(clicked()), this, SLOT(findDocument()));
}

AddMenu::~AddMenu()
{
    delete this->ui;
    delete this->timerName;
}

QTime AddMenu::getEndTime()
{
    return this->endTime;
}

QLabel* AddMenu::getTimerName()
{
    return this->timerName;
}

QString AddMenu::getProgramPath()
{
    return this->ui->executeProgramPath->text();
}

QString AddMenu::getDocumentPath()
{
    return this->ui->openDocumentPath->text();
}

bool AddMenu::isAlarm()
{
    return this->alarm;
}

void AddMenu::addTimer()
{
    addTimersMenu menu;
    menu.setModal(true);
    if (!menu.exec())
    {
        return;
    }
    this->timerName->setText(menu.getTimerName()->text());
    this->endTime = menu.getEndTime();
    this->alarm = false;
    AddMenu::accept();
}

void AddMenu::addAlarm()
{
    addAlarmsMenu menu;
    menu.setModal(true);
    if (!menu.exec())
    {
        return;
    }
    this->timerName->setText(menu.getTimerName()->text());
    this->endTime = menu.getEndTime();
    this->alarm = true;
    AddMenu::accept();
}

void AddMenu::showHideExecuteProgramPath(int check)
{
    if (check)
    {
        this->ui->executeProgramWidget->show();
    }
    else
    {
        this->ui->executeProgramWidget->hide();
    }
}

void AddMenu::showHideOpenDocumentPath(int check)
{
    if (check)
    {
        this->ui->openDocumentWidget->show();
    }
    else
    {
        this->ui->openDocumentWidget->hide();
    }
}

void AddMenu::findProgram()
{
    this->ui->executeProgramPath->setText(QFileDialog::getOpenFileName(this, "Оберіть програму, яку потрібно запустити", "/Applications"));
}

void AddMenu::findDocument()
{
    this->ui->openDocumentPath->setText(QFileDialog::getOpenFileName(this, "Оберіть файл, який потрібно відкрити"));
}
