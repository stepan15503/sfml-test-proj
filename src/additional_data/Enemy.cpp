#include "Enemy.h"
#include "cmath"

Enemy::Enemy()
{
    // Вписываем в переменную скорость
    m_Speed = 4;

    
    m_TopLeftCorner = {-9,-21};
    // Связываем текстуру и спрайт
    if (!m_Texture.loadFromFile("assets/placeholder.png"))
    {
        printf("Ошибка загрузки"); //Добавить повторные попытки/замену на текстуру ошибки(посмотреть на возможность создания оной векторно а не загрузкой из файла)
    }
    
    m_Sprite= new Sprite(m_Texture);     
 
    // Устанавливаем начальную позицию
    m_Position.x = 0;
    m_Position.y = 0;

 
}
 
// Делаем приватный спрайт доступным для функции draw()
Sprite Enemy::getSprite()
{
    return *m_Sprite;
}
 
Vector2f Enemy::getPosition()
{
    return m_Position;
}
Vector2f Enemy::getTopLeftPosition()
{
    return m_Position+m_TopLeftCorner;
}
//Выстрел по объекту

void Enemy::update(Vector2i playerposition, std::list<std::unique_ptr<EnemyBullet>>* enemybullets)
{
    Vector2i positionDelta={playerposition.x-m_Position.x,playerposition.y-m_Position.y};
    (*enemybullets).push_back(std::make_unique<EnemyBullet>());
    (*enemybullets).back()->setPosition(m_Position);
    (*enemybullets).back()->setSpeedVector({positionDelta.x/sqrt(positionDelta.x*positionDelta.x+positionDelta.y*positionDelta.y),positionDelta.y/sqrt(positionDelta.x*positionDelta.x+positionDelta.y*positionDelta.y)});
    for (auto iter = (*enemybullets).begin(); iter != (*enemybullets).end(); iter++)
    {
        if ((*iter)->getPosition().y < -50) // Если пуля далеко за верхней границей
        {
            iter=(*enemybullets).erase(iter);
        }
    } 
}