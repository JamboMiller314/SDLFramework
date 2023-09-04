#ifndef __ENEMY_H
#define __ENEMY_H
#include "AnimatedTexture.h"
#include "BezierPath.h"
#include "Formation.h"
#include "PhysEntity.h"
#include "Player.h"
#include "Timer.h"
#include "Bullet.h"

class Enemy : public PhysEntity {
private:
	Texture* mEnemyTexture1;
	Texture* mEnemyTexture2;
	Texture* mEnemyTexture3;

	std::vector<Texture*> mNumEnemy1;
	std::vector<Texture*> mNumEnemy2;
	std::vector<Texture*> mNumEnemy2Again;
	std::vector<Texture*> mNumEnemy3;
	const int numTextures = 11;
	Bullet* mBullet;
	Timer* mShootTimer;
	float mShootDelay;
public:
	Enemy(const char* texturePath, int x, int y, int w, int h);
	~Enemy();
	Bullet* GetBullet() const;
	void shoot();
	void Update() override;
	void Render() override;
};
#endif