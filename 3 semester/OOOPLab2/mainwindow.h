#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "timercollection.h"

#include <QMainWindow>
#include <QVBoxLayout>

using std::vector;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

private slots:
    // Додавання таймерів
    void timersMenu();

    // Обрати таймер
    void selectTimer();
    // Обрати будильник
    void selectAlarm();
    // Допоміжна функція, що встановлює
    // вибрані елементи списку вибраними таймерами
    void select(vector<int> indexes, QList<QListWidgetItem*> selectedI);

    // Призупинити таймер
    void pauseTimer();

    // Відновити таймер
    void continueTimer();

private:
    // Інтерфейс
    Ui::MainWindow *ui;

    // Таймери
    TimerCollection timers;

    // Для зберігання найближчого таймера
    QVBoxLayout* nearestTimerLayout;
};

#endif // MAINWINDOW_H
