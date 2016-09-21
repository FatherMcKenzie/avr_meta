// Sun May 25 21:56:37  2014
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef MISC_POWER_CLASS_HEADER
#define MISC_POWER_CLASS_HEADER


#include "power_helper.hpp"

namespace misc
{

template
<
    unsigned BASE,
    unsigned POWER,
    typename ValueType = unsigned
>
struct power
{
    static const ValueType value;
};

template<unsigned BASE, unsigned POWER, typename ValueType>
const ValueType power<BASE, POWER, ValueType>::value = misc::power_helper<BASE, POWER, ValueType>::value;

} // misc namespace
#endif
