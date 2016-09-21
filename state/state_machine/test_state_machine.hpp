// Wed Oct 14 13:41:33  2015
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


#include "state_machine.hpp"
#if 1
#include "../../container/bit_field/bit_field.hpp"

    enum BIT_FIELDS_ENUM
    {
        FSM0_STATE,
        FSM1_STATE
    };
    
    BF::bit_field<BIT_FIELDS_ENUM,
                        BF::FIELDS<
                            BF::FIELD<FSM0_STATE, 2>,
                            BF::FIELD<FSM1_STATE, 2, 2>
                            >
                        > FSM_STATE;

#endif


namespace
{
#if 0
    uint8_t fsm_state;
    void set_state(uint8_t new_state){fsm_state = new_state;}
    uint8_t get_state(){return fsm_state;}
#else
    void set_state(uint8_t new_state){FSM_STATE.set<FSM0_STATE>(new_state);}
    uint8_t get_state(){return FSM_STATE.get<FSM0_STATE>();}
#endif

    enum TEST_STATES
    {
        ST_STOP,
        ST_RUNNING,
        ST_PAUSE,
    };
    
    enum TEST_EVENTS
    {
        RUN,
        STOP,
        PAUSE,
        ERROR
    };
    
    //typedef bool (*EventFunction)(typename mpl::PARAM<TEST_EVENTS>::type);
    //bool default_func(typename mpl::PARAM<TEST_EVENTS>::type){return false;}
    
    bool stop_state(typename mpl::PARAM<TEST_EVENTS>::type event)
    {
        if(RUN == event) set_state(ST_RUNNING);
        return true;
    }
    
    bool running_state(typename mpl::PARAM<TEST_EVENTS>::type event)
    {
        if(PAUSE == event) set_state(ST_PAUSE);
        else
        if(STOP == event) set_state(ST_STOP);
        return true;
    }

    bool pause_state(typename mpl::PARAM<TEST_EVENTS>::type event)
    {
        if(STOP == event) set_state(ST_STOP);
        else
        if(PAUSE == event) set_state(ST_RUNNING);
        else
        if(RUN == event) set_state(ST_RUNNING);
        return true;
    }
}

namespace
{
#if 0
    uint8_t state_;
    void set2_state(uint8_t new_state){state_ = new_state;}
    uint8_t get2_state(){return state_;}
#else
    void set2_state(uint8_t new_state){FSM_STATE.set<FSM1_STATE>(new_state);}
    uint8_t get2_state(){return FSM_STATE.get<FSM1_STATE>();}
#endif

    
    enum TEST2_STATES
    {
        STATE0,
        STATE1,
        STATE2,
        STATE3,
    };
    
    enum TEST2_EVENTS
    {
        GO_0,
        GO_1,
        GO_2,
        GO_3,
    };
    
    //typedef bool (*Event2Function)(typename mpl::PARAM<TEST2_EVENTS>::type);
    //bool default2_func(typename mpl::PARAM<TEST2_EVENTS>::type){return false;}
    
    bool state_0(typename mpl::PARAM<TEST2_EVENTS>::type event)
    {
        if(GO_1 == event) set2_state(STATE1);
        printf("\n[current STATE : %d, event : %d]\n", get2_state(), event);
        return true;
    }

    bool state_1(typename mpl::PARAM<TEST2_EVENTS>::type event)
    {
        if(GO_2 == event) set2_state(STATE2);
        printf("\n[current STATE : %d, event : %d]\n", get2_state(), event);
        return true;
    }

    bool state_2(typename mpl::PARAM<TEST2_EVENTS>::type event)
    {
        if(GO_3 == event) set2_state(STATE3);
        printf("\n[current STATE : %d, event : %d]\n", get2_state(), event);
        return true;
    }

