#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h";
 
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
 
public:
    // Конструктор движка
    Engine();
 
    // Функция старт вызовет все приватные функции
    void start();
 };