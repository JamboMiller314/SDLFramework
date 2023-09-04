#include "Enemy.h"

Enemy::Enemy(const char* texturePath, int x, int y, int w, int h)
{


	for (int i = 0; i < numTextures; ++i)
	{
		mEnemyTexture1 = new Texture("30.png", 0, 0, 24, 17, true);
		mEnemyTexture1->Parent(this);

		//calculate x position
		float xPosition = (Graphics::SCREEN_WIDTH * 0.25f) + (i * 50);
		mEnemyTexture1->Position(xPosition, Graphics::SCREEN_HEIGHT * 0.2f);

		mNumEnemy1.push_back(mEnemyTexture1);
	}

	for (int i = 0; i < numTextures; ++i)
	{
		mEnemyTexture2 = new Texture("20.png", 0, 0, 24, 17, true);
		mEnemyTexture2->Parent(this);

		//calculate x position
		float xPosition = (Graphics::SCREEN_WIDTH * 0.25f) + (i * 50);
		mEnemyTexture2->Position(xPosition, Graphics::SCREEN_HEIGHT * 0.25f);

		mNumEnemy2.push_back(mEnemyTexture2);
	}

	for (int i = 0; i < numTextures; ++i)
	{
		mEnemyTexture2 = new Texture("20.png", 0, 0, 24, 17, true);
		mEnemyTexture2->Parent(this);

		//calculate x position
		float xPosition = (Graphics::SCREEN_WIDTH * 0.25f) + (i * 50);
		mEnemyTexture2->Position(xPosition, Graphics::SCREEN_HEIGHT * 0.3f);

		mNumEnemy2.push_back(mEnemyTexture2);
	}

	for (int i = 0; i < numTextures; ++i)
	{
		mEnemyTexture3 = new Texture("10.png", 0, 0, 24, 17, true);
		mEnemyTexture3->Parent(this);

		//calculate x position
		float xPosition = (Graphics::SCREEN_WIDTH * 0.25f) + (i * 50);
		mEnemyTexture3->Position(xPosition, Graphics::SCREEN_HEIGHT * 0.35f);

		mNumEnemy3.push_back(mEnemyTexture3);
	}

	for (int i = 0; i < numTextures; ++i)
	{
		mEnemyTexture3 = new Texture("10.png", 0, 0, 24, 17, true);
		mEnemyTexture3->Parent(this);

		//calculate x position
		float xPosition = (Graphics::SCREEN_WIDTH * 0.25f) + (i * 50);
		mEnemyTexture3->Position(xPosition, Graphics::SCREEN_HEIGHT * 0.4f);

		mNumEnemy3.push_back(mEnemyTexture3);
	}
	mBullet = new Bullet(false, "enemybullet.png", 300.0f);
	mBullet->Parent(this);
	mShootTimer = Timer::Instance();
	mShootDelay = 0.0f;
}

void Enemy::shoot()
{
	if (!mBullet->Active()) {
		mBullet->Fire(Position());
		mBullet->Active(true);
	}
}

Enemy::~Enemy()
{
	delete mEnemyTexture1;
	mEnemyTexture1 = nullptr;
	delete mEnemyTexture2;
	mEnemyTexture2 = nullptr;
	delete mEnemyTexture3;
	mEnemyTexture3 = nullptr;
}

void Enemy::Update()
{
	for (auto& mEnemyTexture1 : mNumEnemy1) {
		mEnemyTexture1->Update();
	}
	for (auto& mEnemyTexture2 : mNumEnemy2) {
		mEnemyTexture2->Update();
	}
	for (auto& mEnemyTexture2 : mNumEnemy2) {
		mEnemyTexture2->Update();
	}
	for (auto& mEnemyTexture3 : mNumEnemy3) {
		mEnemyTexture3->Update();
	}
	for (auto& mEnemyTexture3 : mNumEnemy3) {
		mEnemyTexture3->Update();
	}
	
	float dt = mShootTimer->DeltaTime();
	mShootDelay += dt;

	if (mShootDelay >= 1.0f) {
		shoot();
		mShootDelay = 0.0f;
	}
	mBullet->Update();
}

void Enemy::Render()
{
	for (auto& mEnemyTexture1 : mNumEnemy1) {
		mEnemyTexture1->Render();
	}
	for (auto& mEnemyTexture2 : mNumEnemy2) {
		mEnemyTexture2->Render();
	}
	for (auto& mEnemyTexture2 : mNumEnemy2) {
		mEnemyTexture2->Render();
	}
	for (auto& mEnemyTexture3 : mNumEnemy3) {
		mEnemyTexture3->Render();
	}
	for (auto& mEnemyTexture3 : mNumEnemy3) {
		mEnemyTexture3->Render();
	}
}

Bullet* Enemy::GetBullet() const {
	return mBullet;
}