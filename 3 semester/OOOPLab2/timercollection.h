#ifndef TIMERCOLLECTION_H
#define TIMERCOLLECTION_H

#include "timer.h"
#include <vector>

#include <QObject>
#include <QTime>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>

class TimerCollection : public QObject
{
    Q_OBJECT
public:
    explicit TimerCollection(QObject *parent = nullptr);
    ~TimerCollection();

    // Гетери
    QTime getZeroTime();
    Timer* getNearestTimer();
    std::vector<int> getSelectedTimers();
    int getSize();

    // Сетери
    void setSelectedTimers(std::vector<int> index);

    // Додати таймер
    void add(Timer* newTimer);

    // Запуск таймерів
    void start();

    // Призупинити таймер
    void pause();

    // Відновити таймер
    void cont();

    // Зупинити таймер
    void stop(int index);

    // Отримати таймер за індексом
    Timer *&operator [](const int& i);
private:
    // Таймери
    std::vector<Timer*> timers;

    // Найближчий таймер
    Timer* nearestTimer;

    // час, коли зупинили найближчий таймер
    QTime nearestTimerPauseTime;

    // Індекси обраних елементів
    std::vector<int> selectedTimers;

    // Нульовий час
    // (потрібний для завершення роботи таймера)
    QTime zeroTime;

    // Таймер для відліку
    QTimer timer;

    // Для звуку завершення таймера
    QMediaPlayer* player;
    QAudioOutput* audioOutput;
private slots:
    // Оновити час
    void updateTime();

};

#endif // TIMERCOLLECTION_H
