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
    ui->spinBoxHours->setRange(0, maxHours);
    ui->spinBoxMinutes->setRange(0, 59);
    ui->spinBoxSeconds->setRange(0, 59);
    ui->spinBoxMiliseconds->setRange(0, 999);

    ui->timerName->setMaxLength(maxTimerNameLenght);

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

void addTimersMenu::setTime()
{
    int hours = ui->spinBoxHours->value();
    int minutes = ui->spinBoxMinutes->value();
    int seconds = ui->spinBoxSeconds->value();
    int miliseconds = ui->spinBoxMiliseconds->value();

    endTime.setHMS(hours, minutes, seconds, miliseconds);
    timerName->setText(ui->timerName->text());
    alarm = ui->checkedAlarm->isChecked();
}
