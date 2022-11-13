#include "addtimersmenu.h"
#include "ui_addtimersmenu.h"

#include <QTime>

addTimersMenu::addTimersMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addTimersMenu)
{
    ui->setupUi(this);

    timerName = new QLabel;

    // колір фону - чорний
    this->setStyleSheet("background-color: black;");

    // Обмеження на інпут спінбоксів
    ui->spinBoxNumberOfTimers->setRange(0, maxTimers);
    ui->spinBoxHours->setRange(0, maxHours);
    ui->spinBoxMinutes->setRange(0, 59);
    ui->spinBoxSeconds->setRange(0, 59);
    ui->spinBoxMiliseconds->setRange(0, 999);

    // startTimersButton - пуск таймерів
    connect(ui->startTimersButton, SIGNAL(clicked()), this, SLOT(startTimers()));
    // backButton - вихід
    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(close()));
}

addTimersMenu::~addTimersMenu()
{
    delete ui;
    delete timerName;
}

QTime addTimersMenu::getEndTime()
{
    return endTime;
}

uint addTimersMenu::getNumberOfTimers()
{
    return numberOfTimers;
}

QLabel* addTimersMenu::getTimerName()
{
    return timerName;
}

bool addTimersMenu::isAlarm()
{
    return alarm;
}

void addTimersMenu::startTimers()
{
    setTime();
    addTimersMenu::accept();
}

void addTimersMenu::goBack()
{

}

void addTimersMenu::setTime()
{
    int hours = ui->spinBoxHours->text().toInt();
    int minutes = ui->spinBoxMinutes->text().toInt();
    int seconds = ui->spinBoxSeconds->text().toInt();
    int miliseconds = ui->spinBoxMiliseconds->text().toInt();

    endTime.setHMS(hours, minutes, seconds, miliseconds);
    numberOfTimers = ui->spinBoxNumberOfTimers->text().toInt();
    timerName->setText(ui->timerName->text());
    alarm = ui->checkedAlarm->isChecked();

}
