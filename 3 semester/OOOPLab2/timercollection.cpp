#include "timercollection.h"
#include <QMessageBox>

TimerCollection::TimerCollection(QObject *parent)
    : QObject{parent}
{
    this->zeroTime.setHMS(0, 0, 0);
    this->selectedTimer = -1;
}

TimerCollection::~TimerCollection()
{
    for (uint i = 0; i < this->timers.size(); i++)
    {
        delete this->timers[i];
    }
}

QTime TimerCollection::getZeroTime()
{
    return this->zeroTime;
}

int TimerCollection::getSelectedTimer()
{
    return this->selectedTimer;
}

void TimerCollection::setSelectedTimer(int index)
{
    this->selectedTimer = index;
}

void TimerCollection::add(Timer* newTimer)
{
    this->timers.emplace_back(newTimer);
}


void TimerCollection::start()
{
    QTimer::singleShot(0, this, SLOT(updateTime()));
}

void TimerCollection::pause()
{
    this->timers[selectedTimer]->setStopped(true);
}

void TimerCollection::cont()
{
    this->timers[selectedTimer]->setStopped(false);
}

void TimerCollection::updateTime()
{
    for (uint i = 0; i < this->timers.size(); i++)
    {
        if (this->timers[i]->getEndTime() == this->zeroTime)
        {
            stop(i);
        }
        else if (!this->timers[i]->isStopped())
        {
            // Зворотній відлік:
            // Поправка на час, що пройшов з моменту останнього оновлення
            int milisecondsPassed =
                    (QTime::currentTime().addMSecs
                     (-(this->timers[i]->getLastUpdateTime()
                        .msecsSinceStartOfDay())))
                    .msecsSinceStartOfDay();
            if (milisecondsPassed > this->timers[i]->getEndTime().msecsSinceStartOfDay())
            {
                stop(i);
            }
            this->timers[i]->setEndTime(this->timers[i]->getEndTime().addMSecs(-milisecondsPassed));
            timers[i]->setLastUpdateTime(QTime::currentTime());
            this->timers[i]->setTime(this->timers[i]->getEndTime().toString("hh:mm:ss.zzz"));
        }
    }
    QTimer::singleShot(1, this, SLOT(updateTime()));
}

void TimerCollection::stop(int index)
{
    QMessageBox timerOver;
    timerOver.setWindowTitle("Час таймера вийшов.");
    timerOver.setText((this->timers[index]->getName())->text());
    timerOver.exec();
    delete this->timers[index];
    Timer* copy = this->timers.back();
    this->timers[index] = copy;
    this->timers.pop_back();
}

