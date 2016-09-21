//Tue Oct 20 00:33:22 MSK 2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef POWER_CONTRIOL_HELPER_HEADER
#define POWER_CONTRIOL_HELPER_HEADER

#include "../../avr_misc/avr_misc.hpp"

namespace
{

//==========================================================================================================
enum MASKBYTE{LOWBYTE,HIGBYTE};

template<int bitnum,MASKBYTE mb>
struct dmask{static const uint8_t value;};

template<int bitnum,MASKBYTE mb>
const uint8_t dmask<bitnum,mb>::value = bit<bitnum, uint16_t>::value >> 8;

template<int bitnum>
struct dmask<bitnum,LOWBYTE>{static const uint8_t value;};

template<int bitnum>
const uint8_t dmask<bitnum,LOWBYTE>::value = 0xFF & bit<bitnum, uint16_t>::value;

//==========================================================================================================


}
#endif
