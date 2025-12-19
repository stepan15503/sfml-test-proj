#include "Bullet.h"


Bullet::Bullet()
{
    // Вписываем в переменную скорость
    m_Speed={0,-10};
    // Связываем текстуру и спрайт

    // Связываем текстуру и спрайт
    if (!m_Texture.loadFromFile("assets/bullet.png"))
    {
        printf("Ошибка загрузки bullet"); //Прикрутить плейсхолдер что рисуется без допфайлов вместо пули
    }
    
    m_Sprite= new Sprite(m_Texture);
 
    // Устанавливаем начальную позицию пули в пикселях
    m_Position.x = 300;
    m_Position.y = 300;
    
    m_TopLeftCorner = {-2,-2};
}
 
// Делаем приватный спрайт доступным для функции draw()
Sprite Bullet::getSprite()
{
    return *m_Sprite;
}

void Bullet::setPosition(Vector2i position)
{
    m_Position.x=position.x;
    m_Position.y=position.y;
}

// Сливаем корды(по необходимости)
 
Vector2f Bullet::getPosition()
{
    return m_Position;
}
Vector2f Bullet::getTopLeftPosition()
{
    return m_Position+m_TopLeftCorner;
}
// Двигаем Пулю
void Bullet::update()
{
    m_Position.x+=m_Speed.x;
    m_Position.y+=m_Speed.y;
    // Теперь сдвигаем спрайт на новую позицию
    (*m_Sprite).setPosition(m_Position+m_TopLeftCorner);   
 
}