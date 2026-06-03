#pragma once
#include "Engine/GameObject.h"
class Bullet :
    public GameObject
{
public:
    Bullet(GameObject* parent);
    ~Bullet();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
private:
    int hModel_;   //モデルのハンドル
    Transform tr_; //位置や向きなどを管理するオブジェクト
    float speed_;  //弾の速さ
};

