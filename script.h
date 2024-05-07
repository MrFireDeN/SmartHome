#ifndef SCRIPT_H
#define SCRIPT_H

#include <QString>
#include <QVector>

class script
{
private:
    QString thing;
    QVector<QString> morning;
    QVector<QString> day;
    QVector<QString> evening;

public:
    script();

    QVector<QVector<QString>> getFrige();           // Холодильник
    QVector<QVector<QString>> getAirConditioner();  // Кондиционер
    QVector<QVector<QString>> getCameras();         // Камера
    QVector<QVector<QString>> getCoffeMachine();    // Кофемашина
    QVector<QVector<QString>> getDoor();            // Дверь
    QVector<QVector<QString>> getIntercom();        // Домофон
    QVector<QVector<QString>> getKettle();          // Чайник
    QVector<QVector<QString>> getLight();           // Свет
    QVector<QVector<QString>> getLightSwitch();     // Выключатель
    QVector<QVector<QString>> getLocks();           // Замок
    QVector<QVector<QString>> getRobotCleaner();    // Робот-пылесос
    QVector<QVector<QString>> getSecuritySystem();  // Система охраны
    QVector<QVector<QString>> getSmartSpeaker();    // Умная колонка
    QVector<QVector<QString>> getSocket();          // Розетка
};

#endif // SCRIPT_H
