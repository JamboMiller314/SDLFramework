#include "Bullet.h"
#include "PhysicsManager.h"

Bullet::Bullet(bool Friendly, const std::string& texturePath, float speed)
{
	mTimer = Timer::Instance();

	mTexture = new Texture("bullet.png");
	mTexture->Parent(this);
	mTexture->Position(Vec2_Zero);

	mSpeed = 500;
	AddCollider(new BoxCollider(10)); 
	PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Friendly);


	Reload();
}


Bullet::~Bullet() {
	mTimer = nullptr;

	delete mTexture;
	mTexture = nullptr;
}

void Bullet::Fire(Vector2 pos) {
	Position(pos);
	Active(true);
}

void Bullet::Reload() {
	Active(false);
}

void Bullet::Update() {
	if (Active()) {
		Translate(-Vec2_Up * mSpeed * mTimer->DeltaTime());

		Vector2 pos = Position();
		if (pos.y < -OFFSCREEN_BUFFER) {
			Reload();
		}
	}
}

void Bullet::Render() {
	if (Active()) {
		mTexture->Render();

	}
}

bool Bullet::IgnoreCollisions() {
	return !Active();
}

void Bullet::Hit(PhysEntity* other) {
	Reload();
	if (other->GetTag() == "Enemy") {
		this->Destroy();
		other->Destroy();
	}
}