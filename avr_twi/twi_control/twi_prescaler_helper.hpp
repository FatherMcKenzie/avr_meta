// Thu Mar 26 13:30:30 MSK 2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef AVR_TWI_PRESCALER_HELPER_HEADER
#define AVR_TWI_PRESCALER_HELPER_HEADER

#include <stdint.h>
#include "../../avr_misc/avr_misc.hpp"

namespace twi_control
{

enum TWPS_PWR
{
    H_TWPS_0 = 0,
    H_TWPS_1,
    H_TWPS_2,
    H_TWPS_3,
};


enum HV_TWPS_VAL
{
    HV_TWPS_0 = (1 << (H_TWPS_0 << 1)), //  1
    HV_TWPS_1 = (1 << (H_TWPS_1 << 1)), //  4
    HV_TWPS_2 = (1 << (H_TWPS_2 << 1)), // 16
    HV_TWPS_3 = (1 << (H_TWPS_3 << 1)), // 64
};


template
<
    uint8_t TWBR_VALUE,
    HV_TWPS_VAL TWPS_VAL,
    uint32_t OSC_FREQUENCY
>
struct scl_frequency
{
    static const uint32_t value;
};
template<uint8_t TWBR_VALUE,HV_TWPS_VAL TWPS_VAL,uint32_t OSC_FREQUENCY>
const uint32_t scl_frequency<TWBR_VALUE,TWPS_VAL,OSC_FREQUENCY>::value = OSC_FREQUENCY / (16 + (2 * TWBR_VALUE * TWPS_VAL));


template
<
    uint32_t SCL_FREQUENCY,
    HV_TWPS_VAL TWPS_VAL,
    uint32_t OSC_FREQUENCY
>
struct twbr
{
    static const uint8_t value;
};

template<uint32_t SCL_FREQUENCY, HV_TWPS_VAL TWPS_VAL, uint32_t OSC_FREQUENCY>
const uint8_t twbr<SCL_FREQUENCY, TWPS_VAL, OSC_FREQUENCY>::value = 0xFF & ((((OSC_FREQUENCY / SCL_FREQUENCY) >> 1) - 8) / TWPS_VAL);



template
<
    uint32_t SCL_FREQUENCY,
    uint32_t OSC_FREQUENCY
>
struct TWI_PRESCALER
{
    static const uint8_t value;
};

template<uint32_t SCL_FREQUENCY,uint32_t OSC_FREQUENCY>
const uint8_t TWI_PRESCALER<SCL_FREQUENCY,OSC_FREQUENCY>::value = minimal<
    minimal<
        error<SCL_FREQUENCY, scl_frequency<twbr<SCL_FREQUENCY,HV_TWPS_3,OSC_FREQUENCY>::value, HV_TWPS_3, OSC_FREQUENCY>::value>::value,
        error<SCL_FREQUENCY, scl_frequency<twbr<SCL_FREQUENCY,HV_TWPS_2,OSC_FREQUENCY>::value, HV_TWPS_2, OSC_FREQUENCY>::value>::value,
        H_TWPS_3,
        H_TWPS_2
    >::value,
    
    minimal<
        error<SCL_FREQUENCY, scl_frequency<twbr<SCL_FREQUENCY,HV_TWPS_1,OSC_FREQUENCY>::value, HV_TWPS_1, OSC_FREQUENCY>::value>::value,
        error<SCL_FREQUENCY, scl_frequency<twbr<SCL_FREQUENCY,HV_TWPS_0,OSC_FREQUENCY>::value, HV_TWPS_0, OSC_FREQUENCY>::value>::value,
        H_TWPS_1,
        H_TWPS_0
    >::value,
    
    minimal<
        error<SCL_FREQUENCY, scl_frequency<twbr<SCL_FREQUENCY,HV_TWPS_3,OSC_FREQUENCY>::value, HV_TWPS_3, OSC_FREQUENCY>::value>::value,
        error<SCL_FREQUENCY, scl_frequency<twbr<SCL_FREQUENCY,HV_TWPS_2,OSC_FREQUENCY>::value, HV_TWPS_2, OSC_FREQUENCY>::value>::value,
        H_TWPS_3,
        H_TWPS_2
    >::index,

    minimal<
        error<SCL_FREQUENCY, scl_frequency<twbr<SCL_FREQUENCY,HV_TWPS_1,OSC_FREQUENCY>::value, HV_TWPS_1, OSC_FREQUENCY>::value>::value,
        error<SCL_FREQUENCY, scl_frequency<twbr<SCL_FREQUENCY,HV_TWPS_0,OSC_FREQUENCY>::value, HV_TWPS_0, OSC_FREQUENCY>::value>::value,
        H_TWPS_1,
        H_TWPS_0
    >::index
>::index;


template
<
    uint32_t SCL_FREQUENCY, //  = 400000,
    uint32_t osc_freq       //  = F_CPU /**< F_CPU value should be defined somewere above, possibly using makefile -D directive */
>
struct TWI_CLOCK
{
    static const uint8_t TWPS_value;
    static const uint8_t TWBR_value;
};

template<uint32_t SCL_FREQUENCY,uint32_t osc_freq>
const uint8_t TWI_CLOCK<SCL_FREQUENCY,osc_freq>::TWPS_value = TWI_PRESCALER<SCL_FREQUENCY,osc_freq>::value; //(1 << (TWI_PRESCALER<SCL_FREQUENCY,osc_freq>::value << 1));

template<uint32_t SCL_FREQUENCY,uint32_t osc_freq>
const uint8_t TWI_CLOCK<SCL_FREQUENCY,osc_freq>::TWBR_value = twbr<SCL_FREQUENCY, static_cast<HV_TWPS_VAL>(1 << (TWI_PRESCALER<SCL_FREQUENCY,osc_freq>::value << 1)), osc_freq>::value;

} // twi_control namespace

#endif



