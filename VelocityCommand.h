#pragma once
#include "BaseCommand.h"
#include "SaiphApp.h"
class VelocityCommand :
    public BaseCommand
{
	Vec2f velocity;
public:
	Vec2f GetVelocity();
	void SetVelocity(Vec2f _velocity);
	void Execute() override;

};

