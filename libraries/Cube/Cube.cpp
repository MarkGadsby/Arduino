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

////////////////////////////////////////////////////////////////////////////////
//	Function name	: CCube::AllOff
//	Description		: Will set all pins to LOW which is an All Off state.
//
//						Switching the layers HIGH from this state will turn each
//						layer on.
//
////////////////////////////////////////////////////////////////////////////////
void CCube::AllOff()
{
	void AllLow();
}

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

svoid CCube::AlternateLayers()
{
	int nHalfSecs = 10;
	
	while (nHalfSecs--)
	{
		AllLow();
		LayersOdd();
		delay(500);
		AllLow();
		LayersEven()
		delay(500);
	}
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

void CCube::BlockCheckerOdd(int mSec)
{
	unsigned long start = millis();

	do
	{
		AllLow();
		LayersTop();
		ColumnsFR_BL();
		delay(1);
		AllLow();
		LayersBottom();
		ColumnsFL_BR();
		delay(1);
	} while(millis() < start + mSec);
}

void BlockCheckerEven(int mSec)
{
	unsigned long start = millis();

	do
	{
		AllLow();
		LayersTop();
		ColumnsFL_BR();
		delay(1);
		AllLow();
		LayersBottom();
		ColumnsFR_BL();
		delay(1);
	} while(millis() < start + mSec);
}

void MiddleBlock()
{
	int nHalfSecs = 10;
	
	while (nHalfSecs--)
	{
		AllLow();
		LayersMiddle();
		ColumnsMiddle();
		delay(500);
	}
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

void CCube::LayersTop()
{
	digitalWrite(m_Layers[2], HIGH);
	digitalWrite(m_Layers[3], HIGH);
}

void CCube::LayersBottom()
{
	digitalWrite(m_Layers[0], HIGH);
	digitalWrite(m_Layers[1], HIGH);
}

void CCube::LayersMiddle()
{
	digitalWrite(m_Layers[1], HIGH);
	digitalWrite(m_Layers[2], HIGH);
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

void CCube::ColumnsFL_BR()
{
	for (int y = 0; y < NUM_X_Y; y++)
	{
		for (int x =0; x < NUM_X_Y; x++)
		{
			digitalWrite(m_Columns[(y * NUM_X_Y) + x], HIGH);
		}
	}
}

void CCube:: ColumnsBR_FL()
{
	for (int y = 0; y < NUM_X_Y; y++)
	{
		for (int x =0; x < NUM_X_Y; x++)
		{
			digitalWrite(m_Columns[(y * NUM_X_Y) + x], HIGH);
		}
	}
}

void CCube::ColumnsMiddle()
{
	for (int y = 0; y < NUM_X_Y; y++)
	{
		for (int x =0; x < NUM_X_Y; x++)
		{
			if ((x == 0 || x == 3) &&
				(y == 0 || y == 3))
			{
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