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

#include <tut/tut.hpp>
#include "pin_control.hpp"
#include "port_helper.hpp"

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
        set_test_name("test_0001 PIN_MASK");
        
        //pin::PIN_CONTROL<PORT_D> s;
       
        typedef pin::PIN_MASK<
                        PIN<BIT_7, OUT>,
                        PIN<BIT_6, IN>,
                        PIN<BIT_0, IN_PULL_UP>,
                        PIN<BIT_1, IN_PULL_UP>
                > BIT_TEST;
        
        ensure_equals("DIRECTION_MASK", BIT_TEST::DIRECTION_MASK, 0x80);
        ensure_equals("PULL_UP_MASK",   BIT_TEST::PULL_UP_MASK,   0x03);
    } 
    
#if 0
    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002");
        
        pin::pin_control s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003");
        
        pin::pin_control s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004");
        
        pin::pin_control s;
        ensure_equals("message", 42, 42);
    } 
#endif
} 
