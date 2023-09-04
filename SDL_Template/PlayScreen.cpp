#include "PlayScreen.h"
#include "Bullet.h"
#include "PhysEntity.h"
#include "BoxCollider.h"


PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();

	//background
	mBackground = new Texture("invaders.png", 0, 0, 1024, 896, true);
	mBackground->Parent(this);
	mBackground->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	// top bar entities
	mTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 80.0f);
	mPlayerOne = new Texture("SCORE<1>", "space_invaders.ttf", 22, { 255, 255, 255 });
	mPlayerTwo = new Texture("SCORE<2>", "space_invaders.ttf", 22, { 255, 255, 255 });
	mHiScore = new Texture("HI-SCORE", "space_invaders.ttf", 22, { 255, 255, 255 });
	mPlayerOneScore = new Scoreboard();
	mPlayerTwoScore = new Scoreboard();
	mTopScore = new Scoreboard();

	mTopBar->Parent(this);
	mPlayerOne->Parent(mTopBar);
	mPlayerTwo->Parent(mTopBar);
	mHiScore->Parent(mTopBar);
	mPlayerOneScore->Parent(mTopBar);
	mPlayerTwoScore->Parent(mTopBar);
	mTopScore->Parent(mTopBar);

	mPlayerOne->Position(-Graphics::SCREEN_WIDTH * 0.2f, 0.0f);
	mPlayerTwo->Position(Graphics::SCREEN_WIDTH * 0.15f, 0.0f);
	mHiScore->Position(-30.0f, 0.0f);

	mPlayerOneScore->Position(-Graphics::SCREEN_WIDTH * 0.2f, 30.0f);
	mPlayerTwoScore->Position(Graphics::SCREEN_WIDTH * 0.15f, 30.0f);
	mTopScore->Position(-30.0f, 30.0f);

	mTopScore->Score(0);

	delete mPlayer;
	mPlayer = new Player();
	mPlayer->Parent(this);
	mPlayer->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.85f);
	mPlayer->Active(true);

	// bottom credits
	mCredits = new Texture("CREDIT 00", "space_invaders.ttf", 22, { 255, 255, 255 });
	mCredits->Parent(this);
	mCredits->Position(Graphics::SCREEN_WIDTH * 0.7f, Graphics::SCREEN_HEIGHT * 0.95f);


	mLivesText = new Texture("3", "space_invaders.ttf", 22, { 255, 255, 255 });
	mLivesText->Parent(this);
	mLivesText->Position(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.95f);

	mLivesShip = new Texture("ship.png", 0, 0, 42, 26);
	mLivesShip->Parent(this);
	mLivesShip->Position(Graphics::SCREEN_WIDTH * 0.3f, Graphics::SCREEN_HEIGHT * 0.95f);

	
		mEnemyTexture1 = new Enemy("30.png", 0, 0, 24, 17);
		mEnemyTexture1->Parent(this);

	
	
		mEnemyTexture2 = new Enemy("20.png", 0, 0, 24, 17);
		mEnemyTexture2->Parent(this);


	
		mEnemyTexture2 = new Enemy("20.png", 0, 0, 24, 17);
		mEnemyTexture2->Parent(this);


	
		mEnemyTexture3 = new Enemy("10.png", 0, 0, 24, 17);
		mEnemyTexture3->Parent(this);

	

	
		mEnemyTexture3 = new Enemy("10.png", 0, 0, 24, 17);
		mEnemyTexture3->Parent(this);

	


	for (int i = 0; i < numBunkers; ++i) {
		mBunker1 = new Texture("one.png", 0, 0, 44, 32, true);
		mBunker1->Parent(this);
		float xPosition = (Graphics::SCREEN_WIDTH * 0.25f) + (i * 170);
		mBunker1->Position(xPosition, Graphics::SCREEN_HEIGHT * 0.7f);

		mBunkers.push_back(mBunker1);
	}

	
}



PlayScreen::~PlayScreen() {
	mTimer = nullptr;
	mAudio = nullptr;
	//background
	delete mBackground;
	mBackground = nullptr;

	// top bar entities
	delete mTopBar;
	mTopBar = nullptr;
	delete mPlayerOne;
	mPlayerOne = nullptr;
	delete mPlayerTwo;
	mPlayerTwo = nullptr;
	delete mHiScore;
	mHiScore = nullptr;
	delete mPlayerOneScore;
	mPlayerOneScore = nullptr;
	delete mPlayerTwoScore;
	mPlayerTwoScore = nullptr;
	delete mTopScore;
	mTopScore = nullptr;
	// bottom credits
	delete mCredits;
	mCredits = nullptr;
	delete mLivesText;
	mLivesText = nullptr;
	delete mLivesShip;
	mLivesShip = nullptr;
	
	
	delete mPlayer;
	mPlayer = nullptr;
}

void PlayScreen::Update() {
	mBackground->Update();
	mPlayerOne->Update();
	mPlayerTwo->Update();
	mHiScore->Update();
	mPlayerOneScore->Update();
	mPlayerTwoScore->Update();
	mTopScore->Update();
	mPlayer->Update();
	mCredits->Update();
	mLivesText->Update();
	mLivesShip->Update();
	mPlayer->GetBullet()->Update();
	mEnemyTexture1->Update();
	mEnemyTexture2->Update();
	mEnemyTexture2->Update();
	mEnemyTexture3->Update();
	mEnemyTexture3->Update();
	for (auto& mBunker1 : mBunkers) {
		mBunker1->Update();
	}
	// Loop for enemies of type 1
	for (auto& enemy : mNumEnemy1) {
		enemy->Update();
		if (rand() % 100 < 5) {  // 5% chance to shoot
			enemy->shoot();
		}
	}

	// Loop for enemies of type 2
	for (auto& enemy : mNumEnemy2) {
		enemy->Update();
		if (rand() % 100 < 90) {
			enemy->shoot();
		}
	}

	// Loop for enemies of type 2 again (assuming they are different)
	for (auto& enemy : mNumEnemy2Again) {
		enemy->Update();
		if (rand() % 100 < 90) {
			enemy->shoot();
		}
	}

	// Loop for enemies of type 3
	for (auto& enemy : mNumEnemy3) {
		enemy->Update();
		if (rand() % 100 < 90) {
			enemy->shoot();
		}
	}

	
	
}

void PlayScreen::Render() {
	//mBackground->Render();
	mPlayerOne->Render();
	mPlayerTwo->Render();
	mHiScore->Render();
	mPlayerOneScore->Render();
	mPlayerTwoScore->Render();
	mTopScore->Render();
	mPlayer->Render();
	mCredits->Render();
	mLivesText->Render();
	mLivesShip->Render();
	mPlayer->GetBullet()->Render();
	mEnemyTexture1->Render();
	mEnemyTexture2->Render();
	mEnemyTexture2->Render();
	mEnemyTexture3->Render();
	mEnemyTexture3->Render();
	for (auto& mBunker1 : mBunkers) {
		mBunker1->Render();
	}
	// Loop to render enemies of type 1
	for (auto& enemy : mNumEnemy1) {
		enemy->Render();
		enemy->GetBullet()->Render();
	}

	// Loop to render enemies of type 2
	for (auto& enemy : mNumEnemy2) {
		enemy->Render();
		enemy->GetBullet()->Render();
	}

	// Loop to render enemies of type 2 again
	for (auto& enemy : mNumEnemy2Again) {
		enemy->Render();
		enemy->GetBullet()->Render();
	}

	// Loop to render enemies of type 3
	for (auto& enemy : mNumEnemy3) {
		enemy->Render();
		enemy->GetBullet()->Render();
	}
}
