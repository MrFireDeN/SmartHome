#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

// Конструктор главного окна
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Инициализация пользовательского интерфейса

    // Настройка различных частей интерфейса
    setupProfile();
    setupHomePage();
    setupSettings();

    setupScript(ui->scrollAreaMorningScript);
    setupScript(ui->scrollAreaDayScript);
    setupScript(ui->scrollAreaEveningScript);

    //ui->dayScript_1->setStyleSheet("QTextBrowser { background-color: purple; }");
    //ui->dayScript_2->setStyleSheet("QTextBrowser { background-color: red; }");
    //ui->dayScript_3->setStyleSheet("QTextBrowser { background-color: green; }");
    //ui->dayScript_4->setStyleSheet("QTextBrowser { background-color: blue; }");
}

// Деструктор главного окна
MainWindow::~MainWindow()
{
    delete ui; // Освобождение ресурсов пользовательского интерфейса
}

// Настройка профиля пользователя
void MainWindow::setupProfile() {
    name = ui->name->text(); // Получение имени пользователя из текстового поля

    // Настройка поведения при включении/выключении чекбокса "Всегда дома"
    connect(ui->checkBoxAlwaysHome, &QCheckBox::clicked, this, [this](bool checked) {
        qDebug() << "Always Home: " << checked; // Логирование состояния чекбокса
        // Включение/выключение элементов управления временем работы в зависимости от состояния чекбокса
        ui->timeEditStartWorking->setEnabled(!checked);
        ui->timeEditStopWorking->setEnabled(!checked);
    });

    // Обновление имени пользователя и приветствия при изменении текста в поле ввода имени
    connect(ui->name, &QLineEdit::textChanged, this, [this]() {
        name = ui->name->text(); // Обновление имени пользователя
        qDebug() << "name: " << name; // Логирование нового имени

        changeWelcome(); // Обновление приветствия
    });
}

// Настройка домашней страницы
void MainWindow::setupHomePage() {
    changeWelcome(); // Инициализация приветствия на домашней странице
}

// Настройка настроек приложения
void MainWindow::setupSettings() {
    globalTime = ui->timeEditGlobalTime->time(); // Инициализация глобального времени

    // Настройка поведения при включении/выключении чекбокса "Системное время"
    connect(ui->checkBoxSystemTime, &QCheckBox::clicked, this, [this](bool checked) {
        // Включение/выключение элементов управления временем и днями недели
        ui->comboBoxWeekday->setEnabled(!checked);
        ui->timeEditGlobalTime->setEnabled(!checked);

        // Установка времени в зависимости от состояния чекбокса
        if (checked) {
            globalTime = QTime::currentTime(); // Текущее системное время
        }
        else {
            globalTime = ui->timeEditGlobalTime->time(); // Время, выбранное пользователем
        }

        changeWelcome(); // Обновление приветствия
    });

    // Обновление глобального времени и приветствия при изменении времени
    connect(ui->timeEditGlobalTime, &QTimeEdit::timeChanged, this, [this]() {
        globalTime = ui->timeEditGlobalTime->time(); // Обновление глобального времени

        changeWelcome(); // Обновление приветствия
    });
}

void MainWindow::setupScript(QScrollArea *area) {
    // Создаем горизонтальный Layout для содержимого QScrollArea
    QHBoxLayout *layout = new QHBoxLayout();

    // Создаем QTextBrowser и добавляем его в Layout
    QTextBrowser *script = new QTextBrowser();
    script->setText("Утром: датчик освещенности включает свет, кофемашина автоматически готовит кофе, термостат повышает температуру. Утренний рассвет начинается.");
    script->setMinimumHeight(120);
    script->setMaximumHeight(167);
    script->setMinimumWidth(200);
    script->setMaximumWidth(200);
    script->setStyleSheet("QTextBrowser { background-color: purple; }");
    layout->addWidget(script);

    // Повторяем для остальных QTextBrowser
    QTextBrowser *script1 = new QTextBrowser();
    script1->setText("Утром: датчик освещенности включает свет, кофемашина автоматически готовит кофе, термостат повышает температуру. Утренний рассвет начинается.");
    script1->setMinimumHeight(120);
    script1->setMaximumHeight(167);
    script1->setMinimumWidth(200);
    script1->setMaximumWidth(200);
    script1->setStyleSheet("QTextBrowser { background-color: red; }");
    layout->addWidget(script1);

    QTextBrowser *script2 = new QTextBrowser();
    script2->setText("Утром: датчик освещенности включает свет, кофемашина автоматически готовит кофе, термостат повышает температуру. Утренний рассвет начинается.");
    script2->setMinimumHeight(120);
    script2->setMaximumHeight(167);
    script2->setMinimumWidth(200);
    script2->setMaximumWidth(200);
    script2->setStyleSheet("QTextBrowser { background-color: green; }");
    layout->addWidget(script2);

    QTextBrowser *script3 = new QTextBrowser();
    script3->setText("Утром: датчик освещенности включает свет, кофемашина автоматически готовит кофе, термостат повышает температуру. Утренний рассвет начинается.");
    script3->setMinimumHeight(120);
    script3->setMaximumHeight(167);
    script3->setMinimumWidth(200);
    script3->setMaximumWidth(200);
    script3->setStyleSheet("QTextBrowser { background-color: blue; }");
    layout->addWidget(script3);

    // Создаем QWidget для содержимого QScrollArea и устанавливаем в него Layout
    QWidget *scrollAreaWidgetMorningScript = new QWidget();
    scrollAreaWidgetMorningScript->setLayout(layout);

    // Устанавливаем scrollAreaWidgetMorningScript в качестве содержимого QScrollArea
    area->setWidget(scrollAreaWidgetMorningScript);
}

// Метод для обновления текста приветствия в зависимости от времени суток
void MainWindow::changeWelcome() {
    QString welcome; // Строка для хранения приветствия
    int hour = globalTime.hour(); // Получение текущего часа

    // Определение приветствия в зависимости от времени суток
    if (hour >= 4 && hour <= 10) {
        welcome = "Доброе утро, " + name;
    } else if (hour > 10 && hour <= 16) {
        welcome = "Добрый день, " + name;
    } else if (hour > 16 && hour <= 22) {
        welcome = "Добрый вечер, " + name;
    } else {
        welcome = "Доброй ночи, " + name;
    }

    // Установка текста приветствия в пользовательский интерфейс
    ui->labelWelcome->setText(welcome);
}

// Метод изменения утренних скриптов
void MainWindow::changeMorningScripts() {

}

// Метод изменения дневных скриптов
void MainWindow::changeDayScripts() {

}

// Метод изменения дневных скриптов
void MainWindow::changeEveningScripts() {

}
