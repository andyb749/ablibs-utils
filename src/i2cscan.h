//***************************************************************************
//
//  File Name :		At90CanLib.h
//
//  Project :		Arduino style libraries
//
//  Purpose :		CAN
//
// The MIT License (MIT)
//
// Copyright (c) 2015-2023 Andy Burgess
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//  Revisions :
//
//      see rcs below
//
//***************************************************************************
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