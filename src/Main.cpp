#define RAYGUI_IMPLEMENTATION
#include "SceneManager.hpp"
#include "Character.hpp"
#include "DialogueManager.hpp"
#include <raylib.h>
#include <cstdio>

int main(void)
{
    // -- Window Config --
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1280, 720, "Raylib");
    SetTargetFPS(144);

    // -- Character --
    Character player;
    Position playerPos = {x : (float)GetScreenWidth() / 2.0f, y : (float)GetScreenHeight() / 2.0f};
    Position velocity = {x : 0.0f, y : 0.0f};
    Character::Actions actions = Character::Actions::IDLE;

    // -- Load Texture --
    player.LoadSprite();

    // -- Scene Management --
    SceneManager sceneManager;
    Scene currentScene = Scene::Title;

    // -- Dialogue Management --
    DialogueManager dialogue;

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
            actions = Character::Actions::W_UP;
        }
        else if (IsKeyDown(KEY_S))
        {
            velocity.x = 0.0f;
            velocity.y = 2.0f;
            actions = Character::Actions::W_DOWN;
        }
        else if (IsKeyDown(KEY_A))
        {
            velocity.x = -2.0f;
            velocity.y = 0.0f;
            actions = Character::Actions::W_LEFT;
        }
        else if (IsKeyDown(KEY_D))
        {
            velocity.x = 2.0f;
            velocity.y = 0.0f;
            actions = Character::Actions::W_RIGHT;
        }
        else
        {
            actions = Character::Actions::IDLE;
            velocity = {x : 0.0f, y : 0.0f};
        }

        // -- Movement Logic & Boundary Check --
        player.Move(&playerPos, &velocity, delta);

        // -- Draw --
        BeginDrawing();
        ClearBackground(WHITE);
        sceneManager.PlayScene(&currentScene);
        if (currentScene != Scene::Title)
        {
            player.DrawSprite(playerPos.x, playerPos.y, actions);
            dialogue.DrawMessageBox();
            const char* text = "Hello! This is a message dialogue abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
            dialogue.ShowMessage(text);
        }
        EndDrawing();
    }

    player.UnloadSprite();
    CloseWindow();

    return 0;
}