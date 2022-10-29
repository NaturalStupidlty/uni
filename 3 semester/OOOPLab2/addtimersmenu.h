#ifndef ADDTIMERSMENU_H
#define ADDTIMERSMENU_H

#include <QDialog>
#include <QTime>

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

private slots:
    // Запуск таймерів
    void startTimers();

private:
    // Інтерфейс
    Ui::addTimersMenu *ui;

    // Обмеження на введення кількості годин
    const ulong maxHours = 999999999999999999;

    // Час завершення таймера
    QTime endTime;

    // Встановити endTime за даними, що
    // були введені в spinBoxes
    void setTime();
};

#endif // ADDTIMERSMENU_H
