#ifndef ADDTIMERSMENU_H
#define ADDTIMERSMENU_H

#include <QDialog>
#include <QTime>
#include <QLabel>

namespace Ui {
class addTimersMenu;
}

class addTimersMenu : public QDialog
{
    Q_OBJECT

public:
    explicit addTimersMenu(QWidget *parent = nullptr);
    ~addTimersMenu();

    // Гетери
    QTime getEndTime();
    uint getNumberOfTimers();
    QLabel* getTimerName();

    bool isAlarm();

private slots:
    // Запуск таймерів
    void startTimers();
    void goBack();
private:
    // Інтерфейс
    Ui::addTimersMenu *ui;

    // Обмеження на введення кількості годин
    const ulong maxHours = INT_MAX;
    // Обмеження на введення кількості таймерів
    const ulong maxTimers = INT_MAX;

    // Час завершення таймера
    QTime endTime;
    // Кількість таймерів
    uint numberOfTimers;
    // Назва таймера
    QLabel* timerName;
    // будильник
    bool alarm;

    // Встановити endTime за даними, що
    // були введені в spinBoxes
    void setTime();
};

#endif // ADDTIMERSMENU_H
