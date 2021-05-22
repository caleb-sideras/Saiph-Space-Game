#pragma once
#include "../Model/IDeflectionStrategy.h"
class Strategy2 :
    public IDeflectionStrategy
{
    void Deflect(float& bulletHeading);
    void Destroy();
};

