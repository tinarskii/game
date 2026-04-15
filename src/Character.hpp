#include <raylib.h>

struct Position
{
    float x;
    float y;
};

class Character
{
public:
    enum Actions { W_UP, W_DOWN, W_LEFT, W_RIGHT, R_UP, R_DOWN, R_LEFT, R_RIGHT, IDLE };
    int frameCounter = 0;
    int currentFrame = 0;
    int chWidth;
    int chHeight;
    Texture2D texture;
    Rectangle rect;

    void DrawSprite(int posX, int posY, Actions actions);
    void Move(Position *playerPos, Position *velocity, float delta);
    void LoadSprite(void);
    void UnloadSprite(void);
};