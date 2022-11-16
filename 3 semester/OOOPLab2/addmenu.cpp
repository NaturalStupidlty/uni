#include "addmenu.h"
#include "ui_addmenu.h"
#include "addtimersmenu.h"
#include "addalarmsmenu.h"

AddMenu::AddMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMenu)
{
    this->ui->setupUi(this);

    this->timerName = new QLabel;

    // колір фону - чорний
    this->setStyleSheet("background-color: black;");

    // backButton - вихід
    connect(this->ui->alarmButton, SIGNAL(clicked()), this, SLOT(addAlarm()));
    connect(this->ui->timerButton, SIGNAL(clicked()), this, SLOT(addTimer()));
    connect(this->ui->backButton, SIGNAL(clicked()), this, SLOT(close()));
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
