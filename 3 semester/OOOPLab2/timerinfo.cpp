#include "timerinfo.h"

TimerInfo::TimerInfo(QWidget *parent)
    : QWidget{parent}
{
    this->time = new QLabel;
    this->name = new QLabel;
    this->time->setAlignment(Qt::AlignCenter);
    this->name->setAlignment(Qt::AlignCenter);
    this->time->setFont(QFont("JetBrains Mono NL", 18));
    this->name->setFont(QFont("Montserrat", 18));
}

TimerInfo::TimerInfo(QString time, QString name)
{
    this->time = new QLabel;
    this->name = new QLabel;
    this->time->setText(time);
    this->name->setText(name);
    this->time->setAlignment(Qt::AlignCenter);
    this->name->setAlignment(Qt::AlignCenter);
    this->time->setFont(QFont("JetBrains Mono NL", 18));
    this->name->setFont(QFont("Montserrat", 18));
}

TimerInfo::~TimerInfo()
{
    delete this->time;
    delete this->name;
}

void TimerInfo::setTime(QString newTime)
{
    this->time->setText(newTime);
}

void TimerInfo::setName(QString newName)
{
    this->name->setText(newName);
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
    return this->alarm;
}
