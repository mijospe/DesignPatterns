#include "ObjectPool.h"

ObjectPool::ObjectPool(int poolSize, std::string entityName) : maxPoolSize(poolSize)
{
	// Construct all the Entities at the start of the game
	for (int i = 0; i < maxPoolSize; i++)
	{
		pool.push_back(std::make_unique<Entity>(entityName));
	}
}

std::unique_ptr<Entity> ObjectPool::RequestPoolItem()
{
	// If there are objects left in the pool, give the requested object
	if (pool.size() > 0)
	{
		std::unique_ptr<Entity> poolItem = std::move(pool.back());
		pool.pop_back();
		return poolItem;
	}
	return nullptr;
}

void ObjectPool::ReturnPoolItem(std::unique_ptr<Entity> returnItem)
{
	// If there is still space left in the pool, return objects to pool
	if (pool.size() < maxPoolSize)
	{
		pool.push_back(std::move(returnItem));
	}
	else
	{
		std::cout << ">> Error: Pool is full, can't add any more items to pool";
	}
}