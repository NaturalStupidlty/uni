#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "timer.h"

#include <QMainWindow>
#include <QGroupBox>
#include <vector>

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
    // Меню додавання таймерів
    void timersMenu();

    // Призупинити таймер
    void pauseTimer();

    // Відновити таймер
    void continueTimer();

private:
    // Інтерфейс
    Ui::MainWindow *ui;

    // Таймери
    vector<Timer*> timers;

    // Для зберігання таймерів
    QGroupBox* timersBox;
    QGroupBox* alarmsBox;
};

#endif // MAINWINDOW_H
