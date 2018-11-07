#include "CubeSnake.h"

CCubeSnake cubeSnake;

void setup()
{
	cubeSnake.SetUp();
}

void loop()
{
  int i = 0;

  while (i <= 63)
  {  
    cubeSnake.ColumnsHigh();
    cubeSnake.LightByIndex(i++);
    delay(250);
  }
  delay(1000);
}

