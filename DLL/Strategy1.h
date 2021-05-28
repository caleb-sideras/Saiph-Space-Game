#pragma once
#include "../Model/IDeflectionStrategy.h"

class Strategy1 :
    public IDeflectionStrategy
{
public:
    void Deflect(float& bulletHeading);
    void Destroy();
};

