#pragma once
#include <iostream>
#include <vector>
#include "Entity.h"

class ObjectPool
{
private:
	// All objects in pool
	std::vector<std::unique_ptr<Entity>> pool;
	// The max size of the pool
	int maxPoolSize;

public:
	// Constructor
	ObjectPool(int poolSize, std::string entityName);

	// Request and Return to Pool
	std::unique_ptr<Entity> RequestPoolItem();
	void ReturnPoolItem(std::unique_ptr<Entity> returnItem);
};