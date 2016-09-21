// Sun May 25 21:56:37  2014
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
#include <stdint.h>
#include "power.hpp"


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
    void testobject::test<0>()
    {
        set_test_name("test_0001 POWER OF TEN");
        ensure_equals("misc::power<0, 0>", misc::power<0, 0>::value, 0);
        ensure_equals("misc::power<0, 1>", misc::power<0, 1>::value, 0);
        ensure_equals("misc::power<0, 2>", misc::power<0, 2>::value, 0);
        ensure_equals("misc::power<0, 3>", misc::power<0, 3>::value, 0);
        ensure_equals("misc::power<1, 0>", misc::power<1, 0>::value, 1);
        ensure_equals("misc::power<1, 1>", misc::power<1, 1>::value, 1);
        ensure_equals("misc::power<1, 2>", misc::power<1, 2>::value, 1);
        ensure_equals("misc::power<1, 3>", misc::power<1, 3>::value, 1);
        ensure_equals("misc::power<2, 0>", misc::power<2, 0>::value, 1);
        ensure_equals("misc::power<2, 1>", misc::power<2, 1>::value, 2);
        ensure_equals("misc::power<2, 2>", misc::power<2, 2>::value, 4);
        ensure_equals("misc::power<2, 3>", misc::power<2, 3>::value, 8);
    }

    template<>
    template<>
    void testobject::test<1>()
    { 
        set_test_name("test_0001 POWER OF TEN");
        ensure_equals("misc::power<10, 0>", misc::power<10, 0>::value, 1);
        ensure_equals("misc::power<10, 1>", misc::power<10, 1>::value, 10);
        ensure_equals("misc::power<10, 2>", misc::power<10, 2>::value, 10 * 10);
        ensure_equals("misc::power<10, 3>", misc::power<10, 3>::value, 10 * 10 * 10);
        ensure_equals("misc::power<10, 4>", misc::power<10, 4>::value, 10 * 10 * 10 * 10);
        ensure_equals("misc::power<10, 5>", misc::power<10, 5>::value, 10 * 10 * 10 * 10 * 10);
        ensure_equals("misc::power<10, 6>", misc::power<10, 6>::value, 10 * 10 * 10 * 10 * 10 * 10);
        ensure_equals("misc::power<10, 7>", misc::power<10, 7>::value, 10 * 10 * 10 * 10 * 10 * 10 * 10);
    } 

    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002 POWER OF TWO");
        
        ensure_equals("misc::power<2, 0>", misc::power<2, 0>::value, 1);
        ensure_equals("misc::power<2, 1>", misc::power<2, 1>::value, 2);
        ensure_equals("misc::power<2, 2>", misc::power<2, 2>::value, 2 * 2);
        ensure_equals("misc::power<2, 3>", misc::power<2, 3>::value, 2 * 2 * 2);
        ensure_equals("misc::power<2, 4>", misc::power<2, 4>::value, 2 * 2 * 2 * 2);
        ensure_equals("misc::power<2, 5>", misc::power<2, 5>::value, 2 * 2 * 2 * 2 * 2);
        ensure_equals("misc::power<2, 6>", misc::power<2, 6>::value, 2 * 2 * 2 * 2 * 2 * 2);
        ensure_equals("misc::power<2, 7>", misc::power<2, 7>::value, 2 * 2 * 2 * 2 * 2 * 2 * 2);
        ensure_equals("misc::power<2, 8>", misc::power<2, 8>::value, 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2);
    } 
    
    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003 POWER OF THREE");
        
        ensure_equals("misc::power<3, 0>", misc::power<3, 0>::value, 1);
        ensure_equals("misc::power<3, 1>", misc::power<3, 1>::value, 3);
        ensure_equals("misc::power<3, 2>", misc::power<3, 2>::value, 3 * 3);
        ensure_equals("misc::power<3, 3>", misc::power<3, 3>::value, 3 * 3 * 3);
        ensure_equals("misc::power<3, 4>", misc::power<3, 4>::value, 3 * 3 * 3 * 3);
        ensure_equals("misc::power<3, 5>", misc::power<3, 5>::value, 3 * 3 * 3 * 3 * 3);
        ensure_equals("misc::power<3, 6>", misc::power<3, 6>::value, 3 * 3 * 3 * 3 * 3 * 3);
        ensure_equals("misc::power<3, 7>", misc::power<3, 7>::value, 3 * 3 * 3 * 3 * 3 * 3 * 3);
        ensure_equals("misc::power<3, 8>", misc::power<3, 8>::value, 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3);
    } 
    
    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004 POWER OF FOUR");
        
        ensure_equals("misc::power<4, 0>", misc::power<4, 0>::value, 1);
        ensure_equals("misc::power<4, 1>", misc::power<4, 1>::value, 4);
        ensure_equals("misc::power<4, 2>", misc::power<4, 2>::value, 4 * 4);
        ensure_equals("misc::power<4, 3>", misc::power<4, 3>::value, 4 * 4 * 4);
        ensure_equals("misc::power<4, 4>", misc::power<4, 4>::value, 4 * 4 * 4 * 4);
        ensure_equals("misc::power<4, 5>", misc::power<4, 5>::value, 4 * 4 * 4 * 4 * 4);
        ensure_equals("misc::power<4, 6>", misc::power<4, 6>::value, 4 * 4 * 4 * 4 * 4 * 4);
        ensure_equals("misc::power<4, 7>", misc::power<4, 7>::value, 4 * 4 * 4 * 4 * 4 * 4 * 4);
        ensure_equals("misc::power<4, 8>", misc::power<4, 8>::value, 4 * 4 * 4 * 4 * 4 * 4 * 4 * 4);
        ensure_equals("misc::power<4, 9>", misc::power<4, 9>::value, 4 * 4 * 4 * 4 * 4 * 4 * 4 * 4 * 4);
        ensure_equals("misc::power<4, 10>", misc::power<4, 10>::value, 4 * 4 * 4 * 4 * 4 * 4 * 4 * 4 * 4 * 4);
    }

    template<>
    template<>
    void testobject::test<8>()
    { 
        set_test_name("test_0008 POWER OF 8");
        
        ensure_equals("misc::power<8, 0>", misc::power<8, 0>::value,  1);
        ensure_equals("misc::power<8, 1>", misc::power<8, 1>::value,  8);
        ensure_equals("misc::power<8, 2>", misc::power<8, 2>::value,  8 * 8);
        ensure_equals("misc::power<8, 3>", misc::power<8, 3>::value,  8 * 8 * 8);
        ensure_equals("misc::power<8, 4>", misc::power<8, 4>::value,  8 * 8 * 8 * 8);
        ensure_equals("misc::power<8, 5>", misc::power<8, 5>::value,  8 * 8 * 8 * 8 * 8);
        ensure_equals("misc::power<8, 6>", misc::power<8, 6>::value,  8 * 8 * 8 * 8 * 8 * 8);
        ensure_equals("misc::power<8, 7>", misc::power<8, 7>::value,  8 * 8 * 8 * 8 * 8 * 8 * 8);
        ensure_equals("misc::power<8, 8>", misc::power<8, 8>::value,  8 * 8 * 8 * 8 * 8 * 8 * 8 * 8);
        ensure_equals("misc::power<8, 9>", misc::power<8, 9>::value,  8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8);
        ensure_equals("misc::power<8, 10>", misc::power<8, 10>::value, 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8);
        //ensure_equals("misc::power<8, 11>", misc::power<8, 2>::value, 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8);
    }

    template<>
    template<>
    void testobject::test<9>()
    { 
        set_test_name("uint64_1 power tests");
        
        ensure_equals("misc::power<2, 0, uint64_t>", misc::power<2, 0, uint64_t>::value,  uint64_t(1 << 0));
        ensure_equals("misc::power<2, 7, uint64_t>", misc::power<2, 7, uint64_t>::value,  uint64_t(1 << 7));
        ensure_equals("misc::power<2, 8, uint64_t>", misc::power<2, 8, uint64_t>::value,  uint64_t(1 << 8));
 
        ensure_equals("misc::power<2, 61, uint64_t>", misc::power<2, 61, uint64_t>::value,  uint64_t(1LLU << 61));
        ensure_equals("misc::power<2, 62, uint64_t>", misc::power<2, 62, uint64_t>::value,  uint64_t(1LLU << 62));
        ensure_equals("misc::power<2, 63, uint64_t>", misc::power<2, 63, uint64_t>::value,  uint64_t(1LLU << 63));
        //ensure_equals("misc::power<2, 64, uint64_t>", misc::power<2, 64, uint64_t>::value,  uint64_t(1LLU << 64));
    }

} 



