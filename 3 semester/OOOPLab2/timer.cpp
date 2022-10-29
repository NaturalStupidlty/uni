#include "timer.h"

Timer::Timer(QTime time, QLabel name)
{
    this->time = time;
    this->name = name.text();
}

Timer::Timer(QTime time, QString name)
{
    this->time = time;
    this->name = name;
}

QTime Timer::getTime()
{
    return time;
}

void Timer::setTime(QTime newTime)
{
    time = newTime;
}

QString Timer::getName()
{
    return name;
}

void Timer::setName(QString newName)
{
    name = newName;
}

Timer::Timer()
{
    this->time.setHMS(0,0,0);
    this->name = "\0";
}
