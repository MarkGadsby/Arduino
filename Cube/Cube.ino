#include <Cube.h>

CCube cube;

void setup()
{  
}

void loop()
{
    cube.LayerSweep();
    cube.CheckerEven(500);
    cube.CheckerOdd(500);
}
