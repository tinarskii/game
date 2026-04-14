enum class Scene
{
    Title,
    Game
};

class SceneManager
{

private:
    int PlayTitleScene();
    int PlayGameScene();

public:
    int PlayScene(Scene sceneName);
};