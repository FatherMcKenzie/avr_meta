//Wed Sep 30 23:55:14 MSK 2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//

#ifndef BIT_FIELD_HELPER_HEADER
#define BIT_FIELD_HELPER_HEADER

#include "../../avr_misc/avr_misc.hpp"
#include "../../meta/typelist/typelist.hpp"
#include "../../misc/is_signed/is_signed.hpp"

namespace BF
{

template
<
    uint8_t MASK_LENGTH,
    uint8_t MASK_OFFSET = 0,
    typename ValueType = uint8_t
>
struct MASK
{
    static const ValueType value;
};
template<uint8_t MASK_LENGTH,uint8_t MASK_OFFSET,typename ValueType>
const ValueType MASK<MASK_LENGTH,MASK_OFFSET,ValueType>::value = static_cast<ValueType>(((ValueType(1) << MASK_LENGTH) - 1) << MASK_OFFSET);
//--------------------------------------------------------------

template
<
    uint8_t SIZE_BIT
>
struct FIELD_STORAGE_SIZE
{
    static const uint8_t value;
};

template<uint8_t SIZE_BIT>
const uint8_t FIELD_STORAGE_SIZE<SIZE_BIT>::value = (1 == SIZE_BIT) ? 0 : ((9 > SIZE_BIT) ? 1 : ((17 > SIZE_BIT) ? 2 : ((33 > SIZE_BIT) ? 4 : (65 > SIZE_BIT) ? 8 : -1)));

//==============================================================
template
<
    typename ID_TYPE,
    ID_TYPE ID,
    class CONTAINER
>
struct FIELD_INFO
{
    static const uint8_t WIDTH;
    static const uint8_t OFFSET;
};

template<typename ID_TYPE,ID_TYPE ID,class CONTAINER>
const uint8_t FIELD_INFO<ID_TYPE,ID,CONTAINER>::WIDTH  = TL::find_id<ID_TYPE, ID, typename CONTAINER::LIST>::type::WIDTH;
template<typename ID_TYPE,ID_TYPE ID,class CONTAINER>
const uint8_t FIELD_INFO<ID_TYPE,ID,CONTAINER>::OFFSET = TL::find_id<ID_TYPE, ID, typename CONTAINER::LIST>::type::OFFSET;;
//==============================================================
template
<
    uint8_t SIZE_BYTES,
    bool SIGNED
>
struct FIELD_TYPE_HELPER
{
    typedef bool type;
};

#define DECLARE_FIELD_TYPE(SIZE,SIGNED,OUTTYPE)   \
template<> struct FIELD_TYPE_HELPER<SIZE,SIGNED>{ typedef OUTTYPE type; };

// unsigned
DECLARE_FIELD_TYPE(1, false, uint8_t)
DECLARE_FIELD_TYPE(2, false, uint16_t)
DECLARE_FIELD_TYPE(4, false, uint32_t)
DECLARE_FIELD_TYPE(8, false, uint64_t)

// signed
DECLARE_FIELD_TYPE(1, true, int8_t)
DECLARE_FIELD_TYPE(2, true, int16_t)
DECLARE_FIELD_TYPE(4, true, int32_t)
DECLARE_FIELD_TYPE(8, true, int64_t)
//============================================================

template
<
    uint8_t SIZE_BIT,
    typename ValueType
>
struct FIELD_TYPE
{
    typedef typename FIELD_TYPE_HELPER< FIELD_STORAGE_SIZE<SIZE_BIT>::value, misc::IS_SIGNED<ValueType>::value >::type type;
};

//============================================================
template<typename ValueType>
struct NON_VOLATILE{typedef void type;};

#define DECLARE_NON_VOLATILE_TYPE(INTYPE,OUTTYPE)   \
template<> struct NON_VOLATILE<INTYPE>{ typedef OUTTYPE type; };

DECLARE_NON_VOLATILE_TYPE(bool,  bool);
DECLARE_NON_VOLATILE_TYPE(volatile bool,  bool);

DECLARE_NON_VOLATILE_TYPE(uint8_t,  uint8_t);
DECLARE_NON_VOLATILE_TYPE(uint16_t, uint16_t);
DECLARE_NON_VOLATILE_TYPE(uint32_t, uint32_t);
DECLARE_NON_VOLATILE_TYPE(uint64_t, uint64_t);

DECLARE_NON_VOLATILE_TYPE(int8_t,  int8_t);
DECLARE_NON_VOLATILE_TYPE(int16_t, int16_t);
DECLARE_NON_VOLATILE_TYPE(int32_t, int32_t);
DECLARE_NON_VOLATILE_TYPE(int64_t, int64_t);

DECLARE_NON_VOLATILE_TYPE(volatile uint8_t,  uint8_t);
DECLARE_NON_VOLATILE_TYPE(volatile uint16_t, uint16_t);
DECLARE_NON_VOLATILE_TYPE(volatile uint32_t, uint32_t);
DECLARE_NON_VOLATILE_TYPE(volatile uint64_t, uint64_t);

DECLARE_NON_VOLATILE_TYPE(volatile int8_t,  int8_t);
DECLARE_NON_VOLATILE_TYPE(volatile int16_t, int16_t);
DECLARE_NON_VOLATILE_TYPE(volatile int32_t, int32_t);
DECLARE_NON_VOLATILE_TYPE(volatile int64_t, int64_t);
//============================================================
template
<
    uint8_t MASK_LENGTH,
    uint8_t MASK_OFFSET,
    class ValueType
>
struct FIELD_CONTROL
{
    typedef typename FIELD_TYPE<MASK_LENGTH,ValueType>::type type;
    
