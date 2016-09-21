// Wed Sep 02 15:29:25  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef PIN_PIN_CONTROL_CLASS_HEADER
#define PIN_PIN_CONTROL_CLASS_HEADER

#include <stdint.h>
#include "../../avr_misc/avr_misc.hpp"

#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
}; 
#endif


#include "port_helper.hpp"

namespace // anonimous
{

enum PORT_PIN
{
    BIT_0 = 0,
    BIT_1 = 1,
    BIT_2 = 2,
    BIT_3 = 3,
    BIT_4 = 4,
    BIT_5 = 5,
    BIT_6 = 6,
    BIT_7 = 7,
    NO_CTRL = -1
};

enum PIN_FUNCTION
{
    IN,         /**< Pin configured as unput  */
    OUT,        /**< Pin configured as output */
    IN_PULL_UP  /**< Input pin with pull up */
};

template
<
    PORT_PIN pin_num = NO_CTRL,
    PIN_FUNCTION pin_func = IN
>
struct PIN
{
    static const uint8_t dir_mask;      // Pin direction mask
    static const uint8_t pull_up_mask;
};

template<PORT_PIN pin_num, PIN_FUNCTION pin_func>
const uint8_t PIN<pin_num, pin_func>::dir_mask = ((NO_CTRL == pin_num) ? 0 : bit_mask<(OUT == pin_func), pin_num>::value);

template<PORT_PIN pin_num, PIN_FUNCTION pin_func>
const uint8_t PIN<pin_num, pin_func>::pull_up_mask = ((NO_CTRL == pin_num) ? 0 : bit_mask<(IN_PULL_UP == pin_func), pin_num>::value);

} //ns

namespace pin
{


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//PIN<BIT_3, OUT>
//PIN<BIT_2, IN_PULL_UP>
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


template
<
    class pin0 = PIN<NO_CTRL>,
    class pin1 = PIN<NO_CTRL>,
    class pin2 = PIN<NO_CTRL>,
    class pin3 = PIN<NO_CTRL>,
    class pin4 = PIN<NO_CTRL>,
    class pin5 = PIN<NO_CTRL>,
    class pin6 = PIN<NO_CTRL>,
    class pin7 = PIN<NO_CTRL>
>
struct PIN_MASK
{
    static const uint8_t DIRECTION_MASK;
    static const uint8_t PULL_UP_MASK;
};

#if 1

template<class pin0,class pin1,class pin2,class pin3,class pin4,class pin5,class pin6,class pin7>
const uint8_t PIN_MASK<pin0,pin1,pin2,pin3,pin4,pin5,pin6,pin7>::DIRECTION_MASK = compound_masks
                    <
                        pin0::dir_mask,
                        pin1::dir_mask,
                        pin2::dir_mask,
                        pin3::dir_mask,
                        pin4::dir_mask,
                        pin5::dir_mask,
                        pin6::dir_mask,
                        pin7::dir_mask
                    >::value;

template<class pin0,class pin1,class pin2,class pin3,class pin4,class pin5,class pin6,class pin7>
const uint8_t PIN_MASK<pin0,pin1,pin2,pin3,pin4,pin5,pin6,pin7>::PULL_UP_MASK = compound_masks
                    <
                        pin0::pull_up_mask,
                        pin1::pull_up_mask,
                        pin2::pull_up_mask,
                        pin3::pull_up_mask,
                        pin4::pull_up_mask,
                        pin5::pull_up_mask,
                        pin6::pull_up_mask,
                        pin7::pull_up_mask
                    >::value;
#endif


typedef  void (*PIN_FUNC_TYPE)(uint8_t);
template
<
    bool CONDITION,
    PIN_FUNC_TYPE func_true
>
struct conditional_call
{
    static void inline func(uint8_t param_value){func_true(param_value);}
};

template<PIN_FUNC_TYPE func_true>
struct conditional_call<0,func_true>
{
    static void inline func(uint8_t){}
};

// Data Register – PORTx, 
// Data Direction Register – DDRx, and the 
// Port Input Pins – PINx.

template
<
    PORT_CONTROL port_id,
    class pins_ctrl = PIN_MASK<>
>
struct PIN_CONTROL
{
    //static pin::io_port_unit<port_id> unit;
    typedef pin::io_port_unit<port_id> UNIT;
    
