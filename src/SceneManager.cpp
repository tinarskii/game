#include <raylib.h>
#include "SceneManager.hpp"

int SceneManager::PlayTitleScene()
{
    const char *text = "Title Screen";
    const int fontSize = 48;
    int textWidth = MeasureText(text, fontSize);
    DrawText("Title Screen", (GetScreenWidth() / 2) - textWidth / 2, (GetScreenHeight() / 6) - fontSize / 6, fontSize, LIGHTGRAY);
    return 0;
}

int SceneManager::PlayGameScene()
{
    DrawText("Game Screen", 100, 100, 28, LIGHTGRAY);
    return 0;
}

int SceneManager::PlayScene(Scene sceneName)
{
    switch (sceneName)
    {
    case Scene::Title:
        PlayTitleScene();
        break;
    case Scene::Game:
        PlayGameScene();
        break;
    default:
        break;
    }
    return 0;
};