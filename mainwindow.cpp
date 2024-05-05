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
    setupThings();

    setupScript();

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

    //Настройка поведения при изменении времени на дорогу
    connect(ui->travelTime, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](){

    });
}
// Настройка вкладки устройства
void MainWindow::setupThings(){

    connect(ui->frige,&QCheckBox::stateChanged,this,[this](){ // Устройство: Холодильник

    });
    connect(ui->airConditioner,&QCheckBox::stateChanged,this,[this](){ // Устройство: Кондиционер

    });
    connect(ui->cameras,&QCheckBox::stateChanged,this,[this](){ // Устройство: Камеры

    });
    connect(ui->coffeMachine,&QCheckBox::stateChanged,this,[this](){ // Устройство: Кофемашина

    });
    connect(ui->door,&QCheckBox::stateChanged,this,[this](){ // Устройство: Дверь

    });
    connect(ui->intercom,&QCheckBox::stateChanged,this,[this](){ // Устройство: Домофон

    });
    connect(ui->kettle,&QCheckBox::stateChanged,this,[this](){ // Устройство: Чайник

    });
    connect(ui->light,&QCheckBox::stateChanged,this,[this](){ // Устройство: Свет

    });
    connect(ui->lightSwitch,&QCheckBox::stateChanged,this,[this](){ // Устройство: Переключатель света

    });
    connect(ui->locks,&QCheckBox::stateChanged,this,[this](){ // Устройство: Замок

    });
    connect(ui->robotCleaner,&QCheckBox::stateChanged,this,[this](){ // Устройство: Робот пылесос

    });
    connect(ui->securitySystem,&QCheckBox::stateChanged,this,[this](){ // Устройство: Система безопасности

    });
    connect(ui->smartSpeaker,&QCheckBox::stateChanged,this,[this](){ // Устройство: Умная колонка

    });
    connect(ui->socket,&QCheckBox::stateChanged,this,[this](){ // Устройство: Розетка

    });

}
// Метод для настройки сценариев приложения
void MainWindow::setupScript() {
    changeMorningScripts();
    changeDayScripts();
    changeEveningScripts();
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
    ui->scrollAreaMorningScript->setWidget(scrollAreaWidgetMorningScript);
}

// Метод изменения дневных скриптов
void MainWindow::changeDayScripts() {

    // Создаем горизонтальный Layout для содержимого QScrollArea
    QHBoxLayout *layout = new QHBoxLayout();

    // Создаем QTextBrowser и добавляем его в Layout
    QTextBrowser *script = new QTextBrowser();
    script->setText("Днём: датчик освещенности включает свет, кофемашина автоматически готовит кофе, термостат повышает температуру. Утренний рассвет начинается.");
    script->setMinimumHeight(120);
    script->setMaximumHeight(167);
    script->setMinimumWidth(200);
    script->setMaximumWidth(200);
    script->setStyleSheet("QTextBrowser { background-color: purple; }");
    layout->addWidget(script);

    // Повторяем для остальных QTextBrowser
    QTextBrowser *script1 = new QTextBrowser();
    script1->setText("Днём: датчик освещенности включает свет, кофемашина автоматически готовит кофе, термостат повышает температуру. Утренний рассвет начинается.");
    script1->setMinimumHeight(120);
    script1->setMaximumHeight(167);
    script1->setMinimumWidth(200);
    script1->setMaximumWidth(200);
    script1->setStyleSheet("QTextBrowser { background-color: red; }");
    layout->addWidget(script1);

    QTextBrowser *script2 = new QTextBrowser();
    script2->setText("Днём: датчик освещенности включает свет, кофемашина автоматически готовит кофе, термостат повышает температуру. Утренний рассвет начинается.");
    script2->setMinimumHeight(120);
    script2->setMaximumHeight(167);
    script2->setMinimumWidth(200);
    script2->setMaximumWidth(200);
    script2->setStyleSheet("QTextBrowser { background-color: green; }");
    layout->addWidget(script2);

    QTextBrowser *script3 = new QTextBrowser();
    script3->setText("Днём: датчик освещенности включает свет, кофемашина автоматически готовит кофе, термостат повышает температуру. Утренний рассвет начинается.");
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
    ui->scrollAreaDayScript->setWidget(scrollAreaWidgetMorningScript);
}

// Метод изменения дневных скриптов
void MainWindow::changeEveningScripts() {

    // Создаем горизонтальный Layout для содержимого QScrollArea
    QHBoxLayout *layout = new QHBoxLayout();

    // Создаем QTextBrowser и добавляем его в Layout
    QTextBrowser *script = new QTextBrowser();
    script->setText("Вечером: датчик освещенности включает свет, кофемашина автоматически готовит кофе, термостат повышает температуру. Утренний рассвет начинается.");
    script->setMinimumHeight(120);
    script->setMaximumHeight(167);
    script->setMinimumWidth(200);
    script->setMaximumWidth(200);
    script->setStyleSheet("QTextBrowser { background-color: purple; }");
    layout->addWidget(script);

    // Повторяем для остальных QTextBrowser
    QTextBrowser *script1 = new QTextBrowser();
    script1->setText("Вечером: датчик освещенности включает свет, кофемашина автоматически готовит кофе, термостат повышает температуру. Утренний рассвет начинается.");
    script1->setMinimumHeight(120);
    script1->setMaximumHeight(167);
    script1->setMinimumWidth(200);
    script1->setMaximumWidth(200);
    script1->setStyleSheet("QTextBrowser { background-color: red; }");
    layout->addWidget(script1);

    QTextBrowser *script2 = new QTextBrowser();
    script2->setText("Вечером: датчик освещенности включает свет, кофемашина автоматически готовит кофе, термостат повышает температуру. Утренний рассвет начинается.");
    script2->setMinimumHeight(120);
    script2->setMaximumHeight(167);
    script2->setMinimumWidth(200);
    script2->setMaximumWidth(200);
    script2->setStyleSheet("QTextBrowser { background-color: green; }");
    layout->addWidget(script2);

    QTextBrowser *script3 = new QTextBrowser();
    script3->setText("Вечером: датчик освещенности включает свет, кофемашина автоматически готовит кофе, термостат повышает температуру. Утренний рассвет начинается.");
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
    ui->scrollAreaEveningScript->setWidget(scrollAreaWidgetMorningScript);

}
