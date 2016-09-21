//Tue Dec 15 14:25:13 MSK 2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//

#ifndef BLINKER_HELPER_HEADER
#define BLINKER_HELPER_HEADER

#include "../../avr_misc/avr_misc.hpp"
#include "led_helper.hpp"

namespace led
{

template
<
    uint8_t BIT_LENGTH,
    typename led::PATTERN_TYPE<led::PATTERN_SIZE<BIT_LENGTH>::BYTES>::type value_to_rotate
>
struct ROTATED
{
    typedef typename led::PATTERN_TYPE<led::PATTERN_SIZE<BIT_LENGTH>::BYTES>::type value_type;
    static const value_type VALUE_MASK;
    static const value_type HIGHEST_BIT_MASK;
    static const value_type HIGHEST_BIT;
    static const value_type LOWEST_BIT;
    
    static const value_type LEFT;
    static const value_type RIGHT;
};

template<uint8_t BIT_LENGTH, typename PATTERN_TYPE<PATTERN_SIZE<BIT_LENGTH>::BYTES>::type value_to_rotate>
const typename ROTATED<BIT_LENGTH,value_to_rotate>::value_type ROTATED<BIT_LENGTH,value_to_rotate>::VALUE_MASK = mask<BIT_LENGTH,0,value_type>::value;

template<uint8_t BIT_LENGTH, typename PATTERN_TYPE<PATTERN_SIZE<BIT_LENGTH>::BYTES>::type value_to_rotate>
const typename ROTATED<BIT_LENGTH,value_to_rotate>::value_type ROTATED<BIT_LENGTH,value_to_rotate>::HIGHEST_BIT_MASK = bit<BIT_LENGTH -1, typename ROTATED<BIT_LENGTH,value_to_rotate>::value_type>::value;

template<uint8_t BIT_LENGTH, typename PATTERN_TYPE<PATTERN_SIZE<BIT_LENGTH>::BYTES>::type value_to_rotate>
const typename ROTATED<BIT_LENGTH,value_to_rotate>::value_type ROTATED<BIT_LENGTH,value_to_rotate>::HIGHEST_BIT = ((HIGHEST_BIT_MASK & value_to_rotate) ? 1 : 0);

template<uint8_t BIT_LENGTH, typename PATTERN_TYPE<PATTERN_SIZE<BIT_LENGTH>::BYTES>::type value_to_rotate>
const typename ROTATED<BIT_LENGTH,value_to_rotate>::value_type ROTATED<BIT_LENGTH,value_to_rotate>::LOWEST_BIT  = ((value_type(1) & value_to_rotate) ? HIGHEST_BIT_MASK : 0);

template<uint8_t BIT_LENGTH, typename PATTERN_TYPE<PATTERN_SIZE<BIT_LENGTH>::BYTES>::type value_to_rotate>
const typename ROTATED<BIT_LENGTH,value_to_rotate>::value_type ROTATED<BIT_LENGTH,value_to_rotate>::LEFT  = VALUE_MASK & (value_type(value_to_rotate << 1) | HIGHEST_BIT);

template<uint8_t BIT_LENGTH, typename PATTERN_TYPE<PATTERN_SIZE<BIT_LENGTH>::BYTES>::type value_to_rotate>
const typename ROTATED<BIT_LENGTH,value_to_rotate>::value_type ROTATED<BIT_LENGTH,value_to_rotate>::RIGHT = VALUE_MASK & ((value_to_rotate >> 1) | LOWEST_BIT);


template
<
    typename ValueType,
    ValueType VALUE0,
    ValueType VALUE1
>
struct XOR
{
    static const ValueType value;
};

template<typename ValueType,ValueType VALUE0,ValueType VALUE1>
const ValueType XOR<ValueType,VALUE0,VALUE1>::value = VALUE0 ^ VALUE1;


} // namespace

#endif



