#ifndef TIMERINFO_H
#define TIMERINFO_H

#include <QWidget>
#include <QLabel>

class TimerInfo : public QWidget
{
    Q_OBJECT
public:
    explicit TimerInfo(QWidget *parent = nullptr);
    TimerInfo(QString time, QString name);
    ~TimerInfo();

    void setTime(QString newTime);
    void setName(QString newName);
    void setAlarm(bool alarm);

    QLabel* getTime();
    QLabel* getName();
    bool isAlarm();

private:
    QLabel* time;
    QLabel* name;
    bool alarm;
};

#endif // TIMERINFO_H
