#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "timer.h"

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

    // Об'єкт таймера
    Timer timer;

};

#endif // MAINWINDOW_H
