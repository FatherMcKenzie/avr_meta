//Sun Nov  1 18:09:42 MSK 2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef LED_SWITCH_FOR_LED_BLINKER
#define LED_SWITCH_FOR_LED_BLINKER

#include "../../meta/functiontype/functiontype.hpp"
#include "../../meta/typelist/typelist.hpp"

namespace led
{

namespace
{
void empty_function(){}
}

template
<
    typename ModeIdType,
    typename ParamType,
    template<ModeIdType, typename> class PROCESSOR,
    typename TLIST,
    uint8_t SIZE
>
struct switch_helper
{
    static inline void process(uint8_t, ParamType){}
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,1>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,2>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,3>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,4>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,5>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,6>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,7>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,8>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,9>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,10>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,11>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,12>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,13>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,14>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,15>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,16>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,17>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,18>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<17,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<17,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,19>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<17,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<17,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<18,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<18,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,20>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<17,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<17,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<18,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<18,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<19,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<19,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,21>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<17,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<17,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<18,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<18,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<19,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<19,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<20,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<20,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,22>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<17,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<17,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<18,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<18,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<19,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<19,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<20,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<20,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<21,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<21,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,23>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<17,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<17,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<18,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<18,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<19,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<19,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<20,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<20,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<21,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<21,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<22,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<22,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,24>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<17,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<17,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<18,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<18,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<19,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<19,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<20,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<20,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<21,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<21,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<22,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<22,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<23,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<23,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,25>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<17,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<17,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<18,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<18,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<19,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<19,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<20,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<20,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<21,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<21,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<22,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<22,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<23,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<23,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<24,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<24,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,26>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<17,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<17,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<18,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<18,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<19,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<19,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<20,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<20,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<21,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<21,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<22,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<22,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<23,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<23,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<24,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<24,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<25,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<25,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,27>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<17,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<17,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<18,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<18,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<19,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<19,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<20,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<20,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<21,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<21,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<22,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<22,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<23,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<23,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<24,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<24,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<25,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<25,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<26,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<26,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,28>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<17,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<17,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<18,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<18,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<19,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<19,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<20,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<20,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<21,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<21,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<22,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<22,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<23,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<23,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<24,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<24,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<25,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<25,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<26,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<26,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<27,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<27,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,29>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<17,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<17,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<18,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<18,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<19,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<19,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<20,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<20,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<21,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<21,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<22,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<22,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<23,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<23,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<24,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<24,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<25,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<25,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<26,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<26,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<27,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<27,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<28,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<28,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,30>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<17,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<17,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<18,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<18,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<19,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<19,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<20,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<20,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<21,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<21,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<22,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<22,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<23,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<23,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<24,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<24,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<25,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<25,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<26,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<26,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<27,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<27,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<28,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<28,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<29,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<29,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,31>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<17,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<17,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<18,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<18,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<19,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<19,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<20,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<20,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<21,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<21,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<22,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<22,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<23,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<23,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<24,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<24,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<25,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<25,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<26,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<26,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<27,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<27,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<28,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<28,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<29,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<29,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<30,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<30,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};


template<typename ModeIdType,typename ParamType,template<ModeIdType, typename> class PROCESSOR,typename TLIST>
struct switch_helper<ModeIdType,ParamType,PROCESSOR,TLIST,32>
{
    static inline void process(uint8_t label, ParamType value)
    {
        switch(label)
        {
        case TL::type_at<0,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<0,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<1,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<1,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<2,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<2,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<3,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<3,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<4,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<4,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<5,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<5,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<6,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<6,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<7,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<7,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<8,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<8,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<9,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<9,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<10,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<10,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<11,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<11,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<12,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<12,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<13,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<13,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<14,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<14,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<15,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<15,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<16,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<16,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<17,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<17,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<18,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<18,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<19,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<19,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<20,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<20,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<21,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<21,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<22,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<22,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<23,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<23,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<24,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<24,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<25,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<25,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<26,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<26,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<27,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<27,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<28,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<28,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<29,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<29,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<30,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<30,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        case TL::type_at<31,TLIST>::type::ID:
            PROCESSOR<static_cast<ModeIdType>(TL::type_at<31,TLIST>::type::ID), ParamType>::mode_process(value);
            break;
        default: ;
        }
    }
};



}
#endif


