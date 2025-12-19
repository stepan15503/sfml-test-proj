#include "Engine.h"

bool Engine::checkCollisionPE(std::list<std::unique_ptr<EnemyBullet>>* enemybullets, Vector2i PlayerPosition, Vector2i PlayerSpeedVector){
    bool flag=0;
    for (auto iter=(*enemybullets).begin(); iter!=(*enemybullets).end();){
        bool flag1=0;
        if (PlayerSpeedVector.x==0 and PlayerSpeedVector.y==0){ //Хитбокс игрока полагаем квадрат в 1 пиксель, хитбокс пули- квадрат в 3*3
            Vector2f bulletPos = (*iter)->getPosition();
            Vector2f bulletTopLeft = {bulletPos.x-1,bulletPos.y-1};
            Vector2f bulletBottRight = {bulletPos.x+2,bulletPos.y+2};
            Vector2i playerPosRN = PlayerPosition;
            Vector2i playerPosTopLeft = {playerPosRN.x,playerPosRN.y};
            Vector2i playerPosBottright = {playerPosRN.x+1,playerPosRN.y+1};
            if (not ((playerPosTopLeft.x>bulletBottRight.x or playerPosBottright.x < bulletTopLeft.x) or (playerPosTopLeft.y>bulletBottRight.y or playerPosBottright.y<bulletBottRight.y))){
                flag=1;
                iter=(*enemybullets).erase(iter);
                flag1=1;
            }
        }
        else if(PlayerSpeedVector.x!=0){
            Vector2f bulletPos = (*iter)->getPosition();
            Vector2f bulletTopLeft = {bulletPos.x-1,bulletPos.y-1};
            Vector2f bulletBottRight = {bulletPos.x+2,bulletPos.y+2};
            Vector2i playerPosRN = PlayerPosition;
            Vector2i playerPosTopLeft = {playerPosRN.x,playerPosRN.y};
            Vector2i playerPosBottright = {playerPosRN.x+1,playerPosRN.y+1};
            while (PlayerSpeedVector.x!=0 or PlayerSpeedVector.y!=0){
                if (not ((playerPosTopLeft.x>bulletBottRight.x or playerPosBottright.x < bulletTopLeft.x) or (playerPosTopLeft.y>bulletBottRight.y or playerPosBottright.y<bulletBottRight.y))){
                    flag = 1;
                    iter=(*enemybullets).erase(iter);
                    flag1=1;
                }
                playerPosRN.x+=(PlayerSpeedVector.x > 0) - (PlayerSpeedVector.x < 0); // 1 if >0 -1 if <0 0 if 0
                playerPosRN.y+=(PlayerSpeedVector.y > 0) - (PlayerSpeedVector.y < 0);
                playerPosBottright = {playerPosRN.x+1,playerPosRN.y+1};
                playerPosTopLeft = {playerPosRN.x,playerPosRN.y};
                PlayerSpeedVector.x-=(PlayerSpeedVector.x > 0) - (PlayerSpeedVector.x < 0);
                PlayerSpeedVector.y-=(PlayerSpeedVector.y > 0) - (PlayerSpeedVector.y < 0);
            }
            if (not((playerPosTopLeft.x>bulletBottRight.x or playerPosBottright.x < bulletTopLeft.x) and (playerPosTopLeft.y>bulletBottRight.y or playerPosBottright.y<bulletBottRight.y))){
                flag = 1;
                iter=(*enemybullets).erase(iter);
                flag1=1;
            }  
        }
        if (not flag1){
            iter++;
        }
    }
    return flag;
}