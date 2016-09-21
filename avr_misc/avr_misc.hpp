// Tue Feb 17 02:01:13  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef AVR_MISCELLANEOUS_HEADER
#define AVR_MISCELLANEOUS_HEADER


#ifdef UNITTEST_MODE

#include <stdint.h>

namespace tut
{
    template<class T> class test_object;
};


#endif


namespace //???
{

enum
{
    DISABLE = 0,
    ENABLE  = 1
};

#if 1
template
<
    int64_t VALUE
>
struct abs_value
{
    static const int64_t value;
};
template<int64_t VALUE>
const int64_t abs_value<VALUE>::value = ((0 > VALUE) ? (-VALUE) : VALUE);


template
<
    int64_t ACTUAL_VAL,
    int64_t EXPECTED_VAL
>
struct error
{
    static const uint64_t value;
};

template<int64_t ACTUAL_VAL,int64_t EXPECTED_VAL>
const uint64_t error<ACTUAL_VAL,EXPECTED_VAL>::value = abs_value<ACTUAL_VAL - EXPECTED_VAL>::value;


template
<
    uint64_t VAL0,
    uint64_t VAL1,
    uint16_t  IDX0,
    uint16_t  IDX1
>
struct minimal
{
    static const uint64_t value;
    static const uint16_t  index;
};

template<uint64_t VAL0, uint64_t VAL1,uint16_t IDX0,uint16_t IDX1>
const uint64_t minimal<VAL0,VAL1,IDX0,IDX1>::value = ((VAL0 < VAL1) ? VAL0 : VAL1);

template<uint64_t VAL0, uint64_t VAL1,uint16_t IDX0,uint16_t IDX1>
const uint16_t minimal<VAL0,VAL1,IDX0,IDX1>::index  = ((VAL0 < VAL1) ? IDX0 : IDX1);
#endif


template
<
    typename ValueType,
    ValueType test_value,
    ValueType MIN_LIMIT,
    ValueType MAX_LIMIT
>
struct out_of_range
{
    static const uint8_t value;
};

template<typename ValueType,ValueType test_value,ValueType MIN_LIMIT,ValueType MAX_LIMIT>
const uint8_t out_of_range<ValueType,test_value,MIN_LIMIT,MAX_LIMIT>::value = (((MIN_LIMIT > test_value) || (MAX_LIMIT < test_value)) ? 1 : 0);

//------------------------------------------------------------
template
<
    typename ValueType,
    ValueType MIN,
    ValueType MAX,
    ValueType VALUE
>
struct static_ensure_range
{
    static const ValueType value;
};
template<typename ValueType,ValueType MIN,ValueType MAX,ValueType VALUE>
const ValueType static_ensure_range<ValueType,MIN,MAX,VALUE>::value = ((MIN > VALUE) ? MIN : ((MAX < VALUE) ? MAX : VALUE));

//=============================================================
template
<
    typename ValueType,
    ValueType VALUE
>
struct static_value
{
    static const ValueType value;
};

template<typename ValueType,ValueType VALUE>
const ValueType static_value<ValueType,VALUE>::value = VALUE;

} // anonimous namespace

