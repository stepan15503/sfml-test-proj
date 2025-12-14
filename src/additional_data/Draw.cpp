#include "Engine.h"
 
void Engine::draw()
{
    // Стираем предыдущий кадр
    m_Window.clear(Color::White);
 
    // Отрисовываем фон
    m_Window.draw(*m_BackgroundSprite);
    // И Боба
    m_Window.draw(m_Player.getSprite());

    for (int i=0;i<bullets.size();i++){
        m_Window.draw(bullets[i].getSprite());
    }
 
    // Отображаем все, что нарисовали
    m_Window.display();
}