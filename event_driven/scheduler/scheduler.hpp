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


#ifndef EVT_SCHEDULER_CLASS_HEADER
#define EVT_SCHEDULER_CLASS_HEADER

#include "../../container/circular_buffer/circular_buffer.hpp"
#include "../dispatcher/dispatcher.hpp"
#include "../../avr_debug/avr_debug/avr_debug.hpp"

#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
}; 
#endif


namespace evt
{

template
<
     typename EVENT_ID_TYPE
    ,typename EventType
    ,unsigned BUFF_SIZE_ORDER = 2
    ,class dbg = NO_DEBUG
>
class SCHEDULER
{
#ifdef UNITTEST_MODE
    template<class T> friend class tut::test_object;
#endif
    
    SCHEDULER(const SCHEDULER& other);
    SCHEDULER& operator = (const SCHEDULER &other);
    
    cb::circular_buffer<EventType, BUFF_SIZE_ORDER> buffer;
public:

    SCHEDULER()
    :buffer(){};
    
    //typedef typename mpl::PARAM<EventType>::type FUNC_PARAM_TYPE;
    typedef typename mpl::FUNC1<void,EventType>::param1type FUNC_PARAM_TYPE;
    
    void submit_event(FUNC_PARAM_TYPE event)
    {
        if(!buffer.append(event)) dbg::print("*SC:%d*\n", buffer.size());
    }
    
    typedef typename mpl::FUNC1<void,EventType>::type EVENT_FUNC_TYPE;
    
    
    template
    <
        EVENT_FUNC_TYPE function
    >
    void process_events()
    {
        while(buffer.size())
        {
            EventType event;
            if(buffer.pop(event))
            {
                // dispatch event
                function(event);
            }
            else break; // ???????????????????
        }
    }
};
    

template
<
    typename EVENT_ID_TYPE
    ,typename EventType
    ,class DE01 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE02 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE03 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE04 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
#if 1
    ,class DE05 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE06 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE07 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE08 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE09 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE10 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE11 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE12 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE13 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE14 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE15 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE16 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE17 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE18 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE19 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE20 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE21 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE22 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE23 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE24 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE25 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE26 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE27 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE28 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE29 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE30 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE31 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
    ,class DE32 = TL::LIST_TERM //,SUBSCRIBE class that defines event dispatching functions set
#endif
    ,unsigned BUFF_SIZE_ORDER = 2
    ,class dbg = NO_DEBUG
>
class scheduler
{ 
#ifdef UNITTEST_MODE
    template<class T> friend class tut::test_object;
#endif
    
    scheduler(const scheduler& other);
    scheduler& operator = (const scheduler &other);
    
    // Circular buffer
    cb::circular_buffer<EventType,BUFF_SIZE_ORDER> buffer;
    
    
    // Dispatcher
    DISPATCHER<
            EVENT_ID_TYPE
            ,EventType
            ,DE01,DE02,DE03,DE04,DE05,DE06,DE07,DE08,DE09,DE10,DE11,DE12,DE13,DE14,DE15,DE16
            ,DE17,DE18,DE19,DE20,DE21,DE22,DE23,DE24,DE25,DE26,DE27,DE28,DE29,DE30,DE31,DE32
            > dispatcher;
    
public:
    
    /**
     * \brief Brief description which ends at this dot.
     * 
     * Details follow here.
     */
    
    /**
     * default constructor
     */
    scheduler()
    :buffer()
    ,dispatcher()
    {};

    void submit_event(typename mpl::PARAM<EventType>::type event)
    {
        // MUTEX????
        if(!buffer.append(event)) dbg::print("*SC*\n");
    }
    
    void process_events()
    {
        while(buffer.size())
        {
            EventType event;
            if(buffer.pop(event))
            {
                // dispatch event
                dispatcher.process(event.id(), event);
            }
            else break; // ???????????????????
        }
    }

}; 

} // evt namespace
#endif



