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

void DialogueManager::ShowMessage(const char *text, int fontSize, Color color)
{
    int curTextWidth = 0;
    int startPos = 0;
    int line = 0;
    std::string str(text);
    int strSize = str.size();
    for (int i = 0; i < strSize; i++)
    {
        curTextWidth = MeasureText(str.substr(startPos, i - startPos).c_str(), fontSize);
        std::string substr = str.substr(startPos, i - startPos - 1);
        if (curTextWidth > rect.width - (2 * padding))
        {
            DrawText(substr.c_str(), rect.x + padding, rect.y + (padding + (line * fontSize)), fontSize, color);
            line += 1;
            startPos = i;
            curTextWidth = 0;
        }
        if (i == strSize - 1)
        {
            DrawText((str.substr(startPos - 1)).c_str(), rect.x + padding, rect.y + (padding + (line * fontSize)), fontSize, color);
        }
    }
}