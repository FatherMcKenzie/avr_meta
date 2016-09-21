// Fri Oct 23 13:25:18  2015
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
#include "scheduler.hpp"



namespace
{

enum EVT_NAMES
{
    START,
    STOP,
    PAUSE,
    ERROR
};  

struct TEST_EVENT
{
    uint8_t _id;
    
    TEST_EVENT(uint8_t evt_id = ERROR):_id(evt_id){} // DEFAULT MUST BE!!!
    
    uint8_t id()const
    {
        return _id;
    }
    
    int name(char* buf, uint8_t bufsize)const
    {
        switch(_id)
        {
        case START:
            return snprintf(buf, bufsize, "%s", "START");
            break;
        case STOP:
            return snprintf(buf, bufsize, "%s", "STOP");
            break;
        case PAUSE:
            return snprintf(buf, bufsize, "%s", "PAUSE");
            break;
        case ERROR:
            return snprintf(buf, bufsize, "%s", "ERROR");
            break;
        default:
            return snprintf(buf, bufsize, "%s", "UNKNOWN");
        }
    }
    
    operator int()const
    {
        return _id;
    }
};

typedef typename mpl::PARAM<TEST_EVENT>::type FUNC_PARAM_TYPE;

void logger(FUNC_PARAM_TYPE evt)
{
    char buffer[16];
    evt.name(buffer, 16);
    printf("PROCESS %s EVT \t: %s\n", __FUNCTION__, buffer);
}

void control(FUNC_PARAM_TYPE evt)
{
    char buffer[16];
    evt.name(buffer, 16);
    printf("PROCESS %s EVT \t: %s\n", __FUNCTION__, buffer);
}

void unit(FUNC_PARAM_TYPE evt)
{
    char buffer[16];
    evt.name(buffer, 16);
    printf("PROCESS %s EVT \t: %s\n", __FUNCTION__, buffer);
}

void module(FUNC_PARAM_TYPE evt)
{
    char buffer[16];
    evt.name(buffer, 16);
    printf("PROCESS %s EVT \t: %s\n", __FUNCTION__, buffer);
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
        
        evt::scheduler<
            EVT_NAMES,
            TEST_EVENT,
            evt::SUBSCRIBE<START,
                            TEST_EVENT,
                            mpl::ST_VOID_FUNCTION1<TEST_EVENT,&logger>,
                            mpl::ST_VOID_FUNCTION1<TEST_EVENT,&control>
                            >,
            
            evt::SUBSCRIBE<STOP,
                            TEST_EVENT,
                            mpl::ST_VOID_FUNCTION1<TEST_EVENT,&logger>,
                            mpl::ST_VOID_FUNCTION1<TEST_EVENT,&control>,
                            mpl::ST_VOID_FUNCTION1<TEST_EVENT,&unit>
                            >,
            evt::SUBSCRIBE<PAUSE,
                            TEST_EVENT,
                            mpl::ST_VOID_FUNCTION1<TEST_EVENT,&logger>,
                            mpl::ST_VOID_FUNCTION1<TEST_EVENT,&unit>
                            >,
            evt::SUBSCRIBE<ERROR,
                            TEST_EVENT,
                            mpl::ST_VOID_FUNCTION1<TEST_EVENT,&logger>,
                            mpl::ST_VOID_FUNCTION1<TEST_EVENT,&control>,
                            mpl::ST_VOID_FUNCTION1<TEST_EVENT,&unit>,
                            mpl::ST_VOID_FUNCTION1<TEST_EVENT,&module>
                            >
                        > sc;
            
            printf("\n===================================\n");
            sc.submit_event(TEST_EVENT(START));
            sc.submit_event(TEST_EVENT(PAUSE));
            sc.submit_event(TEST_EVENT(START));
            
            sc.process_events();
            printf("===================================\n");
            
            sc.submit_event(TEST_EVENT(STOP));
            sc.submit_event(TEST_EVENT(ERROR));
            sc.submit_event(TEST_EVENT(ERROR));
            
            sc.process_events();
        
        
        
        ensure_equals("message", 42, 42);
    } 

    
    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002");
        
        printf("\n================ TEST 2 ===================\n");
        
        
        evt::SCHEDULER<EVT_NAMES,TEST_EVENT,2> sched;


        typedef evt::DISPATCHER<
                EVT_NAMES,
                TEST_EVENT,
                evt::SUBSCRIBE<START,
                                TEST_EVENT,
                                mpl::ST_VOID_FUNCTION1<TEST_EVENT,&logger>,
                                mpl::ST_VOID_FUNCTION1<TEST_EVENT,&control>
                                >,
                
                evt::SUBSCRIBE<STOP,
                                TEST_EVENT,
                                mpl::ST_VOID_FUNCTION1<TEST_EVENT,&logger>,
                                mpl::ST_VOID_FUNCTION1<TEST_EVENT,&control>,
                                mpl::ST_VOID_FUNCTION1<TEST_EVENT,&unit>
                                >,
                evt::SUBSCRIBE<PAUSE,
                                TEST_EVENT,
                                mpl::ST_VOID_FUNCTION1<TEST_EVENT,&logger>,
                                mpl::ST_VOID_FUNCTION1<TEST_EVENT,&unit>
                                >,
                evt::SUBSCRIBE<ERROR,
                                TEST_EVENT,
                                mpl::ST_VOID_FUNCTION1<TEST_EVENT,&logger>,
                                mpl::ST_VOID_FUNCTION1<TEST_EVENT,&control>,
                                mpl::ST_VOID_FUNCTION1<TEST_EVENT,&unit>,
                                mpl::ST_VOID_FUNCTION1<TEST_EVENT,&module>
                                >
                        > DISP;
        
        
        sched.submit_event(TEST_EVENT(START));
        sched.submit_event(TEST_EVENT(PAUSE));
        sched.submit_event(TEST_EVENT(START));
        
        sched.process_events<&DISP::process_event>();
        printf("===================================\n");
        
        sched.submit_event(TEST_EVENT(STOP));
        sched.submit_event(TEST_EVENT(ERROR));
        sched.submit_event(TEST_EVENT(ERROR));
        
        sched.process_events<&DISP::process_event>();
        
    } 
    
#if 0
    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003");
        
        evt::scheduler s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004");
        
        evt::scheduler s;
        ensure_equals("message", 42, 42);
    } 
#endif
} 
