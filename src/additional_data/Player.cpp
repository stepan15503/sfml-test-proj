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
 
Vector2i Player::getPosition()
{
    return m_Position;
}
Vector2i Player::getTopLeftPosition()
{
    return m_Position+m_TopLeftCorner;
}
//Движение на основании ввода

Vector2i Player::getSpeedVector() //Получаем вектор куда сместится спрайт.
{
    int speed=m_Speed;
    Vector2i speedvec={0,0};

    if (m_ShiftPressed){
        speed = m_Focused_Speed;
    }

    if (m_RightPressed and not m_LeftPressed)
    {
        if (m_Position.x+speed>459) speedvec.x=459-m_Position.x;
        else speedvec.x=speed;
    }
 
    if (m_LeftPressed and not m_RightPressed)
    {
        if (m_Position.x-speed<13) speedvec.x=13-m_Position.x;
        else speedvec.x=-speed;
    }

    if (m_UpPressed and not m_DownPressed)
    {
        if (m_Position.y-speed<13) speedvec.y=13-m_Position.y;
        else speedvec.y=-speed;
    }

     if (m_DownPressed and not m_UpPressed)
    {
        if (m_Position.y+speed>459) speedvec.y=459-m_Position.y;
        else speedvec.y=speed;
    }
    return speedvec;
}

void Player::update(bool isShot,std::list<std::unique_ptr<EnemyBullet>>* enemybullets)
{
    if (!enemybullets){
        printf("а где массив с вражескими пулями?");
        return;
    }
    if (m_InvFrameCount!=0){
        m_InvFrameCount--;
    }
    else if (isShot==1 and m_InvFrameCount==0){
        m_InvFrameCount=30;
        (*enemybullets).clear();
        m_Position={100,300};
    }
    if (m_InvFrameCount<24)    m_Position=m_Position+getSpeedVector();
    // Cдвигаем спрайт на новую позицию
    (*m_Sprite).setPosition({m_Position.x+m_TopLeftCorner.x , m_Position.y+m_TopLeftCorner.y});   
 
}