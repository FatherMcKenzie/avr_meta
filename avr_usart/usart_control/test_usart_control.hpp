// Wed Feb 18 21:03:52  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//

#include <tut/tut.hpp>
#include "usart_control.hpp"

#include <string>

namespace tut
{ 
    
    struct data
    { 
    }; 
    
    typedef tut::test_group<tut::data> tg;
    tg testgroup("first_test_group");
    
    typedef tg::object testobject;

#if 0
baudrates.py output:
==========================NORMAL MODE===========================
BAUD    2400, UBRR = 0x01A0, UBRR =  416, baudrate =    2398, ERROR :   -0.0833 %
BAUD    4800, UBRR = 0x00CF, UBRR =  207, baudrate =    4807, ERROR :    0.1458 %
BAUD    9600, UBRR = 0x0067, UBRR =  103, baudrate =    9615, ERROR :    0.1562 %
BAUD   14400, UBRR = 0x0044, UBRR =   68, baudrate =   14492, ERROR :    0.6389 %
BAUD   19200, UBRR = 0x0033, UBRR =   51, baudrate =   19230, ERROR :    0.1562 %
BAUD   28800, UBRR = 0x0022, UBRR =   34, baudrate =   28571, ERROR :   -0.7951 %
BAUD   38400, UBRR = 0x0019, UBRR =   25, baudrate =   38461, ERROR :    0.1589 %
BAUD   56000, UBRR = 0x0011, UBRR =   17, baudrate =   55555, ERROR :   -0.7946 %
BAUD   57600, UBRR = 0x0010, UBRR =   16, baudrate =   58823, ERROR :    2.1233 %
BAUD   76800, UBRR = 0x000C, UBRR =   12, baudrate =   76923, ERROR :    0.1602 %
BAUD  115200, UBRR = 0x0008, UBRR =    8, baudrate =  111111, ERROR :   -3.5495 %
BAUD  128000, UBRR = 0x0007, UBRR =    7, baudrate =  125000, ERROR :   -2.3438 %
BAUD  153600, UBRR = 0x0006, UBRR =    6, baudrate =  142857, ERROR :   -6.9941 %
BAUD  230400, UBRR = 0x0003, UBRR =    3, baudrate =  250000, ERROR :    8.5069 %
BAUD  256000, UBRR = 0x0003, UBRR =    3, baudrate =  250000, ERROR :   -2.3438 %
BAUD  460800, UBRR = 0x0001, UBRR =    1, baudrate =  500000, ERROR :    8.5069 %
BAUD  921600, UBRR = 0x0000, UBRR =    0, baudrate = 1000000, ERROR :    8.5069 %
#endif

#if 0
=======================BAUDRATES avr-libc=======================
BAUD    2400, UBRR = 0x01A0, UBRR =  416, baudrate =    2398, ERROR :   -0.0833 %
BAUD    4800, UBRR = 0x00CF, UBRR =  207, baudrate =    4807, ERROR :    0.1458 %
BAUD    9600, UBRR = 0x0067, UBRR =  103, baudrate =    9615, ERROR :    0.1562 %
BAUD   14400, UBRR = 0x0044, UBRR =   68, baudrate =   14492, ERROR :    0.6389 %
BAUD   19200, UBRR = 0x0033, UBRR =   51, baudrate =   19230, ERROR :    0.1562 %
BAUD   28800, UBRR = 0x0022, UBRR =   34, baudrate =   28571, ERROR :   -0.7951 %
BAUD   38400, UBRR = 0x0019, UBRR =   25, baudrate =   38461, ERROR :    0.1589 %
BAUD   56000, UBRR = 0x0011, UBRR =   17, baudrate =   55555, ERROR :   -0.7946 %
BAUD   57600, UBRR = 0x0022, UBRR =   34, baudrate =   57142, ERROR :   -0.7951 %
BAUD   76800, UBRR = 0x000C, UBRR =   12, baudrate =   76923, ERROR :    0.1602 %
BAUD  115200, UBRR = 0x0010, UBRR =   16, baudrate =  117647, ERROR :    2.1241 %
BAUD  128000, UBRR = 0x000F, UBRR =   15, baudrate =  125000, ERROR :   -2.3438 %
BAUD  153600, UBRR = 0x000C, UBRR =   12, baudrate =  153846, ERROR :    0.1602 %
BAUD  230400, UBRR = 0x0008, UBRR =    8, baudrate =  222222, ERROR :   -3.5495 %
BAUD  256000, UBRR = 0x0007, UBRR =    7, baudrate =  250000, ERROR :   -2.3438 %
BAUD  460800, UBRR = 0x0003, UBRR =    3, baudrate =  500000, ERROR :    8.5069 %
BAUD  921600, UBRR = 0x0001, UBRR =    1, baudrate = 1000000, ERROR :    8.5069 %
#endif

#if 0
  -0.0833 :   -0.0833 2400:0 +
   0.1458 :    0.1458 4800:0 +
   0.1562 :    0.1562 9600:0 +
   0.6389 :    0.6389 14400:0 +
   0.1562 :    0.1562 19200:0 +
  -0.7951 :   -0.7951 28800:0 +
   0.1589 :    0.1589 38400:0 +
  -0.7946 :   -0.7946 56000:0 +
   2.1233 :   -0.7951 57600:1 +
   0.1602 :    0.1602 76800:0 +
  -3.5495 :    2.1241 115200:1 +
  -2.3438 :   -2.3438 128000:1 +
  -6.9941 :    0.1602 153600:1 +
   8.5069 :   -3.5495 230400:1 +
  -2.3438 :   -2.3438 256000:1 +
   8.5069 :    8.5069 460800:1 +
   8.5069 :    8.5069 921600:1 +
#endif
    
    
    uint8_t cmp_buff(const uint8_t* a, const uint8_t* b, uint8_t size)
    {
        for(uint8_t i = 0; i < size; ++i)
            if( *(a + i) != *(b + i)) return -1;
        return 0;
    }
    
