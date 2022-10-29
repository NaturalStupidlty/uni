#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

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
    // Слот, що показує час
    void displayTime();

    // Меню додавання таймерів
    void timersMenu();

    // Додати таймери
    void addTimers();

    // Зупинити таймер
    void stopTimer();

private:
    // Юзер інтерфейс
    Ui::MainWindow *ui;

    // Таймер
    QTimer timer;

    // Час закінчення таймера
    QTime endTime;

    // Нульовий час
    // (потрібний для завершення роботи таймера)
    QTime zeroTime;
};

#endif // MAINWINDOW_H
