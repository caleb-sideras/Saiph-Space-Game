#include "precompiled_header"
#include "HeadingCommand.h"

float HeadingCommand::GetHeading()
{
	return heading;
}

void HeadingCommand::SetHeading(float _heading)
{
	heading = _heading;
}

void HeadingCommand::Execute()
{
	SetHeading(heading);
}