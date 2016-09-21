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


#include <tut/tut.hpp>
#include "ext_int_control.hpp"

namespace tut
{ 
    
    struct data{}; 
    
    typedef tut::test_group<tut::data> tg;
    tg testgroup("first_test_group");
    
    typedef tg::object testobject;
    
    
    template<>
    template<>
    void testobject::test<1>()
    { 
        set_test_name("test_0001 EIMSK");
        
        ensure_equals("EIMSK INT0", EXT_INT<INT_0, LOW_LEVEL>::ExtIntMask, 0x01);
        ensure_equals("EIMSK INT1", EXT_INT<INT_1, LOW_LEVEL>::ExtIntMask, 0x02);
        ensure_equals("EIMSK INT2", EXT_INT<INT_2, LOW_LEVEL>::ExtIntMask, 0x04);
        ensure_equals("EIMSK INT3", EXT_INT<INT_3, LOW_LEVEL>::ExtIntMask, 0x08);
        ensure_equals("EIMSK INT4", EXT_INT<INT_4, LOW_LEVEL>::ExtIntMask, 0x10);
        ensure_equals("EIMSK INT5", EXT_INT<INT_5, LOW_LEVEL>::ExtIntMask, 0x20);
        ensure_equals("EIMSK INT6", EXT_INT<INT_6, LOW_LEVEL>::ExtIntMask, 0x40);
        ensure_equals("EIMSK INT7", EXT_INT<INT_7, LOW_LEVEL>::ExtIntMask, 0x80);
    } 
    

    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002 EICRA");
        
