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

void CCube::LayersOdd()
{
	digitalWrite(m_Layers[1], HIGH);
	digitalWrite(m_Layers[3], HIGH);
}

void CCube::LayersEven()
{
	digitalWrite(m_Layers[0], HIGH);
	digitalWrite(m_Layers[2], HIGH);
}

void CCube::CheckerEven(int mSec)
{
	unsigned long start = millis();

	do
	{
		AllLow();
		LayersEven();
		EveryOtherColumn(false);
		delay(1);
		AllLow();
		LayersOdd();
		EveryOtherColumn(true);
		delay(1);
	} while(millis() < start + mSec);
}

void CCube::CheckerOdd(int mSec)
{
	unsigned long start = millis();

	do
	{
		AllLow();
    LayersOdd();
    EveryOtherColumn(false);
    delay(1);
    AllLow();
    LayersEven();
    EveryOtherColumn(true);
    delay(1);
	} while(millis() < start + mSec);
}

void CCube::EveryOtherColumn(bool bEven)
{
	for (int y = 0; y < NUM_X_Y; y++)
	{
			for (int x =0; x < NUM_X_Y; x++)
			{
				 if (bEven)
				 {
					 if (!(y % 2) && !(x % 2))
	 					digitalWrite(m_Columns[(y * NUM_X_Y) + x], HIGH);

	 				if ((y % 2) && (x % 2))
	 					digitalWrite(m_Columns[(y * NUM_X_Y) + x], HIGH);
				 }
				 else
				 {
					 if (!(y % 2) && (x % 2))
						 digitalWrite(m_Columns[(y * NUM_X_Y) + x], HIGH);

					 if ((y % 2) && !(x % 2))
						 digitalWrite(m_Columns[(y * NUM_X_Y) + x], HIGH);
				 	}
			}
	 }
}

void CCube::LayerStack(int nStackTopLayer)
{
  AllLow();

  if (nStackTopLayer / 4 == 0)
  {
    while (nStackTopLayer--)
      digitalWrite(m_Layers[nStackTopLayer], HIGH);
  }
  else
  {
    int shiftVal = nStackTopLayer % 4;
    int index = 8 - nStackTopLayer;

    while (index--)
      digitalWrite(m_Layers[index + shiftVal], HIGH);
  }
}

void CCube::LayerSweep()
{
  int layer = 1;

  while(layer <= 7)
  {
    LayerStack(layer++);
    delay(500);
  }

  layer--;

  while(layer >= 1)
  {
    LayerStack(layer--);
    delay(150);
  }
}

void CCube::EachColumnsLine()
{
	AllHigh();			// all off
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
