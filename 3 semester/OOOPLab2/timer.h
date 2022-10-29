#ifndef TIMER_H
#define TIMER_H

#include <QTime>
#include <QLabel>

class Timer {
    QTime time;
    QString name;
public:
    // Конструктори
    Timer();
    Timer(QTime time, QLabel name);
    Timer(QTime time, QString name);

    // Сетери
    QTime getTime();
    void setTime(QTime newTime);

    // Гетери
    QString getName();
    void setName(QString newName);
};

#endif // TIMER_H
