        
#include "Engine.h"
 
using namespace sf;
 
void Engine::update()
{
    m_Enemy.update(m_Player.getPosition(),&enemybullets);
    m_Player.update(checkCollisionPE(&enemybullets, m_Player.getPosition(), m_Player.getSpeedVector()),&enemybullets);
    for (auto iter=bullets.begin();iter!=bullets.end();iter++){
        (*iter)->update();
    }
    for (auto iter=enemybullets.begin();iter!=enemybullets.end();iter++){
        (*iter)->update();
    }
}