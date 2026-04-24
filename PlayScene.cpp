#include "PlayScene.h"
#include "Engine\\Model.h"


PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),hModel_(-1)
{
}

void PlayScene::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
}

void PlayScene::Update()
{
	if (ot_.position_.x < 10)
	{
	    ot_.position_.x += 0.2f;
    }
	else if(ot_.position_.x > 10)
	{
		ot_.position_.x -= 0.2f;
	}
	ot_.position_.y = -2.5f;
	ot_.position_.z = 5.5f;
	ot_.scale_ = { 1.0f, 1.0f, 1.0f };
	ot_.rotate_.y += 0.5f; //回転させる
}

void PlayScene::Draw()
{
	Model::SetTransform(hModel_, ot_);
	Model::Draw(hModel_);
}

void PlayScene::Release()
{
}
