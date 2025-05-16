#include "EntityFactory.h"

//EnemyFactory::EnemyFactory()
//{
//
//}


// Spawn enemy based on input string
std::unique_ptr<Entity> EntityFactory::SpawnEnemy(const std::string enemyToSpawn)
{
	// Spawn Entity
	std::unique_ptr<Entity> spawnedEntity;
	if (enemyToSpawn == "Spawn Freddy") spawnedEntity = freddyPool.RequestPoolItem();
	else if (enemyToSpawn == "Spawn Bonnie") spawnedEntity = bonniePool.RequestPoolItem();
	else if (enemyToSpawn == "Spawn Chica") spawnedEntity = chicaPool.RequestPoolItem();
	else if (enemyToSpawn == "Spawn Foxy") spawnedEntity = foxyPool.RequestPoolItem();
	else if (enemyToSpawn == "Spawn Golden Freddy") spawnedEntity = goldenFreddyPool.RequestPoolItem();
	else return nullptr;

	// Has entity been spawned in?
	if (!spawnedEntity) return nullptr;

	// Event to as Event Listener (Observer)
	spawnedEntity->onEntitySpawned.SubscribeToEvent([this]()
		{
			this->OnEntitySpawned();
		});

	// Execute the Beginplay Interface and return the entity
	spawnedEntity->BeginPlay();
	return spawnedEntity;
}

// Destroy the Entity
void EntityFactory::DestroyEntity(std::unique_ptr<Entity> entity)
{
	// Check which Pool to return the Entity to
	if (entity->name == "Freddy") freddyPool.ReturnPoolItem(std::move(entity));
	else if (entity->name == "Bonnie") bonniePool.ReturnPoolItem(std::move(entity));
	else if (entity->name == "Chica") chicaPool.ReturnPoolItem(std::move(entity));
	else if (entity->name == "Foxy") foxyPool.ReturnPoolItem(std::move(entity));
	else if (entity->name == "Golden Freddy") goldenFreddyPool.ReturnPoolItem(std::move(entity));
	else
	{
		std::cout << ">> Error: No Entity found to destroy";
		return;
	}
	std::cout << ">> Destruction succesfull";
}

void EntityFactory::OnEntitySpawned()
{
	std::cout << ">> Spawn Succesfull:" << std::endl;
}