#include "timer.h"

Timer::Timer()
{
    this->endTime.setHMS(0, 0, 0);
    this->time = new QLabel;
    this->name = new QLabel;
    this->time->setAlignment(Qt::AlignCenter);
    this->name->setAlignment(Qt::AlignCenter);
    this->time->setFont(QFont("JetBrains Mono NL", 18));
    this->name->setFont(QFont("Montserrat", 18));
    this->lastUpdateTime = QTime::currentTime();
}

Timer::Timer(QTime time)
{
    this->endTime = time;
    this->time = new QLabel;
    this->name = new QLabel;
    this->time->setAlignment(Qt::AlignCenter);
    this->name->setAlignment(Qt::AlignCenter);
    this->time->setFont(QFont("JetBrains Mono NL", 18));
    this->name->setFont(QFont("Montserrat", 18));
    this->lastUpdateTime = QTime::currentTime();
}

Timer::~Timer()
{
    delete this->time;
    delete this->name;
}

QTime Timer::getEndTime()
{
    return endTime;
}

QTime Timer::getLastUpdateTime()
{
    return this->lastUpdateTime;
}

void Timer::setEndTime(QTime newTime)
{
    this->endTime = newTime;
}

void Timer::setLastUpdateTime(QTime newUpdateTime)
{
    this->lastUpdateTime = newUpdateTime;
}

void Timer::setTime(QString newTime)
{
    this->time->setText(newTime);
}

void Timer::setName(QString newName)
{
    this->name->setText(newName);
}

void Timer::setAlarm(bool alarm)
{
    this->alarm = alarm;
}

void Timer::setStopped(bool stop)
{
    this->stopped = stop;
}

QLabel* Timer::getTime()
{
    return this->time;
}

QLabel* Timer::getName()
{
    return this->name;
}

bool Timer::isAlarm()
{
    return this->alarm;
}

bool Timer::isStopped()
{
    return this->stopped;
}
