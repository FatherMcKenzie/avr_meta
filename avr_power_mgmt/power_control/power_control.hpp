// Mon Mar 02 15:37:50  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef POWER_CONTROL_CLASS_HEADER
#define POWER_CONTROL_CLASS_HEADER

#include <stdint.h>


#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
}; 
#endif

#ifndef UNITTEST_MODE
#include <avr/io.h>
#endif

#include "../../avr_misc/avr_misc.hpp"
#include "power_control_helper.hpp"
 
/** Select between the five available sleep modes for power management.
 * Standby modes are only recommended for use with external crystals or resonators.
 */
enum SLEEP_MODE
{
    IDLE = 0,               /**< Idle*/
    ADC_NOISE_REDUCTION = 1,/**< ADC Noise Reduction*/
    POWER_DOWN = 2,         /**< Power-down*/
    POWER_SAFE = 3,         /**< Power-save*/
    // RESERVED             /**< Reserved*/
    // RESERVED             /**< Reserved*/
    STANDBY = 6,            /**< Standby*/
    EXTENDED_STANDBY = 7,   /**< Extended Standby*/
};

/**
 * The SE bit must be written to logic one to make the MCU enter the sleep mode when the SLEEP
 * instruction is executed. To avoid the MCU entering the sleep mode unless it is the programmer’s
 * purpose, it is recommended to write the Sleep Enable (SE) bit to one just before the execution of
 * the SLEEP instruction and to clear it immediately after waking up.
 */
enum SLEEP_MODE_ENABLE
{
    SLEEP_DISABLE = 0, /**< To avoid the MCU entering the sleep mode when the SLEEP instruction is executed.*/
    SLEEP_ENABLE  = 1, /**< To make the MCU enter the sleep mode when the SLEEP instruction is executed.*/
};

//==========================================================================================================
enum PR_DEV
{
    NO_DEVICE   = -1,
    PR_TWI      =  7, /**< TWI*/
    PR_TIMER2   =  6, /**< TIMER2*/
    PR_TIMER0   =  5, /**< TIMER0*/
    PR_TIMER1   =  3, /**< TIMER1*/
    PR_SPI      =  2, /**< SPI*/
    PR_USART0   =  1, /**< USART0*/
    PR_ADC      =  0, /**< ADC*/
    PR_TIMER5   = 13, /**< TIMER5*/
    PR_TIMER4   = 12, /**< TIMER4*/
    PR_TIMER3   = 11, /**< TIMER3*/
    PR_USART3   = 10, /**< USART3*/
    PR_USART2   =  9, /**< USART2*/
    PR_USART1   =  8, /**< USART1*/
};
//==========================================================================================================
template
<
    PR_DEV dev0 = NO_DEVICE,
    PR_DEV dev1 = NO_DEVICE,
    PR_DEV dev2 = NO_DEVICE,
    PR_DEV dev3 = NO_DEVICE,
    PR_DEV dev4 = NO_DEVICE,
    PR_DEV dev5 = NO_DEVICE,
    PR_DEV dev6 = NO_DEVICE,
    PR_DEV dev7 = NO_DEVICE,
    PR_DEV dev8 = NO_DEVICE,
    PR_DEV dev9 = NO_DEVICE,
    PR_DEV devA = NO_DEVICE,
    PR_DEV devB = NO_DEVICE,
    PR_DEV devC = NO_DEVICE
>
struct USE_DEVICES
{
    static const uint8_t PRR0_value;
    static const uint8_t PRR1_value;
};

template<PR_DEV dev0,PR_DEV dev1,PR_DEV dev2,PR_DEV dev3,PR_DEV dev4,PR_DEV dev5,PR_DEV dev6,PR_DEV dev7,PR_DEV dev8,PR_DEV dev9,PR_DEV devA,PR_DEV devB,PR_DEV devC>
const uint8_t USE_DEVICES<dev0,dev1,dev2,dev3,dev4,dev5,dev6,dev7,dev8,dev9,devA,devB,devC>::PRR0_value =
    static_cast<uint8_t>(
      ~(dmask<dev0,LOWBYTE>::value |
        dmask<dev1,LOWBYTE>::value |
        dmask<dev2,LOWBYTE>::value |
        dmask<dev3,LOWBYTE>::value |
        dmask<dev4,LOWBYTE>::value |
        dmask<dev5,LOWBYTE>::value |
        dmask<dev6,LOWBYTE>::value |
        dmask<dev7,LOWBYTE>::value |
        dmask<dev8,LOWBYTE>::value |
        dmask<dev9,LOWBYTE>::value |
        dmask<devA,LOWBYTE>::value |
        dmask<devB,LOWBYTE>::value |
        dmask<devC,LOWBYTE>::value));

template<PR_DEV dev0,PR_DEV dev1,PR_DEV dev2,PR_DEV dev3,PR_DEV dev4,PR_DEV dev5,PR_DEV dev6,PR_DEV dev7,PR_DEV dev8,PR_DEV dev9,PR_DEV devA,PR_DEV devB,PR_DEV devC>
const uint8_t USE_DEVICES<dev0,dev1,dev2,dev3,dev4,dev5,dev6,dev7,dev8,dev9,devA,devB,devC>::PRR1_value =
    static_cast<uint8_t>(
      ~(dmask<dev0,HIGBYTE>::value |
        dmask<dev1,HIGBYTE>::value |
        dmask<dev2,HIGBYTE>::value |
        dmask<dev3,HIGBYTE>::value |
        dmask<dev4,HIGBYTE>::value |
        dmask<dev5,HIGBYTE>::value |
        dmask<dev6,HIGBYTE>::value |
        dmask<dev7,HIGBYTE>::value |
        dmask<dev8,HIGBYTE>::value |
        dmask<dev9,HIGBYTE>::value |
        dmask<devA,HIGBYTE>::value |
        dmask<devB,HIGBYTE>::value |
        dmask<devC,HIGBYTE>::value));


template
<
    SLEEP_MODE mode,
    SLEEP_MODE_ENABLE se = SLEEP_ENABLE,
    class used_devices = USE_DEVICES<>
>
struct PWR_CONTROL
{
    static const uint8_t SMCR_value; // Sleep Mode Control Register
    static const uint8_t PRR0_value; // Power Reduction Register 0
    static const uint8_t PRR1_value; // Power Reduction Register 1
    
    static void init()
    {
#ifdef UNITTEST_MODE
        uint8_t PRR0;
        uint8_t PRR1;
        uint8_t SMCR;
#endif

#ifdef PRR0
        PRR0 = PRR0_value;
#endif

#ifdef PRR1
        PRR1 = PRR1_value;
#endif

#ifdef PRR
        PRR  = PRR0_value;
#endif
        SMCR = SMCR_value;
    }
    
};

template<SLEEP_MODE mode,SLEEP_MODE_ENABLE se,class used_devices>
const uint8_t PWR_CONTROL<mode, se, used_devices>::SMCR_value = compound_masks<
                 ((0x07 & mode) << 1)          // SM2:0: Sleep Mode Select Bits 2, 1, and 0
                ,bit_mask<se,0/*SE*/>::value   // SE: Sleep Enable
            >::value;

template<SLEEP_MODE mode,SLEEP_MODE_ENABLE se,class used_devices>
const uint8_t PWR_CONTROL<mode, se, used_devices>::PRR0_value = used_devices::PRR0_value;
 
template<SLEEP_MODE mode,SLEEP_MODE_ENABLE se,class used_devices>
const uint8_t PWR_CONTROL<mode, se, used_devices>::PRR1_value = used_devices::PRR1_value;
 

#endif



