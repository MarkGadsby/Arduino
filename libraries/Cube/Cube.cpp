#include "Cube.h"

CCube::CCube()
{
	// Set all columns and all layers to ouput
	int i = NUMCOLS;

	while (i--)
		pinMode(m_Columns[i], OUTPUT);

	i = NUMLAYS;

	while (i--)
		pinMode(m_Layers[i], OUTPUT);
}

CCube::~CCube()
{
}
	
////////////////////////////////////////////////////////////////////////////////
//	Function name	: CCube::AllLow
//	Description		: Will set all pins to LOW which is an All Off state.
//
//						Switching the layers HIGH from this state will turn each
//						layer on.
//
////////////////////////////////////////////////////////////////////////////////
void CCube::AllLow()
{
	int i = NUMLAYS;

	// all layers (positives) low.
	while (i--)
		digitalWrite(m_Layers[i], LOW);

	i = NUMCOLS;

	// all columns (negatives) low also.
	while (i--)
		digitalWrite(m_Columns[i], LOW);
}

////////////////////////////////////////////////////////////////////////////////
//	Function name	: CCube::AllHigh
//	Description		: Will set all pins to HIGH which is an All Off state.
//
//						Switching the columns LOW from this state will turn 
//						individual columns on.
//
////////////////////////////////////////////////////////////////////////////////
void CCube::AllHigh()
{
	int i = NUMLAYS;

	// all layers (positives) high.
	while (i--)
		digitalWrite(m_Layers[i], HIGH);

	i = NUMCOLS;

	// all columns (negatives) high also
	while (i--)
		digitalWrite(m_Columns[i], HIGH);
}


void CCube::AllOn()
{
	int i = NUMLAYS;

	// all layers (positives) high
	while (i--)
		digitalWrite(m_Layers[i], HIGH);

	i = NUMCOLS;

	// all columns (negatives) low
	while (i--)
		digitalWrite(m_Columns[i], LOW);
}		

void CCube::LightLayer(int nLayer)
{
  AllLow();

  if (nLayer / 4 == 0)
  {
    while (nLayer--)
      digitalWrite(m_Layers[nLayer], HIGH);
  }
  else
  {
    int shiftVal = nLayer % 4;
    int index = 8 - nLayer;

    while (index--)
      digitalWrite(m_Layers[index + shiftVal], HIGH);
  }
}

void CCube::LayerSweep()
{
  int layer = 1;

  while(layer <= 7)
  {
    LightLayer(layer++);
    delay(150);
  }  

  layer--;

  while(layer >= 1)
  {
    LightLayer(layer--);
    delay(150); 
  }
}

void CCube::SnakeForwardBackward()
{
	AllHigh();			// all off
	SnakeForward();		// all on
	SnakeBackward();	// all off
}

void CCube::EachColumnsLine()
{
	int y = 0;

	while (y <= 3) // y == 0,1,2 & 3 
	{
		int x = 0;
		while (x <= 3) // x == 0,1,2 & 3 
		{
			// Set individual column low
			digitalWrite(m_Columns[x + (y * NUM_X_Y)], LOW);
			delay(150);
			x++;
		}
		y++;
	}
}

void CCube::SnakeForward()
{
	int x = 0;
	int y = 0;

	while (y <= 3) // y == 0,1,2 & 3 
	{
		// So the x axis does the 'snaking'
		if (x == 0)
		{
			while (x <= 3) // x == 0,1,2 & 3 
			{
				// Set individual column low
				digitalWrite(m_Columns[x + (y * NUM_X_Y)], LOW);
				delay(150);
				x++;
			}
		}
		else if (x == 3)
		{
			while (x >= 0) // x == 3,2,1 & 0 
			{
				// Set individual column low
				digitalWrite(m_Columns[x + (y * NUM_X_Y)], LOW);
				delay(150);
				x--;
			}
		}
		y++;
	}
}

void CCube::SnakeBackward()
{
	int x = 3;
	int y = 3;

	while (y >= 0) // y == 3,2,1 & 0 
	{
		if (x == 3)
		{
			while (x >= 0) // x == 3,2,1 & 0 
			{
				// Set individual column high
				digitalWrite(m_Columns[x + (y * NUM_X_Y)], HIGH);
				delay(150);
				x--;
			}
		}
		else if (x == 0)
		{
			while (x <= 3) // x == 0,1,2 & 3 
			{
				// Set individual column low
				digitalWrite(m_Columns[x + (y * NUM_X_Y)], HIGH);
				delay(150);
				x++;
			}
		}
		y--;
	}
}