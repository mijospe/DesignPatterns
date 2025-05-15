#pragma once
#include <iostream>
#include "GameBehaviour.h"
#include "Event.h"

class Entity : public GameBehaviour
{
public:
	void Update() override;
	void BeginPlay() override;

	Entity(std::string inName = "null");

	std::string name;
	Event onEntitySpawned;
};

