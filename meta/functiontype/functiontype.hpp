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


#ifndef MPL_FUNCTIONTYPE_CLASS_HEADER
#define MPL_FUNCTIONTYPE_CLASS_HEADER

#include <stdint.h>
#include "../func_param_type/func_param_type.hpp"

#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
}; 
#endif


namespace mpl
{

template
<
    typename ReturnType
>
struct FUNC0
{
    typedef ReturnType (*type)();
    typedef ReturnType return_type;
};
    
template
<
    typename ReturnType,
    typename ParamType
>
struct FUNC1
{
    typedef ReturnType (*type)(ParamType);
    typedef ReturnType return_type;
    typedef typename PARAM<ParamType>::type param1type;
};

template
<
    typename ReturnType,
    typename Param1Type,
    typename Param2Type
>
struct FUNC2
{
    typedef ReturnType (*type)(Param1Type,Param2Type);
    typedef ReturnType return_type;
    typedef typename PARAM<Param1Type>::type param1type;
    typedef typename PARAM<Param2Type>::type param2type;
};

template
<
    typename ReturnType,
    typename Param1Type,
    typename Param2Type,
    typename Param3Type
>
struct FUNC3
{
    typedef ReturnType (*type)(Param1Type,Param2Type,Param3Type);
    typedef ReturnType return_type;
    typedef typename PARAM<Param1Type>::type param1type;
    typedef typename PARAM<Param2Type>::type param2type;
    typedef typename PARAM<Param3Type>::type param3type;
};

template
<
    typename ReturnType,
    typename Param1Type,
    typename Param2Type,
    typename Param3Type,
    typename Param4Type
>
struct FUNC4
{
    typedef ReturnType (*type)(Param1Type,Param2Type,Param3Type);
    typedef ReturnType return_type;
    typedef typename PARAM<Param1Type>::type param1type;
    typedef typename PARAM<Param2Type>::type param2type;
    typedef typename PARAM<Param3Type>::type param3type;
    typedef typename PARAM<Param4Type>::type param4type;
};
//=============================================
// WRAPPERS
// Functions returning VOID
template
<
    typename FUNC0<void>::type function
>
struct VOID_FUNCTION0
{
    typename FUNC0<void>::return_type operator()()
    {
        function();
    }

    typename FUNC0<void>::return_type func()
    {
        function();
    }
};

template
<
    typename ParamType,
    typename FUNC1<void, ParamType>::type function
>
struct VOID_FUNCTION1
{
    typename FUNC1<void, ParamType>::return_type operator()(typename FUNC1<void, ParamType>::param1type value)
    {
        function(value);
    }
};

// STATIC Functions returning VOID
template
<
    typename FUNC0<void>::type function
>
struct ST_VOID_FUNCTION0
{
    static typename FUNC0<void>::return_type func()
    {
        function();
    }
};

template
<
    typename ParamType,
    typename FUNC1<void,ParamType>::type function
>
struct ST_VOID_FUNCTION1
{
    static typename FUNC1<void,ParamType>::return_type func(typename FUNC1<void,ParamType>::param1type value)
    {
        function(value);
    }
};

//====================================
// Function returning boolean

template
<
    typename ParamType,
    typename FUNC1<bool, ParamType>::type function
>
struct BOOL_FUNCTION1
{
    typename FUNC1<bool, ParamType>::return_type operator()(typename FUNC1<bool, ParamType>::param1type value)
    {
        function(value);
    }

    typename FUNC1<bool, ParamType>::return_type func(typename FUNC1<bool, ParamType>::param1type value)
    {
        function(value);
    }
};

// STATIC 
template
<
    typename ParamType,
    typename FUNC1<bool,ParamType>::type function
>
struct ST_BOOL_FUNCTION1
{
    static typename FUNC1<bool,ParamType>::return_type func(typename FUNC1<bool,ParamType>::param1type value)
    {
        function(value);
    }
};



} // mpl namespace
#endif
