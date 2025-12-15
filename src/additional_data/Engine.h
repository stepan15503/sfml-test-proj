#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include <vector>
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

    //Куча пуль
    //std::vector<Bullet> bullets;
    std::vector<std::unique_ptr<Bullet>> bullets;

    std::vector<std::unique_ptr<EnemyBullet>> enemybullets;

    Enemy m_Enemy;
    bool m_IsFocused; // Фокус окна
 
public:
    // Конструктор движка
    Engine();
 
    // Функция старт вызовет все приватные функции
    void start();
 };