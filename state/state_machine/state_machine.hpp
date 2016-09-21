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


#ifndef STATE_STATE_MACHINE_CLASS_HEADER
#define STATE_STATE_MACHINE_CLASS_HEADER

#include <stdint.h>
#include "../switch_case/switch_case.hpp"
#include "../../meta/functiontype/functiontype.hpp"


#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
}; 
#endif


#if 1

namespace
{

typedef uint8_t (*GetStateFuncType)();
typedef void (*SetStateFuncType)(uint8_t);


template
<
    uint8_t id,
    typename EventType,
    typename mpl::FUNC1<bool,EventType>::type process
>
struct STATE
{
    static const uint8_t ID;
    static bool inline process_state(typename mpl::PARAM<EventType>::type event)
    {
        return process(event);
    }
};

template<uint8_t id,typename EventType, typename mpl::FUNC1<bool,EventType>::type process>
const uint8_t STATE<id,EventType, process>::ID = id;


}

#endif

namespace state
{

template<class TTT>
bool empty(typename mpl::PARAM<TTT>::type){return false;}
    
    
template
<
    typename StateIdType,
    typename EventType,
    class STATES,
    StateIdType initial_state,
    GetStateFuncType get_state_func,
    SetStateFuncType set_state_func,
    typename mpl::FUNC1<bool,EventType>::type default_function = &empty<EventType>
>
class state_machine
{ 
#ifdef UNITTEST_MODE
    template<class T> friend class tut::test_object;
#endif
    
    state_machine(const state_machine& other);
    state_machine& operator = (const state_machine &other);

public:
    
    /**
     * \brief Brief description which ends at this dot.
     * 
     * Details follow here.
     */
    
    /**
     * default constructor
     */
    state_machine(){set_state_func(initial_state);};
    
    void inline process_event(typename mpl::PARAM<EventType>::type event)
    {
        sc::switch_helper<typename STATES::ITEMLIST, EventType, default_function, STATES::LENGTH>::process(get_state_func(), event);
    }
    
    void inline reset(){set_state_func(initial_state);}
    
    StateIdType inline current_state()const
    {
        return static_cast<StateIdType>(get_state_func());
    }
}; 


} // state namespace
#endif

