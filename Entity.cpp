#include "Entity.h"

Entity::Entity(std::string inName) : name(inName)
{
	
}

void Entity::Update()
{

}

void Entity::BeginPlay()
{
	onEntitySpawned.Invoke();
}