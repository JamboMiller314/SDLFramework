#ifndef __PHYSENTITY_H
#define __PHYSENTITY_H
#include <vector>
#include <string>
#include "Collider.h"

class PhysEntity : public GameEntity {
protected:
	unsigned long mId;

	std::string mTag;

	std::vector<Collider*> mColliders;

	Collider* mBroadPhaseCollider;

	void AddCollider(Collider* collider, Vector2 localPos = Vec2_Zero);

	virtual bool IgnoreCollisions();
	bool isActive;

public:
	PhysEntity() : isActive(true)
	{
		mBroadPhaseCollider = nullptr;
		mTag = "";
		mId = 0;
	}
	virtual ~PhysEntity();

	unsigned long GetId();

	void Destroy() {
		isActive = false;
	}

	bool IsActive() const {
		return isActive;
	}
	bool CheckCollision(PhysEntity* other);

	void SetTag(std::string tag);
	std::string GetTag();

	virtual void Hit(PhysEntity* other) { }

	virtual void Render() override;
};
#endif