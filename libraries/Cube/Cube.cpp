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
	
void CCube::AllOff()
{
	int i = NUMCOLS;

	// all columns (negatives) low
	while (i--)
		digitalWrite(m_Columns[i], LOW);
  
	i = NUMLAYS;
  
	// all columns (positives) low also.
	while (i--)
		digitalWrite(m_Layers[i], LOW);
}

void CCube::AllOn()
{
	int i = NUMCOLS;

	// all columns (negatives) low
	while (i--)
		digitalWrite(m_Columns[i], LOW);
  
	i = NUMLAYS;
  
	// all columns (positives) high
	while (i--)
		digitalWrite(m_Layers[i], HIGH);
}		

void CCube::LightLayer(int nLayer)
{
  AllOff();

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


