#include "Engine.h"
 
void Engine::input()
{
    // Обрабатываем нажатие Escape
    if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
    {
        m_Window.close();
    }
 
    // Обрабатываем нажатие клавиш движения
    if (Keyboard::isKeyPressed(Keyboard::Key::Left))
    {
        m_Player.moveLeft();
    }
    else
    {
        m_Player.stopLeft();
    }
 
    if (Keyboard::isKeyPressed(Keyboard::Key::Right))
    {
        m_Player.moveRight();
    }
    else
    {
        m_Player.stopRight();
    }                       

    if (Keyboard::isKeyPressed(Keyboard::Key::Up))
    {
        m_Player.moveUp();
    }
    else
    {
        m_Player.stopUp();
    }     

    if (Keyboard::isKeyPressed(Keyboard::Key::Down))
    {
        m_Player.moveDown();
    }
    else
    {
        m_Player.stopDown();
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::LShift))
    {
        m_Player.getShifted();
    }
    else
    {
        m_Player.getUnshifted();
    }    
}