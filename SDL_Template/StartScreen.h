#ifndef __STARTSCREEN_H
#define __STARTSCREEN_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "Scoreboard.h"
#include "AudioManager.h"

using namespace SDLFramework;

class StartScreen : public GameEntity {

private:
	Timer * mTimer;
	InputManager * mInput;
	AudioManager * mAudio;

	// Top Bar Entities
	GameEntity * mTopBar;
	Texture * mPlayerOne;
	Texture * mPlayerTwo;
	Texture * mHiScore;
	Scoreboard * mPlayerOneScore;
	Scoreboard * mPlayerTwoScore;
	Scoreboard * mTopScore;

	// Background
	Texture* mBackground;
	

	//play and space invaders text
	Texture* mPlay;
	Texture* mSpaceInvaders;

	// Score Advance Table *
	Texture * mScoreAdvanceTable;
	Texture * mMystery;
	Texture* mMysteryText;
	Texture* m30Texture;
	Texture * m30Points;
	Texture* m20Texture;
	Texture* m20Points;
	Texture* m10Texture;
	Texture* m10Points;
	int mSelectedMode;

	// Bottom Bar Entities
	GameEntity * mBottomBar;
	Texture * mNamco;
	Texture * mDates;
	Texture * mRights;
	Texture* mCredits;

	// Screen Animation Variables
	Vector2 mAnimationStartPos;
	Vector2 mAnimationEndPos;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;

public:
	StartScreen();
	~StartScreen();

	int SelectedMode();

	void ChangeSelectedMode(int change);

	void Update() override;
	void Render() override;
};
#endif