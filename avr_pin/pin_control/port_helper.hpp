// Wed Sep  2 16:04:25 MSK 2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//

#ifndef IO_PORT_HELPER_HEADER
#define IO_PORT_HELPER_HEADER

#include <stdint.h>

namespace
{
enum PORT_CONTROL
{
    PORT_A,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F,
    PORT_G,
    PORT_H,
    PORT_J,
    PORT_K,
    PORT_L,
};
}


namespace pin
{

// Data Register – PORTx, 
// Data Direction Register – DDRx, and the 
// Port Input Pins – PINx.

#if defined(UNITTEST_MODE) || defined(PC_TARGET)

struct EMPTY_MOCK_STUB
{
    const static uint8_t ID = -1;
    static uint8_t get_port(){return 0;};
    static void set_port(uint8_t){};

    static uint8_t get_ddr(){return 0;};
    static void set_ddr(uint8_t){};

    static uint8_t get_pin(){return 0;};
    static void set_pin(uint8_t){};
};

#ifndef MOCK_STUB_DEFINITION
#define MOCK_STUB_DEFINITION
typedef EMPTY_MOCK_STUB MOCK_STUB;
#endif


template
<
    PORT_CONTROL port_id
>
struct io_port_unit
{
    typedef MOCK_STUB mock;
    static inline uint8_t  PORTX(){return mock::get_port();}  // Data Register – PORTx
    static inline void set_PORTX(uint8_t value){mock::set_port(value);}

    static inline uint8_t  DDRX(){return mock::get_ddr();}   // Data Direction Register – DDRx
    static inline void set_DDRX(uint8_t value){mock::set_ddr(value);}

    static inline uint8_t  PINX(){return mock::get_pin();}   // Port Input Pins – PINx
    static inline void set_PINX(uint8_t value){mock::set_pin(value);}
};


#else

// Primary template / empty
template
<
    PORT_CONTROL port_id
>
struct io_port_unit
{
    static inline uint8_t  PORTX(){return 0;}  // Data Register – PORTx
    static inline void set_PORTX(uint8_t){}

    static inline uint8_t  DDRX(){return 0;}   // Data Direction Register – DDRx
    static inline void set_DDRX(uint8_t){}

    static inline uint8_t  PINX(){return 0;}   // Port Input Pins – PINx
    static inline void set_PINX(uint8_t){}
};

// PORT A specialization
#ifdef PORTA
template<>
struct io_port_unit<PORT_A>
{
    static inline uint8_t  PORTX(){return PORTA;}   // Data Register – PORTx
    static inline void set_PORTX(uint8_t value){PORTA = value;}

    static inline uint8_t  DDRX(){return DDRA;}   // Data Direction Register – DDRx
    static inline void set_DDRX(uint8_t value){DDRA = value;}

    static inline uint8_t  PINX(){return PINA;}   // Port Input Pins – PINx
    static inline void set_PINX(uint8_t value){PINA = value;}
};
#endif

// PORT B specialization
#ifdef PORTB
template<>
struct io_port_unit<PORT_B>
{
    static inline uint8_t  PORTX(){return PORTB;}   // Data Register – PORTx
    static inline void set_PORTX(uint8_t value){PORTB = value;}

    static inline uint8_t  DDRX(){return DDRB;}   // Data Direction Register – DDRx
    static inline void set_DDRX(uint8_t value){DDRB = value;}

    static inline uint8_t  PINX(){return PINB;}   // Port Input Pins – PINx
    static inline void set_PINX(uint8_t value){PINB = value;}
};
#endif

// PORT C specialization
#ifdef PORTC
template<>
struct io_port_unit<PORT_C>
{
    static inline uint8_t  PORTX(){return PORTC;}   // Data Register – PORTx
    static inline void set_PORTX(uint8_t value){PORTC = value;}

    static inline uint8_t  DDRX(){return DDRC;}   // Data Direction Register – DDRx
    static inline void set_DDRX(uint8_t value){DDRC = value;}

    static inline uint8_t  PINX(){return PINC;}   // Port Input Pins – PINx
    static inline void set_PINX(uint8_t value){PINC = value;}
};
#endif

// PORT D specialization
#ifdef PORTD
template<>
struct io_port_unit<PORT_D>
{
    static inline uint8_t  PORTX(){return PORTD;}   // Data Register – PORTx
    static inline void set_PORTX(uint8_t value){PORTD = value;}

    static inline uint8_t  DDRX(){return DDRD;}   // Data Direction Register – DDRx
    static inline void set_DDRX(uint8_t value){DDRD = value;}

