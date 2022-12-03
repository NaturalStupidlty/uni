#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addmenu.h"

#include <QMessageBox>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);

    // Колір фону - чорний
    this->setStyleSheet("background-color: black;");

    // Колір кнопок
    this->ui->continueTimerButton->setStyleSheet("color: rgb(69,69,69)");
    this->ui->pauseTimerButton->setStyleSheet("color: rgb(69,69,69)");

    // Для зберігання найближчого таймера
    this->nearestTimerLayout = new QVBoxLayout;

    // Запуск відліку
    this->timers.start();

    // setTimerButton викликає timersMenu
    connect(this->ui->setTimerButton, SIGNAL(clicked(bool)), this, SLOT(timersMenu()));

    // pauseTimerButton призупиняє таймер
    connect(this->ui->pauseTimerButton, SIGNAL(clicked(bool)), this, SLOT(pauseTimer()));

    // continueTimerButton продовжує таймер
    connect(this->ui->continueTimerButton, SIGNAL(clicked(bool)), this, SLOT(continueTimer()));

    // Вибір таймерів
    connect(this->ui->timersList, SIGNAL(itemSelectionChanged()), this, SLOT(selectTimer()));
    connect(this->ui->alarmsList, SIGNAL(itemSelectionChanged()), this, SLOT(selectAlarm()));
}

MainWindow::~MainWindow()
{
    delete this->ui;
}

void MainWindow::timersMenu()
{
    // Створюємо меню вибору
    AddMenu menu;
    menu.setModal(true);

    // Назад
    if (!menu.exec())
    {
        return;
    }
    // Створюємо таймер
    Timer* timer = new Timer(menu.getEndTime(), menu.getTimerName()->text(), menu.isAlarm());
    if (timer->getEndTime() != this->timers.getZeroTime())
    {
            this->timers.add(timer);

            if (timer->isAlarm())
            {
                this->ui->alarmsList->addItem(timer->getInfo());
            }
            else
            {
                this->ui->timersList->addItem(timer->getInfo());
            }
    }
    else
    {
        QMessageBox::warning(this, "Ти шо бем бем?", "Введений час не може бути рівним нулю");

    }
    // Додаємо до вікна найближчий таймер
    if (this->nearestTimerLayout->widget() != this->timers.getNearestTimer()->getTime())
    {
        delete this->nearestTimerLayout;
        this->nearestTimerLayout = new QVBoxLayout;

        this->timers.getNearestTimer()->getName()->setFont(QFont("Montserrat", 36));
        this->timers.getNearestTimer()->getTime()->setFont(QFont("JetBrains Mono NL", 48));
        this->timers.getNearestTimer()->getName()->setAlignment(Qt::AlignCenter|Qt::AlignBottom);
        this->timers.getNearestTimer()->getTime()->setAlignment(Qt::AlignCenter|Qt::AlignTop);

        this->nearestTimerLayout->addWidget(this->timers.getNearestTimer()->getName());
        this->nearestTimerLayout->addWidget(this->timers.getNearestTimer()->getTime());
        this->ui->nearestTimer->setLayout(this->nearestTimerLayout);
    }
    // Відкриваємо програму
    QProcess::startDetached(menu.getProgramPath());
    // Відкриваємо документ
    QDesktopServices::openUrl(QUrl::fromLocalFile(menu.getDocumentPath()));
}

void MainWindow::selectTimer()
{
    select(this->ui->timersList);
}

void MainWindow::selectAlarm()
{
    select(this->ui->alarmsList);
}

void MainWindow::select(QListWidget* items)
{
    vector<int> indexes;
    for (int i = 0; i < items->count(); i++)
    {
        if (items->item(i)->isSelected())
        {
            indexes.emplace_back(i);
        }
    }

    this->timers.setSelectedTimers(indexes);
    this->ui->pauseTimerButton->setStyleSheet("color: rgb(69,69,69)");
    this->ui->continueTimerButton->setStyleSheet("color: rgb(69,69,69)");

    for (uint i = 0; i < indexes.size(); i++)
    {
        if (this->timers[indexes[i]]->isPaused() == false)
        {
            this->ui->pauseTimerButton->setStyleSheet("color: rgb(220,20,60)");
        }
        else
        {
            this->ui->continueTimerButton->setStyleSheet("color: rgb(50,205,50)");
        }
    }
}

void MainWindow::pauseTimer()
{
    if (this->timers.getSelectedTimers().size())
    {
        this->ui->pauseTimerButton->setStyleSheet("color: rgb(69,69,69)");
        this->ui->continueTimerButton->setStyleSheet("color: rgb(50,205,50)");
    }
    this->timers.pause();
}

void MainWindow::continueTimer()
{
    if (this->timers.getSelectedTimers().size())
    {
        this->ui->continueTimerButton->setStyleSheet("color: rgb(69,69,69)");
        this->ui->pauseTimerButton->setStyleSheet("color: rgb(220,20,60)");
    }
    this->timers.cont();
}
