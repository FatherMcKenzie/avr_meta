// Wed Sep 30 23:42:40  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef DATA_BIT_FIELD_CLASS_HEADER
#define DATA_BIT_FIELD_CLASS_HEADER

// #include <cstdio>

#include <stdint.h>
#include "../../avr_misc/avr_misc.hpp"
#include "bit_field_helper.hpp"
//#include "typelist.hpp"

#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
}; 
#endif

namespace BF
{
template
<
    uint8_t ID_VAL,
    uint8_t WIDTH_VAL  = 0,
    uint8_t OFFSET_VAL = 0
>
struct FIELD
{
    static const uint8_t ID;
    static const uint8_t WIDTH;
    static const uint8_t OFFSET;
};

template<uint8_t ID_VAL,uint8_t WIDTH_VAL,uint8_t OFFSET_VAL>
const uint8_t FIELD<ID_VAL,WIDTH_VAL,OFFSET_VAL>::ID = ID_VAL;
template<uint8_t ID_VAL,uint8_t WIDTH_VAL,uint8_t OFFSET_VAL>
const uint8_t FIELD<ID_VAL,WIDTH_VAL,OFFSET_VAL>::WIDTH = WIDTH_VAL;
template<uint8_t ID_VAL,uint8_t WIDTH_VAL,uint8_t OFFSET_VAL>
const uint8_t FIELD<ID_VAL,WIDTH_VAL,OFFSET_VAL>::OFFSET = OFFSET_VAL;



template
<
    class F00 = FIELD<-1>,
    class F01 = FIELD<-1>,
    class F02 = FIELD<-1>,
    class F03 = FIELD<-1>,
    class F04 = FIELD<-1>,
    class F05 = FIELD<-1>,
    class F06 = FIELD<-1>,
    class F07 = FIELD<-1>,
    class F08 = FIELD<-1>,
    class F09 = FIELD<-1>,
    class F10 = FIELD<-1>,
    class F11 = FIELD<-1>,
    class F12 = FIELD<-1>,
    class F13 = FIELD<-1>,
    class F14 = FIELD<-1>,
    class F15 = FIELD<-1>
>
struct FIELDS
{
    typedef TL::TYPELIST_16(F00,F01,F02,F03,F04,F05,F06,F07,F08,F09,F10,F11,F12,F13,F14,F15) LIST;
};

template
<
    typename ID_TYPE,
    class FIELDS_INFO,
    typename ValueType = uint8_t
>
class bit_field
{ 
#ifdef UNITTEST_MODE
    template<class T> friend class tut::test_object;
#endif
    ValueType int_value;
    
public:

    typedef ValueType value_type;
    
    /**
     * \brief Brief description which ends at this dot.
     * 
     * Details follow here.
     */
    
    /**
     * default constructor
     */
    bit_field(ValueType ext = 0) : int_value(ext){}

    template<ID_TYPE ID>
    typename FIELD_CONTROL<FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::WIDTH, FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::OFFSET, ValueType>::type get()const
    {
        //printf("non volatile\n");
        return FIELD_CONTROL<FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::WIDTH, FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::OFFSET, ValueType>::get_field(int_value);
    }
    
    template<ID_TYPE ID>
    void set(typename FIELD_CONTROL<FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::WIDTH, FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::OFFSET, ValueType>::type value)
    {
        FIELD_CONTROL<FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::WIDTH, FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::OFFSET, ValueType>::set_field(int_value, value);
    }

    template<ID_TYPE ID>
    typename FIELD_CONTROL<FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::WIDTH, FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::OFFSET, ValueType>::type get()const volatile
    {
        //printf("volatile\n");
        return FIELD_CONTROL<FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::WIDTH, FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::OFFSET, ValueType>::get_field(int_value);
    }
    
    template<ID_TYPE ID>
    void set(typename FIELD_CONTROL<FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::WIDTH, FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::OFFSET, ValueType>::type value) volatile
    {
        FIELD_CONTROL<FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::WIDTH, FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::OFFSET, ValueType>::set_field(int_value, value);
    }

    /**
     * the "make" static method is supposed to be used for the bit_field internal value construction, just use
     *    (bit_field::make<fld_0>(fld_val0) | bit_field::make<fld_1>(fld_val1) | ... | bit_field::make<fld_n>(fld_valn)) 
     * for initialization
     */
    template<ID_TYPE ID>
    static ValueType make(ValueType value)
    {
        return FIELD_CONTROL<FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::WIDTH, FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::OFFSET, ValueType>::make_field(value);
    }

    template<ID_TYPE ID, ValueType VALUE>
    static ValueType make()
    {
        return FIELD_CONTROL<FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::WIDTH, FIELD_INFO<ID_TYPE, ID, FIELDS_INFO>::OFFSET, ValueType>::template make_field<VALUE>();
    }
    
    void clear()
    {
        int_value = 0;
    }
};


} // container namespace
#endif