namespace misc
{

template<typename T>
T min(const T& a, const T& b){return (a < b) ? a : b;};

template<typename T>
T max(const T& a, const T& b){return (a < b) ? b : a;};

template<typename T>
T abs(const T& a){return ((T(0) > a) ? (-a) : a);}

template
<
    typename ValueType,
    ValueType MIN,
    ValueType MAX
>
ValueType ensure_range(ValueType value)
{
    if(MIN > value) return MIN;
    if(MAX < value) return MAX;
    return value;
}

template
<
    unsigned MIN,
    unsigned MAX,
    typename ValueType
>
ValueType ensure_val_in_range(ValueType value)
{
    if(static_cast<ValueType>(MIN) > value) return MIN;
    if(static_cast<ValueType>(MAX) < value) return MAX;
    return value;
}


template
<
    typename ValueType,
    ValueType MIN,
    ValueType MAX
>
bool out_of_range(ValueType value)
{
    return ((MIN > value) || (MAX < value));
}

template
<
    typename ValueType,
    ValueType MIN,
    ValueType MAX
>
bool inside_the_range(ValueType value)
{
    return ((MIN <= value) && (MAX >= value));
}

template
<
    typename ValueType,
    ValueType VALUE
>
bool is_equal(ValueType value)
{
    return (VALUE == value);
}

template<typename ValueType, ValueType VALUE>
bool is(ValueType value)
{
    return ((-1 == VALUE) ? 0 : (VALUE == value));
}

// TODO : Refactor this to use switch statement instead of OR, at least for small sets
// perhaps we need some additional template parameter ???

template
<
    typename ValueType,
    unsigned VAL_0 = -1,
    unsigned VAL_1 = -1,
    unsigned VAL_2 = -1,
    unsigned VAL_3 = -1,
    unsigned VAL_4 = -1,
    unsigned VAL_5 = -1,
    unsigned VAL_6 = -1,
    unsigned VAL_7 = -1,
    unsigned VAL_8 = -1,
    unsigned VAL_9 = -1,
    unsigned VAL_A = -1,
    unsigned VAL_B = -1,
    unsigned VAL_C = -1,
    unsigned VAL_D = -1,
    unsigned VAL_E = -1,
    unsigned VAL_F = -1
>struct set
{
    static bool contains(ValueType value)
    {
        return  is<ValueType, VAL_0>(value) ||
                is<ValueType, VAL_1>(value) ||
                is<ValueType, VAL_2>(value) ||
                is<ValueType, VAL_3>(value) ||
                is<ValueType, VAL_4>(value) ||
                is<ValueType, VAL_5>(value) ||
                is<ValueType, VAL_6>(value) ||
                is<ValueType, VAL_7>(value) ||
                is<ValueType, VAL_8>(value) ||
                is<ValueType, VAL_9>(value) ||
                is<ValueType, VAL_A>(value) ||
                is<ValueType, VAL_B>(value) ||
                is<ValueType, VAL_C>(value) ||
                is<ValueType, VAL_D>(value) ||
                is<ValueType, VAL_E>(value) ||
                is<ValueType, VAL_F>(value);
    }
};
//===============================================================

// actually these specializations are not necessary...
template<typename ValueType, ValueType VAL_0, ValueType VAL_1, ValueType VAL_2, ValueType VAL_3, ValueType VAL_4>
struct set<ValueType,VAL_0,VAL_1,VAL_2,VAL_3,VAL_4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1>
{
    static bool contains(ValueType value)
    {
        return  is<ValueType, VAL_0>(value) ||
                is<ValueType, VAL_1>(value) ||
                is<ValueType, VAL_2>(value) ||
                is<ValueType, VAL_3>(value) ||
                is<ValueType, VAL_4>(value);
    }
};

template<typename ValueType, ValueType VAL_0, ValueType VAL_1, ValueType VAL_2, ValueType VAL_3>
struct set<ValueType,VAL_0,VAL_1,VAL_2,VAL_3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1>
{
    static bool contains(ValueType value)
    {
        return  is<ValueType, VAL_0>(value) ||
                is<ValueType, VAL_1>(value) ||
                is<ValueType, VAL_2>(value) ||
                is<ValueType, VAL_3>(value);
    }
};

template<typename ValueType, ValueType VAL_0, ValueType VAL_1, ValueType VAL_2>
struct set<ValueType,VAL_0,VAL_1,VAL_2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1>
{
    static bool contains(ValueType value)
    {
        return  is<ValueType, VAL_0>(value) ||
                is<ValueType, VAL_1>(value) ||
                is<ValueType, VAL_2>(value);
    }
};

template<typename ValueType, ValueType VAL_0, ValueType VAL_1>
struct set<ValueType,VAL_0,VAL_1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1>
{
    static bool contains(ValueType value)
    {
        return  is<ValueType, VAL_0>(value) || is<ValueType, VAL_1>(value);
    }
};

//===============================================================

template<typename ValueType, ValueType VALUE, typename SizeType>
SizeType skip(const ValueType* data)
{
    for(SizeType offset = 0; ; ++offset){if(VALUE != *(data + offset)) return offset;}
}



}

//==============================================================
namespace
{
// anonimous namespace
uint8_t high_byte(uint16_t value)
{
    //return 0xFF & (value >> 8);
    return uint8_t(value >> 8);
}

uint8_t low_byte(uint16_t value)
{
    //return 0xFF & value;
    return uint8_t(value);
}
//====== opposite operation

uint16_t make_word(uint8_t high_byte, uint8_t low_byte)
{
    return ((high_byte << 8) | low_byte);
}
} // anonimous namespace
//==============================================================
template<typename ValueType>
struct byte_type
{
    typedef ValueType type;
};

