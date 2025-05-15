#include "EnemyFactory.h"

//EnemyFactory::EnemyFactory()
//{
//
//}


// Spawn enemy based on input string
std::unique_ptr<Entity> EnemyFactory::SpawnEnemy(const std::string enemyToSpawn)
{
	std::unique_ptr<Entity> spawnedEntity;
	if (enemyToSpawn == "Spawn Freddy") spawnedEntity = freddyPool.RequestPoolItem();
	else if (enemyToSpawn == "Spawn Bonnie") spawnedEntity = bonniePool.RequestPoolItem();
	else if (enemyToSpawn == "Spawn Chica") spawnedEntity = chicaPool.RequestPoolItem();
	else if (enemyToSpawn == "Spawn Foxy") spawnedEntity = foxyPool.RequestPoolItem();
	else if (enemyToSpawn == "Spawn Golden Freddy") spawnedEntity = goldenFreddyPool.RequestPoolItem();
	else return nullptr;

	if (!spawnedEntity) return nullptr;

	spawnedEntity->onEntitySpawned.SubscribeToEvent([this]()
		{
			this->OnEntitySpawned();
		});

	spawnedEntity->BeginPlay();

	return spawnedEntity;
}

void EnemyFactory::DestroyEntity(std::unique_ptr<Entity> entity)
{
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

void EnemyFactory::OnEntitySpawned()
{
	std::cout << ">> Spawn Succesfull:" << std::endl;
}