#include "StartScreen.h"

StartScreen::StartScreen() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
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

	mPlayerOneScore->Position(-Graphics::SCREEN_WIDTH * 0.2f, 40.0f);
	mPlayerTwoScore->Position(Graphics::SCREEN_WIDTH * 0.15f, 40.0f);
	mTopScore->Position(-30.0f, 40.0f);

	mTopScore->Score(0);

	//play and space invaders
	mPlay = new Texture("PLAY", "space_invaders.ttf", 22, { 255, 255, 255 });
	mPlay->Parent(this);
	mPlay->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.25f);
	mSpaceInvaders = new Texture("SPACE INVADERS", "space_invaders.ttf", 22, { 255, 255, 255 });
	mSpaceInvaders->Parent(this);
	mSpaceInvaders->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.3f);
	
	// Score Advance stuff
	mScoreAdvanceTable = new Texture("* SCORE ADVANCE TABLE *", "space_invaders.ttf", 22, { 255, 255, 255 });
	mScoreAdvanceTable->Parent(this);
	mScoreAdvanceTable->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.4f);

	mMystery = new Texture("ufo.png", 0, 0, 48, 21, true);
	mMystery->Parent(this);
	mMystery->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.5f);
	mMysteryText = new Texture("=? MYSTERY", "space_invaders.ttf", 22, { 255, 255, 255 });
	mMysteryText->Parent(this);
	mMysteryText->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	m30Texture = new Texture("30.png", 0, 0, 24, 17, true);
	m30Texture->Parent(this);
	m30Texture->Position(Graphics::SCREEN_WIDTH * 0.41f, Graphics::SCREEN_HEIGHT * 0.6f);
	m30Points = new Texture("= 30 POINTS", "space_invaders.ttf", 22, { 255, 255, 255 });
	m30Points->Parent(this);
	m30Points->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.6f);

	m20Texture = new Texture("20.png", 0, 0, 24, 17, true);
	m20Texture->Parent(this);
	m20Texture->Position(Graphics::SCREEN_WIDTH * 0.41f, Graphics::SCREEN_HEIGHT * 0.7f);
	m20Points = new Texture("= 20 POINTS", "space_invaders.ttf", 22, { 255, 255, 255 });
	m20Points->Parent(this);
	m20Points->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);

	m10Texture = new Texture("10.png", 0, 0, 24, 17, true);
	m10Texture->Parent(this);
	m10Texture->Position(Graphics::SCREEN_WIDTH * 0.41f, Graphics::SCREEN_HEIGHT * 0.8f);
	m10Points = new Texture("= 10 POINTS", "space_invaders.ttf", 22, { 255, 255, 255 });
	m10Points->Parent(this);
	m10Points->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.8f);
	

	// bottom credits
	mCredits = new Texture("CREDIT 00", "space_invaders.ttf", 22, { 255, 255, 255 });
	mCredits->Parent(this);
	mCredits->Position(Graphics::SCREEN_WIDTH * 0.7f, Graphics::SCREEN_HEIGHT * 0.9f);
	
	
	

}


StartScreen::~StartScreen() {
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

	// play and space invaders
	delete mPlay;
	mPlay = nullptr;
	delete mSpaceInvaders;
	mSpaceInvaders = nullptr;
	
	//score advance stuff
	delete mScoreAdvanceTable;
	mScoreAdvanceTable = nullptr;
	delete mMystery;
	mMystery = nullptr;
	delete mMysteryText;
	mMysteryText = nullptr;
	delete m30Texture;
	m30Texture = nullptr;
	delete m30Points;
	m30Points = nullptr;
	delete m20Points;
	m20Points = nullptr;
	delete m20Texture;
	m20Texture = nullptr;
	delete m10Texture;
	m10Texture = nullptr;

	// bottom credits
	delete mCredits;
	mCredits = nullptr;
	
	mTimer = nullptr;
	mInput = nullptr;
}

int StartScreen::SelectedMode() {
	return mSelectedMode;
}

void StartScreen::ChangeSelectedMode(int change) {
	mSelectedMode += change;

	if (mSelectedMode < 0) {
		mSelectedMode = 1;
	}
	else if (mSelectedMode > 1) {
		mSelectedMode = 0;
	}

	
}

void StartScreen::Update() {
	mBackground->Update();
	mPlay->Update();
	mSpaceInvaders->Update();
	mScoreAdvanceTable->Update();
	mMystery->Update();
	mMysteryText->Update();
	m30Texture->Update();
	m30Points->Update();
	m20Texture->Update();
	m20Points->Update();
	m10Texture->Update();
	m10Points->Update();
	mCredits->Update();

	
}

void StartScreen::Render() {
	//mBackground->Render();
	mPlayerOne->Render();
	mPlayerTwo->Render();
	mHiScore->Render();
	mPlayerOneScore->Render();
	mPlayerTwoScore->Render();
	mTopScore->Render();
	mPlay->Render();
	mSpaceInvaders->Render();
	mScoreAdvanceTable->Render();
	mMystery->Render();
	mMysteryText->Render();
	m30Texture->Render();
	m30Points->Render();
	m20Texture->Render();
	m20Points->Render();
	m10Texture->Render();
	m10Points->Render();
	mCredits->Render();

	


}