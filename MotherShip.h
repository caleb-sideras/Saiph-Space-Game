#pragma once
#include"Model/Ship.h"
#include "BaseCommand.h"
#include <vector>
class MotherShip :
    public Ship
{
	std::vector<BaseCommand*> commands;
	std::vector<Ship*> shadows;
	void ProcessCommands(float _delta);
public:
	void CleanUpCommands();
	MotherShip(const Ship& _copy);
	~MotherShip();
	void Heartbeat(float _delta);
	void AddShadow(Ship* _shadow);
};

