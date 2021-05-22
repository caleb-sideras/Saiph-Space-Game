#include "Strategy2.h"

void Strategy2::Deflect(float& bulletHeading)
{
	bulletHeading = bulletHeading * 0;

}
void Strategy2::Destroy()
{
	delete this;
}

IDeflectionStrategy* CreateStrategy()
{
	IDeflectionStrategy* strat = new Strategy2();
	return strat;
}