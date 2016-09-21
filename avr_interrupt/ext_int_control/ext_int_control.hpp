// Sun Aug 16 14:31:22  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef EXT_INT_CONTROL_CLASS_HEADER
#define EXT_INT_CONTROL_CLASS_HEADER

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
 * External Interrupts
 * The External Interrupts are triggered by the INT7:0 pin or any of the PCINT23:0 pins. 
 * Observe that, if enabled, the interrupts will trigger even if the INT7:0 or PCINT23:0 pins are configured as outputs. 
 * This feature provides a way of generating a software interrupt.
 */

enum EXT_INT_ENUM
{
    INT_0 = 0,
    INT_1,
    INT_2,
    INT_3,
    INT_4,
    INT_5,
    INT_6,
    INT_7,
};

/**
 * The External Interrupts can be triggered by a falling or rising edge or a low level. 
 * This is set up as indicated in the specification for the External Interrupt Control Registers – EICRA (INT3:0) and EICRB (INT7:4). 
 * When the external interrupt is enabled and is configured as level triggered,
 * the interrupt will trigger as long as the pin is held low. 
 * 
 * Note that recognition of falling or rising edge interrupts on INT7:4 requires the presence of an I/O clock, 
 * described in “Overview” on page 40. 
 * Low level interrupts and the edge interrupt on INT3:0 are detected asynchronously.
 * This implies that these interrupts can be used for waking the part also from sleep modes other than Idle mode. 
 * The I/O clock is halted in all sleep modes except Idle mode.
 * 
 * Note: When changing the ISCn1/ISCn0 bits, the interrupt must be disabled by clearing its Interrupt
 * Enable bit in the EIMSK Register. Otherwise an interrupt can occur when the bits are changed.
 */
enum INT_SENSE_CTRL_ENUM
{
    LOW_LEVEL       = 0, /**< 0 0 The low level of INTn generates an interrupt request */
    LOGICAL_CHANGE  = 1, /**< 0 1 Any logical change on INTn generates an interrupt request */
    FALLING_EDGE    = 2, /**< 1 0 The falling edge between two samples of INTn generates an interrupt request*/
    RISING_EDGE     = 3, /**< 1 1 The rising edge between two samples of INTn generates an interrupt request*/
};


template
<
    EXT_INT_ENUM id,
    INT_SENSE_CTRL_ENUM int_sense = FALLING_EDGE
>
struct EXT_INT
{
    static const uint8_t ExtIntMask;
    static const uint8_t EICRA_mask;
    static const uint8_t EICRB_mask;
};

template<EXT_INT_ENUM id,INT_SENSE_CTRL_ENUM int_sense>
const uint8_t EXT_INT<id,int_sense>::ExtIntMask = bit<id>::value;

template<EXT_INT_ENUM id,INT_SENSE_CTRL_ENUM int_sense>
const uint8_t EXT_INT<id,int_sense>::EICRA_mask = ((0x04 & id) ? 0 : ((0x03 & int_sense) << ((0x03 & id) << 1)));

template<EXT_INT_ENUM id,INT_SENSE_CTRL_ENUM int_sense>
const uint8_t EXT_INT<id,int_sense>::EICRB_mask = ((0x04 & id) ? ((0x03 & int_sense) << ((0x03 & id) << 1)) : 0);

struct NO_INT
{
    static const uint8_t ExtIntMask = 0;
    static const uint8_t EICRA_mask = 0;
    static const uint8_t EICRB_mask = 0;
};

template
<
    class eint0 = NO_INT,
    class eint1 = NO_INT,
    class eint2 = NO_INT,
    class eint3 = NO_INT,
    class eint4 = NO_INT,
    class eint5 = NO_INT,
    class eint6 = NO_INT,
    class eint7 = NO_INT
>
struct EXT_INT_CONTROL
{
    static const uint8_t EIMSK_value;
    static const uint8_t EICRA_value;
    static const uint8_t EICRB_value;
    
#ifndef UNITTEST_MODE
    static void inline init()
    {
        EIMSK = EIMSK_value;
        EICRA = EICRA_value;
#ifdef EICRB
        EICRB = EICRB_value;
#endif
    }
#endif
};

template<class eint0,class eint1,class eint2,class eint3,class eint4,class eint5,class eint6,class eint7>
const uint8_t EXT_INT_CONTROL<eint0,eint1,eint2,eint3,eint4,eint5,eint6,eint7>::EIMSK_value = 
                compound_masks<
                    eint0::ExtIntMask,
                    eint1::ExtIntMask,
                    eint2::ExtIntMask,
                    eint3::ExtIntMask,
                    eint4::ExtIntMask,
                    eint5::ExtIntMask,
                    eint6::ExtIntMask,
                    eint7::ExtIntMask
                        >::value;

template<class eint0,class eint1,class eint2,class eint3,class eint4,class eint5,class eint6,class eint7>
const uint8_t EXT_INT_CONTROL<eint0,eint1,eint2,eint3,eint4,eint5,eint6,eint7>::EICRA_value = 
                compound_masks<
                    eint0::EICRA_mask,
                    eint1::EICRA_mask,
                    eint2::EICRA_mask,
                    eint3::EICRA_mask,
                    eint4::EICRA_mask,
                    eint5::EICRA_mask,
                    eint6::EICRA_mask,
                    eint7::EICRA_mask
                        >::value;


template<class eint0,class eint1,class eint2,class eint3,class eint4,class eint5,class eint6,class eint7>
const uint8_t EXT_INT_CONTROL<eint0,eint1,eint2,eint3,eint4,eint5,eint6,eint7>::EICRB_value = 
                compound_masks<
                    eint0::EICRB_mask,
                    eint1::EICRB_mask,
                    eint2::EICRB_mask,
                    eint3::EICRB_mask,
                    eint4::EICRB_mask,
                    eint5::EICRB_mask,
                    eint6::EICRB_mask,
                    eint7::EICRB_mask
                        >::value;



} // namespace

#endif
