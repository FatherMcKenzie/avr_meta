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


#ifndef EVT_DISPATCHER_CLASS_HEADER
#define EVT_DISPATCHER_CLASS_HEADER

#include "../../meta/functiontype/functiontype.hpp"
#include "../../meta/typelist/typelist.hpp"
#include "../../meta/traverse/traverse.hpp"

#include "../../state/switch_case/switch_case.hpp"


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
    unsigned INDEX,
    class CONT,
    typename ParameterType = int
>
struct FUNC_EXEC
{
    //typedef ParameterType param_type;
    typedef typename mpl::FUNC1<void, ParameterType>::param1type param_type;
    
    static void inline EXEC1(param_type param)
    {
        TL::type_at<INDEX, CONT>::type::func(param);
    }
};

//==============================================================

template
<
    uint8_t event_id,
    typename EventType,
    class S01 = TL::LIST_TERM, //mpl::ST_VOID_FUNCTION1<EventType, &function>,
    class S02 = TL::LIST_TERM, //mpl::ST_VOID_FUNCTION1<EventType, &function>,
    class S03 = TL::LIST_TERM, //mpl::ST_VOID_FUNCTION1<EventType, &function>,
    class S04 = TL::LIST_TERM, //mpl::ST_VOID_FUNCTION1<EventType, &function>,
#if 1
    class S05 = TL::LIST_TERM, //mpl::ST_VOID_FUNCTION1<EventType, &function>,
    class S06 = TL::LIST_TERM, //mpl::ST_VOID_FUNCTION1<EventType, &function>,
    class S07 = TL::LIST_TERM, //mpl::ST_VOID_FUNCTION1<EventType, &function>,
    class S08 = TL::LIST_TERM, //mpl::ST_VOID_FUNCTION1<EventType, &function>,
    class S09 = TL::LIST_TERM, //mpl::ST_VOID_FUNCTION1<EventType, &function>,
    class S10 = TL::LIST_TERM, //mpl::ST_VOID_FUNCTION1<EventType, &function>,
    class S11 = TL::LIST_TERM, //mpl::ST_VOID_FUNCTION1<EventType, &function>,
    class S12 = TL::LIST_TERM, //mpl::ST_VOID_FUNCTION1<EventType, &function>,
    class S13 = TL::LIST_TERM, //mpl::ST_VOID_FUNCTION1<EventType, &function>,
    class S14 = TL::LIST_TERM, //mpl::ST_VOID_FUNCTION1<EventType, &function>,
    class S15 = TL::LIST_TERM, //mpl::ST_VOID_FUNCTION1<EventType, &function>,
    class S16 = TL::LIST_TERM  //mpl::ST_VOID_FUNCTION1<EventType, &function>
#endif
>
struct SUBSCRIBE
{
    typedef typename TL::ITEMS_16<S01,S02,S03,S04,S05,S06,S07,S08,S09,S10,S11,S12,S13,S14,S15,S16>  FUNC_CONTAINER; // Subscribers list
    static const uint8_t SIZE = FUNC_CONTAINER::LENGTH;
    typedef typename mpl::FUNC1<void, EventType>::param1type param_type;

    typedef mpl::forw<
                 FUNC_EXEC
                ,FUNC_CONTAINER::LENGTH
                ,typename FUNC_CONTAINER::ITEMLIST
                ,EventType
                > 
                SUBSCRIBERS_LIST;

    static bool inline process_state(param_type event)
    {
        SUBSCRIBERS_LIST::TRAVERSE1(event);
        return true;
    }

    static const uint8_t ID;
};

template<uint8_t event_id,typename EventType,class S01,class S02,class S03,class S04,class S05,class S06,class S07,class S08,class S09,class S10,class S11,class S12,class S13,class S14,class S15,class S16>
const uint8_t SUBSCRIBE<event_id,EventType,S01,S02,S03,S04,S05,S06,S07,S08,S09,S10,S11,S12,S13,S14,S15,S16>::ID = event_id;
//==============================================================



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
>
struct DISPATCHER
{
    typedef typename TL::ITEMS<DE01,DE02,DE03,DE04,DE05,DE06,DE07,DE08,DE09,DE10,DE11,DE12,DE13,DE14,DE15,DE16,DE17,DE18,DE19,DE20,DE21,DE22,DE23,DE24,DE25,DE26,DE27,DE28,DE29,DE30,DE31,DE32>  CONTAINER; // List
    
    typedef typename mpl::FUNC1<void, EventType>::param1type param_type;
    static bool empty_function(param_type){return false;}

    typedef sc::switch_helper<
                    typename CONTAINER::ITEMLIST,
                    EventType, 
                    &DISPATCHER::empty_function, 
                    CONTAINER::LENGTH
                > SWITCH_CASE;
    
    static inline void process(uint8_t event_id, param_type event)
    {
        SWITCH_CASE::process(event_id, event);
    }
    
    static inline void process_event(param_type event)
    {
        SWITCH_CASE::process(event.id(), event);
    }
};




} // evt namespace
#endif
