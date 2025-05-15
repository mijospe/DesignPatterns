#include "ObjectPool.h"

ObjectPool::ObjectPool(int poolSize, std::string entityName) : maxPoolSize(poolSize)
{
	for (int i = 0; i < maxPoolSize; i++)
	{
		pool.push_back(std::make_unique<Entity>(entityName));
	}
}

std::unique_ptr<Entity> ObjectPool::RequestPoolItem()
{
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
	if (pool.size() < maxPoolSize)
	{
		pool.push_back(std::move(returnItem));
	}
	else
	{
		std::cout << ">> Error: Pool is full, can't add any more items to pool";
	}
}