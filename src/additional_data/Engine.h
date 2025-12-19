#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include <list>
#include "Enemy.h"
 
using namespace sf;
 
class Engine
{
private:
 
    RenderWindow m_Window;  
 
    // Объявляем спрайт и текстуру для фона
    Sprite *m_BackgroundSprite;
    Texture m_BackgroundTexture;
 
    // Экземпляр игрока
    Player m_Player;
 
    void input();
    void update();
    void draw();
    void handleEvents();

    bool checkCollisionPE(std::list<std::unique_ptr<EnemyBullet>>* enemybullets, Vector2i PlayerPosition, Vector2i PlayerSpeedVector);

    //Куча пуль
    //std::vector<Bullet> bullets;
    std::list<std::unique_ptr<Bullet>> bullets; //Сделать list ом

    std::list<std::unique_ptr<EnemyBullet>> enemybullets;

    Enemy m_Enemy;
    bool m_IsFocused; // Фокус окна
 
public:
    // Конструктор движка
    Engine();
 
    // Функция старт вызовет все приватные функции
    void start();
 };