        
#include "Engine.h"
 
using namespace sf;
 
void Engine::update()
{
    m_Enemy.update(m_Player.getPosition(),&enemybullets);
    m_Player.update();
    for (int i=0;i<bullets.size();i++){
        bullets[i]->update();
    }
     for (int i=0;i<enemybullets.size();i++){
        enemybullets[i]->update();
    }
}
