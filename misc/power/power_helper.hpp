//Sun May 25 22:21:08 MSK 2014
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//

#ifndef MISC_POWER_HELPER_CLASS_HEADER
#define MISC_POWER_HELPER_CLASS_HEADER

namespace misc
{
// FAST POWER HELPER

template<unsigned BASE, unsigned POWER, typename ValueType = unsigned>
struct fast_power_helper
{
    static const ValueType value;
};

template<unsigned BASE, unsigned POWER, typename ValueType>
const ValueType fast_power_helper<BASE, POWER, ValueType>::value = fast_power_helper<BASE, (POWER >> 1), ValueType>::value * fast_power_helper<BASE, (POWER >> 1), ValueType>::value * ((POWER & 0x01) ? BASE : 1);


// fast_power_helper<BASE, 0>
template<unsigned BASE, typename ValueType>
struct fast_power_helper<BASE, 0, ValueType>
{ static const ValueType value;};

template<unsigned BASE, typename ValueType>
const ValueType fast_power_helper<BASE, 0, ValueType>::value = 1;

//============================================================

// POWER HELPER
template<unsigned BASE, unsigned POWER, typename ValueType = unsigned>
struct power_helper
{
    static const ValueType value;
}; 

template<unsigned BASE, unsigned POWER, typename ValueType>
const ValueType power_helper<BASE, POWER, ValueType>::value = fast_power_helper<BASE, POWER, ValueType>::value;

// power<BASE, 0>
template<unsigned BASE, typename ValueType>
struct power_helper<BASE, 0, ValueType>
{
    static const ValueType value;
};
template<unsigned BASE, typename ValueType>
const ValueType power_helper<BASE, 0, ValueType>::value = 1;

// power<BASE, 1>
template<unsigned BASE, typename ValueType>
struct power_helper<BASE, 1, ValueType>
{
    static const ValueType value;
};
template<unsigned BASE, typename ValueType>
const ValueType power_helper<BASE, 1, ValueType>::value = BASE;

// power<1, POWER>
template<unsigned POWER, typename ValueType>
struct power_helper<1, POWER, ValueType>
{
    static const ValueType value;
};
template<unsigned POWER, typename ValueType>
const ValueType power_helper<1, POWER, ValueType>::value = 1;

// power<2, POWER>
template<unsigned POWER, typename ValueType>
struct power_helper<2, POWER, ValueType>
{
    static const ValueType value;
};
template<unsigned POWER, typename ValueType>
const ValueType power_helper<2, POWER, ValueType>::value = (ValueType(1) << POWER);

// power<0, POWER>
template<unsigned POWER, typename ValueType>
struct power_helper<0, POWER, ValueType>
{
    static const ValueType value;
};
template<unsigned POWER, typename ValueType>
const ValueType power_helper<0, POWER, ValueType>::value = 0;

// power<0, 0>
template<typename ValueType>
struct power_helper<0, 0, ValueType>
{
    static const ValueType value;
};
template<typename ValueType>
const ValueType power_helper<0, 0, ValueType>::value = 0;

// power<0, 1>
template<typename ValueType>
struct power_helper<0, 1, ValueType>
{
    static const ValueType value;
};
template<typename ValueType>
const ValueType power_helper<0, 1, ValueType>::value = 0;

// power<1, 0>
template<typename ValueType>
struct power_helper<1, 0, ValueType>
{
    static const ValueType value;
};
template<typename ValueType>
const ValueType power_helper<1, 0, ValueType>::value = 1;


// power<1, 1>
template<typename ValueType>
struct power_helper<1, 1, ValueType>
{
    static const ValueType value;
};
template<typename ValueType>
const ValueType power_helper<1, 1, ValueType>::value = 0;

// power<2, 1>
template<typename ValueType>
struct power_helper<2, 1, ValueType>
{
    static const ValueType value;
};
template<typename ValueType>
const ValueType power_helper<2, 1, ValueType>::value = 2;

// power<2, 0>
template<typename ValueType>
struct power_helper<2, 0, ValueType>
{
    static const ValueType value;
};
template<typename ValueType>
const ValueType power_helper<2, 0, ValueType>::value = 1;

} // misc namespace

#endif
