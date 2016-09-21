// Tue Oct 20 00:41:07  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//

#include <cstdio>
#include <tut/tut.hpp>
#include "dispatcher.hpp"

namespace
{

    enum TEST_EVENT_TYPE
    {
        UNO,
        DUE,
        TRIO,
        QUATTRO
    };
    
    void func00(uint8_t param)
    {
        printf("Function [%s] parameter : %d\n", __FUNCTION__, param);
    }
    
    void func01(uint8_t param)
    {
        printf("Function [%s] parameter : %d\n", __FUNCTION__, param);
    }
    
    void func02(uint8_t param)
    {
        printf("Function [%s] parameter : %d\n", __FUNCTION__, param);
    }
    
    void func03(uint8_t param)
    {
        printf("Function [%s] parameter : %d\n", __FUNCTION__, param);
    }
    
    void func04(uint8_t param)
    {
        printf("Function [%s] parameter : %d\n", __FUNCTION__, param);
    }
    
    void func05(uint8_t param)
    {
        printf("Function [%s] parameter : %d\n", __FUNCTION__, param);
    }
    
    void func06(uint8_t param)
    {
        printf("Function [%s] parameter : %d\n", __FUNCTION__, param);
    }
    
    void func07(uint8_t param)
    {
        printf("Function [%s] parameter : %d\n", __FUNCTION__, param);
    }
    
    void func08(uint8_t param)
    {
        printf("Function [%s] parameter : %d\n", __FUNCTION__, param);
    }
    
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
        
        typedef evt::SUBSCRIBE<
                        UNO, 
                        uint8_t
                        ,mpl::ST_VOID_FUNCTION1<uint8_t, &func00>
                        ,mpl::ST_VOID_FUNCTION1<uint8_t, &func01>
                        ,mpl::ST_VOID_FUNCTION1<uint8_t, &func02>
                        ,mpl::ST_VOID_FUNCTION1<uint8_t, &func03>
                        >
                    FUNC_LIST;

        
        FUNC_LIST::process_state(42);
        FUNC_LIST::process_state(37);
        
        //ensure_equals("message", 42, 42);
    } 
    

    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002");
        
        //static const uint8_t QUINTO = 8;
        
        typedef evt::SUBSCRIBE<
                        UNO, 
                        uint8_t
                        ,mpl::ST_VOID_FUNCTION1<uint8_t, &func00>
                        ,mpl::ST_VOID_FUNCTION1<uint8_t, &func01>
                        >
                    UNO_LIST;
                    
        typedef evt::SUBSCRIBE<
                        DUE, 
                        uint8_t
                        ,mpl::ST_VOID_FUNCTION1<uint8_t, &func02>
                        ,mpl::ST_VOID_FUNCTION1<uint8_t, &func03>
                        >
                    DUE_LIST;
        
        typedef evt::SUBSCRIBE<
                        TRIO, 
                        uint8_t
                        ,mpl::ST_VOID_FUNCTION1<uint8_t, &func04>
                        ,mpl::ST_VOID_FUNCTION1<uint8_t, &func05>
                        >
                    TRIO_LIST;
        

        typedef evt::SUBSCRIBE<
                        QUATTRO, 
                        uint8_t
                        ,mpl::ST_VOID_FUNCTION1<uint8_t, &func06>
                        ,mpl::ST_VOID_FUNCTION1<uint8_t, &func07>
                        >
                    QUAT_LIST;
                    
#if 0
        typedef evt::SUBSCRIBE<
                        QUINTO, 
                        uint8_t
                        ,mpl::ST_VOID_FUNCTION1<uint8_t, &func08>
                        //,mpl::ST_VOID_FUNCTION1<uint8_t, &func07>
                        >
                    QUINT_LIST;
#endif

        typedef evt::DISPATCHER<
                    TEST_EVENT_TYPE,
                    TEST_EVENT_TYPE
                    
                    ,UNO_LIST
                    ,DUE_LIST
                    ,TRIO_LIST
                    ,QUAT_LIST
                    //,QUINT_LIST
                    > DSP;
                    
        printf("\nDispatcher test\n");
        
        printf("======================================== UNO \n");
        DSP::process(UNO, UNO);
        
        printf("======================================== DUE \n");
        DSP::process(DUE, DUE);
        
        printf("======================================== TRIO \n");
        DSP::process(TRIO, TRIO);
        
        printf("======================================== QUATTRO \n");
        DSP::process(QUATTRO, QUATTRO);

        //printf("======================================== QUINTO \n");
        //DSP::process(QUINTO, QUINTO);       // Expected compile time error 
    } 
    
#if 0
    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003");
        
        evt::dispatcher s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004");
        
        evt::dispatcher s;
        ensure_equals("message", 42, 42);
    } 
#endif
} 
