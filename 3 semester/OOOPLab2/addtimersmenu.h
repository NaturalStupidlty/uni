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
    QLabel* getTimerName();
    QString getTimerSound();

private slots:
    // Запуск таймерів
    void startTimers();

    // Знайти звук
    void findSound();

private:
    // Інтерфейс
    Ui::addTimersMenu *ui;

    // Обмеження на введення кількості годин
    const ulong maxHours = 23;
    const uint maxTimerNameLenght = 24;

    // Час завершення таймера
    QTime endTime;
    // Назва таймера
    QLabel* timerName;

    // Встановити endTime за даними, що
    // були введені в spinBoxes
    void setTime();
};

#endif // ADDTIMERSMENU_H