    /**
     * The DDxn bit in the DDRx Register selects the direction of this pin. 
     * If DDxn is written logic one, Pxn is configured as an output pin. 
     * If DDxn is written logic zero, Pxn is configured as an input pin.
     * 
     * If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is activated. 
     * To switch the pull-up resistor off, PORTxn has to be written logic zero or the pin has to be configured as an output pin.
     * The port pins are tri-stated when reset condition becomes active, even if no clocks are running.
     * 
     * If PORTxn is written logic one when the pin is configured as an output pin, the port pin is driven high (one).
     * If PORTxn is written logic zero when the pin is configured as an output pin, the port pin is driven low (zero).
     * 
     * Writing a logic one to PINxn toggles the value of PORTxn, independent on the value of DDRxn.
     * Note that the SBI instruction can be used to toggle one single bit in a port.
     */
    static void init()
    {
        UNIT::set_DDRX(pins_ctrl::DIRECTION_MASK); // set pins direction
        //UNIT::set_PORTX(pins_ctrl::PULL_UP_MASK);  // set pins pull ups
        
        // So we only set pull-ups in tha case PULL_UP_MASK is defined (not zero) AND just for those pins that aren't OUT-pins
        conditional_call<pins_ctrl::PULL_UP_MASK, &UNIT::set_PORTX>::func(pins_ctrl::PULL_UP_MASK & ~pins_ctrl::DIRECTION_MASK); // set pins pull ups
    }
    
    static void inline set_direction()
    {
        //UNIT::set_DDRX(pins_ctrl::DIRECTION_MASK); // set pins direction
        UNIT::set_DDRX(UNIT::DDRX() | pins_ctrl::DIRECTION_MASK);
    }

    static void inline clear_direction()
    {
        //UNIT::set_DDRX(pins_ctrl::DIRECTION_MASK); // set pins direction
        UNIT::set_DDRX(UNIT::DDRX()   & ~pins_ctrl::DIRECTION_MASK);
        //UNIT::set_PORTX(UNIT::PORTX() & ~pins_ctrl::DIRECTION_MASK);
    }
    
    static uint8_t inline read()
    {
        return UNIT::PINX();
    }
    
    static uint8_t inline get()
    {
        return UNIT::PORTX();
    }

    static void inline set(uint8_t value)
    {
        UNIT::set_PORTX(value);
    }

    template
    <
        PORT_PIN pina
    >
    static bool inline get()
    {
        return bool(bit<pina>::value & UNIT::PORTX());
    }

    template
    <
        PORT_PIN pina
    >
    static void inline set(bool value)
    {
        if(value) UNIT::set_PORTX(    bit<pina>::value | UNIT::PORTX());
        else      UNIT::set_PORTX(inv_bit<pina>::value & UNIT::PORTX());
    }
    
    template
    <
        PORT_PIN pina
    >
    static void inline set()
    {
        UNIT::set_PORTX(bit<pina>::value | UNIT::PORTX());
    }
    
    template
    <
        PORT_PIN pina,
        PORT_PIN pinb
    >
    static void inline set()
    {
        UNIT::set_PORTX(bit<pina>::value | bit<pinb>::value | UNIT::PORTX());
    }

    template
    <
        PORT_PIN pina
    >
    static void inline clear()
    {
        UNIT::set_PORTX(nobits<pina>::value & UNIT::PORTX());
    }
    
    template
    <
        PORT_PIN pina,
        PORT_PIN pinb
    >
    static void inline clear()
    {
        UNIT::set_PORTX(nobits<pina, pinb>::value & UNIT::PORTX());
    }

    template
    <
        PORT_PIN pina
    >
    static void inline toggle()
    {
        UNIT::set_PINX(bit<pina>::value);
    }
    
    template
    <
        PORT_PIN pina,
        PORT_PIN pinb
    >
    static void inline toggle()
    {
        UNIT::set_PINX(bit<pina>::value | bit<pinb>::value);
    }
};







} // pin namespace
#endif
