// Thu May 12 14:44:22  2016
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef MISC_IS_SIGNED_CLASS_HEADER
#define MISC_IS_SIGNED_CLASS_HEADER


#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
}; 
#endif


namespace misc
{

template
<
    typename ValueType
>
struct IS_SIGNED
{
    static const bool value;
};
template<typename ValueType>
const bool IS_SIGNED<ValueType>::value = (ValueType(-1) < ValueType(0));

} // misc namespace
#endif
