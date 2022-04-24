#include "Cube.h"

CCube cube;

void setup()
{  
}

void loop()
{
  cube.AllOn();

  delay(10000);

  int i = 5;

  while(i--)
  {
    cube.LayerSweep();
  }
 
  cube.MiddleBlock();
  delay(1000);
 
  i = 5;

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
  delay(1000);

  
  cube.AlternateLayers();

  cube.MiddleBlock();
  delay(1000);
}
