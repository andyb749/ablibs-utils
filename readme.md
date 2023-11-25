# ablibs-utils

## Introduction

Utility functions and classes for Arduino.

The following functions are provided:

* void strprintf(Stream& str, const char * fmt, ...) - provides fprintf support to Stream
* void i2cscan(TwoWire&, Stream&) - scans the supplied I2C bus returning the results to the supplied stream object.