#define DECLARE_BYTE_TYPE(INTYPE, OUTTYPE)  \
template<> struct byte_type<INTYPE>{        \
    typedef OUTTYPE type;                   \
};

// unsigned
DECLARE_BYTE_TYPE(uint8_t,  uint8_t);
DECLARE_BYTE_TYPE(uint16_t, uint8_t);
DECLARE_BYTE_TYPE(uint32_t, uint8_t);

// signed
DECLARE_BYTE_TYPE(int8_t,  int8_t);
DECLARE_BYTE_TYPE(int16_t, int8_t);
DECLARE_BYTE_TYPE(int32_t, int8_t);

//============================================================

namespace
{
template<typename ValueType,typename ResultType>
ResultType byte_3(const ValueType& value)
{
    return 0xFF & (value >> 24);
}

template<typename ValueType,typename ResultType>
ResultType byte_2(const ValueType& value)
{
    return 0xFF & (value >> 16);
}

template<typename ValueType,typename ResultType>
ResultType byte_1(const ValueType& value)
{
    return 0xFF & (value >> 8);
}

template<typename ValueType,typename ResultType>
ResultType byte_0(const ValueType& value)
{
    return 0xFF & value;
}
//==============================================================
template<typename ValueType, typename ByteType>
ValueType make_32_bit_value(ByteType byte_3, ByteType byte_2, ByteType byte_1, ByteType byte_0)
{
    return ((byte_3 << 24) | (byte_2 << 16) | (byte_1 << 8) | byte_0);
}

//=============================================================================

template<uint64_t input, uint8_t bytenum>
struct byte
{
    static const uint8_t value;
};
template<uint64_t input,uint8_t bytenum>
const uint8_t byte<input,bytenum>::value = 0xFF & (input >> (bytenum << 3));
}
//==============================================================
//

template
<
    unsigned MASK,
    typename ValueType

>
ValueType set_reset(unsigned condition, ValueType value)
{
    if(condition) return value | MASK;
    return value & ~MASK;
}

//==============================================================
template<uint16_t input_value>
struct HIGH_BYTE
{
    static const uint8_t value;
};
template<uint16_t input_value>
const uint8_t HIGH_BYTE<input_value>::value = 0xFF & (input_value >> 8);

template<uint16_t input_value>
struct LOW_BYTE
{
    static const uint8_t value;
};
template<uint16_t input_value>
const uint8_t LOW_BYTE<input_value>::value = 0xFF & input_value;
//==============================================================

template
<
    uint8_t bitnum,
    typename ValueType = uint8_t
>
struct bit
{
    static const ValueType value;
};

template<uint8_t bitnum, typename ValueType>
const ValueType bit<bitnum, ValueType>::value = ValueType(1) << bitnum;

// bitnum value of -1 specialization
template<typename ValueType>
struct bit<-1, ValueType> { static const ValueType value; };

template<typename ValueType>
const ValueType bit<-1, ValueType>::value = 0;

//========================================================
template
<
    uint8_t bitnum,
    typename ValueType = uint8_t
>
struct inv_bit
{
    static const ValueType value;
};
template<uint8_t bitnum, typename ValueType>
const ValueType inv_bit<bitnum, ValueType>::value = static_cast<ValueType>(~bit<bitnum, ValueType>::value);
//========================================================

template
<
    bool bitvalue,
    uint8_t bitnum,
    typename ValueType = uint8_t
>
struct bit_mask
{
    static const ValueType value;
};

template<bool bitvalue,uint8_t bitnum,typename ValueType>
const ValueType bit_mask<bitvalue,bitnum,ValueType>::value = ValueType((bitvalue) ? bit<bitnum, ValueType>::value : 0);

// USAGE : bit_mask<bitvalue,bitnum,ValueType>::value OR
// USAGE : bit_mask<bitvalue,bitnum>::value
//========================================================
template
<
    typename ValueType,
    bool condition,
    ValueType mask
>
struct condition_mask
{
    static const ValueType value;
};
template<typename ValueType,bool condition,ValueType mask>
const ValueType condition_mask<ValueType,condition,mask>::value = ((condition) ? mask : 0);

//========================================================

template
<
    uint8_t MASK_LENGTH,
    uint8_t MASK_OFFSET = 0,
    typename ValueType = uint8_t
>
struct mask
{
    static const ValueType value;
};

