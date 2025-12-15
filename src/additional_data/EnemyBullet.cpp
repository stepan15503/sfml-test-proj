#include "EnemyBullet.h"


EnemyBullet::EnemyBullet()
{
    // Вписываем в переменную скорость
    m_Speed={0,-10};
    // Связываем текстуру и спрайт

    // Связываем текстуру и спрайт
    if (!m_Texture.loadFromFile("assets/bullet.png")) //пока что грузим обычные пули, потом поменяем
    {
        printf("Ошибка загрузки bullet"); //Прикрутить плейсхолдер что рисуется без допфайлов вместо пули
    }
    
    m_Sprite= new Sprite(m_Texture);
 
    // Устанавливаем начальную позицию пули в пикселях
    m_Position.x = 0;
    m_Position.y = 0;
    
    m_TopLeftCorner = {-2,-2};
}
 
// Делаем приватный спрайт доступным для функции draw()
Sprite EnemyBullet::getSprite()
{
    return *m_Sprite;
}

void EnemyBullet::setPosition(Vector2f position)
{
    m_Position.x=position.x;
    m_Position.y=position.y;
}

void EnemyBullet::setSpeedVector(Vector2f vector)
{
    m_Speed=vector;
}

// Сливаем корды(по необходимости)
 
Vector2f EnemyBullet::getPosition()
{
    return m_Position;
}
Vector2f EnemyBullet::getTopLeftPosition()
{
    return m_Position+m_TopLeftCorner;
}
// Двигаем Пулю
void EnemyBullet::update()
{
    m_Position.x+=m_Speed.x;
    m_Position.y+=m_Speed.y;
    // Теперь сдвигаем спрайт на новую позицию
    (*m_Sprite).setPosition(m_Position+m_TopLeftCorner);   
}