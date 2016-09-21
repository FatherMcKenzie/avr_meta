// Thu Oct 22 11:49:25  2015
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
#include "functiontype.hpp"
#include "../typelist/typelist.hpp"
#include "../traverse/traverse.hpp"


namespace
{



void func_0(uint8_t val)
{
    printf("%s returns %d\n", __FUNCTION__, val);
}

void func_1(uint8_t val)
{
    printf("%s returns %d\n", __FUNCTION__, val * val);
}

struct TEST_STRUCT
{
    static void func(uint8_t val)
    {
        printf("%s returns %d\n", __FUNCTION__, val + val);
    }
};


void super_function()
{
    printf("%s\n", __FUNCTION__);
}



}

template
<
    unsigned INDEX,
    class CONT,
    typename ParameterType = int
>
struct EX
{
    typedef ParameterType param_type;
    static void EXEC1(ParameterType)
    {
        TL::type_at<INDEX, CONT>::type::func(8);
    }
};
   
#if 1
typedef TL::ITEMS<
            mpl::ST_VOID_FUNCTION1<uint8_t, &func_0>,
            mpl::ST_VOID_FUNCTION1<uint8_t, &func_1>,
            mpl::ST_VOID_FUNCTION1<uint8_t, &TEST_STRUCT::func>
                    > FUNC_CONTAINER;

typedef mpl::forw<
                EX,
                FUNC_CONTAINER::LENGTH,
                FUNC_CONTAINER::ITEMLIST
            > NNNNN;
#endif

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
        
        mpl::VOID_FUNCTION1<uint8_t, &func_0> one;
        mpl::VOID_FUNCTION1<uint8_t, &func_1> two;
        
        mpl::VOID_FUNCTION1<uint8_t, &TEST_STRUCT::func> three;
        
        //mpl::FuncType one = &func_0;
        //mpl::FuncType two = &func_1;
        
        one(2);
        two(2);
        three(2);
        

        one(3);
        two(3);
        three(3);


    } 

    

    template<>
    template<>
    void testobject::test<2>()
    {
        set_test_name("test_0002");
        
        printf("\n=========================================================\n");
        
        typedef mpl::ST_VOID_FUNCTION1<uint8_t, &func_0> ONE;
        typedef mpl::ST_VOID_FUNCTION1<uint8_t, &func_1> TWO;
        typedef mpl::ST_VOID_FUNCTION1<uint8_t, &TEST_STRUCT::func> THREE;
        
        
        ONE::func(4);
        TWO::func(4);
        THREE::func(4);
        
        ONE::func(5);
        TWO::func(5);
        THREE::func(5);
    }
    

    
    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003");
        
        printf("\n=========================================================\n");
        
        
        NNNNN::TRAVERSE1(42);


    } 

#if 1
    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004");
        
        printf("\n=========================================================\n");
        
        mpl::ST_VOID_FUNCTION0<&super_function>::func();
        
        typedef mpl::ST_VOID_FUNCTION0<&super_function> FUUU;
        FUUU::func();
        
        
        ensure_equals("message", 42, 42);
    } 
#endif
} 
