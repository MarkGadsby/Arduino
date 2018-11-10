#include "CubeSnake.h"

CCubeSnake cubeSnake;

void setup()
{
	cubeSnake.SetUp();
  Serial.begin(9600);  
}

void loop()
{
  int incoming = 63;

  if (Serial.available())
  {
    incoming = Serial.read();
    cubeSnake.ColumnsHigh();
    cubeSnake.LightByIndex(incoming);
  }
}

