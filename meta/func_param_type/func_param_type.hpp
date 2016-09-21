// Sat Dec 05 17:31:46  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef MPL_FUNC_PARAM_TYPE_CLASS_HEADER
#define MPL_FUNC_PARAM_TYPE_CLASS_HEADER

#include "../type_selector/type_selector.hpp"

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
    typename ValueType
>
struct PARAM
{
    typedef ValueType value_type;
    typedef typename mpl::type_selector<(sizeof(ValueType*) < sizeof(ValueType)), const ValueType&, ValueType>::type type;
};

} // mpl namespace
#endif


