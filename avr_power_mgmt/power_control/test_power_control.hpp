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

#include <tut/tut.hpp>
#include "power_control.hpp"

namespace tut
{ 
    
    struct data
    { 
    }; 
    
    typedef tut::test_group<tut::data> tg;
    tg testgroup("first_test_group");
    
    typedef tg::object testobject;
    
    
    template<>
    template<>
    void testobject::test<1>()
    { 
        set_test_name("test_0001 PWR_CONTROL");
        
        ensure_equals("test PWR_CONTROL IDLE SLEEP_DISABLE",                PWR_CONTROL<IDLE,               SLEEP_DISABLE>::SMCR_value, uint8_t(0x00));
        ensure_equals("test PWR_CONTROL ADC_NOISE_REDUCTION SLEEP_DISABLE", PWR_CONTROL<ADC_NOISE_REDUCTION,SLEEP_DISABLE>::SMCR_value, uint8_t(0x02));
        ensure_equals("test PWR_CONTROL POWER_DOWN SLEEP_DISABLE",          PWR_CONTROL<POWER_DOWN,         SLEEP_DISABLE>::SMCR_value, uint8_t(0x04));
        ensure_equals("test PWR_CONTROL POWER_SAFE SLEEP_DISABLE",          PWR_CONTROL<POWER_SAFE,         SLEEP_DISABLE>::SMCR_value, uint8_t(0x06));
        ensure_equals("test PWR_CONTROL STANDBY SLEEP_DISABLE",             PWR_CONTROL<STANDBY,            SLEEP_DISABLE>::SMCR_value, uint8_t(0x0C));
        ensure_equals("test PWR_CONTROL EXTENDED_STANDBY SLEEP_DISABLE",    PWR_CONTROL<EXTENDED_STANDBY,   SLEEP_DISABLE>::SMCR_value, uint8_t(0x0E));

        ensure_equals("test PWR_CONTROL IDLE SLEEP_ENABLE",                PWR_CONTROL<IDLE,                SLEEP_ENABLE>::SMCR_value,  uint8_t(0x01));
        ensure_equals("test PWR_CONTROL ADC_NOISE_REDUCTION SLEEP_ENABLE", PWR_CONTROL<ADC_NOISE_REDUCTION, SLEEP_ENABLE>::SMCR_value,  uint8_t(0x03));
        ensure_equals("test PWR_CONTROL POWER_DOWN SLEEP_ENABLE",          PWR_CONTROL<POWER_DOWN,          SLEEP_ENABLE>::SMCR_value,  uint8_t(0x05));
        ensure_equals("test PWR_CONTROL POWER_SAFE SLEEP_ENABLE",          PWR_CONTROL<POWER_SAFE,          SLEEP_ENABLE>::SMCR_value,  uint8_t(0x07));
        ensure_equals("test PWR_CONTROL STANDBY SLEEP_ENABLE",             PWR_CONTROL<STANDBY,             SLEEP_ENABLE>::SMCR_value,  uint8_t(0x0D));
        ensure_equals("test PWR_CONTROL EXTENDED_STANDBY SLEEP_ENABLE",    PWR_CONTROL<EXTENDED_STANDBY,    SLEEP_ENABLE>::SMCR_value,  uint8_t(0x0F));
    } 
    

    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002");
#if 0
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
#endif
        ensure_equals("PRR0", USE_DEVICES<>::PRR0_value, 0xFF);
        ensure_equals("PRR1", USE_DEVICES<>::PRR1_value, 0xFF);

        ensure_equals("PRR0 PR_TWI", (uint16_t)USE_DEVICES<PR_TWI>::PRR0_value, 0x7F);
        ensure_equals("PRR1 PR_TWI", USE_DEVICES<PR_TWI>::PRR1_value, 0xFF);

        ensure_equals("PRR0 PR_TIMER2", USE_DEVICES<PR_TIMER2>::PRR0_value, 0xBF);
        ensure_equals("PRR1 PR_TIMER2", USE_DEVICES<PR_TIMER2>::PRR1_value, 0xFF);

        ensure_equals("PRR0 PR_TIMER0", USE_DEVICES<PR_TIMER0>::PRR0_value, 0xDF);
        ensure_equals("PRR1 PR_TIMER0", USE_DEVICES<PR_TIMER0>::PRR1_value, 0xFF);

        ensure_equals("PRR0 PR_TIMER1", USE_DEVICES<PR_TIMER1>::PRR0_value, 0xF7);
        ensure_equals("PRR1 PR_TIMER1", USE_DEVICES<PR_TIMER1>::PRR1_value, 0xFF);

        ensure_equals("PRR0 PR_SPI", USE_DEVICES<PR_SPI>::PRR0_value, 0xFB);
        ensure_equals("PRR1 PR_SPI", USE_DEVICES<PR_SPI>::PRR1_value, 0xFF);

        ensure_equals("PRR0 PR_USART0", USE_DEVICES<PR_USART0>::PRR0_value, 0xFD);
        ensure_equals("PRR1 PR_USART0", USE_DEVICES<PR_USART0>::PRR1_value, 0xFF);

        ensure_equals("PRR0 PR_ADC", USE_DEVICES<PR_ADC>::PRR0_value, 0xFE);
        ensure_equals("PRR1 PR_ADC", USE_DEVICES<PR_ADC>::PRR1_value, 0xFF);

        ensure_equals("PRR0 PR_TIMER5", USE_DEVICES<PR_TIMER5>::PRR0_value, 0xFF);
        ensure_equals("PRR1 PR_TIMER5", (uint16_t)USE_DEVICES<PR_TIMER5>::PRR1_value, 0xDF);

        ensure_equals("PRR0 PR_TIMER4", USE_DEVICES<PR_TIMER4>::PRR0_value, 0xFF);
        ensure_equals("PRR1 PR_TIMER4", USE_DEVICES<PR_TIMER4>::PRR1_value, 0xEF);

        ensure_equals("PRR0 PR_TIMER3", USE_DEVICES<PR_TIMER3>::PRR0_value, 0xFF);
        ensure_equals("PRR1 PR_TIMER3", USE_DEVICES<PR_TIMER3>::PRR1_value, 0xF7);

        ensure_equals("PRR0 PR_USART3", USE_DEVICES<PR_USART3>::PRR0_value, 0xFF);
        ensure_equals("PRR1 PR_USART3", USE_DEVICES<PR_USART3>::PRR1_value, 0xFB);

        ensure_equals("PRR0 PR_USART2", USE_DEVICES<PR_USART2>::PRR0_value, 0xFF);
        ensure_equals("PRR1 PR_USART2", USE_DEVICES<PR_USART2>::PRR1_value, 0xFD);

        ensure_equals("PRR0 PR_USART1", USE_DEVICES<PR_USART1>::PRR0_value, 0xFF);
        ensure_equals("PRR1 PR_USART1", USE_DEVICES<PR_USART1>::PRR1_value, 0xFE);
    } 
    
#if 0
    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003");
        
        ::power_control s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004");
        
        ::power_control s;
        ensure_equals("message", 42, 42);
    } 
#endif
} 
