// Thu May 12 14:44:22  2016
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//

#include <stdint.h>
#include <tut/tut.hpp>
#include "is_signed.hpp"

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
        
        ensure_equals("IS_SIGNED<int8_t >::value", misc::IS_SIGNED<int8_t >::value, true);
        ensure_equals("IS_SIGNED<int16_t>::value", misc::IS_SIGNED<int16_t>::value, true);
        ensure_equals("IS_SIGNED<int32_t>::value", misc::IS_SIGNED<int32_t>::value, true);
        ensure_equals("IS_SIGNED<int64_t>::value", misc::IS_SIGNED<int64_t>::value, true);
        
        ensure_equals("IS_SIGNED<uint8_t >::value", misc::IS_SIGNED<uint8_t >::value, false);
        ensure_equals("IS_SIGNED<uint16_t>::value", misc::IS_SIGNED<uint16_t>::value, false);
        ensure_equals("IS_SIGNED<uint32_t>::value", misc::IS_SIGNED<uint32_t>::value, false);
        ensure_equals("IS_SIGNED<uint64_t>::value", misc::IS_SIGNED<uint64_t>::value, false);
    } 
    
    
#if 0
    
    
    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002");
        
        misc::is_signed s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003");
        
        misc::is_signed s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004");
        
        misc::is_signed s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<5>()
    { 
        set_test_name("test_0005");
        
        misc::is_signed s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<6>()
    { 
        set_test_name("test_0006");
        
        misc::is_signed s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<7>()
    { 
        set_test_name("test_0007");
        
        misc::is_signed s;
        ensure_equals("message", 42, 42);
    } 
    
    
#endif
} 
