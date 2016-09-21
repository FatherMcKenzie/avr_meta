//Tue Oct 20 02:07:54 MSK 2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef CIRCULAR_BUFFER_HELPER_HEADER
#define CIRCULAR_BUFFER_HELPER_HEADER

#include <stdint.h>

namespace cb
{

template
<
    unsigned VAL0,
    unsigned VAL1
>
struct MIN
{
    static const unsigned value;
};
template<unsigned VAL0,unsigned VAL1>
const unsigned MIN<VAL0,VAL1>::value = ((VAL0 < VAL1) ? VAL0 : VAL1);


template
<
    unsigned SIZE_ORDER,
    unsigned MAX_ORDER = 3
>
struct SIZE_HELPER
{
    static const uint8_t SIZE;
    static const uint8_t MAX_VALUE;
    static const uint8_t MASK;
};

template<unsigned SIZE_ORDER,unsigned MAX_ORDER>
const uint8_t SIZE_HELPER<SIZE_ORDER,MAX_ORDER>::SIZE = (1 << MIN<MAX_ORDER,SIZE_ORDER>::value);

template<unsigned SIZE_ORDER,unsigned MAX_ORDER>
const uint8_t SIZE_HELPER<SIZE_ORDER,MAX_ORDER>::MAX_VALUE = (SIZE - 1);

template<unsigned SIZE_ORDER,unsigned MAX_ORDER>
const uint8_t SIZE_HELPER<SIZE_ORDER,MAX_ORDER>::MASK = MAX_VALUE;

//===================================

// LOW PASS FILTER

template
<
    typename ValueType,
    typename TempType,
    unsigned SIZE_ORDER
>
struct average_value
{
    static ValueType inline calculate(const ValueType* buffer)
    {
        TempType result(0);
        for(uint8_t i(SIZE_HELPER<SIZE_ORDER,7>::SIZE); i-- ;) result += *(buffer + i);
        return (result >> SIZE_ORDER);
    }
};

}
#endif
