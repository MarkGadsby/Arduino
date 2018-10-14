#ifndef CUBE_H
#define CUBE_H

#include "Arduino.h"

const int NUMCOLS = 16;
const int NUMLAYS = 4;

class CCube
{
	public:
		CCube();
		virtual ~CCube();
		
		void AllOn();
		void AllOff();
		void LightLayer(int nLayer);
		void LayerSweep();
		
	private:
		// Column array
		int m_Columns[NUMCOLS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1};

		// Initialise the layer array 
		int m_Layers[NUMLAYS] = {A2, A3, A4, A5};
};

#endif // CUBE_H
