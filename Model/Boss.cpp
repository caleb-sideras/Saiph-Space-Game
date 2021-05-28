#include "precompiled_header"
#include "Boss.h"
#include "Ship.h"
//#include "Behavior.cpp"

#define SPAZ_TIME	1.0f
#define SHOT_FREQ	0.05f

Boss::Boss() : Enemy()
{
	SetJoust(false);
	SetWeaponLevel(0);
	SetScore(1000);
	SetShipID(10);
	SetWeaponID(4);
	SetShieldID(10);
	SetGeneratorID(9);
	SetPropulsionID(6);
	SetFireFrequency(1);
	SetShip(SaiphApp::CloneShipFromPrototype(GetShipID()));
	GetShip()->SetShield(SaiphApp::GetShieldFlyweight(GetShieldID()).strength);
	GetShip()->SetBattery(SaiphApp::GetGeneratorFlyweight(GetGeneratorID()).battery);
	GetShip()->SetPosition(64, BOUNDS_SIZE);
	GetShip()->SetActive(false);
	spazTime = SPAZ_TIME;
}

Boss::~Boss()
{
}

// interface
void Boss::AddWaypoint(const Vec2f &_waypoint)
{
	waypoints.push_back(_waypoint);
}
void Boss::Heartbeat(float _delta)
{
	SetRetargetReady(true);
	
	// update firing
	if(RandomFloat(0,1).GenerateValue() < GetFireFrequency())
		SetFireReady(true);
	GetShip()->SetLastFired(GetShip()->GetLastFired() + _delta);

	// update shield
	if(SaiphApp::GetShieldFlyweight(GetShieldID()).strength)
	{
		if(GetShip()->GetBattery() > SaiphApp::GetShieldFlyweight(GetShieldID()).energy * _delta)
		{
			GetShip()->SetBattery(GetShip()->GetBattery() - SaiphApp::GetShieldFlyweight(GetShieldID()).energy * _delta);
			GetShip()->SetShield(GetShip()->GetShield() + SaiphApp::GetShieldFlyweight(GetShieldID()).recharge * _delta);
			if(GetShip()->GetShield() > SaiphApp::GetShieldFlyweight(GetShieldID()).strength)
				GetShip()->SetShield(SaiphApp::GetShieldFlyweight(GetShieldID()).strength);
		}
	}

	// update battery
	GetShip()->SetBattery(GetShip()->GetBattery() + SaiphApp::GetGeneratorFlyweight(GetGeneratorID()).energy * _delta);
	if(GetShip()->GetBattery() > SaiphApp::GetGeneratorFlyweight(GetGeneratorID()).battery)
		GetShip()->SetBattery(SaiphApp::GetGeneratorFlyweight(GetGeneratorID()).battery);

	// TODO: insert your behavior algorithm code here

		if (currentWaypoint >= waypoints.size())
			currentWaypoint = 0;
		if (GetFireFrequency() < 0)
		{
			Vec2f forward = GetTarget() - GetShip()->GetPosition();
			forward.Normalize();
			//l = SaiphApp::GetHeadingFromUnitVector(forward);
			GetShip()->SetHeading(SaiphApp::GetHeadingFromUnitVector(forward));

			Vec2f backward = waypoints[currentWaypoint] - GetShip()->GetPosition();
			float distance = GetShip()->GetWidth() / 2;
			if (backward * backward < distance * distance)
			{
				SetFireFrequency(1.0f);
				currentWaypoint++;
			}
			backward.Normalize();
			//k = SaiphApp::GetPropulsionFlyweight(GetPropulsionID());
			//backward *= k.force;
			backward *= SaiphApp::GetPropulsionFlyweight(GetPropulsionID()).force;
			GetShip()->SetVelocity(backward);
		}
		else
		{
			float temp = GetFireFrequency();
			SetFireFrequency(temp -= _delta);
			GetShip()->SetHeading(RandomFloat(0, 2 * PI).GenerateValue());
		}

		GetShip()->Heartbeat(_delta);

		//d = _delta
		//h = GetShip()
		//i = forward
		//j = backward
		//g = GetTarget()
		//n = GetPropulsionID()
		//f = distance
		//l is removed
		//k is removed


}