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

#include <tut/tut.hpp>
#include "pin_ch_int_control.hpp"

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
        set_test_name("test_0001 PIN_CH_INT");
        
        ensure_equals("PIN_CH_INT PCINT_00 PCICR", PIN_CH_INT<PCINT_00>::PCICR_mask, 0x01);
        ensure_equals("PIN_CH_INT PCINT_01 PCICR", PIN_CH_INT<PCINT_01>::PCICR_mask, 0x01);
        ensure_equals("PIN_CH_INT PCINT_02 PCICR", PIN_CH_INT<PCINT_02>::PCICR_mask, 0x01);
        ensure_equals("PIN_CH_INT PCINT_03 PCICR", PIN_CH_INT<PCINT_03>::PCICR_mask, 0x01);
        ensure_equals("PIN_CH_INT PCINT_04 PCICR", PIN_CH_INT<PCINT_04>::PCICR_mask, 0x01);
        ensure_equals("PIN_CH_INT PCINT_05 PCICR", PIN_CH_INT<PCINT_05>::PCICR_mask, 0x01);
        ensure_equals("PIN_CH_INT PCINT_06 PCICR", PIN_CH_INT<PCINT_06>::PCICR_mask, 0x01);
        ensure_equals("PIN_CH_INT PCINT_07 PCICR", PIN_CH_INT<PCINT_07>::PCICR_mask, 0x01);
        ensure_equals("PIN_CH_INT PCINT_08 PCICR", PIN_CH_INT<PCINT_08>::PCICR_mask, 0x02);
        ensure_equals("PIN_CH_INT PCINT_09 PCICR", PIN_CH_INT<PCINT_09>::PCICR_mask, 0x02);
        ensure_equals("PIN_CH_INT PCINT_10 PCICR", PIN_CH_INT<PCINT_10>::PCICR_mask, 0x02);
        ensure_equals("PIN_CH_INT PCINT_11 PCICR", PIN_CH_INT<PCINT_11>::PCICR_mask, 0x02);
        ensure_equals("PIN_CH_INT PCINT_12 PCICR", PIN_CH_INT<PCINT_12>::PCICR_mask, 0x02);
        ensure_equals("PIN_CH_INT PCINT_13 PCICR", PIN_CH_INT<PCINT_13>::PCICR_mask, 0x02);
        ensure_equals("PIN_CH_INT PCINT_14 PCICR", PIN_CH_INT<PCINT_14>::PCICR_mask, 0x02);
        ensure_equals("PIN_CH_INT PCINT_15 PCICR", PIN_CH_INT<PCINT_15>::PCICR_mask, 0x02);
        ensure_equals("PIN_CH_INT PCINT_16 PCICR", PIN_CH_INT<PCINT_16>::PCICR_mask, 0x04);
        ensure_equals("PIN_CH_INT PCINT_17 PCICR", PIN_CH_INT<PCINT_17>::PCICR_mask, 0x04);
        ensure_equals("PIN_CH_INT PCINT_18 PCICR", PIN_CH_INT<PCINT_18>::PCICR_mask, 0x04);
        ensure_equals("PIN_CH_INT PCINT_19 PCICR", PIN_CH_INT<PCINT_19>::PCICR_mask, 0x04);
        ensure_equals("PIN_CH_INT PCINT_20 PCICR", PIN_CH_INT<PCINT_20>::PCICR_mask, 0x04);
        ensure_equals("PIN_CH_INT PCINT_21 PCICR", PIN_CH_INT<PCINT_21>::PCICR_mask, 0x04);
        ensure_equals("PIN_CH_INT PCINT_22 PCICR", PIN_CH_INT<PCINT_22>::PCICR_mask, 0x04);
        ensure_equals("PIN_CH_INT PCINT_23 PCICR", PIN_CH_INT<PCINT_23>::PCICR_mask, 0x04);
    }
 

    
    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002 PIN_CH_INT");
        
        ensure_equals("PIN_CH_INT PCINT_00 PCMSK0", PIN_CH_INT<PCINT_00>::PCMSK0_mask, 0x01);
        ensure_equals("PIN_CH_INT PCINT_01 PCMSK0", PIN_CH_INT<PCINT_01>::PCMSK0_mask, 0x02);
        ensure_equals("PIN_CH_INT PCINT_02 PCMSK0", PIN_CH_INT<PCINT_02>::PCMSK0_mask, 0x04);
        ensure_equals("PIN_CH_INT PCINT_03 PCMSK0", PIN_CH_INT<PCINT_03>::PCMSK0_mask, 0x08);
        ensure_equals("PIN_CH_INT PCINT_04 PCMSK0", PIN_CH_INT<PCINT_04>::PCMSK0_mask, 0x10);
        ensure_equals("PIN_CH_INT PCINT_05 PCMSK0", PIN_CH_INT<PCINT_05>::PCMSK0_mask, 0x20);
        ensure_equals("PIN_CH_INT PCINT_06 PCMSK0", PIN_CH_INT<PCINT_06>::PCMSK0_mask, 0x40);
        ensure_equals("PIN_CH_INT PCINT_07 PCMSK0", PIN_CH_INT<PCINT_07>::PCMSK0_mask, 0x80);
        ensure_equals("PIN_CH_INT PCINT_08 PCMSK0", PIN_CH_INT<PCINT_08>::PCMSK0_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_09 PCMSK0", PIN_CH_INT<PCINT_09>::PCMSK0_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_10 PCMSK0", PIN_CH_INT<PCINT_10>::PCMSK0_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_11 PCMSK0", PIN_CH_INT<PCINT_11>::PCMSK0_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_12 PCMSK0", PIN_CH_INT<PCINT_12>::PCMSK0_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_13 PCMSK0", PIN_CH_INT<PCINT_13>::PCMSK0_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_14 PCMSK0", PIN_CH_INT<PCINT_14>::PCMSK0_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_15 PCMSK0", PIN_CH_INT<PCINT_15>::PCMSK0_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_16 PCMSK0", PIN_CH_INT<PCINT_16>::PCMSK0_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_17 PCMSK0", PIN_CH_INT<PCINT_17>::PCMSK0_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_18 PCMSK0", PIN_CH_INT<PCINT_18>::PCMSK0_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_19 PCMSK0", PIN_CH_INT<PCINT_19>::PCMSK0_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_20 PCMSK0", PIN_CH_INT<PCINT_20>::PCMSK0_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_21 PCMSK0", PIN_CH_INT<PCINT_21>::PCMSK0_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_22 PCMSK0", PIN_CH_INT<PCINT_22>::PCMSK0_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_23 PCMSK0", PIN_CH_INT<PCINT_23>::PCMSK0_mask, 0x00);

    } 
    
    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003 PIN_CH_INT");
        
        ensure_equals("PIN_CH_INT PCINT_00 PCMSK1", PIN_CH_INT<PCINT_00>::PCMSK1_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_01 PCMSK1", PIN_CH_INT<PCINT_01>::PCMSK1_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_02 PCMSK1", PIN_CH_INT<PCINT_02>::PCMSK1_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_03 PCMSK1", PIN_CH_INT<PCINT_03>::PCMSK1_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_04 PCMSK1", PIN_CH_INT<PCINT_04>::PCMSK1_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_05 PCMSK1", PIN_CH_INT<PCINT_05>::PCMSK1_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_06 PCMSK1", PIN_CH_INT<PCINT_06>::PCMSK1_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_07 PCMSK1", PIN_CH_INT<PCINT_07>::PCMSK1_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_08 PCMSK1", PIN_CH_INT<PCINT_08>::PCMSK1_mask, 0x01);
        ensure_equals("PIN_CH_INT PCINT_09 PCMSK1", PIN_CH_INT<PCINT_09>::PCMSK1_mask, 0x02);
        ensure_equals("PIN_CH_INT PCINT_10 PCMSK1", PIN_CH_INT<PCINT_10>::PCMSK1_mask, 0x04);
        ensure_equals("PIN_CH_INT PCINT_11 PCMSK1", PIN_CH_INT<PCINT_11>::PCMSK1_mask, 0x08);
        ensure_equals("PIN_CH_INT PCINT_12 PCMSK1", PIN_CH_INT<PCINT_12>::PCMSK1_mask, 0x10);
        ensure_equals("PIN_CH_INT PCINT_13 PCMSK1", PIN_CH_INT<PCINT_13>::PCMSK1_mask, 0x20);
        ensure_equals("PIN_CH_INT PCINT_14 PCMSK1", PIN_CH_INT<PCINT_14>::PCMSK1_mask, 0x40);
        ensure_equals("PIN_CH_INT PCINT_15 PCMSK1", PIN_CH_INT<PCINT_15>::PCMSK1_mask, 0x80);
        ensure_equals("PIN_CH_INT PCINT_16 PCMSK1", PIN_CH_INT<PCINT_16>::PCMSK1_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_17 PCMSK1", PIN_CH_INT<PCINT_17>::PCMSK1_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_18 PCMSK1", PIN_CH_INT<PCINT_18>::PCMSK1_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_19 PCMSK1", PIN_CH_INT<PCINT_19>::PCMSK1_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_20 PCMSK1", PIN_CH_INT<PCINT_20>::PCMSK1_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_21 PCMSK1", PIN_CH_INT<PCINT_21>::PCMSK1_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_22 PCMSK1", PIN_CH_INT<PCINT_22>::PCMSK1_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_23 PCMSK1", PIN_CH_INT<PCINT_23>::PCMSK1_mask, 0x00);

    } 
    
    
    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004 PIN_CH_INT");
        
        ensure_equals("PIN_CH_INT PCINT_00 PCMSK2", PIN_CH_INT<PCINT_00>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_01 PCMSK2", PIN_CH_INT<PCINT_01>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_02 PCMSK2", PIN_CH_INT<PCINT_02>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_03 PCMSK2", PIN_CH_INT<PCINT_03>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_04 PCMSK2", PIN_CH_INT<PCINT_04>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_05 PCMSK2", PIN_CH_INT<PCINT_05>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_06 PCMSK2", PIN_CH_INT<PCINT_06>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_07 PCMSK2", PIN_CH_INT<PCINT_07>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_08 PCMSK2", PIN_CH_INT<PCINT_08>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_09 PCMSK2", PIN_CH_INT<PCINT_09>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_10 PCMSK2", PIN_CH_INT<PCINT_10>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_11 PCMSK2", PIN_CH_INT<PCINT_11>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_12 PCMSK2", PIN_CH_INT<PCINT_12>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_13 PCMSK2", PIN_CH_INT<PCINT_13>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_14 PCMSK2", PIN_CH_INT<PCINT_14>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_15 PCMSK2", PIN_CH_INT<PCINT_15>::PCMSK2_mask, 0x00);
        ensure_equals("PIN_CH_INT PCINT_16 PCMSK2", PIN_CH_INT<PCINT_16>::PCMSK2_mask, 0x01);
        ensure_equals("PIN_CH_INT PCINT_17 PCMSK2", PIN_CH_INT<PCINT_17>::PCMSK2_mask, 0x02);
        ensure_equals("PIN_CH_INT PCINT_18 PCMSK2", PIN_CH_INT<PCINT_18>::PCMSK2_mask, 0x04);
        ensure_equals("PIN_CH_INT PCINT_19 PCMSK2", PIN_CH_INT<PCINT_19>::PCMSK2_mask, 0x08);
        ensure_equals("PIN_CH_INT PCINT_20 PCMSK2", PIN_CH_INT<PCINT_20>::PCMSK2_mask, 0x10);
        ensure_equals("PIN_CH_INT PCINT_21 PCMSK2", PIN_CH_INT<PCINT_21>::PCMSK2_mask, 0x20);
        ensure_equals("PIN_CH_INT PCINT_22 PCMSK2", PIN_CH_INT<PCINT_22>::PCMSK2_mask, 0x40);
        ensure_equals("PIN_CH_INT PCINT_23 PCMSK2", PIN_CH_INT<PCINT_23>::PCMSK2_mask, 0x80);

    } 

} 
