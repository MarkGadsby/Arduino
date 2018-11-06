#include "CubeSnake.h"

CCubeSnake cubeSnake;

void setup()
{
	cubeSnake.SetUp();
}

void loop()
{
	cubeSnake.ColumnsLow();
	delay(500);
	cubeSnake.LightLayer(0);
	delay(500);
	cubeSnake.LightLayer(1);
	delay(500);
	cubeSnake.LightLayer(2);
	delay(500);
	cubeSnake.LightLayer(3);
	delay(500);
}


