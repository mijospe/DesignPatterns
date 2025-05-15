#pragma once
#include <iostream>
#include "GameBehaviour.h"
#include "Event.h"

class Entity : public GameBehaviour
{
public:
	// Interface overrides
	void Update() override;
	void BeginPlay() override;
	// Constructor
	Entity(std::string inName = "null");

	// Name of entity
	std::string name;
	// Event for when the entity is spawned
	Event onEntitySpawned;
};

