#include <raylib.h>
#include "SceneManager.hpp"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int SceneManager::PlayTitleScene(Scene *scene)
{
    const char *text = "Title Screen";
    const int fontSize = 128;
    int textWidth = MeasureText(text, fontSize);
    DrawText("Title Screen", (GetScreenWidth() / 2) - textWidth / 2, (GetScreenHeight() / 6) - fontSize / 6, fontSize, LIGHTGRAY);

    float rectW = 300.0f,
        rectH = 50.0f,
        rectX = ((float)GetScreenWidth()/2) - rectW/2,
        rectY = ((float)GetScreenHeight()/2) - rectH/2;
    Rectangle playBtnRec = {rectX, rectY, rectW, rectH};
    if (GuiButton(playBtnRec, "Play Game!"))
    {
        *scene = Scene::Game;
    }
    return 0;
}

int SceneManager::PlayGameScene()
{
    DrawText("Game Screen", 100, 100, 28, LIGHTGRAY);
    return 0;
}

int SceneManager::PlayScene(Scene *sceneName)
{
    switch (*sceneName)
    {
    case Scene::Title:
        PlayTitleScene(sceneName);
        break;
    case Scene::Game:
        PlayGameScene();
        break;
    default:
        break;
    }
    return 0;
};