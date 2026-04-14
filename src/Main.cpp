#include "SceneManager.hpp"
#include "Character.hpp"
#include <raylib.h>
#include <cstdio>

int main(void)
{
    // -- Window Config --
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1280, 720, "Raylib");
    SetTargetFPS(144);

    // -- Scene Management --
    SceneManager sceneManager;
    Scene currentScene = Scene::Title;

    // -- Character --
    Character player;
    Position playerPos = {x : (float)GetScreenWidth() / 2.0f, y : (float)GetScreenHeight() / 2.0f};
    Position velocity = {x : 0.0f, y : 0.0f};

    // -- Main Loop --
    while (!WindowShouldClose())
    {
        float delta = GetFrameTime() * 144.0f;

        // -- Change Scene --
        int key = GetKeyPressed();
        if (key == KEY_ONE)
        {
            currentScene = Scene::Title;
        }
        else if (key == KEY_TWO)
        {
            currentScene = Scene::Game;
        }

        // -- Toggle Fullscreen --
        if (IsKeyPressed(KEY_F11))
        {
            ToggleFullscreen();
        }

        // -- Input Control --
        if (IsKeyDown(KEY_W))
        {
            velocity.x = 0.0f;
            velocity.y = -2.0f;
        }
        else if (IsKeyDown(KEY_S))
        {
            velocity.x = 0.0f;
            velocity.y = 2.0f;
        }
        else if (IsKeyDown(KEY_A))
        {
            velocity.x = -2.0f;
            velocity.y = 0.0f;
        }
        else if (IsKeyDown(KEY_D))
        {
            velocity.x = 2.0f;
            velocity.y = 0.0f;
        }
        else if (IsKeyUp(KEY_W) || IsKeyUp(KEY_A) || IsKeyUp(KEY_S) || IsKeyUp(KEY_D))
        {
            velocity = {x : 0.0f, y : 0.0f};
        }

#ifndef NDEBUG
        printf("velocity: %.1f %.1f\n", velocity.x, velocity.y);
        printf("playerPos: %.1f %.1f\n", playerPos.x, playerPos.y);
#endif

        // -- Movement Logic & Boundary Check --
        if (playerPos.x > 0 && velocity.x < 0.0f) // Move Left
        {
            playerPos.x += velocity.x * delta;
        }
        if (playerPos.x + player.chWidth < GetScreenWidth() && velocity.x > 0.0f) // Move Right
        {
            playerPos.x += velocity.x * delta;
        }
        if (playerPos.y > 0 && velocity.y < 0.0f) // Move Up
        {
            playerPos.y += velocity.y * delta;
        }
        if (playerPos.y + player.chHeight < GetScreenHeight() && velocity.y > 0.0f) // Move Down
        {
            playerPos.y += velocity.y * delta;
        }

        // -- Draw --
        BeginDrawing();
        ClearBackground(WHITE);
        sceneManager.PlayScene(currentScene);
        if (currentScene != Scene::Title)
        {
            player.LoadSprite(playerPos.x, playerPos.y);
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
}