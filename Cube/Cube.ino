#include <Cube.h>

CCube cube;

void setup()
{  
}

void loop()
{
  cube.LayerSweep();
  cube.LayerSweep();
 
  cube.MiddleBlock();
 
    int i = 5;

    while(i--)
    {
      cube.CheckerEven(250);
      cube.CheckerOdd(250);
    }

    cube.MiddleBlock();
 
    i = 20;

    while(i--)
    {
      cube.BlockCheckerOdd(500);
      cube.BlockCheckerEven(500);
    }

    cube.MiddleBlock();
    
    cube.AlternateLayers();

    cube.MiddleBlock();
 
}
