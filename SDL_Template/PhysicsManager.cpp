#include "PhysicsManager.h"

PhysicsManager * PhysicsManager::sInstance = nullptr;

PhysicsManager * PhysicsManager::Instance() {
	if (sInstance == nullptr) {
		sInstance = new PhysicsManager();
	}

	return sInstance;
}

void PhysicsManager::Release() {
	delete sInstance;
	sInstance = nullptr;
}

void PhysicsManager::SetLayerCollisionMask(CollisionLayers layer, CollisionFlags flags) {
	mLayerMasks[static_cast<unsigned int>(layer)] = std::bitset<static_cast<unsigned int>(CollisionLayers::MaxLayers)>(static_cast<unsigned int>(flags));
}

unsigned long PhysicsManager::RegisterEntity(PhysEntity * entity, CollisionLayers layer) {
	mCollisionLayers[static_cast<unsigned int>(layer)].push_back(entity);
	mLastId++;
	return mLastId;
}

void PhysicsManager::UnregisterEntity(unsigned long id) {
	bool found = false;

	for (int i = 0; i < static_cast<unsigned int>(CollisionLayers::MaxLayers) && !found; i++) {
		for (int j = 0; j < mCollisionLayers[i].size() && !found; j++) {
			if (mCollisionLayers[i][j]->GetId() == id) {
				mCollisionLayers[i].erase(mCollisionLayers[i].begin() + j);
				found = true;
			}
		}
	}
}
void PhysicsManager::Update() {
    for (unsigned int i = 0; i < static_cast<unsigned int>(CollisionLayers::MaxLayers); i++) {
        for (unsigned int j = 0; j < static_cast<unsigned int>(CollisionLayers::MaxLayers); j++) {
            if (mLayerMasks[i].test(j) && i <= j) {
                auto& layer1 = mCollisionLayers[i];
                auto& layer2 = mCollisionLayers[j];
                auto it1 = layer1.begin();
                while (it1 != layer1.end()) {
                    auto it2 = layer2.begin();
                    while (it2 != layer2.end()) {
                        if ((*it1)->IsActive() && (*it2)->IsActive() &&
                            (*it1)->CheckCollision(*it2)) {
                            (*it1)->Hit(*it2);
                            (*it2)->Hit(*it1);
                        }

                        // Remove destroyed entities from layer2
                        if (!(*it2)->IsActive()) {
                            delete* it2;
                            it2 = layer2.erase(it2);
                        }
                        else {
                            ++it2;
                        }
                    }

                    // Remove destroyed entities from layer1
                    if (!(*it1)->IsActive()) {
                        delete* it1;
                        it1 = layer1.erase(it1);
                    }
                    else {
                        ++it1;
                    }
                }
            }
        }
    }
}



PhysicsManager::PhysicsManager() {
	mLastId = 0;

	for (unsigned int i = 0; i < static_cast<unsigned int>(CollisionLayers::MaxLayers); i++) {
		mLayerMasks[i] = std::bitset<static_cast<unsigned int>(CollisionLayers::MaxLayers)>(static_cast<unsigned int>(CollisionFlags::None));
	}
}

PhysicsManager::~PhysicsManager() {
	for (auto l : mCollisionLayers) {
		l.clear();
	}
}
