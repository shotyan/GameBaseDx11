#include "PlayScene.h"
#include "Engine\\Model.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"
#include "Engine/Camera.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),hModel_(-1)
{
}

void PlayScene::Initialize()
{

	Enemy* enemy1 = Instantiate<Enemy>(this);
	enemy1->SetPosition({ -5.0f, 0.0f, 20.0f });

	Enemy* enemy2 = Instantiate<Enemy>(this);
	enemy2->SetPosition({ 5.0f, 0.0f, 20.0f });
	Instantiate<Player>(this); //Playerのインスタンス＝プレイヤーのオブジェクトを作る
	/*Instantiate<Bullet>(this);*/

	//Instantiate<Player>(this); //Playerのインスタンス＝プレイヤーオブジェクトを作る
	Camera::SetPosition(XMFLOAT3(0.0f, 5.0f, -13.0f));
	Camera::SetTarget(XMFLOAT3(0.0f, 0.0f, 10.0f));
}

void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr) {
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	};
}

void PlayScene::Draw()
{

}

void PlayScene::Release()
{
}
