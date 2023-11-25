#ifndef __I2CSCAN_H__
#define __I2CSCAN_H__

#include <Arduino.h>
#include <Wire.h>

void scanI2C (TwoWire& wire = Wire, Stream& stream = Serial)
{
  char buf[5];
  // Print the headers...
  stream.println("Scanning Bus ");
  stream.print("    ");
  for (uint8_t lsb = 0; lsb < 16; lsb++)
  {
    sprintf(buf, " %x ", lsb);
    stream.print(buf);
  }
  stream.println();

  // Now go around all the addresses
  for (uint8_t msb = 0; msb < 8; msb++)
  {
    sprintf(buf, "%X0: ", msb);
    stream.print(buf);
    for (uint8_t lsb = 0; lsb < 16; lsb++)
    {
      uint8_t addr = (msb << 4) + lsb;
      wire.beginTransmission(addr);
	    uint8_t err = wire.endTransmission();
      if (err == 0)
      {
        sprintf(buf, "%02X ", addr);
        stream.print(buf);
        }
      else
        stream.print("-- ");
    }
    stream.println();
  }
}

#endif