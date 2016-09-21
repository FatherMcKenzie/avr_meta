// Tue Oct 20 10:07:59  2015
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

#include <cstdio>
#include <stdint.h>
#include "traverse.hpp"

namespace
{

template
<
    unsigned INDEX,
    class CONT,
    typename DUMMY
>
struct TEST1
{
    static inline void EXEC()
    {
        printf("Calling function with %d value\n", INDEX);
    }
};


template
<
    unsigned IDX,
    class CONT,
    typename PT
>
struct TEST2
{
    static inline void EXEC1(typename mpl::PARAM<PT>::type param)
    {
        printf("EXEC1 function,  index = %d, param = %d\n", IDX, param);
    }
};


}


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
        
        printf("\n");
        
        mpl::forw<TEST1,4>::TRAVERSE();
        mpl::forw<TEST2,5>::TRAVERSE1(42);
    } 

    
    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002");
        
        printf("\n");
        mpl::back<TEST1,4>::TRAVERSE();
        mpl::back<TEST2,5>::TRAVERSE1(42);
    } 
    
#if 0
    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003");
        
        mpl::traverse s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004");
        
        mpl::traverse s;
        ensure_equals("message", 42, 42);
    } 
#endif
} 
