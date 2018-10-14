#include "CMorseCode.h"

CMorseCode::CMorseCode(int pin):m_Pin(pin)
{
    pinMode(m_Pin, OUTPUT);
}

CMorseCode::~CMorseCode()
{
    //dtor
}

void CMorseCode::SendWord(const char* word)
{
	char* pRunner = (char*)word;
	while (*pRunner)
	{
		SendLetter(*pRunner++);
	}
	WordSpace();
}


void CMorseCode::SendLetter(char letter)
{
	switch(letter)
	{
		case 'A':
		case 'a':
		{
			Dot();
			Space();
			Dash();
			LetterSpace();
			break;
		}
		case 'B':
		case 'b':
		{
			Dash();
			Space();
			Dot();
			Space();
			Dot();
			Space();
			Dot();
			LetterSpace();
			break;
		}
		case 'C':
		case 'c':
		{
			Dash();
			Space();
			Dot();
			Space();
			Dash();
			Space();
			Dot();
			LetterSpace();
			break;
		}
		case 'D':
		case 'd':
		{
			Dash();
			Space();
			Dot();
			Space();
			Dot();
			LetterSpace();
			break;
		}
		case 'E':
		case 'e':
		{
			Dot();
			LetterSpace();
			break;
		}
		case 'F':
		case 'f':
		{
			Dot();
			Space();
			Dot();
			Space();
			Dash();
			Space();
			Dot();
			LetterSpace();
			break;
		}
		case 'G':
		case 'g':
		{
			Dash();
			Space();
			Dash();
			Space();
			Dot();
			Space();
			LetterSpace();
			break;
		}
		case 'H':
		case 'h':
		{
			Dot();
			Space();
			Dot();
			Space();
			Dot();
			Space();
			Dot();
			LetterSpace();
			break;
		}
		case 'I':
		case 'i':
		{
			Dot();
			Space();
			Dot();
			LetterSpace();
			break;
		}
		case 'J':
		case 'j':
		{
			Dot();
			Space();
			Dash();
			Space();
			Dash();
			Space();
			Dash();
			LetterSpace();
			break;
		}
		case 'K':
		case 'k':
		{
			Dash();
			Space();
			Dot();
			Space();
			Dash();
			LetterSpace();
			break;
		}
		case 'L':
		case 'l':
		{
			Dot();
			Space();
			Dash();
			Space();
			Dot();
			Space();
			Dot();
			LetterSpace();
			break;
		}
		case 'M':
		case 'm':
		{
			Dash();
			Space();
			Dash();
			LetterSpace();
			break;
		}
		case 'N':
		case 'n':
		{
			Dash();
			Space();
			Dot();
			LetterSpace();
			break;
		}
		case 'O':
		case 'o':
		{
			Dash();
			Space();
			Dash();
			Space();
			Dash();
			LetterSpace();
			break;
		}
		case 'P':
		case 'p':
		{
			Dot();
			Space();
			Dash();
			Space();
			Dash();
			Space();
			Dot();
			LetterSpace();
			break;
		}
		case 'Q':
		case 'q':
		{
			Dash();
			Space();
			Dash();
			Space();
			Dot();
			Space();
			Dash();
			LetterSpace();
			break;
		}
		case 'R':
		case 'r':
		{
			Dot();
			Space();
			Dash();
			Space();
			Dot();
			LetterSpace();
			break;
		}
		case 'S':
		case 's':
		{
			Dot();
			Space();
			Dot();
			Space();
			Dot();
			LetterSpace();
			break;
		}
		case 'T':
		case 't':
		{
			Dash();
			LetterSpace();
			break;
		}
		case 'U':
		case 'u':
		{
			Dot();
			Space();
			Dot();
			Space();
			Dash();
			LetterSpace();
			break;
		}
		case 'V':
		case 'v':
		{
			Dot();
			Space();
			Dot();
			Space();
			Dot();
			Space();
			Dash();
			LetterSpace();
			break;
		}
		case 'W':
		case 'w':
		{
			Dot();
			Space();
			Dash();
			Space();
			Dash();
			LetterSpace();
			break;
		}
		case 'X':
		case 'x':
		{
			Dash();
			Space();
			Dot();
			Space();
			Dot();
			Space();
			Dash();
			LetterSpace();
			break;
		}
		case 'Y':
		case 'y':
		{
			Dash();
			Space();
			Dot();
			Space();
			Dash();
			Space();
			Dash();
			LetterSpace();
			break;
		}
		case 'Z':
		case 'z':
		{
			Dash();
			Space();
			Dash();
			Space();
			Dot();
			Space();
			Dot();
			LetterSpace();
			break;
		}
	}
}
		
void CMorseCode::Dot()
{
  digitalWrite(m_Pin, HIGH);
  delay(TIME_UNIT);
  digitalWrite(m_Pin, LOW);
}

void CMorseCode::Space()
{
 delay(TIME_UNIT);
}

void CMorseCode::LetterSpace()
{
 delay(3 * TIME_UNIT);
}

void CMorseCode::WordSpace()
{
 delay(7 * TIME_UNIT);
}

void CMorseCode::Dash()
{
  digitalWrite(m_Pin, HIGH);
  delay(TIME_UNIT * 3);
  digitalWrite(m_Pin, LOW);
}
