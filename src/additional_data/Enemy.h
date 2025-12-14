#pragma once
#include <SFML/Graphics.hpp>
 
using namespace sf;
 
class Enemy
{
    // Все private переменные могут быть доступны только внутри объекта
private:
 
    Vector2f m_Position;
 
    // Объявляем объект Sprite
    Sprite *m_Sprite;
 
    // Добавляем текстуру
    Texture m_Texture;
 
    // Скорость и скорость в фокусе в пикселях за кадр
    int m_Speed;
    int m_Focused_Speed;
    // Положение левого угла(места откруда начинается отрисовка текстуры относительно центра)
    Vector2f m_TopLeftCorner;

    // Число кадров неуязвимости
    unsigned int m_InvFrameCount;
    // число хитпойнтов
    int m_HP;

 public:
    // Конструктор
    Player();
 
    // Для отправки спрайта/позиции в главную функцию
    Sprite getSprite();

    Vector2f getPosition();

    Vector2f getTopLeftPosition();
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
    void update();
 
};