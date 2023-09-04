#ifndef __PLAYSCREEN_H
#define __PLAYSCREEN_H
#include "Timer.h"
#include "AudioManager.h"
#include "Player.h"
#include "Scoreboard.h"
#include "AnimatedTexture.h"
#include "Bullet.h"
#include "Bunker.h"
#include "Enemy.h"
class PlayScreen : public GameEntity {
private:
	Timer * mTimer;
	AudioManager * mAudio;
	//player stuff
	Player * mPlayer;

	
	// Top Bar Entities
	GameEntity* mTopBar;
	Texture* mPlayerOne;
	Texture* mPlayerTwo;
	Texture* mHiScore;
	Scoreboard* mPlayerOneScore;
	Scoreboard* mPlayerTwoScore;
	Scoreboard* mTopScore;

	//background
	Texture* mBackground;

	//walls
	Texture* mWall;

	//lives ui
	Texture* mLivesText;
	Texture* mLivesShip;

	Texture* mCredits;
	//Bullet
	Bullet* mBullet;

	//Enemies
	Enemy* mEnemyTexture1;
	Enemy* mEnemyTexture2;
	Enemy* mEnemyTexture3;

	std::vector<Enemy*> mNumEnemy1;
	std::vector<Enemy*> mNumEnemy2;
	std::vector<Enemy*> mNumEnemy2Again;
	std::vector<Enemy*> mNumEnemy3;
	const int numTextures = 11;


	//bunkers
	std::vector<Texture*> mBunkers;
	int numBunkers = 4; // Change this to the number of bunkers you want
	Texture* mBunker1;

	std::vector<Enemy*> mEnemies;
public:
	PlayScreen();
	~PlayScreen();

	void GenerateEnemies();
	void Update() override;
	void Render() override;
};
#endif