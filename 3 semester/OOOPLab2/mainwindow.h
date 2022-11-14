#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "timer.h"

#include <vector>
#include <QMainWindow>
#include <QLayout>

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

    //
    void selectTimer();

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
    QVBoxLayout* timersLayout;
    QVBoxLayout* alarmsLayout;
};

#endif // MAINWINDOW_H
