#include "Engine.h"

void Engine::draw()
{
    // Стираем предыдущий кадр
    m_Window.clear(Color::White);
 
    // Отрисовываем фон, игрока и тд
    m_Window.draw(*m_BackgroundSprite);

    m_Window.draw(m_Player.getSprite());

    for (auto iter=bullets.begin();iter!=bullets.end();iter++){
        m_Window.draw((*iter)->getSprite());
    }
    for (auto iter=enemybullets.begin();iter!=enemybullets.end();iter++){
        (*iter)->update();
        m_Window.draw((*iter)->getSprite());
    }
    // Отображаем все, что нарисовали
    m_Window.display();
}