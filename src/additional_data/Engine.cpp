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
    m_Window.setFramerateLimit(60);
    // Загружаем фон в текстуру
    // Подготовьте изображение под ваш размер экрана в редакторе
    m_BackgroundTexture.loadFromFile("assets/background.jpg");
 
    // Связываем спрайт и текстуру
    m_BackgroundSprite = new Sprite(m_BackgroundTexture);
 
}
 
void Engine::start()
{
    while (m_Window.isOpen())
    {
        input();
        update();
        draw();
    }
}