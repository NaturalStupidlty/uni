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
    int getSelectedTimer();

    // Сетери
    void setSelectedTimer(int index);

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
private:
    // Таймери
    std::vector<Timer*> timers;

    // Індекс обраного таймера
    int selectedTimer;

    // Нульовий час
    // (потрібний для завершення роботи таймера)
    QTime zeroTime;

    // Таймер для відліку
    QTimer timer;

    QMediaPlayer* player;
    QAudioOutput* audioOutput;
private slots:
    // Оновити час
    void updateTime();

};

#endif // TIMERCOLLECTION_H
