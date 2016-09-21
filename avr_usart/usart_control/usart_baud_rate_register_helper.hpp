//Sat Aug  8 02:32:03 MSK 2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//

#ifndef USART_BAUD_RATE_REGISTER_HELPER
#define USART_BAUD_RATE_REGISTER_HELPER

#include <stdint.h>
#include "../../avr_misc/avr_misc.hpp"

namespace ubrr
{

enum CLOCK_GENERATION_MODE
{
    SINGLE_SPEED_CLOCK = 0,
    DOUBLE_SPEED_CLOCK = 1
};

template
<
    uint64_t BAUDRATE,
    uint8_t  clock_mode,
    uint64_t osc_freq  = F_CPU
>
struct USART_BAUDRATE_REGISTER
{
    static const uint16_t value;
    static const CLOCK_GENERATION_MODE double_speed;
};

// 1 UBRR_VALUE (((F_CPU) + 8UL * (BAUD)) / (16UL * (BAUD)) -1UL)
// 0 UBRR_VALUE (((F_CPU) + 4UL * (BAUD)) / (8UL * (BAUD)) -1UL)

// 1 UBRR_VALUE ((F_CPU / (8  * BAUD)) - 1)
// 0 UBRR_VALUE ((F_CPU / (16 * BAUD)) - 1)

template<uint64_t BAUDRATE,uint8_t  clock_mode, uint64_t osc_freq>
const uint16_t USART_BAUDRATE_REGISTER<BAUDRATE,clock_mode,osc_freq>::value = 
            // 0x0FFF & ((clock_mode) ? ((osc_freq + (BAUDRATE << 2)) / (BAUDRATE << 3) - 1ULL) : ((osc_freq + (BAUDRATE << 3)) / (BAUDRATE << 4) - 1ULL));
            0x0FFF & ((clock_mode) ? ((((osc_freq / (BAUDRATE << 2)) + 1) >> 1) -1) : ((((osc_freq / (BAUDRATE << 3)) + 1) >> 1) -1));


template<uint64_t BAUDRATE,uint8_t  clock_mode, uint64_t osc_freq>
const CLOCK_GENERATION_MODE USART_BAUDRATE_REGISTER<BAUDRATE,clock_mode,osc_freq>::double_speed = static_cast<CLOCK_GENERATION_MODE>(clock_mode);

template
<
    uint64_t BAUDRATE,
    CLOCK_GENERATION_MODE  double_speed,
    uint64_t osc_freq  = F_CPU
>
struct USART_BAUDRATE
{
    static const uint64_t value;
};

template<uint64_t BAUDRATE,CLOCK_GENERATION_MODE  double_speed, uint64_t osc_freq>
const uint64_t USART_BAUDRATE<BAUDRATE, double_speed, osc_freq>::value = 
                                    (double_speed) ? 
                                    (osc_freq / ((USART_BAUDRATE_REGISTER<BAUDRATE,double_speed,osc_freq>::value + 1ULL) << 3)) : 
                                    (osc_freq / ((USART_BAUDRATE_REGISTER<BAUDRATE,double_speed,osc_freq>::value + 1ULL) << 4));

template
<
    uint64_t BAUDRATE,
    uint64_t osc_freq  = F_CPU
>
struct CLOCK_SPEED_IDX
{
    static const uint8_t value;
};

#if 0 // Use only single speed 
template<uint64_t BAUDRATE,uint64_t osc_freq>
const uint8_t CLOCK_SPEED_IDX<BAUDRATE,osc_freq>::value = 0;

#else // Select clock mode that provides minimal baudrate error
template<uint64_t BAUDRATE,uint64_t osc_freq>
const uint8_t CLOCK_SPEED_IDX<BAUDRATE,osc_freq>::value = minimal<
                        error<USART_BAUDRATE<BAUDRATE,DOUBLE_SPEED_CLOCK,osc_freq>::value, BAUDRATE>::value,
                        error<USART_BAUDRATE<BAUDRATE,SINGLE_SPEED_CLOCK,osc_freq>::value, BAUDRATE>::value,
                        DOUBLE_SPEED_CLOCK,
                        SINGLE_SPEED_CLOCK>::index;
#endif




template
<   
    uint64_t BAUDRATE,
    uint64_t osc_freq  = F_CPU
>
struct USART_BRR
{
    static const uint16_t value;
    static const uint8_t double_speed;
};

template<uint64_t BAUDRATE,uint64_t osc_freq>
const uint16_t USART_BRR<BAUDRATE,osc_freq>::value = USART_BAUDRATE_REGISTER<BAUDRATE,CLOCK_SPEED_IDX<BAUDRATE,osc_freq>::value ,osc_freq>::value;

template<uint64_t BAUDRATE,uint64_t osc_freq>
const uint8_t USART_BRR<BAUDRATE,osc_freq>::double_speed = CLOCK_SPEED_IDX<BAUDRATE,osc_freq>::value;

}

#endif





