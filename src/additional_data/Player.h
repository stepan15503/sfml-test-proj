#pragma once
#include <SFML/Graphics.hpp>
 
using namespace sf;
 
class Player
{
    // Все private переменные могут быть доступны только внутри объекта
private:
 
    Vector2f m_Position;
 
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
 
    // Открытые методы
public:
 
    // Настраиваем Боба в конструкторе
    Player();
 
    // Для отправки спрайта в главную функцию
    Sprite getSprite();

    Vector2f getPosition();
 
    // Для движения Боба
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