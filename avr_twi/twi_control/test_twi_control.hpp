// Sun Mar 15 01:57:53  2015
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
#include "twi_control.hpp"
#include "twi_prescaler_helper.hpp"


namespace tut
{ 
    
    struct data
    { 
    }; 
    
    typedef tut::test_group<tut::data> tg;
    tg testgroup("first_test_group");
    
    typedef tg::object testobject;
    
    
#if 0

// twi_clock.py output

-------------------------------------------------------
TWBR:  792 =  SCL_TEST:  250000  TWPS:   1, SCL:    10000,  CPU: 16000000 : ERROR : 2400.00
TWBR:  198 =  SCL_TEST:   10000  TWPS:   4, SCL:    10000,  CPU: 16000000 : ERROR :   0.00
TWBR:   49 =  SCL_TEST:   10101  TWPS:  16, SCL:    10000,  CPU: 16000000 : ERROR :   1.01
TWBR:   12 =  SCL_TEST:   10309  TWPS:  64, SCL:    10000,  CPU: 16000000 : ERROR :   3.09
-------------------------------------------------------
TWBR:  152 =  SCL_TEST:   50000  TWPS:   1, SCL:    50000,  CPU: 16000000 : ERROR :   0.00
TWBR:   38 =  SCL_TEST:   50000  TWPS:   4, SCL:    50000,  CPU: 16000000 : ERROR :   0.00
TWBR:    9 =  SCL_TEST:   52631  TWPS:  16, SCL:    50000,  CPU: 16000000 : ERROR :   5.26
TWBR:    2 =  SCL_TEST:   58823  TWPS:  64, SCL:    50000,  CPU: 16000000 : ERROR :  17.65
-------------------------------------------------------
TWBR:   72 =  SCL_TEST:  100000  TWPS:   1, SCL:   100000,  CPU: 16000000 : ERROR :   0.00
TWBR:   18 =  SCL_TEST:  100000  TWPS:   4, SCL:   100000,  CPU: 16000000 : ERROR :   0.00
TWBR:    4 =  SCL_TEST:  111111  TWPS:  16, SCL:   100000,  CPU: 16000000 : ERROR :  11.11
TWBR:    1 =  SCL_TEST:  111111  TWPS:  64, SCL:   100000,  CPU: 16000000 : ERROR :  11.11
-------------------------------------------------------
TWBR:   18 =  SCL_TEST:  307692  TWPS:   1, SCL:   300000,  CPU: 16000000 : ERROR :   2.56
TWBR:    4 =  SCL_TEST:  333333  TWPS:   4, SCL:   300000,  CPU: 16000000 : ERROR :  11.11
TWBR:    1 =  SCL_TEST:  333333  TWPS:  16, SCL:   300000,  CPU: 16000000 : ERROR :  11.11
TWBR:    0 =  SCL_TEST: 1000000  TWPS:  64, SCL:   300000,  CPU: 16000000 : ERROR : 233.33
-------------------------------------------------------
TWBR:   12 =  SCL_TEST:  400000  TWPS:   1, SCL:   400000,  CPU: 16000000 : ERROR :   0.00
TWBR:    3 =  SCL_TEST:  400000  TWPS:   4, SCL:   400000,  CPU: 16000000 : ERROR :   0.00
TWBR:    0 =  SCL_TEST: 1000000  TWPS:  16, SCL:   400000,  CPU: 16000000 : ERROR : 150.00
TWBR:    0 =  SCL_TEST: 1000000  TWPS:  64, SCL:   400000,  CPU: 16000000 : ERROR : 150.00

#endif
    
    template<>
    template<>
    void testobject::test<1>()
    { 
        set_test_name("test_0001");
        
        //twi_control<100> s;
        ensure_equals("TWPS value 0", twi_control::HV_TWPS_0,  1); //0
        ensure_equals("TWPS value 1", twi_control::HV_TWPS_1,  4); //1
        ensure_equals("TWPS value 2", twi_control::HV_TWPS_2, 16); //2
        ensure_equals("TWPS value 3", twi_control::HV_TWPS_3, 64); //3 
    } 
    
    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002");
        
        ensure_equals("twi prescaler  10000", (uint32_t)twi_control::TWI_PRESCALER< 10000, 16000000>::value, 1);
        ensure_equals("twi prescaler  50000", (uint32_t)twi_control::TWI_PRESCALER< 50000, 16000000>::value, 0);
        ensure_equals("twi prescaler 100000", (uint32_t)twi_control::TWI_PRESCALER<100000, 16000000>::value, 0);
        ensure_equals("twi prescaler 300000", (uint32_t)twi_control::TWI_PRESCALER<300000, 16000000>::value, 0);
        ensure_equals("twi prescaler 400000", (uint32_t)twi_control::TWI_PRESCALER<400000, 16000000>::value, 0);
    } 
    
    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003");
        /*
            for cpu_clock_frequency in 20000000, 12000000, 7000000:
            for scl_freq in 25000, 75000, 100000, 150000, 300000, 400000:
        */

        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<25000,  20000000>::TWBR_value, 98);
        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<75000,  20000000>::TWBR_value, 125);
        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<100000, 20000000>::TWBR_value, 92);
        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<150000, 20000000>::TWBR_value, 58);
        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<300000, 20000000>::TWBR_value, 25);
        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<400000, 20000000>::TWBR_value, 17);

        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<25000,  12000000>::TWBR_value, 232);
        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<75000,  12000000>::TWBR_value, 72);
        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<100000, 12000000>::TWBR_value, 52);
        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<150000, 12000000>::TWBR_value, 32);
        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<300000, 12000000>::TWBR_value, 12);
        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<400000, 12000000>::TWBR_value, 7);

        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<25000,   7000000>::TWBR_value, 132);
        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<75000,   7000000>::TWBR_value, 38);
        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<100000,  7000000>::TWBR_value, 27);
        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<150000,  7000000>::TWBR_value, 15);
        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<300000,  7000000>::TWBR_value, 3);
        ensure_equals("TWI_CLOCK ", (uint32_t)twi_control::TWI_CLOCK<400000,  7000000>::TWBR_value, 0);

    } 
    
#if 0

    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004");
        
        ::twi_control s;
        ensure_equals("message", 42, 42);
    } 
#endif
} 
