#include <raylib.h>
#include "Character.hpp"

int Character::LoadSprite(int posX, int posY)
{
    DrawRectangle(posX, posY, chWidth, chHeight, RED);
    return 0;
}