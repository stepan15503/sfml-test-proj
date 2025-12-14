#pragma once
#include <SFML/Graphics.hpp>
 
using namespace sf;
 
class Entity{
    // Все private переменные могут быть доступны только внутри объекта
private:
 
    Vector2f m_Position;
 
    // Объявляем объект Sprite
    Sprite *m_Sprite;
 
    // Добавляем текстуру
    Texture m_Texture;

    // Открытые методы
public:
 
    // Настраиваем Боба в конструкторе
    Entity();
 
    // Для отправки спрайта в главную функцию
    Sprite getSprite();
 
 
    // Эта функция будет вызываться на каждый кадр
    void update();
 
};
