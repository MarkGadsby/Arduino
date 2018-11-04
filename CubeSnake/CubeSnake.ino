#include <Wire.h>
#include <CubeSnake.h>

CCubeSnake cube;

void setup()
{
  Wire.begin();   // Creates a Wire object

  // Set I/O pins to outputs
  Wire.beginTransmission(0x20);   // Begins talking to the slave device
  Wire.write(0x00);               // Selects the IODIRA register
  Wire.write(0x00);               // This sets all port A pins to outputs
  Wire.endTransmission();         // Stops talking to device
}

void loop()
{
  cube.ColumnsLow();
  
  Wire.beginTransmission(0x20);   // Starts talking to slave device
  Wire.write(0x12);               // Selects the GPIOA pins
  Wire.write(0xF0);               // Turns on pins 4, 5, 6, 7 of GPIOA
  Wire.endTransmission();         // Ends communication with the device

  delay(500);

  Wire.beginTransmission(0x20);   // Starts talking to slave device
  Wire.write(0x12);               // Selects the GPIOA pins
  Wire.write(0x00);               // Turns off all GPIOA pins
  Wire.endTransmission();         // Ends communication with the device

  delay(500);
}


