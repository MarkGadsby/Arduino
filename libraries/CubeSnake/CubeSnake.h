#ifndef CUBESNAKE_H
#define CUBESNAKE_H

#include "Arduino.h"

const int NUMCOLS = 16;
const int NUMLAYS = 4;
const int NUM_X_Y = 4;

class CCubeSnake
{
	public:
		CCubeSnake();
		virtual ~CCubeSnake();
		
		void ColumnsLow();
		void LightLayer(int nLayer);

	private:

		// Column array
		int m_Columns[NUMCOLS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3};
};

#endif // CUBE_H
