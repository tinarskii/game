#include <raylib.h>

class DialogueManager
{
public:
    Rectangle rect;
    int padding = 12;
    bool isDialogueShowing = false;
    void DrawMessageBox();
    void ShowMessage(const char *text);
};