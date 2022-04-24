#ifndef CUBE_H
#define CUBE_H

#include "Arduino.h"

const int NUMCOLS = 16;
const int NUMLAYS = 4;
const int NUM_X_Y = 4;

class CCube
{
public:		// interface
	CCube();
	virtual ~CCube();

	void AllOn();
	void AllOff();

	void LayerSweep();
	void AlternateLayers();

	void MiddleBlock();

	void CheckerOdd(int mSec);
	void CheckerEven(int mSec);

	void BlockCheckerOdd(int mSec);
	void BlockCheckerEven(int mSec);

private:	// data

	// Column array
	int m_Columns[NUMCOLS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1};

	// Layer array
	int m_Layers[NUMLAYS] = {A2, A3, A4, A5};

private:	// Helpers
	void AllLow();

	void LayersEven();
	void LayersOdd();
	void LayersTop();
	void LayersBottom();
	void LayersMiddle();

	void EveryOtherColumn(bool bEven);
	void ColumnsFL_BR();
	void ColumnsFR_BL();
	void ColumnsMiddle();

	void LayerStack(int nStackTopLayer);
};

#endif // CUBE_H