template<uint8_t MASK_LENGTH,uint8_t MASK_OFFSET,typename ValueType>
const ValueType mask<MASK_LENGTH,MASK_OFFSET,ValueType>::value = static_cast<ValueType>(((ValueType(1) << MASK_LENGTH) - 1) << MASK_OFFSET);

//========================================================

template
<
    unsigned mask_0 = 0,
    unsigned mask_1 = 0,
    unsigned mask_2 = 0,
    unsigned mask_3 = 0,
    unsigned mask_4 = 0,
    unsigned mask_5 = 0,
    unsigned mask_6 = 0,
    unsigned mask_7 = 0,
    typename ValueType = uint8_t
>
struct compound_masks
{
    static const ValueType value;
};

template<unsigned mask_0,unsigned mask_1,unsigned mask_2,unsigned mask_3,unsigned mask_4,unsigned mask_5,unsigned mask_6,unsigned mask_7,typename ValueType>
const ValueType compound_masks<mask_0,mask_1,mask_2,mask_3,mask_4,mask_5,mask_6,mask_7,ValueType>::value = (mask_0|mask_1|mask_2|mask_3|mask_4|mask_5|mask_6|mask_7);

template
<
    unsigned mask_0 = 0,
    unsigned mask_1 = 0,
    unsigned mask_2 = 0,
    unsigned mask_3 = 0,
    unsigned mask_4 = 0,
    unsigned mask_5 = 0,
    unsigned mask_6 = 0,
    unsigned mask_7 = 0,
    typename ValueType = uint8_t
>
struct inv_compound_masks
{
    static const ValueType value;
};

template<unsigned mask_0,unsigned mask_1,unsigned mask_2,unsigned mask_3,unsigned mask_4,unsigned mask_5,unsigned mask_6,unsigned mask_7,typename ValueType>
const ValueType inv_compound_masks<mask_0,mask_1,mask_2,mask_3,mask_4,mask_5,mask_6,mask_7,ValueType>::value = static_cast<ValueType>(~compound_masks<mask_0,mask_1,mask_2,mask_3,mask_4,mask_5,mask_6,mask_7,ValueType>::value);  


//==============================================================================================================

template
<
    unsigned mask_0 = 0,
    unsigned mask_1 = 0,
    unsigned mask_2 = 0,
    unsigned mask_3 = 0,
    unsigned mask_4 = 0,
    unsigned mask_5 = 0,
    unsigned mask_6 = 0,
    unsigned mask_7 = 0,
    unsigned mask_8 = 0,
    unsigned mask_9 = 0,
    unsigned mask_a = 0,
    unsigned mask_b = 0,
    unsigned mask_c = 0,
    unsigned mask_d = 0,
    unsigned mask_e = 0,
    unsigned mask_f = 0,
    typename ValueType = uint8_t
>
struct double_compound_mask
{
    static const ValueType low_value;  // Low byte value
    static const ValueType high_value; // High byte value
};
#if 0
template<unsigned mask_0,unsigned mask_1,unsigned mask_2,unsigned mask_3,unsigned mask_4,unsigned mask_5,unsigned mask_6,unsigned mask_7,
         unsigned mask_8,unsigned mask_9,unsigned mask_a,unsigned mask_b,unsigned mask_c,unsigned mask_d,unsigned mask_e,unsigned mask_f,typename ValueType>
const ValueType double_compound_mask<mask_0,mask_1,mask_2,mask_3,mask_4,mask_5,mask_6,mask_7,
                    mask_8,mask_9,mask_a,mask_b,mask_c,mask_d,mask_e,mask_f,ValueType>::low_value = 0xFF & (mask_0|mask_1|mask_2|mask_3|mask_4|mask_5|mask_6|mask_7|mask_8|mask_9|mask_a|mask_b|mask_c|mask_d|mask_e|mask_f);

template<unsigned mask_0,unsigned mask_1,unsigned mask_2,unsigned mask_3,unsigned mask_4,unsigned mask_5,unsigned mask_6,unsigned mask_7,
         unsigned mask_8,unsigned mask_9,unsigned mask_a,unsigned mask_b,unsigned mask_c,unsigned mask_d,unsigned mask_e,unsigned mask_f,typename ValueType>
const ValueType double_compound_mask<mask_0,mask_1,mask_2,mask_3,mask_4,mask_5,mask_6,mask_7,
                    mask_8,mask_9,mask_a,mask_b,mask_c,mask_d,mask_e,mask_f,ValueType>::high_value = 0xFF & ((mask_0|mask_1|mask_2|mask_3|mask_4|mask_5|mask_6|mask_7|mask_8|mask_9|mask_a|mask_b|mask_c|mask_d|mask_e|mask_f) >> 8);
