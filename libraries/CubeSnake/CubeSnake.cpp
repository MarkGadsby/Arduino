#include "CubeSnake.h"
#include <Wire.h>

CCubeSnake::CCubeSnake()
{
	// Set all columns and all layers to ouput
	int i = NUMCOLS;

	while (i--)
		pinMode(m_Columns[i], OUTPUT);
}

CCubeSnake::~CCubeSnake()
{
}

////////////////////////////////////////////////////////////////////////////////
//	Function name	: CCubeSnake::SetUp
//	Description		: Function that can be called from the Arduino setup function.
//						This is better than calling in the constructor which may
//						be called out-of-synch with the Wire object. This is better
//						Arduino style.
//
//	Return type		: void
////////////////////////////////////////////////////////////////////////////////
void CCubeSnake::SetUp()
{
	Wire.begin();   				// Initiate the Wire library and join the I2C bus as a master 
	Wire.beginTransmission(0x20);   // On the slave device 0x20 is the base address
	Wire.write(0x00);               // Selects the IODIRA register
	Wire.write(0x00);               // This sets all port A pins to outputs
	Wire.endTransmission();         
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
	int layerPattern = 0xF0;
	
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