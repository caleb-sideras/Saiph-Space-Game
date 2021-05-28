#include "precompiled_header"
#include "MotherShip.h"

#include "View/ViewManager.h"
#include "VelocityCommand.h"
#include "HeadingCommand.h"
#include <Windows.h>

void MotherShip::ProcessCommands(float _delta)
{
	for (int i = 0; i < commands.size(); i++)
	{
		commands[i]->SetDelay(_delta);

	}
	for (int i = 0; i < commands.size(); i++)
	{
		commands[i]->SetDelay(_delta);
		if (commands[i]->GetDelay() == 0)
		{
			commands[i]->Execute();
			commands.erase(commands.begin() + i);
		}

	}



}

void MotherShip::CleanUpCommands()
{
	Vec2f vel;
	vel.x = 0;
	vel.y = 0;
	for (auto item : shadows) {
		item->SetVelocity(vel);
		item->SetHeading(MotherShip::GetHeading());
		item->SetPosition(MotherShip::GetPosition());

	}
}

MotherShip::MotherShip(const Ship& _copy)
{
}

MotherShip::~MotherShip()
{
	CleanUpCommands();
}

void MotherShip::Heartbeat(float _delta)

{
	ProcessCommands(_delta);
	MotherShip::SetHeading(_delta);
	if (GetAfterburnerFlag()) {
		Ship::Heartbeat(_delta);
		VelocityCommand MotherShipVel;
		HeadingCommand MotherShipHead;
		MotherShipVel.SetVelocity(MotherShip::GetVelocity());
		MotherShipHead.SetHeading(MotherShip::GetHeading());

	}
	else
	{
		CleanUpCommands();
	}


}

void MotherShip::AddShadow(Ship* _shadow)
{
	shadows.push_back(_shadow);
}