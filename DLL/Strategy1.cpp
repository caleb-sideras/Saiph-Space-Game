#include "Strategy1.h"
void Strategy1::Deflect(float& bulletHeading)
{
	bulletHeading = bulletHeading * -1;

}
void Strategy1::Destroy()
{
	delete this;
}

IDeflectionStrategy* CreateStrategy()
{
	IDeflectionStrategy* strat = new Strategy1();
	return strat;
}