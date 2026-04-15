enum class Scene
{
    Title,
    Game
};

class SceneManager
{

private:
    void PlayTitleScene(Scene *sceneName);
    void PlayGameScene();

public:
    void PlayScene(Scene *sceneName);
};