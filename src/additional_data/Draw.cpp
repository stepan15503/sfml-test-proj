#include "Engine.h"

void Engine::draw()
{
    // Стираем предыдущий кадр
    m_Window.clear(Color::White);
 
    // Отрисовываем фон, игрока и тд
    m_Window.draw(*m_BackgroundSprite);

    m_Window.draw(m_Player.getSprite());


    for (int i=0;i<bullets.size();i++){
        m_Window.draw(bullets[i]->getSprite());
    }
     for (int i=0;i<enemybullets.size();i++){
        m_Window.draw(enemybullets[i]->getSprite());
    }   
    // Отображаем все, что нарисовали
    m_Window.display();
}