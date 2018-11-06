#include "CubeSnake.h"

CCubeSnake cubeSnake;

void setup()
{
	cubeSnake.SetUp();
}

void loop()
{
  cubeSnake.LightLayer(0);
  delay(250);
  cubeSnake.LightLayer(1);
  delay(250);
  cubeSnake.LightLayer(2);
  delay(250);
  cubeSnake.LightLayer(3);
  delay(250);  
}

