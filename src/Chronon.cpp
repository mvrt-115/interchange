#include "Chronon.h"

Chronon::Chronon(short mantissa, short exponent)
{
        //TODO
}

short Chronon::getMantissa (Chronon &a)
{
        return a.mantissa;
}

short Chronon::getExponent (Chronon &a)
{
        return a.exponent;
}

void Chronon::changeExponent (Chronon &a, short newExponent)
{
        for (short e = a.exponent; e > 0; e--) a.mantissa *= a.mantissa;
        for (short e = newExponent; e > 0; e--) a.mantissa /= a.mantissa;
}