    template<>
    template<>
    void testobject::test<1>()
    {
        set_test_name("test_0001  SINGLE_SPEED_CLOCK : BAUDRATES : UBRR value");
        //ubrr::USART_BAUDRATE_REGISTER<BAUDRATE,clock_mode,osc_freq  = F_CPU>::value
        //ubrr::USART_BAUDRATE_REGISTER<BR_2400,ubrr::SINGLE_SPEED_CLOCK,16000000L::value
#if 0
BR_2400
BR_4800
BR_9600
BR_14400
BR_19200
BR_28800
BR_38400
BR_56000
BR_57600
BR_76800
BR_115200
BR_128000
BR_153600
BR_230400
BR_256000
BR_460800
BR_921600
#endif
        ensure_equals("BR_2400",   ubrr::USART_BAUDRATE_REGISTER<BR_2400,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value,   416);
        ensure_equals("BR_4800",   ubrr::USART_BAUDRATE_REGISTER<BR_4800,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value,   207);
        ensure_equals("BR_9600",   ubrr::USART_BAUDRATE_REGISTER<BR_9600,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value,   103);
        ensure_equals("BR_14400",  ubrr::USART_BAUDRATE_REGISTER<BR_14400,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value,  68);
        ensure_equals("BR_19200",  ubrr::USART_BAUDRATE_REGISTER<BR_19200,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value,  51);
        ensure_equals("BR_28800",  ubrr::USART_BAUDRATE_REGISTER<BR_28800,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value,  34);
        ensure_equals("BR_38400",  ubrr::USART_BAUDRATE_REGISTER<BR_38400,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value,  25);
        ensure_equals("BR_56000",  ubrr::USART_BAUDRATE_REGISTER<BR_56000,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value,  17);
        ensure_equals("BR_57600",  ubrr::USART_BAUDRATE_REGISTER<BR_57600,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value,  16);
        ensure_equals("BR_76800",  ubrr::USART_BAUDRATE_REGISTER<BR_76800,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value,  12);
        ensure_equals("BR_115200", ubrr::USART_BAUDRATE_REGISTER<BR_115200,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value, 8);
        ensure_equals("BR_128000", ubrr::USART_BAUDRATE_REGISTER<BR_128000,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value, 7);
        ensure_equals("BR_153600", ubrr::USART_BAUDRATE_REGISTER<BR_153600,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value, 6);
        ensure_equals("BR_230400", ubrr::USART_BAUDRATE_REGISTER<BR_230400,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value, 3);
        ensure_equals("BR_256000", ubrr::USART_BAUDRATE_REGISTER<BR_256000,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value, 3);
        ensure_equals("BR_460800", ubrr::USART_BAUDRATE_REGISTER<BR_460800,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value, 1);
        ensure_equals("BR_921600", ubrr::USART_BAUDRATE_REGISTER<BR_921600,ubrr::SINGLE_SPEED_CLOCK,16000000L>::value, 0);
    }
    
    template<>
    template<>
    void testobject::test<2>()
    {
        set_test_name("test_0002  DOUBLE_SPEED_CLOCK : BAUDRATES : UBRR value");

        ensure_equals("BR_2400",   ubrr::USART_BAUDRATE_REGISTER<BR_2400,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value,   832);
        ensure_equals("BR_4800",   ubrr::USART_BAUDRATE_REGISTER<BR_4800,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value,   416);
        ensure_equals("BR_9600",   ubrr::USART_BAUDRATE_REGISTER<BR_9600,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value,   207);
        ensure_equals("BR_14400",  ubrr::USART_BAUDRATE_REGISTER<BR_14400,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value,  138);
        ensure_equals("BR_19200",  ubrr::USART_BAUDRATE_REGISTER<BR_19200,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value,  103);
        ensure_equals("BR_28800",  ubrr::USART_BAUDRATE_REGISTER<BR_28800,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value,  68);
        ensure_equals("BR_38400",  ubrr::USART_BAUDRATE_REGISTER<BR_38400,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value,  51);
        ensure_equals("BR_56000",  ubrr::USART_BAUDRATE_REGISTER<BR_56000,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value,  35);
        ensure_equals("BR_57600",  ubrr::USART_BAUDRATE_REGISTER<BR_57600,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value,  34);
        ensure_equals("BR_76800",  ubrr::USART_BAUDRATE_REGISTER<BR_76800,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value,  25);
        ensure_equals("BR_115200", ubrr::USART_BAUDRATE_REGISTER<BR_115200,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value, 16);
        ensure_equals("BR_128000", ubrr::USART_BAUDRATE_REGISTER<BR_128000,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value, 15);
        ensure_equals("BR_153600", ubrr::USART_BAUDRATE_REGISTER<BR_153600,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value, 12);
        ensure_equals("BR_230400", ubrr::USART_BAUDRATE_REGISTER<BR_230400,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value, 8);
        ensure_equals("BR_256000", ubrr::USART_BAUDRATE_REGISTER<BR_256000,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value, 7);
        ensure_equals("BR_460800", ubrr::USART_BAUDRATE_REGISTER<BR_460800,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value, 3);
        ensure_equals("BR_921600", ubrr::USART_BAUDRATE_REGISTER<BR_921600,ubrr::DOUBLE_SPEED_CLOCK,16000000L>::value, 1);
    }

