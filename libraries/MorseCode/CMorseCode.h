#ifndef CMORSECODE_H
#define CMORSECODE_H

#include "Arduino.h"

const int TIME_UNIT = 200;

class CMorseCode
{
    public:
        CMorseCode(int pin);
        virtual ~CMorseCode();
       
        void SendLetter(char letter);
		void WordSpace();
		void SendWord(const char* word);

    private:
        void Dot();
        void Dash();
		void Space();
		void LetterSpace();
     
        int m_Pin;
};

#endif // CMORSECODE_H
