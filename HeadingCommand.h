#pragma once
#include "BaseCommand.h"
class HeadingCommand :
    public BaseCommand
{
	float heading;

public:
	float GetHeading();
	void SetHeading(float _heading);
	void Execute() override;
};

