struct Position
{
    float x;
    float y;
};

class Character
{
public:
    int chWidth = 35;
    int chHeight = 60;

    int LoadSprite(int posX, int posY);
};