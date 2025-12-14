        
#include "Engine.h"
 
using namespace sf;
 
void Engine::update()
{
    m_Player.update();
    for (int i=0;i<bullets.size();i++){
        bullets[i]->update();
    }
 
}