#endif

template<unsigned mask_0,unsigned mask_1,unsigned mask_2,unsigned mask_3,unsigned mask_4,unsigned mask_5,unsigned mask_6,unsigned mask_7,
         unsigned mask_8,unsigned mask_9,unsigned mask_a,unsigned mask_b,unsigned mask_c,unsigned mask_d,unsigned mask_e,unsigned mask_f,typename ValueType>
const ValueType double_compound_mask<mask_0,mask_1,mask_2,mask_3,mask_4,mask_5,mask_6,mask_7,
                    mask_8,mask_9,mask_a,mask_b,mask_c,mask_d,mask_e,mask_f,ValueType>::low_value = LOW_BYTE<(mask_0|mask_1|mask_2|mask_3|mask_4|mask_5|mask_6|mask_7|mask_8|mask_9|mask_a|mask_b|mask_c|mask_d|mask_e|mask_f)>::value;

template<unsigned mask_0,unsigned mask_1,unsigned mask_2,unsigned mask_3,unsigned mask_4,unsigned mask_5,unsigned mask_6,unsigned mask_7,
         unsigned mask_8,unsigned mask_9,unsigned mask_a,unsigned mask_b,unsigned mask_c,unsigned mask_d,unsigned mask_e,unsigned mask_f,typename ValueType>
const ValueType double_compound_mask<mask_0,mask_1,mask_2,mask_3,mask_4,mask_5,mask_6,mask_7,
                    mask_8,mask_9,mask_a,mask_b,mask_c,mask_d,mask_e,mask_f,ValueType>::high_value = HIGH_BYTE<(mask_0|mask_1|mask_2|mask_3|mask_4|mask_5|mask_6|mask_7|mask_8|mask_9|mask_a|mask_b|mask_c|mask_d|mask_e|mask_f)>::value;
//==============================================================================================================

template
<
    uint8_t bita = -1,
    uint8_t bitb = -1,
    uint8_t bitc = -1,
    uint8_t bitd = -1,
    uint8_t bite = -1,
    uint8_t bitf = -1,
    uint8_t bitg = -1,
    uint8_t bith = -1,
    typename ValueType = uint8_t
>
struct bits_helper
{
    typedef ValueType value_type;
    static const ValueType value;
};

template<uint8_t bita,uint8_t bitb,uint8_t bitc,uint8_t bitd,uint8_t bite,uint8_t bitf,uint8_t bitg,uint8_t bith,typename ValueType>
const ValueType bits_helper<bita,bitb,bitc,bitd,bite,bitf,bitg,bith,ValueType>::value =
            compound_masks<
                    bit<bita, ValueType>::value,
                    bit<bitb, ValueType>::value,
                    bit<bitc, ValueType>::value,
                    bit<bitd, ValueType>::value,
                    bit<bite, ValueType>::value,
                    bit<bitf, ValueType>::value,
                    bit<bitg, ValueType>::value,
                    bit<bith, ValueType>::value,
                    ValueType
            >::value;
//==============================================================================================================

template
<
    uint8_t bita = -1,
    uint8_t bitb = -1,
    uint8_t bitc = -1,
    uint8_t bitd = -1,
    uint8_t bite = -1,
    uint8_t bitf = -1,
    uint8_t bitg = -1,
    uint8_t bith = -1
>
struct bits
{
    typedef uint8_t value_type;
    static const uint8_t value;
};

template<uint8_t bita,uint8_t bitb,uint8_t bitc,uint8_t bitd,uint8_t bite,uint8_t bitf,uint8_t bitg,uint8_t bith>
const uint8_t bits<bita,bitb,bitc,bitd,bite,bitf,bitg,bith>::value = bits_helper<bita,bitb,bitc,bitd,bite,bitf,bitg,bith>::value;

template
<
    uint8_t bita = -1,
    uint8_t bitb = -1,
    uint8_t bitc = -1,
    uint8_t bitd = -1,
    uint8_t bite = -1,
    uint8_t bitf = -1,
    uint8_t bitg = -1,
    uint8_t bith = -1
>
struct bits16
{
    typedef uint16_t value_type;
    static const uint16_t value;
};

