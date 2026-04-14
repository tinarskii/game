enum class Scene
{
    Title,
    Game
};

class SceneManager
{

private:
    int PlayTitleScene(Scene *sceneName);
    int PlayGameScene();

public:
    int PlayScene(Scene *sceneName);
};