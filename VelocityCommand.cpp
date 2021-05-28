#include "precompiled_header"
#include "VelocityCommand.h"

Vec2f VelocityCommand::GetVelocity()
{
	return velocity;
}

void VelocityCommand::SetVelocity(Vec2f _velocity)
{
	velocity = _velocity;
}

void VelocityCommand::Execute()
{
	SetVelocity(velocity);
}