    static type get_field(ValueType value)
    {
        return static_cast<type>((MASK<MASK_LENGTH,MASK_OFFSET,ValueType>::value & value) >> MASK_OFFSET);
    }
    
    static void set_field(typename NON_VOLATILE<ValueType>::type& value, type field_val)
    {
        value = ((value & static_cast<ValueType>(~MASK<MASK_LENGTH,MASK_OFFSET,ValueType>::value)) | (MASK<MASK_LENGTH,MASK_OFFSET,ValueType>::value & (field_val << MASK_OFFSET)));
    }

    static void set_field(volatile typename NON_VOLATILE<ValueType>::type& value, type field_val)
    {
        value = ((value & static_cast<ValueType>(~MASK<MASK_LENGTH,MASK_OFFSET,ValueType>::value)) | (MASK<MASK_LENGTH,MASK_OFFSET,ValueType>::value & (field_val << MASK_OFFSET)));
    }

    static ValueType make_field(type field_val)
    {
        return (MASK<MASK_LENGTH,MASK_OFFSET,ValueType>::value & (field_val << MASK_OFFSET));
    }

    template<type VALUE>
    static ValueType make_field()
    {
        return (MASK<MASK_LENGTH,MASK_OFFSET,ValueType>::value & (VALUE << MASK_OFFSET));
    }
};

template
<
    uint8_t MASK_OFFSET,
    class ValueType
>
struct FIELD_CONTROL<1,MASK_OFFSET,ValueType>
{
    typedef bool type;
    
    static bool get_field(ValueType value)
    {
        return static_cast<bool>(MASK<1,MASK_OFFSET,ValueType>::value & value); // no shift !!!
    }
    
    static void set_field(typename NON_VOLATILE<ValueType>::type& value, bool field_val)
    {
        //value = ((value & static_cast<ValueType>(~MASK<1,MASK_OFFSET,ValueType>::value)) | (MASK<1,MASK_OFFSET,ValueType>::value & (field_val << MASK_OFFSET)));
        
        if(field_val)   value |=     bit<MASK_OFFSET, ValueType>::value;
        else            value &= inv_bit<MASK_OFFSET, ValueType>::value;
    }

    static void set_field(volatile typename NON_VOLATILE<ValueType>::type& value, bool field_val)
    {
        //value = ((value & static_cast<ValueType>(~MASK<1,MASK_OFFSET,ValueType>::value)) | (MASK<1,MASK_OFFSET,ValueType>::value & (field_val << MASK_OFFSET)));

        if(field_val)   value |=     bit<MASK_OFFSET, ValueType>::value;
        else            value &= inv_bit<MASK_OFFSET, ValueType>::value;
    }
    
    static ValueType make_field(bool field_val)
    {
        if(!field_val) return 0;
        //return MASK<1,MASK_OFFSET,ValueType>::value;
        return bit<MASK_OFFSET, ValueType>::value;
    }
    
    template<bool VALUE>
    static ValueType make_field()
    {
        return ((VALUE) ? bit<MASK_OFFSET, ValueType>::value : 0);
    }
};



} // container namespace
#endif
