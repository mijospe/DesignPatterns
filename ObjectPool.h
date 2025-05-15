#pragma once
#include <iostream>
#include <vector>
#include "Entity.h"

class ObjectPool
{
private:
	std::vector<std::unique_ptr<Entity>> pool;
	int maxPoolSize;

public:
	ObjectPool(int poolSize, std::string entityName);

	std::unique_ptr<Entity> RequestPoolItem();
	void ReturnPoolItem(std::unique_ptr<Entity> returnItem);
};