#include <raylib.h>
#include "Character.hpp"

int Character::LoadSprite(int posX, int posY)
{
    DrawRectangle(posX, posY, 35, 60, RED);
    return 0;
}