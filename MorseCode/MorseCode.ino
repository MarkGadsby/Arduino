#include <CMorseCode.h>

CMorseCode morseCode(LED_BUILTIN);

void setup()
{
}

void loop()
{
  morseCode.SendWord("Hello");
  morseCode.SendWord("World");
}
