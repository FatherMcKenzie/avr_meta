// Thu Dec 03 14:41:38  2015
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
#include "type_selector.hpp"

#include <stdint.h>

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
        set_test_name("test_0001");
        
        //mpl::type_selector s;
        ensure_equals("message", sizeof(mpl::type_selector<1, uint8_t, uint64_t>::type), 1);
        ensure_equals("message", sizeof(mpl::type_selector<0, uint8_t, uint64_t>::type), 8);
    } 
    
    
#if 0
    
    
    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002");
        
        mpl::type_selector s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003");
        
        mpl::type_selector s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004");
        
        mpl::type_selector s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<5>()
    { 
        set_test_name("test_0005");
        
        mpl::type_selector s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<6>()
    { 
        set_test_name("test_0006");
        
        mpl::type_selector s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<7>()
    { 
        set_test_name("test_0007");
        
        mpl::type_selector s;
        ensure_equals("message", 42, 42);
    } 
    
    
#endif
} 