    template<>
    template<>
    void testobject::test<3>()
    {
        set_test_name("test_0003  MINIMAL BAUDRATE ERROR : UBRR and X2 value");
        //ubrr::USART_BRR<BAUDRATE,osc_freq>::value 
        //ubrr::USART_BRR<BAUDRATE,osc_freq>::double_speed 
#if 0 //    bauds.py output
                SINGLE SPEED              DOUBLE SPEED               FINAL (minimal error)
baud:   2400    UBRR: 416 ERR:-0.08333    UBRR: 832 ERR:     0.0  :  UBRR: 832 X2:1 ERR:     0.0
baud:   4800    UBRR: 207 ERR:  0.1458    UBRR: 416 ERR:-0.08333  :  UBRR: 416 X2:1 ERR:-0.08333
baud:   9600    UBRR: 103 ERR:  0.1562    UBRR: 207 ERR:  0.1562  :  UBRR: 103 X2:0 ERR:  0.1562
baud:  14400    UBRR:  68 ERR:  0.6389    UBRR: 138 ERR:-0.08333  :  UBRR: 138 X2:1 ERR:-0.08333
baud:  19200    UBRR:  51 ERR:  0.1562    UBRR: 103 ERR:  0.1562  :  UBRR:  51 X2:0 ERR:  0.1562
baud:  28800    UBRR:  34 ERR: -0.7951    UBRR:  68 ERR:  0.6424  :  UBRR:  68 X2:1 ERR:  0.6424
baud:  38400    UBRR:  25 ERR:  0.1589    UBRR:  51 ERR:  0.1589  :  UBRR:  25 X2:0 ERR:  0.1589
baud:  56000    UBRR:  17 ERR: -0.7946    UBRR:  35 ERR: -0.7946  :  UBRR:  17 X2:0 ERR: -0.7946
baud:  57600    UBRR:  16 ERR:   2.123    UBRR:  34 ERR: -0.7951  :  UBRR:  34 X2:1 ERR: -0.7951
baud:  76800    UBRR:  12 ERR:  0.1602    UBRR:  25 ERR:  0.1602  :  UBRR:  12 X2:0 ERR:  0.1602
baud: 115200    UBRR:   8 ERR:  -3.549    UBRR:  16 ERR:   2.124  :  UBRR:  16 X2:1 ERR:   2.124
baud: 128000    UBRR:   7 ERR:  -2.344    UBRR:  15 ERR:  -2.344  :  UBRR:   7 X2:0 ERR:  -2.344
baud: 153600    UBRR:   6 ERR:  -6.994    UBRR:  12 ERR:  0.1602  :  UBRR:  12 X2:1 ERR:  0.1602
baud: 230400    UBRR:   3 ERR:   8.507    UBRR:   8 ERR:  -3.549  :  UBRR:   8 X2:1 ERR:  -3.549
baud: 256000    UBRR:   3 ERR:  -2.344    UBRR:   7 ERR:  -2.344  :  UBRR:   3 X2:0 ERR:  -2.344
baud: 460800    UBRR:   1 ERR:   8.507    UBRR:   3 ERR:   8.507  :  UBRR:   1 X2:0 ERR:   8.507
baud: 921600    UBRR:   0 ERR:   8.507    UBRR:   1 ERR:   8.507  :  UBRR:   0 X2:0 ERR:   8.507

#endif

        ensure_equals("BR_2400 UBRR",   ubrr::USART_BRR<BR_2400,  16000000L>::value,        832);
        ensure_equals("BR_2400   X2",   ubrr::USART_BRR<BR_2400,  16000000L>::double_speed, 1);
        
        ensure_equals("BR_4800 UBRR",   ubrr::USART_BRR<BR_4800,  16000000L>::value,        416);
        ensure_equals("BR_4800   X2",   ubrr::USART_BRR<BR_4800,  16000000L>::double_speed, 1);
        
        ensure_equals("BR_9600 UBRR",   ubrr::USART_BRR<BR_9600,  16000000L>::value,        103);
        ensure_equals("BR_9600   X2",   ubrr::USART_BRR<BR_9600,  16000000L>::double_speed, 0);
        
        ensure_equals("BR_14400 UBRR",   ubrr::USART_BRR<BR_14400,  16000000L>::value,        138);
        ensure_equals("BR_14400   X2",   ubrr::USART_BRR<BR_14400,  16000000L>::double_speed, 1);
        
        ensure_equals("BR_19200 UBRR",   ubrr::USART_BRR<BR_19200,  16000000L>::value,        51);
        ensure_equals("BR_19200   X2",   ubrr::USART_BRR<BR_19200,  16000000L>::double_speed, 0);
        
        ensure_equals("BR_28800 UBRR",   ubrr::USART_BRR<BR_28800,  16000000L>::value,        68);
        ensure_equals("BR_28800   X2",   ubrr::USART_BRR<BR_28800,  16000000L>::double_speed, 1);
        
        ensure_equals("BR_38400 UBRR",   ubrr::USART_BRR<BR_38400,  16000000L>::value,        25);
        ensure_equals("BR_38400   X2",   ubrr::USART_BRR<BR_38400,  16000000L>::double_speed, 0);
        
        ensure_equals("BR_56000 UBRR",   ubrr::USART_BRR<BR_56000,  16000000L>::value,        17);
        ensure_equals("BR_56000   X2",   ubrr::USART_BRR<BR_56000,  16000000L>::double_speed, 0);
        
        ensure_equals("BR_57600 UBRR",   ubrr::USART_BRR<BR_57600,  16000000L>::value,        34);
        ensure_equals("BR_57600   X2",   ubrr::USART_BRR<BR_57600,  16000000L>::double_speed, 1);

        ensure_equals("BR_76800 UBRR",   ubrr::USART_BRR<BR_76800,  16000000L>::value,        12);
        ensure_equals("BR_76800   X2",   ubrr::USART_BRR<BR_76800,  16000000L>::double_speed, 0);
        
        ensure_equals("BR_115200 UBRR",   ubrr::USART_BRR<BR_115200,  16000000L>::value,        16);
        ensure_equals("BR_115200   X2",   ubrr::USART_BRR<BR_115200,  16000000L>::double_speed, 1);
        
        ensure_equals("BR_128000 UBRR",   ubrr::USART_BRR<BR_128000,  16000000L>::value,        7);
        ensure_equals("BR_128000   X2",   ubrr::USART_BRR<BR_128000,  16000000L>::double_speed, 0);
        
        ensure_equals("BR_153600 UBRR",   ubrr::USART_BRR<BR_153600,  16000000L>::value,        12);
        ensure_equals("BR_153600   X2",   ubrr::USART_BRR<BR_153600,  16000000L>::double_speed, 1);
        
        ensure_equals("BR_230400 UBRR",   ubrr::USART_BRR<BR_230400,  16000000L>::value,        8);
        ensure_equals("BR_230400   X2",   ubrr::USART_BRR<BR_230400,  16000000L>::double_speed, 1);
        
        ensure_equals("BR_256000 UBRR",   ubrr::USART_BRR<BR_256000,  16000000L>::value,        3);
        ensure_equals("BR_256000   X2",   ubrr::USART_BRR<BR_256000,  16000000L>::double_speed, 0);
        
        ensure_equals("BR_460800 UBRR",   ubrr::USART_BRR<BR_460800,  16000000L>::value,        1);
        ensure_equals("BR_460800   X2",   ubrr::USART_BRR<BR_460800,  16000000L>::double_speed, 0);
        
        ensure_equals("BR_921600 UBRR",   ubrr::USART_BRR<BR_921600,  16000000L>::value,        0);
        ensure_equals("BR_921600   X2",   ubrr::USART_BRR<BR_921600,  16000000L>::double_speed, 0);
    }

    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004 DATA_BITS");
        
        ensure_equals("message", FRAME_CONTROL<BR_9600, DATA_BITS_5>::UCSRnB_mask, uint8_t(0x00));
        ensure_equals("message", FRAME_CONTROL<BR_9600, DATA_BITS_6>::UCSRnB_mask, uint8_t(0x00));
        ensure_equals("message", FRAME_CONTROL<BR_9600, DATA_BITS_7>::UCSRnB_mask, uint8_t(0x00));
        ensure_equals("message", FRAME_CONTROL<BR_9600, DATA_BITS_8>::UCSRnB_mask, uint8_t(0x00));
        ensure_equals("message", FRAME_CONTROL<BR_9600, DATA_BITS_9>::UCSRnB_mask, uint8_t(0x04));
        
