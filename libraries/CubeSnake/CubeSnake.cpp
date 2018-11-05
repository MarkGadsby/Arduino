#include "CubeSnake.h"
#include <Wire.h>

CCubeSnake::CCubeSnake()
{
	// Set all columns and all layers to ouput
	int i = NUMCOLS;

	while (i--)
		pinMode(m_Columns[i], OUTPUT);
	
	Wire.begin();   // Creates a Wire object

	// Set I/O pins to outputs
	Wire.beginTransmission(0x20);   // Begins talking to the slave device
	Wire.write(0x00);               // Selects the IODIRA register
	Wire.write(0x00);               // This sets all port A pins to outputs
	Wire.endTransmission();         
}

CCubeSnake::~CCubeSnake()
{
}

void CCubeSnake::ColumnsLow()
{
	int i = NUMCOLS;

	// all columns (negatives) low.
	while (i--)
		digitalWrite(m_Columns[i], LOW);
}

void CCubeSnake::LightLayer(int nLayer)
{
	int layerPattern;
	
	switch(nLayer)
	{
		case 0:
		{
			layerPattern = 0x10;
			break;
		}
		case 1:
		{
			layerPattern = 0x20;
			break;
		}
		case 2:
		{
			layerPattern = 0x40;
			break;
		}
		case 3:
		{
			layerPattern = 0x80;
			break;
		}
	}
	
	Wire.beginTransmission(0x20);   // Starts talking to slave device
	Wire.write(0x12);               // Selects the GPIOA pins
	Wire.write(layerPattern);       // Sets nlayer HIGH
	Wire.endTransmission();         
}