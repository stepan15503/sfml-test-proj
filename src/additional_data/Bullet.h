#pragma once
#include <SFML/Graphics.hpp>
 
using namespace sf;
 
class Bullet
{
    // Все private переменные могут быть доступны только внутри объекта
private:
 
    Vector2f m_Position;
 
    // Объявляем объект Sprite
    Sprite *m_Sprite;
 
    // Добавляем текстуру
    Texture m_Texture;
 
    // Вектор скорости
 
    Vector2f m_Speed;
    // Открытые методы
public:
 
    // Настраиваем в конструкторе
    Bullet();
 
    // Для отправки спрайта в главную функцию
    Sprite getSprite();

    // Для запроса координат(мб не понадобится)
    Vector2f getPosition();

    void setPosition(Vector2f position);
 
    // Для движения
    void move();
 
    // Эта функция будет вызываться на каждый кадр
    void update();
 
};