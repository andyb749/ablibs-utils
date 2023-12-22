#ifndef __COMMONS_H__
#define __COMMONS_H__

#include <Arduino.h>

// Macro to find the count of items in an array
#ifndef MAXITEMS
    #define MAXITEMS(x) sizeof(x)/sizeof(x[0])
#endif

#ifndef ARRAYSIZE
    #define ARRAYSIZE() sizeof(x)/sizeof(x[0])
#endif

#ifndef _cbi
    //! \def _cbi(sfr, bit)
    //! \brief Emulates the cbi instruction and clears the
    //! specified bit of the special function register.
    //! \param sfr Special function register
    //! \param bit Bit number
    #define _cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif


#ifndef _sbi
    //! \def _sbi(sft, bit)
    //! \brief Emulates the sbi instruction and sets the
    //! specified bit of the special function register.
    //! \param sfr Special function register
    //! \param bit Bit number
    #define _sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

extern void strprintf(Stream& str, const char * fmt, ...);

#endif