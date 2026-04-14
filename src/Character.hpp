class Character
{
public:
    struct Position
    {
        float x;
        float y;
    };

    int chWidth = 35;
    int chHeight = 60;

    int LoadSprite(int posX, int posY);
};