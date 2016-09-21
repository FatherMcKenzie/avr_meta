// Mon Jul 27 22:23:50  2015
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
#include "avr_debug.hpp"

namespace tut
{ 
    
    struct data
    { 
    }; 
    
    typedef tut::test_group<tut::data> tg;
    tg testgroup("first_test_group");
    
    typedef tg::object testobject;
    
#if 0
    template<>
    template<>
    void testobject::test<1>()
    { 
        set_test_name("test_0001");
        
        ::avr_debug s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002");
        
        ::avr_debug s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003");
        
        ::avr_debug s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004");
        
        ::avr_debug s;
        ensure_equals("message", 42, 42);
    } 
#endif
} 
