#include <raylib.h>
#include <raymath.h>
#include "Character.hpp"

void Character::LoadSprite()
{
    texture = LoadTexture("./assets/character.png");
    rect = {0.0f, 0.0f, (float)texture.width / 8, (float)texture.height / 6};
    chWidth = texture.width / 8;
    chHeight = texture.height / 6;
}

void Character::UnloadSprite()
{
    UnloadTexture(texture);
}

void Character::DrawSprite(int posX, int posY, Actions actions)
{
    if (actions != Actions::IDLE)
    {
        rect.y = chHeight;
        frameCounter++;
        if (frameCounter >= (144 / 8))
        {
            frameCounter = 0;
            currentFrame++;

            if (currentFrame >= 6)
                currentFrame = 0;

            rect.x = (float)currentFrame * (float)chWidth;
        }
    } else {
        currentFrame = 0;
        rect.x = (float)currentFrame * (float)chWidth;
        rect.y = 0;
    }

    if (actions == Actions::W_LEFT || actions == Actions::R_LEFT) {
        rect.width = -(float)chWidth;
    } else if (actions == Actions::W_RIGHT || actions == Actions::R_RIGHT) {
        rect.width = (float)abs(chWidth);
    }

    Rectangle dest = {
        (float)posX, (float)posY,
        (float)chWidth * scale,
        (float)chHeight * scale,
    };

    DrawTexturePro(texture, rect, dest, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
}

void Character::Move(Position *playerPos, Position *velocity, float delta)
{
    if (playerPos->x > 0 && velocity->x < 0.0f) // Move Left
    {
        playerPos->x += velocity->x * delta;
    }
    if (playerPos->x + (chWidth * scale) < GetScreenWidth() && velocity->x > 0.0f) // Move Right
    {
        playerPos->x += velocity->x * delta;
    }
    if (playerPos->y > 0 && velocity->y < 0.0f) // Move Up
    {
        playerPos->y += velocity->y * delta;
    }
    if (playerPos->y + (chHeight * scale) < GetScreenHeight() && velocity->y > 0.0f) // Move Down
    {
        playerPos->y += velocity->y * delta;
    }
}
