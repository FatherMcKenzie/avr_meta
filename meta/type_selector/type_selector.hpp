// Thu Dec 03 14:41:38  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//

// ************************************************************************************************************
// The code of the type_selector template is taken from Davide Di Gennaro's "Advanced C++ metaprogramming" book
// ************************************************************************************************************

#ifndef MPL_TYPE_SELECTOR_CLASS_HEADER
#define MPL_TYPE_SELECTOR_CLASS_HEADER

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
    bool CONDITION,
    typename TYPE_0,
    typename TYPE_1
>
struct type_selector
{
    typedef TYPE_0 type;
};

template
<
    typename TYPE_0,
    typename TYPE_1
>
struct type_selector<0,TYPE_0,TYPE_1>
{
    typedef TYPE_1 type;
}; 

//=========================================================

template
<
    unsigned INDEX,
    typename TYPE_0,
    typename TYPE_1,
    typename TYPE_2,
    typename TYPE_3
>
struct type_select
{
    typedef TYPE_0 type;
};

template<typename TYPE_0,typename TYPE_1,typename TYPE_2,typename TYPE_3>
struct type_select<1,TYPE_0,TYPE_1,TYPE_2,TYPE_3>
{
    typedef TYPE_1 type;
};
template<typename TYPE_0,typename TYPE_1,typename TYPE_2,typename TYPE_3>
struct type_select<2,TYPE_0,TYPE_1,TYPE_2,TYPE_3>
{
    typedef TYPE_2 type;
};
template<typename TYPE_0,typename TYPE_1,typename TYPE_2,typename TYPE_3>
struct type_select<3,TYPE_0,TYPE_1,TYPE_2,TYPE_3>
{
    typedef TYPE_3 type;
};



} // mpl namespace
#endif
