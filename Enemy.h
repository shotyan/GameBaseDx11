#pragma once
#include "Engine/GameObject.h"
class Enemy :
    public GameObject
{
public:
    Enemy(GameObject* parent);
    ~Enemy();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    void OnCollision(GameObject* pTarget);

    void SetPosition(XMFLOAT3 position);
private:
    int hModel_;
    Transform tr_;
    XMFLOAT3 startPosition_;
};

