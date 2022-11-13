#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtimersmenu.h"
#include "timerinfo.h"


#include <QMessageBox>
#include <QGroupBox>
#include <QTimer>
#include <QTime>
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Колір фону - чорний
    this->setStyleSheet("background-color: black;");

    // поки нульовий таймер
    this->ui->timerTime->setText("00:00:00:000");

    // Бокси для зберігання таймерів
    this->timersBox = new QGroupBox(tr("Regular timers list"));
    this->alarmsBox = new QGroupBox(tr("Alarms list"));

    // setTimerButton викликає timersMenu
    connect(ui->setTimerButton, SIGNAL(clicked(bool)), this, SLOT(timersMenu()));

    // pauseTimerButton призупиняє таймер
    connect(ui->pauseTimerButton, SIGNAL(clicked(bool)), this, SLOT(pauseTimer()));

    // continueTimerButton продовжує таймер
    connect(ui->continueTimerButton, SIGNAL(clicked(bool)), this, SLOT(continueTimer()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timersBox;
    delete alarmsBox;
    for (size_t i = 0; i < timers.size(); i++)
    {
        delete timers[i];
    }
}

void MainWindow::timersMenu()
{
    // Створюємо меню
    addTimersMenu menu;
    menu.setModal(true);

    // Назад
    if (!menu.exec())
    {
        return;
    }

    int n = menu.getNumberOfTimers();
    QLabel* name = menu.getTimerName();
    QScrollArea* scroll = new QScrollArea;
    QVBoxLayout* newBoxLayout = new QVBoxLayout;

    for (int i = 0; i < n; i++)
    {
        // Встановлюємо час завершення таймера
        Timer* timer = new Timer(menu.getEndTime());
        if (timer->getEndTime() != timer->getZeroTime())
        {
                timer->start();
                timer->info->setName(name->text());
                timer->info->setAlarm(menu.isAlarm());

                newBoxLayout->addWidget(timer->info->getName());
                newBoxLayout->addWidget(timer->info->getTime());

                if (timer->info->isAlarm())
                {
                    ui->alarmsList->addWidget(scroll);
                    scroll->setMaximumWidth(ui->alarms->width());
                }
                else
                {
                    ui->regularTimersList->addWidget(scroll);
                    scroll->setMaximumWidth(ui->timers->width());
                }
                this->timers.emplace_back(timer);
        }
        else
        {
            QMessageBox::warning(this, "Ти шо бем бем?", "Введений час не може бути рівним нулю");

        }
    }
    scroll->setLayout(newBoxLayout);
}

void MainWindow::pauseTimer()
{
    timers[0]->pause();
}

void MainWindow::continueTimer()
{
    timers[0]->cont();
}



