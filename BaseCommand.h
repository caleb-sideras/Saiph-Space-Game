#pragma once

class Ship;

class BaseCommand
{
	Ship* target;
	float delay;

public:
	float GetDelay();
	void SetDelay(float _delay);
	Ship* GetTarget();
	void SetTarget(Ship* _target);
	virtual void Execute();


};
