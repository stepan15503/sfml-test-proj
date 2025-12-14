#include "Player.h"


Player::Player()
{
    // Вписываем в переменную скорость
    m_Speed = 4;
    m_Focused_Speed =2;
    
    m_TopLeftCorner = {-9,-21};
    // Связываем текстуру и спрайт
    if (!m_Texture.loadFromFile("assets/placeholder.png"))
    {
        printf("Ошибка загрузки"); //Добавить повторные попытки/замену на текстуру ошибки(посмотреть на возможность создания оной векторно а не загрузкой из файла)
    }
    
    m_Sprite= new Sprite(m_Texture);     
 
    // Устанавливаем начальную позицию
    m_Position.x = 300;
    m_Position.y = 300;

 
}
 
// Делаем приватный спрайт доступным для функции draw()
Sprite Player::getSprite()
{
    return *m_Sprite;
}
 
void Player::moveLeft()
{
    m_LeftPressed = true;
}
 
void Player::moveRight()
{
    m_RightPressed = true;
}

void Player::moveUp()
{
    m_UpPressed = true;
}
 
void Player::moveDown()
{
    m_DownPressed = true;
}
 
void Player::stopLeft()
{
    m_LeftPressed = false;
}
 
void Player::stopRight()
{
    m_RightPressed = false;
}

void Player::stopUp()
{
    m_UpPressed = false;
}
 
void Player::stopDown()
{
    m_DownPressed = false;
}

void Player::getShifted()
{
    m_ShiftPressed = true;
}

void Player::getUnshifted()
{
    m_ShiftPressed = false;
}
 
Vector2f Player::getPosition()
{
    return m_Position;
}
Vector2f Player::getTopLeftPosition()
{
    return m_Position+m_TopLeftCorner;
}
//Движение на основании ввода

void Player::update()
{
    int speed=m_Speed;

    if (m_ShiftPressed){
        speed = m_Focused_Speed;
    }

    if (m_RightPressed and not m_LeftPressed)
    {
        m_Position.x += speed;
        if (m_Position.x>459) m_Position.x=459;
    }
 
    if (m_LeftPressed and not m_RightPressed)
    {
        m_Position.x -= speed;
        if (m_Position.x<13) m_Position.x=13;
    }

    if (m_UpPressed and not m_DownPressed)
    {
        m_Position.y -= speed;
        if (m_Position.y < 13) m_Position.y =13;
    }

     if (m_DownPressed and not m_UpPressed)
    {
        m_Position.y += speed;
        if (m_Position.y>459) m_Position.y=459;
    }
    // Cдвигаем спрайт на новую позицию
    (*m_Sprite).setPosition(m_Position+m_TopLeftCorner);   
 
}