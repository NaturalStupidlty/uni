#include "timercollection.h"
#include <QMessageBox>

TimerCollection::TimerCollection(QObject *parent)
    : QObject{parent}
{
    this->zeroTime.setHMS(0, 0, 0);
    this->player = new QMediaPlayer;
    this->audioOutput = new QAudioOutput;
    this->nearestTimer = new Timer(this->zeroTime, "", false);
    this->nearestTimerPauseTime = this->zeroTime;
}

TimerCollection::~TimerCollection()
{
    delete this->player;
    delete this->audioOutput;
    delete this->nearestTimer;
    for (uint i = 0; i < this->timers.size(); i++)
    {
        delete this->timers[i];
    }
}

QTime TimerCollection::getZeroTime()
{
    return this->zeroTime;
}

Timer* TimerCollection::getNearestTimer()
{
    return this->nearestTimer;
}

std::vector<int> TimerCollection::getSelectedTimers()
{
    return this->selectedTimers;
}

int TimerCollection::getSize()
{
    return this->timers.size();
}

void TimerCollection::setSelectedTimers(std::vector<int> index)
{
    this->selectedTimers.clear();
    for (uint i = 0; i < index.size(); i++)
    {
        this->selectedTimers.emplace_back(index[i]);
    }
}

void TimerCollection::add(Timer* newTimer)
{
    int seconds = newTimer->getEndTime().msecsSinceStartOfDay();
    if ((this->nearestTimer->getEndTime() == this->zeroTime)
        or (seconds <= this->nearestTimer->getEndTime().msecsSinceStartOfDay()))
    {
        this->nearestTimer = newTimer;
    }
    auto it = this->timers.begin();
    while (it != this->timers.end() and seconds >= (*it)->getEndTime().msecsSinceStartOfDay())
    {
        it++;
    }
    this->timers.insert(it, newTimer);
}


void TimerCollection::start()
{
    QTimer::singleShot(0, this, SLOT(updateTime()));
}

void TimerCollection::pause()
{
    for (uint i = 0; i < this->selectedTimers.size(); i++)
    {
        this->timers[this->selectedTimers[i]]->setPaused(true);
        if (this->timers[this->selectedTimers[i]] == this->nearestTimer)
        {
            this->nearestTimerPauseTime = QTime::currentTime();
        }
    }
}

void TimerCollection::cont()
{
    for (uint i = 0; i < this->selectedTimers.size(); i++)
    {
        this->timers[this->selectedTimers[i]]->setPaused(false);
    }
}

void TimerCollection::updateTime()
{
    for (uint i = 0; i < this->timers.size(); i++)
    {
        if (this->timers[i]->getEndTime() == this->zeroTime)
        {
            stop(i);
        }
        else if (!this->timers[i]->isPaused())
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
                continue;
            }
            this->timers[i]->setEndTime(this->timers[i]->getEndTime().addMSecs(-milisecondsPassed));
            this->timers[i]->setLastUpdateTime(QTime::currentTime());
            if (this->timers[i]->getEndTime().msecsSinceStartOfDay() < this->nearestTimer->getEndTime().msecsSinceStartOfDay())
            {
                this->nearestTimer = this->timers[i];
            }
            this->timers[i]->setTime(this->timers[i]->getEndTime().toString("hh:mm:ss:zzz"));
        }
    }
    QTimer::singleShot(1, this, SLOT(updateTime()));
}

void TimerCollection::stop(int index)
{
    this->timers[index]->setTime(zeroTime.toString("hh:mm:ss:zzz"));

    this->player->setAudioOutput(audioOutput);
    this->player->setSource(QUrl("qrc:/resource/sounds/sound.mp3"));
    this->audioOutput->setVolume(0);
    this->player->play();

    QMessageBox timerOver;
    timerOver.setWindowTitle("Час таймера вийшов.");
    timerOver.setText((this->timers[index]->getName())->text());
    timerOver.exec();

    if (this->nearestTimer == timers[index])
    {
        if (this->timers.size() != 1)
        {
            this->nearestTimer = this->timers.front();
        }
        this->nearestTimer = new Timer(zeroTime, "", false);
    }

    delete this->timers[index];
    Timer* copy = this->timers.back();
    this->timers[index] = copy;
    this->timers.pop_back();
}


Timer*& TimerCollection::operator [](const int& i)
{
    return this->timers[i];
}