        ensure_equals("EICRA INT_0 LOW_LEVEL", EXT_INT<INT_0, LOW_LEVEL>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_1 LOW_LEVEL", EXT_INT<INT_1, LOW_LEVEL>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_2 LOW_LEVEL", EXT_INT<INT_2, LOW_LEVEL>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_3 LOW_LEVEL", EXT_INT<INT_3, LOW_LEVEL>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_4 LOW_LEVEL", EXT_INT<INT_4, LOW_LEVEL>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_5 LOW_LEVEL", EXT_INT<INT_5, LOW_LEVEL>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_6 LOW_LEVEL", EXT_INT<INT_6, LOW_LEVEL>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_7 LOW_LEVEL", EXT_INT<INT_7, LOW_LEVEL>::EICRA_mask, 0x00);
        
        ensure_equals("EICRA INT_0 LOGICAL_CHANGE", EXT_INT<INT_0, LOGICAL_CHANGE>::EICRA_mask, 0x01);
        ensure_equals("EICRA INT_1 LOGICAL_CHANGE", EXT_INT<INT_1, LOGICAL_CHANGE>::EICRA_mask, 0x04);
        ensure_equals("EICRA INT_2 LOGICAL_CHANGE", EXT_INT<INT_2, LOGICAL_CHANGE>::EICRA_mask, 0x10);
        ensure_equals("EICRA INT_3 LOGICAL_CHANGE", EXT_INT<INT_3, LOGICAL_CHANGE>::EICRA_mask, 0x40);
        ensure_equals("EICRA INT_4 LOGICAL_CHANGE", EXT_INT<INT_4, LOGICAL_CHANGE>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_5 LOGICAL_CHANGE", EXT_INT<INT_5, LOGICAL_CHANGE>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_6 LOGICAL_CHANGE", EXT_INT<INT_6, LOGICAL_CHANGE>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_7 LOGICAL_CHANGE", EXT_INT<INT_7, LOGICAL_CHANGE>::EICRA_mask, 0x00);
        
        ensure_equals("EICRA INT_0 FALLING_EDGE", EXT_INT<INT_0, FALLING_EDGE>::EICRA_mask, 0x02);
        ensure_equals("EICRA INT_1 FALLING_EDGE", EXT_INT<INT_1, FALLING_EDGE>::EICRA_mask, 0x08);
        ensure_equals("EICRA INT_2 FALLING_EDGE", EXT_INT<INT_2, FALLING_EDGE>::EICRA_mask, 0x20);
        ensure_equals("EICRA INT_3 FALLING_EDGE", EXT_INT<INT_3, FALLING_EDGE>::EICRA_mask, 0x80);
        ensure_equals("EICRA INT_4 FALLING_EDGE", EXT_INT<INT_4, FALLING_EDGE>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_5 FALLING_EDGE", EXT_INT<INT_5, FALLING_EDGE>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_6 FALLING_EDGE", EXT_INT<INT_6, FALLING_EDGE>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_7 FALLING_EDGE", EXT_INT<INT_7, FALLING_EDGE>::EICRA_mask, 0x00);
        
        ensure_equals("EICRA INT_0 RISING_EDGE", EXT_INT<INT_0, RISING_EDGE>::EICRA_mask, 0x03);
        ensure_equals("EICRA INT_1 RISING_EDGE", EXT_INT<INT_1, RISING_EDGE>::EICRA_mask, 0x0C);
        ensure_equals("EICRA INT_2 RISING_EDGE", EXT_INT<INT_2, RISING_EDGE>::EICRA_mask, 0x30);
        ensure_equals("EICRA INT_3 RISING_EDGE", EXT_INT<INT_3, RISING_EDGE>::EICRA_mask, 0xC0);
        ensure_equals("EICRA INT_4 RISING_EDGE", EXT_INT<INT_4, RISING_EDGE>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_5 RISING_EDGE", EXT_INT<INT_5, RISING_EDGE>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_6 RISING_EDGE", EXT_INT<INT_6, RISING_EDGE>::EICRA_mask, 0x00);
        ensure_equals("EICRA INT_7 RISING_EDGE", EXT_INT<INT_7, RISING_EDGE>::EICRA_mask, 0x00);
    } 
    

    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003 EICRB");
        
        ensure_equals("EICRB INT_0 LOW_LEVEL", EXT_INT<INT_0, LOW_LEVEL>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_1 LOW_LEVEL", EXT_INT<INT_1, LOW_LEVEL>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_2 LOW_LEVEL", EXT_INT<INT_2, LOW_LEVEL>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_3 LOW_LEVEL", EXT_INT<INT_3, LOW_LEVEL>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_4 LOW_LEVEL", EXT_INT<INT_4, LOW_LEVEL>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_5 LOW_LEVEL", EXT_INT<INT_5, LOW_LEVEL>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_6 LOW_LEVEL", EXT_INT<INT_6, LOW_LEVEL>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_7 LOW_LEVEL", EXT_INT<INT_7, LOW_LEVEL>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_0 LOGICAL_CHANGE", EXT_INT<INT_0, LOGICAL_CHANGE>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_1 LOGICAL_CHANGE", EXT_INT<INT_1, LOGICAL_CHANGE>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_2 LOGICAL_CHANGE", EXT_INT<INT_2, LOGICAL_CHANGE>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_3 LOGICAL_CHANGE", EXT_INT<INT_3, LOGICAL_CHANGE>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_4 LOGICAL_CHANGE", EXT_INT<INT_4, LOGICAL_CHANGE>::EICRB_mask, 0x01);
        ensure_equals("EICRB INT_5 LOGICAL_CHANGE", EXT_INT<INT_5, LOGICAL_CHANGE>::EICRB_mask, 0x04);
        ensure_equals("EICRB INT_6 LOGICAL_CHANGE", EXT_INT<INT_6, LOGICAL_CHANGE>::EICRB_mask, 0x10);
        ensure_equals("EICRB INT_7 LOGICAL_CHANGE", EXT_INT<INT_7, LOGICAL_CHANGE>::EICRB_mask, 0x40);
        ensure_equals("EICRB INT_0 FALLING_EDGE", EXT_INT<INT_0, FALLING_EDGE>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_1 FALLING_EDGE", EXT_INT<INT_1, FALLING_EDGE>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_2 FALLING_EDGE", EXT_INT<INT_2, FALLING_EDGE>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_3 FALLING_EDGE", EXT_INT<INT_3, FALLING_EDGE>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_4 FALLING_EDGE", EXT_INT<INT_4, FALLING_EDGE>::EICRB_mask, 0x02);
        ensure_equals("EICRB INT_5 FALLING_EDGE", EXT_INT<INT_5, FALLING_EDGE>::EICRB_mask, 0x08);
        ensure_equals("EICRB INT_6 FALLING_EDGE", EXT_INT<INT_6, FALLING_EDGE>::EICRB_mask, 0x20);
        ensure_equals("EICRB INT_7 FALLING_EDGE", EXT_INT<INT_7, FALLING_EDGE>::EICRB_mask, 0x80);
        ensure_equals("EICRB INT_0 RISING_EDGE", EXT_INT<INT_0, RISING_EDGE>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_1 RISING_EDGE", EXT_INT<INT_1, RISING_EDGE>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_2 RISING_EDGE", EXT_INT<INT_2, RISING_EDGE>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_3 RISING_EDGE", EXT_INT<INT_3, RISING_EDGE>::EICRB_mask, 0x00);
        ensure_equals("EICRB INT_4 RISING_EDGE", EXT_INT<INT_4, RISING_EDGE>::EICRB_mask, 0x03);
        ensure_equals("EICRB INT_5 RISING_EDGE", EXT_INT<INT_5, RISING_EDGE>::EICRB_mask, 0x0C);
        ensure_equals("EICRB INT_6 RISING_EDGE", EXT_INT<INT_6, RISING_EDGE>::EICRB_mask, 0x30);
        ensure_equals("EICRB INT_7 RISING_EDGE", EXT_INT<INT_7, RISING_EDGE>::EICRB_mask, 0xC0);
    } 
    

    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004 EXT_INT_CONTROL");
        
        typedef EXT_INT<INT_0, FALLING_EDGE> int0;
        typedef EXT_INT<INT_2, FALLING_EDGE> int2;
        
        
        ensure_equals("EICRA INT_0 FALLING_EDGE", (uint16_t)EXT_INT_CONTROL<int0>::EICRA_value, 0x02);
        ensure_equals("EICRB INT_0 FALLING_EDGE", (uint16_t)EXT_INT_CONTROL<int0>::EICRB_value, 0x00);

        ensure_equals("EICRA INT_2 FALLING_EDGE", (uint16_t)EXT_INT_CONTROL<int2>::EICRA_value, 0x20);
        ensure_equals("EICRB INT_2 FALLING_EDGE", (uint16_t)EXT_INT_CONTROL<int2>::EICRB_value, 0x00);

    } 
} 
