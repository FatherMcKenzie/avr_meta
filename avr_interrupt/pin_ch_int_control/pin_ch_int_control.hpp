// Sun Aug 16 18:41:33  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef PIN_CH_INT_CONTROL_CLASS_HEADER
#define PIN_CH_INT_CONTROL_CLASS_HEADER

#include <stdint.h>
#include "../../avr_misc/avr_misc.hpp"

#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
}; 
#endif

namespace
{

/**
 * The Pin change interrupt PCI2 will trigger if any enabled PCINT23:16 pin toggles, 
 * Pin change interrupt PCI1 if any enabled PCINT15:8 toggles and 
 * Pin change interrupts PCI0 will trigger if any enabled PCINT7:0 pin toggles. 
 * PCMSK2, PCMSK1 and PCMSK0 Registers control which pins contribute to the pin change interrupts. 
 * Pin change interrupts on PCINT23 :0 are detected asynchronously. 
 * This implies that these interrupts can be used for waking the part also from sleep modes other than Idle mode.
 */

enum PIN_CH_MASK
{
    PCINT_00 = 0x00,
    PCINT_01 = 0x01,
    PCINT_02 = 0x02,
    PCINT_03 = 0x03,
    PCINT_04 = 0x04,
    PCINT_05 = 0x05,
    PCINT_06 = 0x06,
    PCINT_07 = 0x07,
    PCINT_08 = 0x10,
    PCINT_09 = 0x11,
    PCINT_10 = 0x12,
    PCINT_11 = 0x13,
    PCINT_12 = 0x14,
    PCINT_13 = 0x15,
    PCINT_14 = 0x16,
    PCINT_15 = 0x17,
    PCINT_16 = 0x20,
    PCINT_17 = 0x21,
    PCINT_18 = 0x22,
    PCINT_19 = 0x23,
    PCINT_20 = 0x24,
    PCINT_21 = 0x25,
    PCINT_22 = 0x26,
    PCINT_23 = 0x27
};

template
<
    PIN_CH_MASK pcintmask
>
struct PIN_CH_INT
{
    static const uint8_t PCICR_mask;
    static const uint8_t PCMSK0_mask;
    static const uint8_t PCMSK1_mask;
    static const uint8_t PCMSK2_mask;
};

template<PIN_CH_MASK pcintmask>
const uint8_t PIN_CH_INT<pcintmask>::PCICR_mask = bit<(0x03 & (pcintmask >> 4))>::value;

template<PIN_CH_MASK pcintmask>
const uint8_t PIN_CH_INT<pcintmask>::PCMSK0_mask = bit_mask<(0x00 == (0xF8 & pcintmask)), (0x07 & pcintmask)>::value;

template<PIN_CH_MASK pcintmask>
const uint8_t PIN_CH_INT<pcintmask>::PCMSK1_mask = bit_mask<(0x10 == (0xF8 & pcintmask)), (0x07 & pcintmask)>::value;

template<PIN_CH_MASK pcintmask>
const uint8_t PIN_CH_INT<pcintmask>::PCMSK2_mask = bit_mask<(0x20 == (0xF8 & pcintmask)), (0x07 & pcintmask)>::value;

#if 1
struct NO_PCINT
{
    static const uint8_t PCICR_mask  = 0;
    static const uint8_t PCMSK0_mask = 0;
    static const uint8_t PCMSK1_mask = 0;
    static const uint8_t PCMSK2_mask = 0;
};
#endif



template
<
    class pcint00 = NO_PCINT,
    class pcint01 = NO_PCINT,
    class pcint02 = NO_PCINT,
    class pcint03 = NO_PCINT,
    class pcint04 = NO_PCINT,
    class pcint05 = NO_PCINT,
    class pcint06 = NO_PCINT,
    class pcint07 = NO_PCINT,
    class pcint08 = NO_PCINT,
    class pcint09 = NO_PCINT,
    class pcint10 = NO_PCINT,
    class pcint11 = NO_PCINT,
    class pcint12 = NO_PCINT,
    class pcint13 = NO_PCINT,
    class pcint14 = NO_PCINT,
    class pcint15 = NO_PCINT
>
struct PIN_CH_INT_CONTROL
{
    static const uint8_t PCICR_value;
    static const uint8_t PCMSK0_value;
    static const uint8_t PCMSK1_value;
    static const uint8_t PCMSK2_value;
    
#ifndef UNITTEST_MODE
    static void init()
    {
        PCICR   = PCICR_value;
        PCMSK0  = PCMSK0_value;
        PCMSK1  = PCMSK1_value;
        PCMSK2  = PCMSK2_value
    }
#endif
};

#if 1

template<class pcint00,class pcint01,class pcint02,class pcint03,class pcint04,class pcint05,class pcint06,class pcint07,
        class pcint08,class pcint09,class pcint10,class pcint11,class pcint12,class pcint13,class pcint14,class pcint15>
const uint8_t PIN_CH_INT_CONTROL<pcint00,pcint01,pcint02,pcint03,pcint04,pcint05,pcint06,pcint07,
    pcint08,pcint09,pcint10,pcint11,pcint12,pcint13,pcint14,pcint15>::PCICR_value =
           (pcint00::PCICR_mask |
            pcint01::PCICR_mask |
            pcint02::PCICR_mask |
            pcint03::PCICR_mask |
            pcint04::PCICR_mask |
            pcint05::PCICR_mask |
            pcint06::PCICR_mask |
            pcint07::PCICR_mask |
            pcint08::PCICR_mask |
            pcint09::PCICR_mask |
            pcint10::PCICR_mask |
            pcint11::PCICR_mask |
            pcint12::PCICR_mask |
            pcint13::PCICR_mask |
            pcint14::PCICR_mask |
            pcint15::PCICR_mask);
    
    
template<class pcint00,class pcint01,class pcint02,class pcint03,class pcint04,class pcint05,class pcint06,class pcint07,
        class pcint08,class pcint09,class pcint10,class pcint11,class pcint12,class pcint13,class pcint14,class pcint15>
const uint8_t PIN_CH_INT_CONTROL<pcint00,pcint01,pcint02,pcint03,pcint04,pcint05,pcint06,pcint07,
    pcint08,pcint09,pcint10,pcint11,pcint12,pcint13,pcint14,pcint15>::PCMSK0_value =
           (pcint00::PCMSK0_mask |
            pcint01::PCMSK0_mask |
            pcint02::PCMSK0_mask |
            pcint03::PCMSK0_mask |
            pcint04::PCMSK0_mask |
            pcint05::PCMSK0_mask |
            pcint06::PCMSK0_mask |
            pcint07::PCMSK0_mask |
            pcint08::PCMSK0_mask |
            pcint09::PCMSK0_mask |
            pcint10::PCMSK0_mask |
            pcint11::PCMSK0_mask |
            pcint12::PCMSK0_mask |
            pcint13::PCMSK0_mask |
            pcint14::PCMSK0_mask |
            pcint15::PCMSK0_mask);
    
template<class pcint00,class pcint01,class pcint02,class pcint03,class pcint04,class pcint05,class pcint06,class pcint07,
        class pcint08,class pcint09,class pcint10,class pcint11,class pcint12,class pcint13,class pcint14,class pcint15>
const uint8_t PIN_CH_INT_CONTROL<pcint00,pcint01,pcint02,pcint03,pcint04,pcint05,pcint06,pcint07,
    pcint08,pcint09,pcint10,pcint11,pcint12,pcint13,pcint14,pcint15>::PCMSK1_value =
           (pcint00::PCMSK1_mask |
            pcint01::PCMSK1_mask |
            pcint02::PCMSK1_mask |
            pcint03::PCMSK1_mask |
            pcint04::PCMSK1_mask |
            pcint05::PCMSK1_mask |
            pcint06::PCMSK1_mask |
            pcint07::PCMSK1_mask |
            pcint08::PCMSK1_mask |
            pcint09::PCMSK1_mask |
            pcint10::PCMSK1_mask |
            pcint11::PCMSK1_mask |
            pcint12::PCMSK1_mask |
            pcint13::PCMSK1_mask |
            pcint14::PCMSK1_mask |
            pcint15::PCMSK1_mask);
    
template<class pcint00,class pcint01,class pcint02,class pcint03,class pcint04,class pcint05,class pcint06,class pcint07,
        class pcint08,class pcint09,class pcint10,class pcint11,class pcint12,class pcint13,class pcint14,class pcint15>
const uint8_t PIN_CH_INT_CONTROL<pcint00,pcint01,pcint02,pcint03,pcint04,pcint05,pcint06,pcint07,
    pcint08,pcint09,pcint10,pcint11,pcint12,pcint13,pcint14,pcint15>::PCMSK2_value =
           (pcint00::PCMSK2_mask |
            pcint01::PCMSK2_mask |
            pcint02::PCMSK2_mask |
            pcint03::PCMSK2_mask |
            pcint04::PCMSK2_mask |
            pcint05::PCMSK2_mask |
            pcint06::PCMSK2_mask |
            pcint07::PCMSK2_mask |
            pcint08::PCMSK2_mask |
            pcint09::PCMSK2_mask |
            pcint10::PCMSK2_mask |
            pcint11::PCMSK2_mask |
            pcint12::PCMSK2_mask |
            pcint13::PCMSK2_mask |
            pcint14::PCMSK2_mask |
            pcint15::PCMSK2_mask);



#endif

} // namespace


#endif



