#include "Engine\\Model.h"
#include "Player.h"
#include "Engine\\Input.h"
#include "Bullet.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("B2.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0.0f,0.0f,-5.0f };
	transform_.scale_ = { 0.25f,0.25f,0.25f };
}

void Player::Update()
{

	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
		transform_.position_.x = transform_.position_.x - 0.1;
	}
	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D))
	{
		transform_.position_.x = transform_.position_.x + 0.1f;
	}
	if (Input::IsKeyDown(DIK_SPACE))
	{
		Bullet *pBullet = Instantiate<Bullet>(this->GetParent());
		pBullet->SetPosition(transform_.position_);
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
