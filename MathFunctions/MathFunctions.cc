#include <stdio.h>
#include <math.h>
#include "MathFunctions.h"

double mysqrt (double input)
{
    fprintf(stdout, "*** Using custom sqrt...\n");
    return sqrt(input);
}