    static inline uint8_t  PINX(){return PIND;}   // Port Input Pins – PINx
    static inline void set_PINX(uint8_t value){PIND = value;}
};
#endif

// PORT E specialization
#ifdef PORTE
template<>
struct io_port_unit<PORT_E>
{
    static inline uint8_t  PORTX(){return PORTE;}   // Data Register – PORTx
    static inline void set_PORTX(uint8_t value){PORTE = value;}

    static inline uint8_t  DDRX(){return DDRE;}   // Data Direction Register – DDRx
    static inline void set_DDRX(uint8_t value){DDRE = value;}

    static inline uint8_t  PINX(){return PINE;}   // Port Input Pins – PINx
    static inline void set_PINX(uint8_t value){PINE = value;}
};
#endif

// PORT F specialization
#ifdef PORTF
template<>
struct io_port_unit<PORT_F>
{
    static inline uint8_t  PORTX(){return PORTF;}   // Data Register – PORTx
    static inline void set_PORTX(uint8_t value){PORTF = value;}

    static inline uint8_t  DDRX(){return DDRF;}   // Data Direction Register – DDRx
    static inline void set_DDRX(uint8_t value){DDRF = value;}

    static inline uint8_t  PINX(){return PINF;}   // Port Input Pins – PINx
    static inline void set_PINX(uint8_t value){PINF = value;}
};
#endif

// PORT G specialization
#ifdef PORTG
template<>
struct io_port_unit<PORT_G>
{
    static inline uint8_t  PORTX(){return PORTG;}   // Data Register – PORTx
    static inline void set_PORTX(uint8_t value){PORTG = value;}

    static inline uint8_t  DDRX(){return DDRG;}   // Data Direction Register – DDRx
    static inline void set_DDRX(uint8_t value){DDRG = value;}

    static inline uint8_t  PINX(){return PING;}   // Port Input Pins – PINx
    static inline void set_PINX(uint8_t value){PING = value;}
};
#endif

// PORT H specialization
#ifdef PORTH
template<>
struct io_port_unit<PORT_H>
{
    static inline uint8_t  PORTX(){return PORTH;}   // Data Register – PORTx
    static inline void set_PORTX(uint8_t value){PORTH = value;}

    static inline uint8_t  DDRX(){return DDRH;}   // Data Direction Register – DDRx
    static inline void set_DDRX(uint8_t value){DDRH = value;}

    static inline uint8_t  PINX(){return PINH;}   // Port Input Pins – PINx
    static inline void set_PINX(uint8_t value){PINH = value;}
};
#endif

// PORT J specialization
#ifdef PORTJ
template<>
struct io_port_unit<PORT_J>
{
    static inline uint8_t  PORTX(){return PORTJ;}   // Data Register – PORTx
    static inline void set_PORTX(uint8_t value){PORTJ = value;}

    static inline uint8_t  DDRX(){return DDRJ;}   // Data Direction Register – DDRx
    static inline void set_DDRX(uint8_t value){DDRJ = value;}

    static inline uint8_t  PINX(){return PINJ;}   // Port Input Pins – PINx
    static inline void set_PINX(uint8_t value){PINJ = value;}
};
#endif

// PORT K specialization
#ifdef PORTK
template<>
struct io_port_unit<PORT_K>
{
    static inline uint8_t  PORTX(){return PORTK;}   // Data Register – PORTx
    static inline void set_PORTX(uint8_t value){PORTK = value;}

    static inline uint8_t  DDRX(){return DDRK;}   // Data Direction Register – DDRx
    static inline void set_DDRX(uint8_t value){DDRK = value;}

    static inline uint8_t  PINX(){return PINK;}   // Port Input Pins – PINx
    static inline void set_PINX(uint8_t value){PINK = value;}
};
#endif

// PORT L specialization
#ifdef PORTL
template<>
struct io_port_unit<PORT_L>
{
    static inline uint8_t  PORTX(){return PORTL;}   // Data Register – PORTx
    static inline void set_PORTX(uint8_t value){PORTL = value;}

    static inline uint8_t  DDRX(){return DDRL;}   // Data Direction Register – DDRx
    static inline void set_DDRX(uint8_t value){DDRL = value;}

    static inline uint8_t  PINX(){return PINL;}   // Port Input Pins – PINx
    static inline void set_PINX(uint8_t value){PINL = value;}
};
#endif

    
#endif


} // namespace pin

#endif