    bool state_3(typename mpl::PARAM<TEST2_EVENTS>::type event)
    {
        if(GO_0 == event) set2_state(STATE0);
        printf("\n[current STATE : %d, event : %d]\n", get2_state(), event);
        return true;
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

        state::state_machine<
                TEST_STATES, 
                TEST_EVENTS,
                TL::ITEMS
                    <
                        STATE<ST_STOP,    TEST_EVENTS, &stop_state>,
                        STATE<ST_RUNNING, TEST_EVENTS, &running_state>,
                        STATE<ST_PAUSE,   TEST_EVENTS, &pause_state>
                    >,
                    ST_STOP,
                    &get_state,
                    &set_state
                    //, &default_func
                > FSM;
        
        //printf("LIST LEGTH = %d\n", FSM.LENGTH);
#if 1
        // STOP STATE 
        ensure_equals("STOP STATE", get_state(), ST_STOP);
        FSM.process_event(STOP);
        ensure_equals("STOP STATE", get_state(), ST_STOP);
        FSM.process_event(PAUSE);
        ensure_equals("STOP STATE", get_state(), ST_STOP);
        
        FSM.process_event(RUN);
        ensure_equals("STOP STATE", get_state(), ST_RUNNING);
        
        // RUNNING STATE
        FSM.process_event(RUN);
        ensure_equals("RUNNING STATE", get_state(), ST_RUNNING);
        
        FSM.process_event(PAUSE);
        ensure_equals("RUNNING STATE", get_state(), ST_PAUSE);
        
        FSM.process_event(PAUSE);
        ensure_equals("RUNNING STATE", get_state(), ST_RUNNING);

        FSM.process_event(STOP);
        ensure_equals("RUNNING STATE", get_state(), ST_STOP);
        
        FSM.process_event(RUN);
        ensure_equals("STOP STATE", get_state(), ST_RUNNING);
        
        // PAUSE STATE
        FSM.process_event(PAUSE);
        ensure_equals("PAUSE STATE", get_state(), ST_PAUSE);
        FSM.process_event(STOP);
        ensure_equals("PAUSE STATE", get_state(), ST_STOP);
        
        FSM.process_event(RUN);
        ensure_equals("PAUSE STATE", get_state(), ST_RUNNING);
        FSM.process_event(PAUSE);
        ensure_equals("PAUSE STATE", get_state(), ST_PAUSE);
        FSM.process_event(ERROR);
        ensure_equals("PAUSE STATE", get_state(), ST_PAUSE);
        
        FSM.reset();
        ensure_equals("PAUSE STATE", get_state(), ST_STOP);
        
#endif
    } 
    

    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002");
        
        state::state_machine<
                TEST2_STATES, 
                TEST2_EVENTS,
                TL::ITEMS
                    <
                        STATE<STATE0, TEST2_EVENTS, &state_0>,
                        STATE<STATE1, TEST2_EVENTS, &state_1>,
                        STATE<STATE2, TEST2_EVENTS, &state_2>,
                        STATE<STATE3, TEST2_EVENTS, &state_3>
                    >,
                    STATE0,
                    &get2_state,
                    &set2_state
                    //, &default2_func
                > TEST_2;

        ensure_equals("STATE0", get2_state(), STATE0);
        
        TEST_2.process_event(GO_0);
        ensure_equals("STATE0", get2_state(), STATE0);
        
        TEST_2.process_event(GO_3);
        ensure_equals("STATE0", get2_state(), STATE0);
        
        TEST_2.process_event(GO_2);
        ensure_equals("STATE0", get2_state(), STATE0);
        
        TEST_2.process_event(GO_1);
        ensure_equals("STATE0", get2_state(), STATE1);
        
        //==========================================


        TEST_2.process_event(GO_3);
        ensure_equals("STATE1", get2_state(), STATE1);
        
        TEST_2.process_event(GO_0);
        ensure_equals("STATE1", get2_state(), STATE1);
        
        TEST_2.process_event(GO_1);
        ensure_equals("STATE1", get2_state(), STATE1);

        TEST_2.process_event(GO_2);
        ensure_equals("STATE1", get2_state(), STATE2);

        //===========================================
        
        TEST_2.process_event(GO_0);
        ensure_equals("STATE2", get2_state(), STATE2);

        TEST_2.process_event(GO_1);
        ensure_equals("STATE2", get2_state(), STATE2);

        TEST_2.process_event(GO_2);
        ensure_equals("STATE2", get2_state(), STATE2);

        TEST_2.process_event(GO_3);
        ensure_equals("STATE2", get2_state(), STATE3);

        //===========================================
        TEST_2.process_event(GO_1);
        ensure_equals("STATE3", get2_state(), STATE3);

        TEST_2.process_event(GO_2);
        ensure_equals("STATE3", get2_state(), STATE3);

        TEST_2.process_event(GO_3);
        ensure_equals("STATE3", get2_state(), STATE3);

        TEST_2.process_event(GO_0);
        ensure_equals("STATE3", get2_state(), STATE0);


    } 

    
#if 0
    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003");
        
        state::state_machine s;
        ensure_equals("message", 42, 42);
    } 
    
    
    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004");
        
        state::state_machine s;
        ensure_equals("message", 42, 42);
    } 
#endif
} 