        ensure_equals("message", FRAME_CONTROL<BR_9600, DATA_BITS_5>::UCSRnC_mask & 0x6, uint8_t(0x00));
        ensure_equals("message", FRAME_CONTROL<BR_9600, DATA_BITS_6>::UCSRnC_mask & 0x6, uint8_t(0x02));
        ensure_equals("message", FRAME_CONTROL<BR_9600, DATA_BITS_7>::UCSRnC_mask & 0x6, uint8_t(0x04));
        ensure_equals("message", FRAME_CONTROL<BR_9600, DATA_BITS_8>::UCSRnC_mask & 0x6, uint8_t(0x06));
        ensure_equals("message", FRAME_CONTROL<BR_9600, DATA_BITS_9>::UCSRnC_mask & 0x6, uint8_t(0x06));
    } 

    template<>
    template<>
    void testobject::test<5>()
    { 
        set_test_name("test_0005 PARIRY, STOP_BIT,  CLOCK_MODE, USART_MODE, CLOCK_POLARITY");
        
        //FRAME_CONTROL<BAUD_RATE baud,DATA_BITS data_bits,PARITY parity,STOP_BITS stop_bits,uint64_t osc_freq,USART_MODE usart_mode,CLOCK_POLARITY uspol>    
        
        
        ensure_equals("message   NO_PARITY", ((FRAME_CONTROL<BR_9600, DATA_BITS_8,   NO_PARITY>::UCSRnC_mask >> 0x04) & 0x03), uint8_t(0x00));
        ensure_equals("message EVEN_PARITY", ((FRAME_CONTROL<BR_9600, DATA_BITS_8, EVEN_PARITY>::UCSRnC_mask >> 0x04) & 0x03), uint8_t(0x02));
        ensure_equals("message  ODD_PARITY", ((FRAME_CONTROL<BR_9600, DATA_BITS_8,  ODD_PARITY>::UCSRnC_mask >> 0x04) & 0x03), uint8_t(0x03));
        
        ensure_equals("message  STOP_1", (FRAME_CONTROL<BR_9600, DATA_BITS_8, ODD_PARITY, STOP_1>::UCSRnC_mask & 0x08), uint8_t(0x00));
        ensure_equals("message  STOP_2", (FRAME_CONTROL<BR_9600, DATA_BITS_8, NO_PARITY,  STOP_2>::UCSRnC_mask & 0x08), uint8_t(0x08));

        /*
        ensure_equals("message  SINGLE_SPEED", (FRAME_CONTROL<BR_9600, DATA_BITS_8, NO_PARITY, STOP_1, F_CPU>::UCSRnA_mask & 0x02), uint8_t(0x00));
        ensure_equals("message  DOUBLE_SPEED", (FRAME_CONTROL<BR_9600, DATA_BITS_8, NO_PARITY, STOP_1, F_CPU>::UCSRnA_mask & 0x02), uint8_t(0x02));
        ensure_equals("message   SYNC_MASTER", (FRAME_CONTROL<BR_9600, DATA_BITS_8, NO_PARITY, STOP_1, F_CPU>::UCSRnA_mask & 0x02), uint8_t(0x00));
        */
        
        ensure_equals("message  ASYNC_USART", ((FRAME_CONTROL<BR_9600, DATA_BITS_8, NO_PARITY, STOP_1, F_CPU, ASYNC_USART>::UCSRnC_mask >> 6) & 0x03), uint8_t(0x00));
        ensure_equals("message   SYNC_USART", ((FRAME_CONTROL<BR_9600, DATA_BITS_8, NO_PARITY, STOP_1, F_CPU,  SYNC_USART>::UCSRnC_mask >> 6) & 0x03), uint8_t(0x01));
        ensure_equals("message   MASTER_SPI", ((FRAME_CONTROL<BR_9600, DATA_BITS_8, NO_PARITY, STOP_1, F_CPU,  MASTER_SPI>::UCSRnC_mask >> 6) & 0x03), uint8_t(0x03));

        /**
         * Bit 0 – UCPOLn: Clock Polarity
         * This bit is used for synchronous mode only. Write this bit to zero when asynchronous mode is used.
         */
        ensure_equals("message  OUT_RISING_IN_FALLING", (FRAME_CONTROL<BR_9600, DATA_BITS_8, NO_PARITY, STOP_1, F_CPU, ASYNC_USART, OUT_RISING_IN_FALLING>::UCSRnC_mask & 0x01), uint8_t(0x00));
        ensure_equals("message  OUT_FALLING_IN_RISING", (FRAME_CONTROL<BR_9600, DATA_BITS_8, NO_PARITY, STOP_1, F_CPU, ASYNC_USART, OUT_FALLING_IN_RISING>::UCSRnC_mask & 0x01), uint8_t(0x00));

        ensure_equals("message  OUT_RISING_IN_FALLING", (FRAME_CONTROL<BR_9600, DATA_BITS_8, NO_PARITY, STOP_1, F_CPU, SYNC_USART, OUT_RISING_IN_FALLING>::UCSRnC_mask & 0x01), uint8_t(0x00));
        ensure_equals("message  OUT_FALLING_IN_RISING", (FRAME_CONTROL<BR_9600, DATA_BITS_8, NO_PARITY, STOP_1, F_CPU, SYNC_USART, OUT_FALLING_IN_RISING>::UCSRnC_mask & 0x01), uint8_t(0x01));
    }
    
    template<>
    template<>
    void testobject::test<6>()
    { 
        set_test_name("test_0006 MPCMn bit Multi-processor Communication mode");
        
        //ensure_equals("MPCMn bit 0", (0x01 & USART_RECEIVER<BUFFER_SIZE<32>, RXCI_ENABLED, MPCM_OFF>::UCSRnA_mask), 0);
        //ensure_equals("MPCMn bit 1", (0x01 & USART_RECEIVER<BUFFER_SIZE<32>, RXCI_ENABLED, MPCM_ON>::UCSRnA_mask), 1);
        
        ensure_equals("MPCMn bit 0", (0x01 & USART_RECEIVER<32, RXCI_ENABLED, MPCM_OFF>::UCSRnA_mask), 0);
        ensure_equals("MPCMn bit 1", (0x01 & USART_RECEIVER<32, RXCI_ENABLED, MPCM_ON>::UCSRnA_mask), 1);
    }
    
    template<>
    template<>
    void testobject::test<7>()
    { 
        set_test_name("test_0007 ");
        typedef USART<USART0, FRAME_CONTROL<>, USART_RECEIVER<>, USART_TRANSMITTER<16> > usart;

        char str_data[] = "abracadabra"; // 11 characters plus '\0'
        
        ensure_equals("send 1", usart::send(str_data), 11);
        ensure_equals("bytes_to_send 1", usart::TRANSMITTER::bytes_to_send, 11);
        ensure_equals("buffer 1", std::string((const char*)usart::TRANSMITTER::buffer), std::string(str_data));
        
        
        ensure_equals("send 2", usart::send(str_data), 5);
        ensure_equals("bytes_to_send 2", usart::TRANSMITTER::bytes_to_send, 16);
        ensure_equals("buffer 2", std::string((const char*)usart::TRANSMITTER::buffer), std::string("abracadabraabrac"));
        
        ensure_equals("send 3", usart::send(str_data), 0);
        ensure_equals("bytes_to_send 1", usart::TRANSMITTER::bytes_to_send, 16);
        ensure_equals("buffer 3", std::string((const char*)usart::TRANSMITTER::buffer), std::string("abracadabraabrac"));
        
        usart::TRANSMITTER::bytes_sent = 3;
        ensure_equals("send 3", usart::send(str_data), 3);
        ensure_equals("bytes_to_send 1", usart::TRANSMITTER::bytes_to_send, 16);
        ensure_equals("buffer 3", std::string((const char*)usart::TRANSMITTER::buffer), std::string("acadabraabracabr"));
    }

    template<>
    template<>
    void testobject::test<8>()
    {
        set_test_name("test_0008");
        typedef USART<USART0, FRAME_CONTROL<>, USART_RECEIVER<>, USART_TRANSMITTER<16> > usart;
        
        usart::TRANSMITTER::bytes_to_send = 0;
        for(uint8_t i = 0; i < usart::TRANSMITTER::BUFFER_SIZE; ++i)
        {
            usart::TRANSMITTER::buffer[i] = 0;
        }

        uint8_t bytes_data[] = {0x2F, 0x2E, 0x49, 0x48, 0x67, 0x26, 0x55, 0x53, 0x22, 0x4E}; // 10
        
        //std::cout << "\nTEST BYTES TO SEND : " << (unsigned)usart::TRANSMITTER::bytes_to_send << std::endl;
        
        ensure_equals("send 1", (int)usart::send(bytes_data, 6), 6);
        ensure_equals("bytes_to_send 1", usart::TRANSMITTER::bytes_to_send, 6);
        ensure_equals("buffer 1", cmp_buff(usart::TRANSMITTER::buffer, bytes_data, 6), 0);

        uint8_t bytes_test[] = {0x2F, 0x2E, 0x49, 0x48, 0x67, 0x26, 0x2F, 0x2E, 0x49, 0x48, 0x67, 0x26};
        ensure_equals("send 2", (int)usart::send(bytes_data, 6), 6);
        ensure_equals("bytes_to_send 2", usart::TRANSMITTER::bytes_to_send, 12);
        ensure_equals("buffer 2", cmp_buff(usart::TRANSMITTER::buffer, bytes_test, 12), 0);
        
        usart::TRANSMITTER::bytes_sent = 5;
        uint8_t bytes_test_0[] = {0x26, 0x2F, 0x2E, 0x49, 0x48, 0x67, 0x26, 0x2F, 0x2E, 0x49, 0x48, 0x67, 0x26, 0x55, 0x53, 0x22};
        ensure_equals("send 2", (int)usart::send(bytes_data, 10), 9);
        ensure_equals("bytes_to_send 2", usart::TRANSMITTER::bytes_to_send, 16);
        ensure_equals("buffer 2", cmp_buff(usart::TRANSMITTER::buffer, bytes_test_0, 16), 0);
        
    }

    template<>
    template<>
    void testobject::test<10>()
    {
        set_test_name("test_0010  helper USART_BAUDRATE_REGISTER");
        
        // generated with instrumental.py
        
        // SINGLE SPEED UBRR
        ensure_equals("USART_BAUDRATE_REGISTER BR_2400 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_2400, ubrr::SINGLE_SPEED_CLOCK>::value, 416);
        ensure_equals("USART_BAUDRATE_REGISTER BR_4800 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_4800, ubrr::SINGLE_SPEED_CLOCK>::value, 207);
        ensure_equals("USART_BAUDRATE_REGISTER BR_9600 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_9600, ubrr::SINGLE_SPEED_CLOCK>::value, 103);
        ensure_equals("USART_BAUDRATE_REGISTER BR_14400 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_14400, ubrr::SINGLE_SPEED_CLOCK>::value, 68);
        ensure_equals("USART_BAUDRATE_REGISTER BR_19200 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_19200, ubrr::SINGLE_SPEED_CLOCK>::value, 51);
        ensure_equals("USART_BAUDRATE_REGISTER BR_28800 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_28800, ubrr::SINGLE_SPEED_CLOCK>::value, 34);
        ensure_equals("USART_BAUDRATE_REGISTER BR_38400 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_38400, ubrr::SINGLE_SPEED_CLOCK>::value, 25);
        ensure_equals("USART_BAUDRATE_REGISTER BR_56000 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_56000, ubrr::SINGLE_SPEED_CLOCK>::value, 17);
        ensure_equals("USART_BAUDRATE_REGISTER BR_57600 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_57600, ubrr::SINGLE_SPEED_CLOCK>::value, 16);
        ensure_equals("USART_BAUDRATE_REGISTER BR_76800 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_76800, ubrr::SINGLE_SPEED_CLOCK>::value, 12);
        ensure_equals("USART_BAUDRATE_REGISTER BR_115200 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_115200, ubrr::SINGLE_SPEED_CLOCK>::value, 8);
        ensure_equals("USART_BAUDRATE_REGISTER BR_128000 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_128000, ubrr::SINGLE_SPEED_CLOCK>::value, 7);
        ensure_equals("USART_BAUDRATE_REGISTER BR_153600 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_153600, ubrr::SINGLE_SPEED_CLOCK>::value, 6);
        ensure_equals("USART_BAUDRATE_REGISTER BR_230400 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_230400, ubrr::SINGLE_SPEED_CLOCK>::value, 3);
        ensure_equals("USART_BAUDRATE_REGISTER BR_256000 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_256000, ubrr::SINGLE_SPEED_CLOCK>::value, 3);
        ensure_equals("USART_BAUDRATE_REGISTER BR_460800 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_460800, ubrr::SINGLE_SPEED_CLOCK>::value, 1);
        ensure_equals("USART_BAUDRATE_REGISTER BR_921600 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_921600, ubrr::SINGLE_SPEED_CLOCK>::value, 0);
        
        // DOUBLE SPEED UBRR
        ensure_equals("USART_BAUDRATE_REGISTER BR_2400 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_2400, ubrr::DOUBLE_SPEED_CLOCK>::value, 832);
        ensure_equals("USART_BAUDRATE_REGISTER BR_4800 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_4800, ubrr::DOUBLE_SPEED_CLOCK>::value, 416);
        ensure_equals("USART_BAUDRATE_REGISTER BR_9600 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_9600, ubrr::DOUBLE_SPEED_CLOCK>::value, 207);
        ensure_equals("USART_BAUDRATE_REGISTER BR_14400 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_14400, ubrr::DOUBLE_SPEED_CLOCK>::value, 138);
        ensure_equals("USART_BAUDRATE_REGISTER BR_19200 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_19200, ubrr::DOUBLE_SPEED_CLOCK>::value, 103);
        ensure_equals("USART_BAUDRATE_REGISTER BR_28800 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_28800, ubrr::DOUBLE_SPEED_CLOCK>::value, 68);
        ensure_equals("USART_BAUDRATE_REGISTER BR_38400 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_38400, ubrr::DOUBLE_SPEED_CLOCK>::value, 51);
        ensure_equals("USART_BAUDRATE_REGISTER BR_56000 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_56000, ubrr::DOUBLE_SPEED_CLOCK>::value, 35);
        ensure_equals("USART_BAUDRATE_REGISTER BR_57600 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_57600, ubrr::DOUBLE_SPEED_CLOCK>::value, 34);
        ensure_equals("USART_BAUDRATE_REGISTER BR_76800 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_76800, ubrr::DOUBLE_SPEED_CLOCK>::value, 25);
        ensure_equals("USART_BAUDRATE_REGISTER BR_115200 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_115200, ubrr::DOUBLE_SPEED_CLOCK>::value, 16);
        ensure_equals("USART_BAUDRATE_REGISTER BR_128000 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_128000, ubrr::DOUBLE_SPEED_CLOCK>::value, 15);
        ensure_equals("USART_BAUDRATE_REGISTER BR_153600 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_153600, ubrr::DOUBLE_SPEED_CLOCK>::value, 12);
        ensure_equals("USART_BAUDRATE_REGISTER BR_230400 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_230400, ubrr::DOUBLE_SPEED_CLOCK>::value, 8);
        ensure_equals("USART_BAUDRATE_REGISTER BR_256000 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_256000, ubrr::DOUBLE_SPEED_CLOCK>::value, 7);
        ensure_equals("USART_BAUDRATE_REGISTER BR_460800 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_460800, ubrr::DOUBLE_SPEED_CLOCK>::value, 3);
        ensure_equals("USART_BAUDRATE_REGISTER BR_921600 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE_REGISTER<BR_921600, ubrr::DOUBLE_SPEED_CLOCK>::value, 1);
    }


    template<>
    template<>
    void testobject::test<11>()
    {
        set_test_name("test_0011  helper USART_BAUDRATE");
        
        // generated with instrumental.py
        
        // SINGLE SPEED BAUDS
        ensure_equals("USART_BAUDRATE BR_2400 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_2400, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 2398);
        ensure_equals("USART_BAUDRATE BR_4800 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_4800, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 4807);
        ensure_equals("USART_BAUDRATE BR_9600 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_9600, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 9615);
        ensure_equals("USART_BAUDRATE BR_14400 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_14400, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 14492);
        ensure_equals("USART_BAUDRATE BR_19200 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_19200, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 19230);
        ensure_equals("USART_BAUDRATE BR_28800 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_28800, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 28571);
        ensure_equals("USART_BAUDRATE BR_38400 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_38400, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 38461);
        ensure_equals("USART_BAUDRATE BR_56000 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_56000, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 55555);
        ensure_equals("USART_BAUDRATE BR_57600 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_57600, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 58823);
        ensure_equals("USART_BAUDRATE BR_76800 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_76800, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 76923);
        ensure_equals("USART_BAUDRATE BR_115200 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_115200, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 111111);
        ensure_equals("USART_BAUDRATE BR_128000 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_128000, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 125000);
        ensure_equals("USART_BAUDRATE BR_153600 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_153600, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 142857);
        ensure_equals("USART_BAUDRATE BR_230400 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_230400, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 250000);
        ensure_equals("USART_BAUDRATE BR_256000 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_256000, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 250000);
        ensure_equals("USART_BAUDRATE BR_460800 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_460800, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 500000);
        ensure_equals("USART_BAUDRATE BR_921600 SINGLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_921600, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 1000000);

        // DOUBLE SPEED BAUDS
        ensure_equals("USART_BAUDRATE BR_2400 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_2400, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 2400);
        ensure_equals("USART_BAUDRATE BR_4800 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_4800, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 4796);
        ensure_equals("USART_BAUDRATE BR_9600 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_9600, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 9615);
        ensure_equals("USART_BAUDRATE BR_14400 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_14400, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 14388);
        ensure_equals("USART_BAUDRATE BR_19200 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_19200, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 19230);
        ensure_equals("USART_BAUDRATE BR_28800 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_28800, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 28985);
        ensure_equals("USART_BAUDRATE BR_38400 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_38400, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 38461);
        ensure_equals("USART_BAUDRATE BR_56000 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_56000, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 55555);
        ensure_equals("USART_BAUDRATE BR_57600 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_57600, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 57142);
        ensure_equals("USART_BAUDRATE BR_76800 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_76800, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 76923);
        ensure_equals("USART_BAUDRATE BR_115200 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_115200, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 117647);
        ensure_equals("USART_BAUDRATE BR_128000 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_128000, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 125000);
        ensure_equals("USART_BAUDRATE BR_153600 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_153600, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 153846);
        ensure_equals("USART_BAUDRATE BR_230400 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_230400, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 222222);
        ensure_equals("USART_BAUDRATE BR_256000 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_256000, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 250000);
        ensure_equals("USART_BAUDRATE BR_460800 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_460800, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 500000);
        ensure_equals("USART_BAUDRATE BR_921600 DOUBLE_SPEED_CLOCK", ubrr::USART_BAUDRATE<BR_921600, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 1000000);
    }

    template<>
    template<>
    void testobject::test<12>()
    {
        set_test_name("test_0012  helper CLOCK_SPEED_IDX");
        
        // generated with instrumental.py
        ensure_equals("CLOCK_SPEED_IDX BR_2400", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_2400, 16000000uLL>::value, 1);
        ensure_equals("CLOCK_SPEED_IDX BR_4800", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_4800, 16000000uLL>::value, 1);
        ensure_equals("CLOCK_SPEED_IDX BR_9600", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_9600, 16000000uLL>::value, 0);
        ensure_equals("CLOCK_SPEED_IDX BR_14400", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_14400, 16000000uLL>::value, 1);
        ensure_equals("CLOCK_SPEED_IDX BR_19200", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_19200, 16000000uLL>::value, 0);
        ensure_equals("CLOCK_SPEED_IDX BR_28800", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_28800, 16000000uLL>::value, 1);
        ensure_equals("CLOCK_SPEED_IDX BR_38400", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_38400, 16000000uLL>::value, 0);
        ensure_equals("CLOCK_SPEED_IDX BR_56000", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_56000, 16000000uLL>::value, 0);
        ensure_equals("CLOCK_SPEED_IDX BR_57600", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_57600, 16000000uLL>::value, 1);
        ensure_equals("CLOCK_SPEED_IDX BR_76800", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_76800, 16000000uLL>::value, 0);
        ensure_equals("CLOCK_SPEED_IDX BR_115200", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_115200, 16000000uLL>::value, 1);
        ensure_equals("CLOCK_SPEED_IDX BR_128000", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_128000, 16000000uLL>::value, 0);
        ensure_equals("CLOCK_SPEED_IDX BR_153600", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_153600, 16000000uLL>::value, 1);
        ensure_equals("CLOCK_SPEED_IDX BR_230400", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_230400, 16000000uLL>::value, 1);
        ensure_equals("CLOCK_SPEED_IDX BR_256000", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_256000, 16000000uLL>::value, 0);
        ensure_equals("CLOCK_SPEED_IDX BR_460800", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_460800, 16000000uLL>::value, 0);
        ensure_equals("CLOCK_SPEED_IDX BR_921600", (uint32_t)ubrr::CLOCK_SPEED_IDX<BR_921600, 16000000uLL>::value, 0);
    }

    template<>
    template<>
    void testobject::test<13>()
    {
        set_test_name("test_0013  helper USART_BAUDRATE_REGISTER");
        
        // generated with instrumental.py
        
        // SINGLE_SPEED_CLOCK
        ensure_equals("USART_BAUDRATE_REGISTER BR_2400 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_2400, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 416);
        ensure_equals("USART_BAUDRATE_REGISTER BR_4800 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_4800, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 207);
        ensure_equals("USART_BAUDRATE_REGISTER BR_9600 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_9600, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 103);
        ensure_equals("USART_BAUDRATE_REGISTER BR_14400 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_14400, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 68);
        ensure_equals("USART_BAUDRATE_REGISTER BR_19200 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_19200, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 51);
        ensure_equals("USART_BAUDRATE_REGISTER BR_28800 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_28800, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 34);
        ensure_equals("USART_BAUDRATE_REGISTER BR_38400 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_38400, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 25);
        ensure_equals("USART_BAUDRATE_REGISTER BR_56000 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_56000, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 17);
        ensure_equals("USART_BAUDRATE_REGISTER BR_57600 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_57600, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 16);
        ensure_equals("USART_BAUDRATE_REGISTER BR_76800 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_76800, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 12);
        ensure_equals("USART_BAUDRATE_REGISTER BR_115200 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_115200, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 8);
        ensure_equals("USART_BAUDRATE_REGISTER BR_128000 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_128000, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 7);
        ensure_equals("USART_BAUDRATE_REGISTER BR_153600 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_153600, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 6);
        ensure_equals("USART_BAUDRATE_REGISTER BR_230400 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_230400, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 3);
        ensure_equals("USART_BAUDRATE_REGISTER BR_256000 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_256000, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 3);
        ensure_equals("USART_BAUDRATE_REGISTER BR_460800 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_460800, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 1);
        ensure_equals("USART_BAUDRATE_REGISTER BR_921600 USE2X=0", ubrr::USART_BAUDRATE_REGISTER<BR_921600, ubrr::SINGLE_SPEED_CLOCK, 16000000uLL>::value, 0);
        // DOUBLE_SPEED_CLOCK
        ensure_equals("USART_BAUDRATE_REGISTER BR_2400 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_2400, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 832);
        ensure_equals("USART_BAUDRATE_REGISTER BR_4800 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_4800, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 416);
        ensure_equals("USART_BAUDRATE_REGISTER BR_9600 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_9600, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 207);
        ensure_equals("USART_BAUDRATE_REGISTER BR_14400 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_14400, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 138);
        ensure_equals("USART_BAUDRATE_REGISTER BR_19200 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_19200, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 103);
        ensure_equals("USART_BAUDRATE_REGISTER BR_28800 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_28800, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 68);
        ensure_equals("USART_BAUDRATE_REGISTER BR_38400 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_38400, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 51);
        ensure_equals("USART_BAUDRATE_REGISTER BR_56000 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_56000, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 35);
        ensure_equals("USART_BAUDRATE_REGISTER BR_57600 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_57600, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 34);
        ensure_equals("USART_BAUDRATE_REGISTER BR_76800 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_76800, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 25);
        ensure_equals("USART_BAUDRATE_REGISTER BR_115200 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_115200, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 16);
        ensure_equals("USART_BAUDRATE_REGISTER BR_128000 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_128000, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 15);
        ensure_equals("USART_BAUDRATE_REGISTER BR_153600 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_153600, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 12);
        ensure_equals("USART_BAUDRATE_REGISTER BR_230400 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_230400, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 8);
        ensure_equals("USART_BAUDRATE_REGISTER BR_256000 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_256000, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 7);
        ensure_equals("USART_BAUDRATE_REGISTER BR_460800 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_460800, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 3);
        ensure_equals("USART_BAUDRATE_REGISTER BR_921600 USE2X=1", ubrr::USART_BAUDRATE_REGISTER<BR_921600, ubrr::DOUBLE_SPEED_CLOCK, 16000000uLL>::value, 1);
        
    }

    template<>
    template<>
    void testobject::test<14>()
    {
        set_test_name("test_0014  helper USART_BAUDRATE");

        // SINGLE_SPEED_CLOCK
        ensure_equals("USART_BAUDRATE_REGISTER BR_2400 USE2X=0", ubrr::USART_BAUDRATE<BR_2400,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 2398);
        ensure_equals("USART_BAUDRATE_REGISTER BR_4800 USE2X=0", ubrr::USART_BAUDRATE<BR_4800,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 4807);
        ensure_equals("USART_BAUDRATE_REGISTER BR_9600 USE2X=0", ubrr::USART_BAUDRATE<BR_9600,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 9615);
        ensure_equals("USART_BAUDRATE_REGISTER BR_14400 USE2X=0", ubrr::USART_BAUDRATE<BR_14400,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 14492);
        ensure_equals("USART_BAUDRATE_REGISTER BR_19200 USE2X=0", ubrr::USART_BAUDRATE<BR_19200,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 19230);
        ensure_equals("USART_BAUDRATE_REGISTER BR_28800 USE2X=0", ubrr::USART_BAUDRATE<BR_28800,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 28571);
        ensure_equals("USART_BAUDRATE_REGISTER BR_38400 USE2X=0", ubrr::USART_BAUDRATE<BR_38400,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 38461);
        ensure_equals("USART_BAUDRATE_REGISTER BR_56000 USE2X=0", ubrr::USART_BAUDRATE<BR_56000,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 55555);
        ensure_equals("USART_BAUDRATE_REGISTER BR_57600 USE2X=0", ubrr::USART_BAUDRATE<BR_57600,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 58823);
        ensure_equals("USART_BAUDRATE_REGISTER BR_76800 USE2X=0", ubrr::USART_BAUDRATE<BR_76800,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 76923);
        ensure_equals("USART_BAUDRATE_REGISTER BR_115200 USE2X=0", ubrr::USART_BAUDRATE<BR_115200,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 111111);
        ensure_equals("USART_BAUDRATE_REGISTER BR_128000 USE2X=0", ubrr::USART_BAUDRATE<BR_128000,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 125000);
        ensure_equals("USART_BAUDRATE_REGISTER BR_153600 USE2X=0", ubrr::USART_BAUDRATE<BR_153600,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 142857);
        ensure_equals("USART_BAUDRATE_REGISTER BR_230400 USE2X=0", ubrr::USART_BAUDRATE<BR_230400,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 250000);
        ensure_equals("USART_BAUDRATE_REGISTER BR_256000 USE2X=0", ubrr::USART_BAUDRATE<BR_256000,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 250000);
        ensure_equals("USART_BAUDRATE_REGISTER BR_460800 USE2X=0", ubrr::USART_BAUDRATE<BR_460800,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 500000);
        ensure_equals("USART_BAUDRATE_REGISTER BR_921600 USE2X=0", ubrr::USART_BAUDRATE<BR_921600,ubrr::SINGLE_SPEED_CLOCK,16000000uLL>::value, 1000000);
        // DOUBLE_SPEED_CLOCK
        ensure_equals("USART_BAUDRATE_REGISTER BR_2400 USE2X=1", ubrr::USART_BAUDRATE<BR_2400,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 2400);
        ensure_equals("USART_BAUDRATE_REGISTER BR_4800 USE2X=1", ubrr::USART_BAUDRATE<BR_4800,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 4796);
        ensure_equals("USART_BAUDRATE_REGISTER BR_9600 USE2X=1", ubrr::USART_BAUDRATE<BR_9600,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 9615);
        ensure_equals("USART_BAUDRATE_REGISTER BR_14400 USE2X=1", ubrr::USART_BAUDRATE<BR_14400,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 14388);
        ensure_equals("USART_BAUDRATE_REGISTER BR_19200 USE2X=1", ubrr::USART_BAUDRATE<BR_19200,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 19230);
        ensure_equals("USART_BAUDRATE_REGISTER BR_28800 USE2X=1", ubrr::USART_BAUDRATE<BR_28800,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 28985);
        ensure_equals("USART_BAUDRATE_REGISTER BR_38400 USE2X=1", ubrr::USART_BAUDRATE<BR_38400,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 38461);
        ensure_equals("USART_BAUDRATE_REGISTER BR_56000 USE2X=1", ubrr::USART_BAUDRATE<BR_56000,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 55555);
        ensure_equals("USART_BAUDRATE_REGISTER BR_57600 USE2X=1", ubrr::USART_BAUDRATE<BR_57600,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 57142);
        ensure_equals("USART_BAUDRATE_REGISTER BR_76800 USE2X=1", ubrr::USART_BAUDRATE<BR_76800,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 76923);
        ensure_equals("USART_BAUDRATE_REGISTER BR_115200 USE2X=1", ubrr::USART_BAUDRATE<BR_115200,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 117647);
        ensure_equals("USART_BAUDRATE_REGISTER BR_128000 USE2X=1", ubrr::USART_BAUDRATE<BR_128000,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 125000);
        ensure_equals("USART_BAUDRATE_REGISTER BR_153600 USE2X=1", ubrr::USART_BAUDRATE<BR_153600,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 153846);
        ensure_equals("USART_BAUDRATE_REGISTER BR_230400 USE2X=1", ubrr::USART_BAUDRATE<BR_230400,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 222222);
        ensure_equals("USART_BAUDRATE_REGISTER BR_256000 USE2X=1", ubrr::USART_BAUDRATE<BR_256000,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 250000);
        ensure_equals("USART_BAUDRATE_REGISTER BR_460800 USE2X=1", ubrr::USART_BAUDRATE<BR_460800,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 500000);
        ensure_equals("USART_BAUDRATE_REGISTER BR_921600 USE2X=1", ubrr::USART_BAUDRATE<BR_921600,ubrr::DOUBLE_SPEED_CLOCK,16000000uLL>::value, 1000000);

    }


    template<>
    template<>
    void testobject::test<15>()
    {
        set_test_name("test_0015  helper USART_BRR");

        //USART_BRR<BR_2400, 16000000uLL>::value
        //ensure_equals("USART_BRR BR_2400 value", ubrr::USART_BRR<BR_2400, 16000000uLL>::value, 000);
        //ensure_equals("USART_BRR BR_2400 use2x", ubrr::USART_BRR<BR_2400, 16000000uLL>::double_speed, 000);
        
        // USART_BRR
        ensure_equals("USART_BRR BR_2400 value", ubrr::USART_BRR<BR_2400, 16000000uLL>::value, 832);
        ensure_equals("USART_BRR BR_4800 value", ubrr::USART_BRR<BR_4800, 16000000uLL>::value, 416);
        ensure_equals("USART_BRR BR_9600 value", ubrr::USART_BRR<BR_9600, 16000000uLL>::value, 103);
        ensure_equals("USART_BRR BR_14400 value", ubrr::USART_BRR<BR_14400, 16000000uLL>::value, 138);
        ensure_equals("USART_BRR BR_19200 value", ubrr::USART_BRR<BR_19200, 16000000uLL>::value, 51);
        ensure_equals("USART_BRR BR_28800 value", ubrr::USART_BRR<BR_28800, 16000000uLL>::value, 68);
        ensure_equals("USART_BRR BR_38400 value", ubrr::USART_BRR<BR_38400, 16000000uLL>::value, 25);
        ensure_equals("USART_BRR BR_56000 value", ubrr::USART_BRR<BR_56000, 16000000uLL>::value, 17);
        ensure_equals("USART_BRR BR_57600 value", ubrr::USART_BRR<BR_57600, 16000000uLL>::value, 34);
        ensure_equals("USART_BRR BR_76800 value", ubrr::USART_BRR<BR_76800, 16000000uLL>::value, 12);
        ensure_equals("USART_BRR BR_115200 value", ubrr::USART_BRR<BR_115200, 16000000uLL>::value, 16);
        ensure_equals("USART_BRR BR_128000 value", ubrr::USART_BRR<BR_128000, 16000000uLL>::value, 7);
        ensure_equals("USART_BRR BR_153600 value", ubrr::USART_BRR<BR_153600, 16000000uLL>::value, 12);
        ensure_equals("USART_BRR BR_230400 value", ubrr::USART_BRR<BR_230400, 16000000uLL>::value, 8);
        ensure_equals("USART_BRR BR_256000 value", ubrr::USART_BRR<BR_256000, 16000000uLL>::value, 3);
        ensure_equals("USART_BRR BR_460800 value", ubrr::USART_BRR<BR_460800, 16000000uLL>::value, 1);
        ensure_equals("USART_BRR BR_921600 value", ubrr::USART_BRR<BR_921600, 16000000uLL>::value, 0);
        // USE 2X
        ensure_equals("USART_BRR BR_2400 use2x", ubrr::USART_BRR<BR_2400, 16000000uLL>::double_speed, 1);
        ensure_equals("USART_BRR BR_4800 use2x", ubrr::USART_BRR<BR_4800, 16000000uLL>::double_speed, 1);
        ensure_equals("USART_BRR BR_9600 use2x", ubrr::USART_BRR<BR_9600, 16000000uLL>::double_speed, 0);
        ensure_equals("USART_BRR BR_14400 use2x", ubrr::USART_BRR<BR_14400, 16000000uLL>::double_speed, 1);
        ensure_equals("USART_BRR BR_19200 use2x", ubrr::USART_BRR<BR_19200, 16000000uLL>::double_speed, 0);
        ensure_equals("USART_BRR BR_28800 use2x", ubrr::USART_BRR<BR_28800, 16000000uLL>::double_speed, 1);
        ensure_equals("USART_BRR BR_38400 use2x", ubrr::USART_BRR<BR_38400, 16000000uLL>::double_speed, 0);
        ensure_equals("USART_BRR BR_56000 use2x", ubrr::USART_BRR<BR_56000, 16000000uLL>::double_speed, 0);
        ensure_equals("USART_BRR BR_57600 use2x", ubrr::USART_BRR<BR_57600, 16000000uLL>::double_speed, 1);
        ensure_equals("USART_BRR BR_76800 use2x", ubrr::USART_BRR<BR_76800, 16000000uLL>::double_speed, 0);
        ensure_equals("USART_BRR BR_115200 use2x", ubrr::USART_BRR<BR_115200, 16000000uLL>::double_speed, 1);
        ensure_equals("USART_BRR BR_128000 use2x", ubrr::USART_BRR<BR_128000, 16000000uLL>::double_speed, 0);
        ensure_equals("USART_BRR BR_153600 use2x", ubrr::USART_BRR<BR_153600, 16000000uLL>::double_speed, 1);
        ensure_equals("USART_BRR BR_230400 use2x", ubrr::USART_BRR<BR_230400, 16000000uLL>::double_speed, 1);
        ensure_equals("USART_BRR BR_256000 use2x", ubrr::USART_BRR<BR_256000, 16000000uLL>::double_speed, 0);
        ensure_equals("USART_BRR BR_460800 use2x", ubrr::USART_BRR<BR_460800, 16000000uLL>::double_speed, 0);
        ensure_equals("USART_BRR BR_921600 use2x", ubrr::USART_BRR<BR_921600, 16000000uLL>::double_speed, 0);
    }

}

