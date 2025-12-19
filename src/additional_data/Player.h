#pragma once
#include <SFML/Graphics.hpp>
#include "EnemyBullet.h"
#include <algorithm>
using namespace sf;
 
class Player
{
    // Все private переменные могут быть доступны только внутри объекта
private:
 
    Vector2i m_Position;
 
    // Объявляем объект Sprite
    Sprite *m_Sprite;
 
    // Добавляем текстуру
    Texture m_Texture;
 
    // Логические переменные для отслеживания направления движения
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_ShiftPressed;
 
    // Скорость и скорость в фокусе в пикселях за кадр
    int m_Speed;
    int m_Focused_Speed;
    // Положение левого угла(места откруда начинается отрисовка текстуры относительно центра)
    Vector2i m_TopLeftCorner;

    // Число кадров неуязвимости
    unsigned int m_InvFrameCount;

    unsigned int m_Lives;

    unsigned int m_Bombs;

    unsigned int m_Power;
public:    // Открытые методы
 
    // Конструктор
    Player();
 
    // Для отправки спрайта/позиции в главную функцию
    Sprite getSprite();

    Vector2i getPosition();

    Vector2i getTopLeftPosition();

    Vector2i getSpeedVector();

    // Для движения от клавиш
    void moveLeft();
 
    void moveRight();

    void moveUp();

    void moveDown();

    void getShifted();
 
    // Прекращение движения
    void stopLeft();
 
    void stopRight();

    void stopUp();

    void stopDown();

    void getUnshifted();

    // Эта функция будет вызываться на каждый кадр
    void update(bool isShot,std::list<std::unique_ptr<EnemyBullet>>* enemybullets);

    
};