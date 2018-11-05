#include <CubeSnake.h>

CCubeSnake cube;

void setup()
{
}

void loop()
{
	cube.ColumnsLow();
	delay(500);
	cube.LightLayer(0);
	delay(500);
	cube.LightLayer(1);
	delay(500);
	cube.LightLayer(2);
	delay(500);
	cube.LightLayer(3);
	delay(500);
}


