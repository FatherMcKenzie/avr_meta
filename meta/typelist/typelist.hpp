// Tue Oct 20 01:24:24  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


// *******************************************************************************************
// Most of the code here is taken from Davide Di Gennaro's "Advanced C++ metaprogramming" book
// *******************************************************************************************



#ifndef TL_TYPELIST_CLASS_HEADER
#define TL_TYPELIST_CLASS_HEADER

#include <stdint.h>
#include "../type_selector/type_selector.hpp"

#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
}; 
#endif


namespace TL
{

struct LIST_TERM;

template
<
    typename T1,
    typename T2 = LIST_TERM
>
struct typelist
{
    typedef T1 HEAD;
    typedef T2 TAIL;
};

#if 1

#define TYPELIST_01(T01) typelist<T01, TL::LIST_TERM >
#define TYPELIST_02(T01, T02) typelist<T01, TL::TYPELIST_01(T02) >
#define TYPELIST_03(T01, T02, T03) typelist<T01, TL::TYPELIST_02(T02, T03) >
#define TYPELIST_04(T01, T02, T03, T04) typelist<T01, TL::TYPELIST_03(T02, T03, T04) >
#define TYPELIST_05(T01, T02, T03, T04, T05) typelist<T01, TL::TYPELIST_04(T02, T03, T04, T05) >
#define TYPELIST_06(T01, T02, T03, T04, T05, T06) typelist<T01, TL::TYPELIST_05(T02, T03, T04, T05, T06) >
#define TYPELIST_07(T01, T02, T03, T04, T05, T06, T07) typelist<T01, TL::TYPELIST_06(T02, T03, T04, T05, T06, T07) >
#define TYPELIST_08(T01, T02, T03, T04, T05, T06, T07, T08) typelist<T01, TL::TYPELIST_07(T02, T03, T04, T05, T06, T07, T08) >
#define TYPELIST_09(T01, T02, T03, T04, T05, T06, T07, T08, T09) typelist<T01, TL::TYPELIST_08(T02, T03, T04, T05, T06, T07, T08, T09) >
#define TYPELIST_10(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10) typelist<T01, TL::TYPELIST_09(T02, T03, T04, T05, T06, T07, T08, T09, T10) >
#define TYPELIST_11(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11) typelist<T01, TL::TYPELIST_10(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11) >
#define TYPELIST_12(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12) typelist<T01, TL::TYPELIST_11(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12) >
#define TYPELIST_13(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13) typelist<T01, TL::TYPELIST_12(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13) >
#define TYPELIST_14(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14) typelist<T01, TL::TYPELIST_13(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14) >
#define TYPELIST_15(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15) typelist<T01, TL::TYPELIST_14(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15) >
#define TYPELIST_16(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16) typelist<T01, TL::TYPELIST_15(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16) >
#define TYPELIST_17(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17) typelist<T01, TL::TYPELIST_16(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17) >
#define TYPELIST_18(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18) typelist<T01, TL::TYPELIST_17(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18) >
#define TYPELIST_19(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19) typelist<T01, TL::TYPELIST_18(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19) >
#define TYPELIST_20(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20) typelist<T01, TL::TYPELIST_19(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20) >
#define TYPELIST_21(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21) typelist<T01, TL::TYPELIST_20(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21) >
#define TYPELIST_22(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22) typelist<T01, TL::TYPELIST_21(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22) >
#define TYPELIST_23(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23) typelist<T01, TL::TYPELIST_22(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23) >
#define TYPELIST_24(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24) typelist<T01, TL::TYPELIST_23(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24) >
#define TYPELIST_25(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25) typelist<T01, TL::TYPELIST_24(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25) >
#define TYPELIST_26(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26) typelist<T01, TL::TYPELIST_25(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26) >
#define TYPELIST_27(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27) typelist<T01, TL::TYPELIST_26(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27) >
#define TYPELIST_28(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28) typelist<T01, TL::TYPELIST_27(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28) >
#define TYPELIST_29(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29) typelist<T01, TL::TYPELIST_28(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29) >
#define TYPELIST_30(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30) typelist<T01, TL::TYPELIST_29(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30) >
#define TYPELIST_31(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31) typelist<T01, TL::TYPELIST_30(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31) >
#define TYPELIST_32(T01, T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32) typelist<T01, TL::TYPELIST_31(T02, T03, T04, T05, T06, T07, T08, T09, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32) >

#endif
//=============================================================================================
template<class TYPE_LIST> struct typelist_len;

template<class H, class T>
struct typelist_len<typelist<H,T> >
{
    enum{ value = 1 + typelist_len<T>::value };
};

template<class U>
struct typelist_len<typelist<LIST_TERM,U> >
{
    enum {value = 0};
};

template <>
struct typelist_len<LIST_TERM>
{
    enum {value = 0};
};
//=============================================================================================

struct ERROR_UNDEFINED_TYPE;

template<typename TYPE>
struct type_of
{
    typedef TYPE type;
};

#if 1
// struct ERROR_UNDEFINED_TYPE;

template
<
    typename ID_TYPE,
    ID_TYPE ID,
    typename CONTAINER,
    typename ERR = ERROR_UNDEFINED_TYPE
>
struct find_id
{
    typedef ERR type;
};

template
<
    typename ID_TYPE,
    ID_TYPE ID,
    typename T0,
    typename T1,
    typename ERR
>
struct find_id<ID_TYPE, ID,typelist<T0,T1>,ERR>
{
    typedef typename mpl::type_selector<(ID == T0::ID), type_of<T0>, find_id<ID_TYPE, ID, T1, ERR> >::type aux_t;
    typedef typename aux_t::type type;
};
#endif

//==============================================================================================
template<unsigned INDEX,typename CONTAINER,typename ERR = ERROR_UNDEFINED_TYPE>struct type_at;

template
<
    unsigned INDEX,
    typename CONTAINER,
    typename ERR
>
struct type_at
{
    typedef ERR type;
};

template
<
    unsigned INDEX,
    typename T0,
    typename T1,
    typename ERR
>
struct type_at<INDEX,typelist<T0,T1>,ERR>
{
    typedef typename type_at<(INDEX - 1),T1,ERR>::type type;
};

template
<
    typename T0,
    typename T1,
    typename ERR
>
struct type_at<0, typelist<T0,T1>,ERR>
{
    typedef T0 type;
};
//==============================================================================================
template
<
    class S01 = LIST_TERM,
    class S02 = LIST_TERM,
    class S03 = LIST_TERM,
    class S04 = LIST_TERM,
    class S05 = LIST_TERM,
    class S06 = LIST_TERM,
    class S07 = LIST_TERM,
    class S08 = LIST_TERM,
    class S09 = LIST_TERM,
    class S10 = LIST_TERM,
    class S11 = LIST_TERM,
    class S12 = LIST_TERM,
    class S13 = LIST_TERM,
    class S14 = LIST_TERM,
    class S15 = LIST_TERM,
    class S16 = LIST_TERM,
    class S17 = LIST_TERM,
    class S18 = LIST_TERM,
    class S19 = LIST_TERM,
    class S20 = LIST_TERM,
    class S21 = LIST_TERM,
    class S22 = LIST_TERM,
    class S23 = LIST_TERM,
    class S24 = LIST_TERM,
    class S25 = LIST_TERM,
    class S26 = LIST_TERM,
    class S27 = LIST_TERM,
    class S28 = LIST_TERM,
    class S29 = LIST_TERM,
    class S30 = LIST_TERM,
    class S31 = LIST_TERM,
    class S32 = LIST_TERM
>
struct ITEMS
{
    typedef TL::TYPELIST_32(S01,S02,S03,S04,S05,S06,S07,S08,S09,S10,S11,S12,S13,S14,S15,S16,S17,S18,S19,S20,S21,S22,S23,S24,S25,S26,S27,S28,S29,S30,S31,S32) ITEMLIST;
    static const uint8_t LENGTH;
};
template<class S01,class S02,class S03,class S04,class S05,class S06,class S07,class S08,class S09,class S10,class S11,class S12,class S13,class S14,class S15,class S16,
        class S17,class S18,class S19,class S20,class S21,class S22,class S23,class S24,class S25,class S26,class S27,class S28,class S29,class S30,class S31,class S32>
const uint8_t ITEMS<S01,S02,S03,S04,S05,S06,S07,S08,S09,S10,S11,S12,S13,S14,S15,S16,S17,S18,S19,S20,S21,S22,S23,S24,S25,S26,S27,S28,S29,S30,S31,S32>::LENGTH = typelist_len<ITEMLIST>::value;


template
<
    class S01 = LIST_TERM,
    class S02 = LIST_TERM,
    class S03 = LIST_TERM,
    class S04 = LIST_TERM,
    class S05 = LIST_TERM,
    class S06 = LIST_TERM,
    class S07 = LIST_TERM,
    class S08 = LIST_TERM,
    class S09 = LIST_TERM,
    class S10 = LIST_TERM,
    class S11 = LIST_TERM,
    class S12 = LIST_TERM,
    class S13 = LIST_TERM,
    class S14 = LIST_TERM,
    class S15 = LIST_TERM,
    class S16 = LIST_TERM
>
struct ITEMS_16
{
    typedef TL::TYPELIST_16(S01,S02,S03,S04,S05,S06,S07,S08,S09,S10,S11,S12,S13,S14,S15,S16) ITEMLIST;
    static const uint8_t LENGTH;
};

template<class S01,class S02,class S03,class S04,class S05,class S06,class S07,class S08,class S09,class S10,class S11,class S12,class S13,class S14,class S15,class S16>
const uint8_t ITEMS_16<S01,S02,S03,S04,S05,S06,S07,S08,S09,S10,S11,S12,S13,S14,S15,S16>::LENGTH = typelist_len<ITEMLIST>::value;

template
<
    class S01 = LIST_TERM,
    class S02 = LIST_TERM,
    class S03 = LIST_TERM,
    class S04 = LIST_TERM,
    class S05 = LIST_TERM,
    class S06 = LIST_TERM,
    class S07 = LIST_TERM,
    class S08 = LIST_TERM
>
struct ITEMS_8
{
    typedef TL::TYPELIST_08(S01,S02,S03,S04,S05,S06,S07,S08) ITEMLIST;
    static const uint8_t LENGTH;
};

template<class S01,class S02,class S03,class S04,class S05,class S06,class S07,class S08>
const uint8_t ITEMS_8<S01,S02,S03,S04,S05,S06,S07,S08>::LENGTH = typelist_len<ITEMLIST>::value;

template
<
    class S01 = LIST_TERM,
    class S02 = LIST_TERM,
    class S03 = LIST_TERM,
    class S04 = LIST_TERM
>
struct ITEMS_4
{
    typedef TL::TYPELIST_04(S01,S02,S03,S04) ITEMLIST;
    static const uint8_t LENGTH;
};

template<class S01,class S02,class S03,class S04>
const uint8_t ITEMS_4<S01,S02,S03,S04>::LENGTH = typelist_len<ITEMLIST>::value;


} // TL namespace
#endif
