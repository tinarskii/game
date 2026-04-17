#include "DialogueManager.hpp"
#include <string>
#include "raygui.h"

void DialogueManager::DrawMessageBox()
{
    float contentRectX = padding;
    float contentRectY = (float)GetScreenHeight() / 1.2;
    rect = {contentRectX, contentRectY, (float)GetScreenWidth() - (padding * 2), ((float)GetScreenHeight() - contentRectY - padding)};
    DrawRectangleRec(rect, WHITE);
    DrawRectangleLines(contentRectX, contentRectY, rect.width, rect.height, BLACK);
}

void DialogueManager::ShowMessage(const char *text) 
{
    DrawText(text, rect.x + padding, rect.y + padding, 40, BLACK);
}