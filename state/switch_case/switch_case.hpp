// Fri Oct 23 12:17:03  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef SC_SWITCH_CASE_CLASS_HEADER
#define SC_SWITCH_CASE_CLASS_HEADER

#include "../../meta/functiontype/functiontype.hpp"
#include "../../meta/typelist/typelist.hpp"

#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
}; 
#endif


namespace sc
{


template
<
    typename TLIST,
    typename ParamType,
    typename mpl::FUNC1<bool,ParamType>::type func,
    uint8_t SIZE
>
struct switch_helper
{
    static inline void process(uint8_t, typename mpl::FUNC1<bool,ParamType>::param1type){}
};

template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,1>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,2>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,3>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,4>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,5>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,6>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,7>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,8>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,9>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,10>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,11>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,12>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,13>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,14>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,15>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,16>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,17>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,18>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        case TL::type_at<17,TLIST>::type::ID:
            if(TL::type_at<17,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,19>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        case TL::type_at<17,TLIST>::type::ID:
            if(TL::type_at<17,TLIST>::type::process_state(param)) break;
        case TL::type_at<18,TLIST>::type::ID:
            if(TL::type_at<18,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,20>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        case TL::type_at<17,TLIST>::type::ID:
            if(TL::type_at<17,TLIST>::type::process_state(param)) break;
        case TL::type_at<18,TLIST>::type::ID:
            if(TL::type_at<18,TLIST>::type::process_state(param)) break;
        case TL::type_at<19,TLIST>::type::ID:
            if(TL::type_at<19,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,21>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        case TL::type_at<17,TLIST>::type::ID:
            if(TL::type_at<17,TLIST>::type::process_state(param)) break;
        case TL::type_at<18,TLIST>::type::ID:
            if(TL::type_at<18,TLIST>::type::process_state(param)) break;
        case TL::type_at<19,TLIST>::type::ID:
            if(TL::type_at<19,TLIST>::type::process_state(param)) break;
        case TL::type_at<20,TLIST>::type::ID:
            if(TL::type_at<20,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,22>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        case TL::type_at<17,TLIST>::type::ID:
            if(TL::type_at<17,TLIST>::type::process_state(param)) break;
        case TL::type_at<18,TLIST>::type::ID:
            if(TL::type_at<18,TLIST>::type::process_state(param)) break;
        case TL::type_at<19,TLIST>::type::ID:
            if(TL::type_at<19,TLIST>::type::process_state(param)) break;
        case TL::type_at<20,TLIST>::type::ID:
            if(TL::type_at<20,TLIST>::type::process_state(param)) break;
        case TL::type_at<21,TLIST>::type::ID:
            if(TL::type_at<21,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,23>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        case TL::type_at<17,TLIST>::type::ID:
            if(TL::type_at<17,TLIST>::type::process_state(param)) break;
        case TL::type_at<18,TLIST>::type::ID:
            if(TL::type_at<18,TLIST>::type::process_state(param)) break;
        case TL::type_at<19,TLIST>::type::ID:
            if(TL::type_at<19,TLIST>::type::process_state(param)) break;
        case TL::type_at<20,TLIST>::type::ID:
            if(TL::type_at<20,TLIST>::type::process_state(param)) break;
        case TL::type_at<21,TLIST>::type::ID:
            if(TL::type_at<21,TLIST>::type::process_state(param)) break;
        case TL::type_at<22,TLIST>::type::ID:
            if(TL::type_at<22,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,24>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        case TL::type_at<17,TLIST>::type::ID:
            if(TL::type_at<17,TLIST>::type::process_state(param)) break;
        case TL::type_at<18,TLIST>::type::ID:
            if(TL::type_at<18,TLIST>::type::process_state(param)) break;
        case TL::type_at<19,TLIST>::type::ID:
            if(TL::type_at<19,TLIST>::type::process_state(param)) break;
        case TL::type_at<20,TLIST>::type::ID:
            if(TL::type_at<20,TLIST>::type::process_state(param)) break;
        case TL::type_at<21,TLIST>::type::ID:
            if(TL::type_at<21,TLIST>::type::process_state(param)) break;
        case TL::type_at<22,TLIST>::type::ID:
            if(TL::type_at<22,TLIST>::type::process_state(param)) break;
        case TL::type_at<23,TLIST>::type::ID:
            if(TL::type_at<23,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,25>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        case TL::type_at<17,TLIST>::type::ID:
            if(TL::type_at<17,TLIST>::type::process_state(param)) break;
        case TL::type_at<18,TLIST>::type::ID:
            if(TL::type_at<18,TLIST>::type::process_state(param)) break;
        case TL::type_at<19,TLIST>::type::ID:
            if(TL::type_at<19,TLIST>::type::process_state(param)) break;
        case TL::type_at<20,TLIST>::type::ID:
            if(TL::type_at<20,TLIST>::type::process_state(param)) break;
        case TL::type_at<21,TLIST>::type::ID:
            if(TL::type_at<21,TLIST>::type::process_state(param)) break;
        case TL::type_at<22,TLIST>::type::ID:
            if(TL::type_at<22,TLIST>::type::process_state(param)) break;
        case TL::type_at<23,TLIST>::type::ID:
            if(TL::type_at<23,TLIST>::type::process_state(param)) break;
        case TL::type_at<24,TLIST>::type::ID:
            if(TL::type_at<24,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,26>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        case TL::type_at<17,TLIST>::type::ID:
            if(TL::type_at<17,TLIST>::type::process_state(param)) break;
        case TL::type_at<18,TLIST>::type::ID:
            if(TL::type_at<18,TLIST>::type::process_state(param)) break;
        case TL::type_at<19,TLIST>::type::ID:
            if(TL::type_at<19,TLIST>::type::process_state(param)) break;
        case TL::type_at<20,TLIST>::type::ID:
            if(TL::type_at<20,TLIST>::type::process_state(param)) break;
        case TL::type_at<21,TLIST>::type::ID:
            if(TL::type_at<21,TLIST>::type::process_state(param)) break;
        case TL::type_at<22,TLIST>::type::ID:
            if(TL::type_at<22,TLIST>::type::process_state(param)) break;
        case TL::type_at<23,TLIST>::type::ID:
            if(TL::type_at<23,TLIST>::type::process_state(param)) break;
        case TL::type_at<24,TLIST>::type::ID:
            if(TL::type_at<24,TLIST>::type::process_state(param)) break;
        case TL::type_at<25,TLIST>::type::ID:
            if(TL::type_at<25,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,27>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        case TL::type_at<17,TLIST>::type::ID:
            if(TL::type_at<17,TLIST>::type::process_state(param)) break;
        case TL::type_at<18,TLIST>::type::ID:
            if(TL::type_at<18,TLIST>::type::process_state(param)) break;
        case TL::type_at<19,TLIST>::type::ID:
            if(TL::type_at<19,TLIST>::type::process_state(param)) break;
        case TL::type_at<20,TLIST>::type::ID:
            if(TL::type_at<20,TLIST>::type::process_state(param)) break;
        case TL::type_at<21,TLIST>::type::ID:
            if(TL::type_at<21,TLIST>::type::process_state(param)) break;
        case TL::type_at<22,TLIST>::type::ID:
            if(TL::type_at<22,TLIST>::type::process_state(param)) break;
        case TL::type_at<23,TLIST>::type::ID:
            if(TL::type_at<23,TLIST>::type::process_state(param)) break;
        case TL::type_at<24,TLIST>::type::ID:
            if(TL::type_at<24,TLIST>::type::process_state(param)) break;
        case TL::type_at<25,TLIST>::type::ID:
            if(TL::type_at<25,TLIST>::type::process_state(param)) break;
        case TL::type_at<26,TLIST>::type::ID:
            if(TL::type_at<26,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,28>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        case TL::type_at<17,TLIST>::type::ID:
            if(TL::type_at<17,TLIST>::type::process_state(param)) break;
        case TL::type_at<18,TLIST>::type::ID:
            if(TL::type_at<18,TLIST>::type::process_state(param)) break;
        case TL::type_at<19,TLIST>::type::ID:
            if(TL::type_at<19,TLIST>::type::process_state(param)) break;
        case TL::type_at<20,TLIST>::type::ID:
            if(TL::type_at<20,TLIST>::type::process_state(param)) break;
        case TL::type_at<21,TLIST>::type::ID:
            if(TL::type_at<21,TLIST>::type::process_state(param)) break;
        case TL::type_at<22,TLIST>::type::ID:
            if(TL::type_at<22,TLIST>::type::process_state(param)) break;
        case TL::type_at<23,TLIST>::type::ID:
            if(TL::type_at<23,TLIST>::type::process_state(param)) break;
        case TL::type_at<24,TLIST>::type::ID:
            if(TL::type_at<24,TLIST>::type::process_state(param)) break;
        case TL::type_at<25,TLIST>::type::ID:
            if(TL::type_at<25,TLIST>::type::process_state(param)) break;
        case TL::type_at<26,TLIST>::type::ID:
            if(TL::type_at<26,TLIST>::type::process_state(param)) break;
        case TL::type_at<27,TLIST>::type::ID:
            if(TL::type_at<27,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,29>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        case TL::type_at<17,TLIST>::type::ID:
            if(TL::type_at<17,TLIST>::type::process_state(param)) break;
        case TL::type_at<18,TLIST>::type::ID:
            if(TL::type_at<18,TLIST>::type::process_state(param)) break;
        case TL::type_at<19,TLIST>::type::ID:
            if(TL::type_at<19,TLIST>::type::process_state(param)) break;
        case TL::type_at<20,TLIST>::type::ID:
            if(TL::type_at<20,TLIST>::type::process_state(param)) break;
        case TL::type_at<21,TLIST>::type::ID:
            if(TL::type_at<21,TLIST>::type::process_state(param)) break;
        case TL::type_at<22,TLIST>::type::ID:
            if(TL::type_at<22,TLIST>::type::process_state(param)) break;
        case TL::type_at<23,TLIST>::type::ID:
            if(TL::type_at<23,TLIST>::type::process_state(param)) break;
        case TL::type_at<24,TLIST>::type::ID:
            if(TL::type_at<24,TLIST>::type::process_state(param)) break;
        case TL::type_at<25,TLIST>::type::ID:
            if(TL::type_at<25,TLIST>::type::process_state(param)) break;
        case TL::type_at<26,TLIST>::type::ID:
            if(TL::type_at<26,TLIST>::type::process_state(param)) break;
        case TL::type_at<27,TLIST>::type::ID:
            if(TL::type_at<27,TLIST>::type::process_state(param)) break;
        case TL::type_at<28,TLIST>::type::ID:
            if(TL::type_at<28,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,30>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        case TL::type_at<17,TLIST>::type::ID:
            if(TL::type_at<17,TLIST>::type::process_state(param)) break;
        case TL::type_at<18,TLIST>::type::ID:
            if(TL::type_at<18,TLIST>::type::process_state(param)) break;
        case TL::type_at<19,TLIST>::type::ID:
            if(TL::type_at<19,TLIST>::type::process_state(param)) break;
        case TL::type_at<20,TLIST>::type::ID:
            if(TL::type_at<20,TLIST>::type::process_state(param)) break;
        case TL::type_at<21,TLIST>::type::ID:
            if(TL::type_at<21,TLIST>::type::process_state(param)) break;
        case TL::type_at<22,TLIST>::type::ID:
            if(TL::type_at<22,TLIST>::type::process_state(param)) break;
        case TL::type_at<23,TLIST>::type::ID:
            if(TL::type_at<23,TLIST>::type::process_state(param)) break;
        case TL::type_at<24,TLIST>::type::ID:
            if(TL::type_at<24,TLIST>::type::process_state(param)) break;
        case TL::type_at<25,TLIST>::type::ID:
            if(TL::type_at<25,TLIST>::type::process_state(param)) break;
        case TL::type_at<26,TLIST>::type::ID:
            if(TL::type_at<26,TLIST>::type::process_state(param)) break;
        case TL::type_at<27,TLIST>::type::ID:
            if(TL::type_at<27,TLIST>::type::process_state(param)) break;
        case TL::type_at<28,TLIST>::type::ID:
            if(TL::type_at<28,TLIST>::type::process_state(param)) break;
        case TL::type_at<29,TLIST>::type::ID:
            if(TL::type_at<29,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,31>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        case TL::type_at<17,TLIST>::type::ID:
            if(TL::type_at<17,TLIST>::type::process_state(param)) break;
        case TL::type_at<18,TLIST>::type::ID:
            if(TL::type_at<18,TLIST>::type::process_state(param)) break;
        case TL::type_at<19,TLIST>::type::ID:
            if(TL::type_at<19,TLIST>::type::process_state(param)) break;
        case TL::type_at<20,TLIST>::type::ID:
            if(TL::type_at<20,TLIST>::type::process_state(param)) break;
        case TL::type_at<21,TLIST>::type::ID:
            if(TL::type_at<21,TLIST>::type::process_state(param)) break;
        case TL::type_at<22,TLIST>::type::ID:
            if(TL::type_at<22,TLIST>::type::process_state(param)) break;
        case TL::type_at<23,TLIST>::type::ID:
            if(TL::type_at<23,TLIST>::type::process_state(param)) break;
        case TL::type_at<24,TLIST>::type::ID:
            if(TL::type_at<24,TLIST>::type::process_state(param)) break;
        case TL::type_at<25,TLIST>::type::ID:
            if(TL::type_at<25,TLIST>::type::process_state(param)) break;
        case TL::type_at<26,TLIST>::type::ID:
            if(TL::type_at<26,TLIST>::type::process_state(param)) break;
        case TL::type_at<27,TLIST>::type::ID:
            if(TL::type_at<27,TLIST>::type::process_state(param)) break;
        case TL::type_at<28,TLIST>::type::ID:
            if(TL::type_at<28,TLIST>::type::process_state(param)) break;
        case TL::type_at<29,TLIST>::type::ID:
            if(TL::type_at<29,TLIST>::type::process_state(param)) break;
        case TL::type_at<30,TLIST>::type::ID:
            if(TL::type_at<30,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};


template<typename TLIST,typename ParamType,typename mpl::FUNC1<bool,ParamType>::type func>
struct switch_helper<TLIST,ParamType,func,32>
{
    static inline void process(uint8_t label, typename mpl::FUNC1<bool,ParamType>::param1type param)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            if(TL::type_at<0,TLIST>::type::process_state(param)) break;
        case TL::type_at<1,TLIST>::type::ID:
            if(TL::type_at<1,TLIST>::type::process_state(param)) break;
        case TL::type_at<2,TLIST>::type::ID:
            if(TL::type_at<2,TLIST>::type::process_state(param)) break;
        case TL::type_at<3,TLIST>::type::ID:
            if(TL::type_at<3,TLIST>::type::process_state(param)) break;
        case TL::type_at<4,TLIST>::type::ID:
            if(TL::type_at<4,TLIST>::type::process_state(param)) break;
        case TL::type_at<5,TLIST>::type::ID:
            if(TL::type_at<5,TLIST>::type::process_state(param)) break;
        case TL::type_at<6,TLIST>::type::ID:
            if(TL::type_at<6,TLIST>::type::process_state(param)) break;
        case TL::type_at<7,TLIST>::type::ID:
            if(TL::type_at<7,TLIST>::type::process_state(param)) break;
        case TL::type_at<8,TLIST>::type::ID:
            if(TL::type_at<8,TLIST>::type::process_state(param)) break;
        case TL::type_at<9,TLIST>::type::ID:
            if(TL::type_at<9,TLIST>::type::process_state(param)) break;
        case TL::type_at<10,TLIST>::type::ID:
            if(TL::type_at<10,TLIST>::type::process_state(param)) break;
        case TL::type_at<11,TLIST>::type::ID:
            if(TL::type_at<11,TLIST>::type::process_state(param)) break;
        case TL::type_at<12,TLIST>::type::ID:
            if(TL::type_at<12,TLIST>::type::process_state(param)) break;
        case TL::type_at<13,TLIST>::type::ID:
            if(TL::type_at<13,TLIST>::type::process_state(param)) break;
        case TL::type_at<14,TLIST>::type::ID:
            if(TL::type_at<14,TLIST>::type::process_state(param)) break;
        case TL::type_at<15,TLIST>::type::ID:
            if(TL::type_at<15,TLIST>::type::process_state(param)) break;
        case TL::type_at<16,TLIST>::type::ID:
            if(TL::type_at<16,TLIST>::type::process_state(param)) break;
        case TL::type_at<17,TLIST>::type::ID:
            if(TL::type_at<17,TLIST>::type::process_state(param)) break;
        case TL::type_at<18,TLIST>::type::ID:
            if(TL::type_at<18,TLIST>::type::process_state(param)) break;
        case TL::type_at<19,TLIST>::type::ID:
            if(TL::type_at<19,TLIST>::type::process_state(param)) break;
        case TL::type_at<20,TLIST>::type::ID:
            if(TL::type_at<20,TLIST>::type::process_state(param)) break;
        case TL::type_at<21,TLIST>::type::ID:
            if(TL::type_at<21,TLIST>::type::process_state(param)) break;
        case TL::type_at<22,TLIST>::type::ID:
            if(TL::type_at<22,TLIST>::type::process_state(param)) break;
        case TL::type_at<23,TLIST>::type::ID:
            if(TL::type_at<23,TLIST>::type::process_state(param)) break;
        case TL::type_at<24,TLIST>::type::ID:
            if(TL::type_at<24,TLIST>::type::process_state(param)) break;
        case TL::type_at<25,TLIST>::type::ID:
            if(TL::type_at<25,TLIST>::type::process_state(param)) break;
        case TL::type_at<26,TLIST>::type::ID:
            if(TL::type_at<26,TLIST>::type::process_state(param)) break;
        case TL::type_at<27,TLIST>::type::ID:
            if(TL::type_at<27,TLIST>::type::process_state(param)) break;
        case TL::type_at<28,TLIST>::type::ID:
            if(TL::type_at<28,TLIST>::type::process_state(param)) break;
        case TL::type_at<29,TLIST>::type::ID:
            if(TL::type_at<29,TLIST>::type::process_state(param)) break;
        case TL::type_at<30,TLIST>::type::ID:
            if(TL::type_at<30,TLIST>::type::process_state(param)) break;
        case TL::type_at<31,TLIST>::type::ID:
            if(TL::type_at<31,TLIST>::type::process_state(param)) break;
        default:
            func(param);
        }
    }
};




} // sc namespace
#endif


