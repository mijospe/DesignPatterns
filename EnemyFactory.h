#pragma once
#include "Entity.h"
#include "ObjectPool.h"
#include "Event.h"
#include <iostream>
#include <vector>

class EnemyFactory
{
private:
	ObjectPool freddyPool{ 1, "Freddy"};
	ObjectPool bonniePool{ 1, "Bonnie" };
	ObjectPool chicaPool{ 1, "Chica" };
	ObjectPool foxyPool{ 1, "Foxy" };
	ObjectPool goldenFreddyPool{ 1, "Golden Freddy" };

	std::vector<std::unique_ptr<Entity>> entities;
public:
	std::unique_ptr<Entity> SpawnEnemy(std::string enemyName);
	void DestroyEntity(std::unique_ptr<Entity> entity);
	void OnEntitySpawned();
};

