#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qdatetime.h"
#include <QMainWindow>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QTextBrowser>
#include <CustomTextBrowser.h>
#include <QList>
#include <QCheckBox>
#include <script.h>

// Объявление пространства имен для UI
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Определение класса MainWindow, наследующего QMainWindow
class MainWindow : public QMainWindow
{
    Q_OBJECT // Макрос Q_OBJECT для поддержки мета-объектной системы Qt

public:
    // Конструктор и деструктор
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui; // Указатель на интерфейс пользователя

    void setupProfile(); // Метод для настройки профиля пользователя
    void setupHomePage(); // Метод для настройки домашней страницы
    void setupSettings(); // Метод для настройки настроек приложения
    void setupScript(); // Метод для настройки сценариев приложения
    void setupThings(); // Метод для настройки используемых устройств

    void changeWelcome(); // Метод для обновления приветствия

    QString calculateClock(); // Метод для расчёта времени будильника
    bool isWorkDay(); // Метод для определения рабочих дней
    bool isWeekend(); // Метод для определения выходных
    bool isHomeday(); // Метод для определения домашних дней

    CustomTextBrowser* addCard(QHBoxLayout*, QScrollArea*);
    void deleteCard(QHBoxLayout*, QScrollArea*);
    void setCardStyle(CustomTextBrowser*, QString);

    void changeScriptsText(QVector<QVector<QString>>, bool, QString); // Метод изменения скриптов
    void updateScripts();

    QString name; // Имя пользователя
    QTime globalTime; // Глобальное время, используемое в приложении
    int weekday = 0; // Текущий день недели (по умолчанию 0)
    QList<QCheckBox*> weekDayCheckBoxes; // Дни недели

    Script scripts;
    bool checkedThings[14];

    QHBoxLayout *layoutMorning  = new QHBoxLayout();
    QHBoxLayout *layoutDay      = new QHBoxLayout();
    QHBoxLayout *layoutEvening  = new QHBoxLayout();

    QScrollArea *areaMorning;
    QScrollArea *areaDay;
    QScrollArea *areaEvening;

    QVector<QVector<CustomTextBrowser*>> scriptTexts = {{}, {}, {}};
};

#endif // MAINWINDOW_H