template<uint8_t bita,uint8_t bitb,uint8_t bitc,uint8_t bitd,uint8_t bite,uint8_t bitf,uint8_t bitg,uint8_t bith>
const uint16_t bits16<bita,bitb,bitc,bitd,bite,bitf,bitg,bith>::value = bits_helper<bita,bitb,bitc,bitd,bite,bitf,bitg,bith,uint16_t>::value;




template
<
    uint8_t bita = -1,
    uint8_t bitb = -1,
    uint8_t bitc = -1,
    uint8_t bitd = -1,
    uint8_t bite = -1,
    uint8_t bitf = -1,
    uint8_t bitg = -1,
    uint8_t bith = -1
>
struct nobits
{
    typedef uint8_t value_type;
    static const uint8_t value;
};

template<uint8_t bita,uint8_t bitb,uint8_t bitc,uint8_t bitd,uint8_t bite,uint8_t bitf,uint8_t bitg,uint8_t bith>
const uint8_t nobits<bita,bitb,bitc,bitd,bite,bitf,bitg,bith>::value = static_cast<uint8_t>(~bits_helper<bita,bitb,bitc,bitd,bite,bitf,bitg,bith>::value);

// not tested ...
template
<
    uint8_t bita = -1,
    uint8_t bitb = -1,
    uint8_t bitc = -1,
    uint8_t bitd = -1,
    uint8_t bite = -1,
    uint8_t bitf = -1,
    uint8_t bitg = -1,
    uint8_t bith = -1
>
struct nobits16
{
    typedef uint16_t value_type;
    static const uint16_t value;
};

template<uint8_t bita,uint8_t bitb,uint8_t bitc,uint8_t bitd,uint8_t bite,uint8_t bitf,uint8_t bitg,uint8_t bith>
const uint16_t nobits16<bita,bitb,bitc,bitd,bite,bitf,bitg,bith>::value = static_cast<uint16_t>(~bits_helper<bita,bitb,bitc,bitd,bite,bitf,bitg,bith,uint16_t>::value);

//=================================================================================================
// Static assert
// Following code is taken from the boost library
//--------------------------------------------------

#ifndef BOOST_STATIC_ASSERT_MSG
//#ifndef BOOST_STATIC_ASSERT_BOOL_CAST
//#ifndef BOOST_JOIN
//#ifndef BOOST_DO_JOIN





//#ifndef BOOST_NO_CXX11_STATIC_ASSERT
//#  define BOOST_STATIC_ASSERT_MSG( B, Msg ) static_assert(B, Msg)
//#else
#  define BOOST_STATIC_ASSERT_MSG( B, Msg ) BOOST_STATIC_ASSERT( B )
//#endif

//
// If the compiler issues warnings about old C style casts,
// then enable this:
//
#if defined(__GNUC__) && ((__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 4)))
#  define BOOST_STATIC_ASSERT_BOOL_CAST( x ) ((x) == 0 ? false : true)
#else
#  define BOOST_STATIC_ASSERT_BOOL_CAST(x) (bool)(x)
#endif

//#ifndef BOOST_NO_CXX11_STATIC_ASSERT
//#  define BOOST_STATIC_ASSERT( B ) static_assert(B, #B)
//#else

namespace boost{

// HP aCC cannot deal with missing names for template value parameters
template <bool x> struct STATIC_ASSERTION_FAILURE;

template <> struct STATIC_ASSERTION_FAILURE<true> { enum { value = 1 }; };

// HP aCC cannot deal with missing names for template value parameters
template<int x> struct static_assert_test{};

}

#define BOOST_JOIN( X, Y ) BOOST_DO_JOIN( X, Y )
#define BOOST_DO_JOIN( X, Y ) BOOST_DO_JOIN2(X,Y, BLA_BLA)
#define BOOST_DO_JOIN2( X, Y, Z ) Z##X##Y##Z

// generic version
#define BOOST_STATIC_ASSERT( B ) \
   typedef ::boost::static_assert_test<\
      sizeof(::boost::STATIC_ASSERTION_FAILURE< BOOST_STATIC_ASSERT_BOOL_CAST( B ) >)>\
         BOOST_JOIN(boost_static_assert_typedef_, __LINE__)

#if 0
// alternative enum based implementation:
#define BOOST_STATIC_ASSERT( B ) \
   enum { BOOST_JOIN(boost_static_assert_enum_, __LINE__) \
      = sizeof(::boost::STATIC_ASSERTION_FAILURE< (bool)( B ) >) }

#endif

#endif


#endif
