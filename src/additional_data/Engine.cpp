#include "Engine.h"


Engine::Engine()
{
    // Создаём окно 640x480
    Vector2u resolution;
    resolution.x = 640;
    resolution.y = 480;
 
    m_Window.create(VideoMode({resolution.x, resolution.y}),
        "Simple Game Engine",
        State::Windowed);
    m_Window.setFramerateLimit(60); //лимит FPS

    m_IsFocused = true; 


    // Загружаем фон в текстуру
    if (!m_BackgroundTexture.loadFromFile("assets/background.jpg"))
    {
        printf("Фон не найден");//  прикрутить экран нарисованный векторно с ошибкой
    }
 
    // Связываем спрайт и текстуру
    m_BackgroundSprite = new Sprite(m_BackgroundTexture);
 
}

void Engine::handleEvents()
{
    while (const std::optional<Event> event = m_Window.pollEvent())
    {
        if (event->is<Event::Closed>())
        {
            m_Window.close();
        }
        // Проверяем события фокуса
        else if (event->is<Event::FocusLost>())
        {
            m_IsFocused = false;
            // Сбрасываем все состояния управления при потере фокуса
            // Это надо для момента когда ты вышел из программы в другую прогу
            m_Player.stopLeft();
            m_Player.stopRight();
            m_Player.stopUp();
            m_Player.stopDown();
            m_Player.getUnshifted();
        }
        else if (event->is<Event::FocusGained>())
        {
            m_IsFocused = true;
        }
    }
}
 
void Engine::start()
{
    while (m_Window.isOpen())
    {
        handleEvents(); // Обработка событий
        if (m_IsFocused) // Обновляем только если окно в фокусе
        {
        input();
        update();
        }
        draw();
    }
}