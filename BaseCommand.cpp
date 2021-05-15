#include "precompiled_header"
#include "BaseCommand.h"

float BaseCommand::GetDelay()
{
	return delay;
}

void BaseCommand::SetDelay(float _delay)
{
	delay = _delay;
}

Ship* BaseCommand::GetTarget()
{
	return target;
}

void BaseCommand::SetTarget(Ship* _target)
{
	target = _target;
}

void BaseCommand::Execute()
{
}
