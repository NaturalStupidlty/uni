#include "timerinfo.h"

TimerInfo::TimerInfo(QWidget *parent)
    : QWidget{parent}
{
    time = new QLabel;
    name = new QLabel;
}

TimerInfo::TimerInfo(QString time, QString name)
{
    this->time = new QLabel;
    this->name = new QLabel;
    this->time->setText(time);
    this->name->setText(name);
    this->time->setAlignment(Qt::AlignCenter);
    this->name->setAlignment(Qt::AlignCenter);
}

TimerInfo::~TimerInfo()
{
    delete time;
    delete name;
}

void TimerInfo::setTime(QString newTime)
{
    this->time->setText(newTime);
    this->time->setAlignment(Qt::AlignCenter);
}

void TimerInfo::setName(QString newName)
{
    this->name->setText(newName);
    this->name->setAlignment(Qt::AlignCenter);
}

void TimerInfo::setAlarm(bool alarm)
{
    this->alarm = alarm;
}

QLabel* TimerInfo::getTime()
{
    return this->time;
}

QLabel* TimerInfo::getName()
{
    return this->name;
}

bool TimerInfo::isAlarm()
{
    return alarm;
}
