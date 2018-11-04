#include "CubeSnake.h"

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

void CCubeSnake::ColumnsLow()
{
	int i = NUMCOLS;

	// all columns (negatives) low.
	while (i--)
		digitalWrite(m_Columns[i], LOW);
}
