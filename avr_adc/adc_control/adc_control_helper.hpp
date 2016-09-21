// Tue May 26 15:29:13 MSK 2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//

#ifndef ADC_CONTROL_HELPER_HEADER
#define ADC_CONTROL_HELPER_HEADER

#include <stdint.h>

// TODO STATIC ASSERT FOR GAIN_10x and GAIN_200x

namespace 
{

#if 1
//Differential Input
enum DIFF_POSITIVE_INPUT  /**< Differential Input positive channel select */
{
    POS_ADC_0 = 0,
    POS_ADC_1,
    POS_ADC_2,
    POS_ADC_3,
    POS_ADC_4,
    POS_ADC_5,
    POS_ADC_6,
    POS_ADC_7,
    POS_ADC_8,
    POS_ADC_9,
    POS_ADC10,
    POS_ADC11,
    POS_ADC12,
    POS_ADC13,
    POS_ADC14,
    POS_ADC15,
};

enum DIFF_NEGATIVE_INPUT   /**< Differential Input negative channel select */
{
    NEG_ADC_0 = 0,
    NEG_ADC_1,
    NEG_ADC_2,
    NEG_ADC_8,
    NEG_ADC_9,
    NEG_ADC10,
};

enum DIFF_GAIN
{
    GAIN_1x     = 0,
    GAIN_10x    = 1,
    GAIN_200x   = 2
};

#endif
    
    
template
<
    DIFF_POSITIVE_INPUT pos,
    DIFF_NEGATIVE_INPUT neg,
    DIFF_GAIN gain = GAIN_1x,
    bool defined = true
>
struct diff_helper
{
    static const uint8_t ADMUX_value;  /**<  ADC Multiplexer Selection Register value */
};

//======================================================================================


#if 1

// #include "../../avr_misc/avr_misc.hpp"

template
<
    DIFF_POSITIVE_INPUT pos,
    DIFF_NEGATIVE_INPUT neg,
    DIFF_GAIN gain
>
struct diff_helper<pos,neg,gain,false>
{
    //  //BOOST_STATIC_ASSERT_MSG(1, ERROR_Specified_template_parameters_combination_is_not_supported);
    BOOST_STATIC_ASSERT_MSG(1, ERROR_Incorect_inputs_combination_specified);
};

#endif
//======================================================================================
#if 1
// negative NEG_ADC_1 & gain GAIN_1x specialization
template
<
    DIFF_POSITIVE_INPUT pos
>
struct diff_helper<pos, NEG_ADC_1, GAIN_1x, true>
{
    BOOST_STATIC_ASSERT_MSG(0 == (0xF8 & pos), ERROR_Incorect_positive_input_specified_for_negative_ADC1_input);
    static const uint8_t ADMUX_value;
};

template<DIFF_POSITIVE_INPUT pos>
const uint8_t diff_helper<pos, NEG_ADC_1, GAIN_1x, true>::ADMUX_value = (0x10 | (0x07 & pos));


// negative NEG_ADC_9 & gain GAIN_1x specialization
template
<
    DIFF_POSITIVE_INPUT pos
>
struct diff_helper<pos, NEG_ADC_9, GAIN_1x, true>
{
    BOOST_STATIC_ASSERT_MSG(0x08 == (0xF8 & pos), ERROR_Incorect_positive_input_specified_for_negative_ADC9_input);
    static const uint8_t ADMUX_value;
};
template<DIFF_POSITIVE_INPUT pos>
const uint8_t diff_helper<pos, NEG_ADC_9, GAIN_1x, true>::ADMUX_value = (0x30 | (0x07 & pos));


// negative NEG_ADC_2 & gain GAIN_1x specialization
template
<
    DIFF_POSITIVE_INPUT pos
>
struct diff_helper<pos, NEG_ADC_2, GAIN_1x, true>
{
    BOOST_STATIC_ASSERT_MSG((0x06 > pos), ERROR_Incorect_positive_input_specified_for_negative_ADC2_input);
    static const uint8_t ADMUX_value;
};

template<DIFF_POSITIVE_INPUT pos>
const uint8_t diff_helper<pos, NEG_ADC_2, GAIN_1x, true>::ADMUX_value = (0x18 | (0x07 & pos));


// negative NEG_ADC10 & gain GAIN_1x specialization
template
<
    DIFF_POSITIVE_INPUT pos
>
struct diff_helper<pos, NEG_ADC10, GAIN_1x, true>
{
    BOOST_STATIC_ASSERT_MSG(((0x07 < pos) && (0x0E > pos)), ERROR_Incorect_positive_input_specified_for_negative_ADC10_input);
    static const uint8_t ADMUX_value;
};

template<DIFF_POSITIVE_INPUT pos>
const uint8_t diff_helper<pos, NEG_ADC10, GAIN_1x, true>::ADMUX_value = (0x38 | (0x07 & pos));
#endif
//======================================================================================

#if 0 // TODO STATIC ASSERT FOR GAIN_10x and GAIN_200x
template
<
    DIFF_POSITIVE_INPUT pos,
    DIFF_NEGATIVE_INPUT neg
>
struct diff_helper<pos, neg, GAIN_10x, true>
{
    BOOST_STATIC_ASSERT_MSG(1, ERROR_Incorect_input_combination_specified);
    static const uint8_t ADMUX_value;
};
#endif

// positive POS_ADC_0 negative NEG_ADC_0 & gain GAIN_10x specialization
template<>
struct diff_helper<POS_ADC_0, NEG_ADC_0, GAIN_10x, true>
{
    static const uint8_t ADMUX_value; // = 0x08;
};
const uint8_t diff_helper<POS_ADC_0, NEG_ADC_0, GAIN_10x, true>::ADMUX_value = 0x08;


// positive POS_ADC_1 negative NEG_ADC_0 & gain GAIN_10x specialization
template<>
struct diff_helper<POS_ADC_1, NEG_ADC_0, GAIN_10x, true>
{
    static const uint8_t ADMUX_value; // = 0x09;
};
const uint8_t diff_helper<POS_ADC_1, NEG_ADC_0, GAIN_10x, true>::ADMUX_value = 0x09;


// positive POS_ADC_2 negative NEG_ADC_2 & gain GAIN_10x specialization
template<>
struct diff_helper<POS_ADC_2, NEG_ADC_2, GAIN_10x, true>
{
    static const uint8_t ADMUX_value; // = 0x0C;
};
const uint8_t diff_helper<POS_ADC_2, NEG_ADC_2, GAIN_10x, true>::ADMUX_value = 0x0C;

// positive POS_ADC_3 negative NEG_ADC_2 & gain GAIN_10x specialization
template<>
struct diff_helper<POS_ADC_3, NEG_ADC_2, GAIN_10x, true>
{
    static const uint8_t ADMUX_value; // = 0x0D;
};
const uint8_t diff_helper<POS_ADC_3, NEG_ADC_2, GAIN_10x, true>::ADMUX_value = 0x0D;


// positive POS_ADC_8 negative NEG_ADC_8 & gain GAIN_10x specialization
template<>
struct diff_helper<POS_ADC_8, NEG_ADC_8, GAIN_10x, true>
{
    static const uint8_t ADMUX_value; // = 0x28;
};
const uint8_t diff_helper<POS_ADC_8, NEG_ADC_8, GAIN_10x, true>::ADMUX_value = 0x28;

// positive POS_ADC_9 negative NEG_ADC_8 & gain GAIN_10x specialization
template<>
struct diff_helper<POS_ADC_9, NEG_ADC_8, GAIN_10x, true>
{
    static const uint8_t ADMUX_value; // = 0x29;
};
const uint8_t diff_helper<POS_ADC_9, NEG_ADC_8, GAIN_10x, true>::ADMUX_value = 0x29;

// positive POS_ADC10 negative NEG_ADC10 & gain GAIN_10x specialization
template<>
struct diff_helper<POS_ADC10, NEG_ADC10, GAIN_10x, true>
{
    static const uint8_t ADMUX_value; // = 0x2C;
};
const uint8_t diff_helper<POS_ADC10, NEG_ADC10, GAIN_10x, true>::ADMUX_value = 0x2C;

// positive POS_ADC11 negative NEG_ADC10 & gain GAIN_10x specialization
template<>
struct diff_helper<POS_ADC11, NEG_ADC10, GAIN_10x, true>
{
    static const uint8_t ADMUX_value; // = 0x2D;
};
const uint8_t diff_helper<POS_ADC11, NEG_ADC10, GAIN_10x, true>::ADMUX_value = 0x2D;
//======================================================================================

// positive POS_ADC_0 negative NEG_ADC_0 & gain GAIN_200x specialization
template<>
struct diff_helper<POS_ADC_0, NEG_ADC_0, GAIN_200x, true>
{
    static const uint8_t ADMUX_value; // = 0x0A;
};
const uint8_t diff_helper<POS_ADC_0, NEG_ADC_0, GAIN_200x, true>::ADMUX_value = 0x0A;

// positive POS_ADC_1 negative NEG_ADC_0 & gain GAIN_200x specialization
template<>
struct diff_helper<POS_ADC_1, NEG_ADC_0, GAIN_200x, true>
{
    static const uint8_t ADMUX_value; // = 0x0B;
};
const uint8_t diff_helper<POS_ADC_1, NEG_ADC_0, GAIN_200x, true>::ADMUX_value = 0x0B;


// positive POS_ADC_2 negative NEG_ADC_2 & gain GAIN_200x specialization
template<>
struct diff_helper<POS_ADC_2, NEG_ADC_2, GAIN_200x, true>
{
    static const uint8_t ADMUX_value; // = 0x0E;
};
const uint8_t diff_helper<POS_ADC_2, NEG_ADC_2, GAIN_200x, true>::ADMUX_value = 0x0E;

// positive POS_ADC_3 negative NEG_ADC_2 & gain GAIN_200x specialization
template<>
struct diff_helper<POS_ADC_3, NEG_ADC_2, GAIN_200x, true>
{
    static const uint8_t ADMUX_value; // = 0x0F;
};
const uint8_t diff_helper<POS_ADC_3, NEG_ADC_2, GAIN_200x, true>::ADMUX_value = 0x0F;


// positive POS_ADC_8 negative NEG_ADC_8 & gain GAIN_200x specialization
template<>
struct diff_helper<POS_ADC_8, NEG_ADC_8, GAIN_200x, true>
{
    static const uint8_t ADMUX_value; // = 0x2A;
};
const uint8_t diff_helper<POS_ADC_8, NEG_ADC_8, GAIN_200x, true>::ADMUX_value = 0x2A;

// positive POS_ADC_9 negative NEG_ADC_8 & gain GAIN_200x specialization
template<>
struct diff_helper<POS_ADC_9, NEG_ADC_8, GAIN_200x, true>
{
    static const uint8_t ADMUX_value; // = 0x2B;
};
const uint8_t diff_helper<POS_ADC_9, NEG_ADC_8, GAIN_200x, true>::ADMUX_value = 0x2B;


// positive POS_ADC10 negative NEG_ADC10 & gain GAIN_200x specialization
template<>
struct diff_helper<POS_ADC10, NEG_ADC10, GAIN_200x, true>
{
    static const uint8_t ADMUX_value; // = 0x2E;
};
const uint8_t diff_helper<POS_ADC10, NEG_ADC10, GAIN_200x, true>::ADMUX_value = 0x2E;

// positive POS_ADC11 negative NEG_ADC10 & gain GAIN_200x specialization
template<>
struct diff_helper<POS_ADC11, NEG_ADC10, GAIN_200x, true>
{
    static const uint8_t ADMUX_value; // = 0x2F;
};
const uint8_t diff_helper<POS_ADC11, NEG_ADC10, GAIN_200x, true>::ADMUX_value = 0x2F;



} // namespace



namespace adc_ps
{

template
<
    uint64_t VAL,
    uint64_t MAX,
    uint64_t MIN
>
struct out_of_range
{
    static const uint8_t value;
};

template<uint64_t VAL,uint64_t MAX,uint64_t MIN>
const uint8_t out_of_range<VAL,MAX,MIN>::value = (((MAX < VAL) || (MIN > VAL)) ? 1 : 0);


    
template
<
    uint64_t VAL0,
    uint64_t VAL1,
    uint8_t  INVALID0,
    uint8_t  INVALID1
>
struct minimal
{
    static const uint64_t value;
    static const uint8_t  invalid;
};

template<uint64_t VAL0, uint64_t VAL1,uint8_t INVALID0, uint8_t INVALID1>
const uint64_t minimal<VAL0,VAL1,INVALID0,INVALID1>::value = ((VAL0 < VAL1) ? VAL0 : VAL1);

template<uint64_t VAL0, uint64_t VAL1,uint8_t INVALID0,uint8_t INVALID1>
const uint8_t minimal<VAL0,VAL1,INVALID0,INVALID1>::invalid  = (INVALID0 && INVALID1);


template<uint64_t VAL0,uint64_t VAL1,uint8_t  INVALID0>
struct minimal<VAL0,VAL1,INVALID0,1>
{
    static const uint64_t value;
    static const uint8_t  invalid;
};
template<uint64_t VAL0,uint64_t VAL1,uint8_t  INVALID0>
const uint64_t minimal<VAL0,VAL1,INVALID0,1>::value = VAL0;

template<uint64_t VAL0,uint64_t VAL1,uint8_t  INVALID0>
const uint8_t minimal<VAL0,VAL1,INVALID0,1>::invalid = INVALID0;


template<uint64_t VAL0,uint64_t VAL1,uint8_t  INVALID1>
struct minimal<VAL0,VAL1,1,INVALID1>
{
    static const uint64_t value;
    static const uint8_t  invalid;
};
template<uint64_t VAL0,uint64_t VAL1,uint8_t  INVALID1>
const uint64_t minimal<VAL0,VAL1,1,INVALID1>::value = VAL1;

template<uint64_t VAL0,uint64_t VAL1,uint8_t  INVALID1>
const uint8_t minimal<VAL0,VAL1,1,INVALID1>::invalid = INVALID1;

template<uint64_t VAL0,uint64_t VAL1>
struct minimal<VAL0,VAL1,1,1>
{
    static const uint64_t value;
    static const uint8_t  invalid;
};
template<uint64_t VAL0,uint64_t VAL1>
const uint64_t minimal<VAL0,VAL1,1,1>::value = 0;

template<uint64_t VAL0,uint64_t VAL1>
const uint8_t minimal<VAL0,VAL1,1,1>::invalid = 1;

template
<
    uint64_t FACTOR,
    uint64_t CPU_CLOCK
>
struct ADC_CLOCK
{
    static const uint64_t value;
};

template<uint64_t FACTOR,uint64_t CPU_CLOCK>
const uint64_t ADC_CLOCK<FACTOR,CPU_CLOCK>::value = CPU_CLOCK / (1 << FACTOR);


// 2,4,8,16,32,64,128

enum INTERNAL_FACTOR // TODO Remove this !!!
{
    FACTOR_2   = 1,
    FACTOR_4   = 2,
    FACTOR_8   = 3,
    FACTOR_16  = 4,
    FACTOR_32  = 5,
    FACTOR_64  = 6,
    FACTOR_128 = 7,
    //DEF_FACTOR = 7
};


template
<
    uint64_t MAX_VALID,
    uint64_t MIN_VALID,
    uint64_t DEFAULT_FACTOR,
    uint64_t CPU_FREQ
>
struct max_valid_helper
{
    static const uint64_t value;
};

#if 1    
template<uint64_t MAX_VALID,uint64_t MIN_VALID,uint64_t DEFAULT_FACTOR,uint64_t CPU_FREQ>
const uint64_t max_valid_helper<MAX_VALID,MIN_VALID,DEFAULT_FACTOR,CPU_FREQ>::value = 
    minimal<
        minimal<
            minimal<   // MIN 2 vs 4 VAL
                FACTOR_2,
                FACTOR_4,
                out_of_range<ADC_CLOCK<FACTOR_2,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                out_of_range<ADC_CLOCK<FACTOR_4,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value
                >::value,

            minimal<    // MIN 8 vs 16 VAL
                FACTOR_8,
                FACTOR_16,
                out_of_range<ADC_CLOCK<FACTOR_8,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                out_of_range<ADC_CLOCK<FACTOR_16,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value
                >::value,
            //-----------------------------------------------------------------------
            minimal<    // MIN 2 vs 4 VALID
                FACTOR_2,
                FACTOR_4,
                out_of_range<ADC_CLOCK<FACTOR_2,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                out_of_range<ADC_CLOCK<FACTOR_4,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value
                >::invalid,
                
            minimal<    // MIN 8 vs 16 VALID
                FACTOR_8,
                FACTOR_16,
                out_of_range<ADC_CLOCK<FACTOR_8,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                out_of_range<ADC_CLOCK<FACTOR_16,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value
                >::invalid
            //-----------------------------------------------------------------------
            >::value,
       
        minimal<
            minimal<    // MIN 32 vs 64 VAL
                FACTOR_32,
                FACTOR_64,
                out_of_range<ADC_CLOCK<FACTOR_32,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                out_of_range<ADC_CLOCK<FACTOR_64,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value
                >::value,

            minimal<
                FACTOR_128,
                DEFAULT_FACTOR,
                out_of_range<ADC_CLOCK<FACTOR_128,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                0 // default valid
                >::value,
            //-----------------------------------------------------------------------
            minimal<    // MIN 32 vs 64 VALID
                FACTOR_32,
                FACTOR_64,
                out_of_range<ADC_CLOCK<FACTOR_32,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                out_of_range<ADC_CLOCK<FACTOR_64,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value
                >::invalid,
                
            minimal<    // MIN 128 vs DEFAULT VALID
                FACTOR_128,
                DEFAULT_FACTOR,
                out_of_range<ADC_CLOCK<FACTOR_128,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                0 // default valid
                >::invalid
            //-----------------------------------------------------------------------
            >::value,
        //===========================================================================
        minimal<
            minimal<    // MIN 2 vs 4 VAL
                FACTOR_2,
                FACTOR_4,
                out_of_range<ADC_CLOCK<FACTOR_2,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                out_of_range<ADC_CLOCK<FACTOR_4,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value
                >::value,

            minimal<    // MIN 8 vs 16 VAL
                FACTOR_8,
                FACTOR_16,
                out_of_range<ADC_CLOCK<FACTOR_8,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                out_of_range<ADC_CLOCK<FACTOR_16,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value
                >::value,
            //-----------------------------------------------------------------------
            minimal<    // MIN 2 vs 4 VALID
                FACTOR_2,
                FACTOR_4,
                out_of_range<ADC_CLOCK<FACTOR_2,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                out_of_range<ADC_CLOCK<FACTOR_4,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value
                >::invalid,
                
            minimal<    // MIN 8 vs 16 VALID
                FACTOR_8,
                FACTOR_16,
                out_of_range<ADC_CLOCK<FACTOR_8,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                out_of_range<ADC_CLOCK<FACTOR_16,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value
                >::invalid
            //-----------------------------------------------------------------------
            >::invalid,
        //===========================================================================
        minimal<
            minimal<    // MIN 32 vs 64 VAL
                FACTOR_32,
                FACTOR_64,
                out_of_range<ADC_CLOCK<FACTOR_32,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                out_of_range<ADC_CLOCK<FACTOR_64,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value
                >::value,

            minimal<    // MIN 128 vs DEFAULT VAL
                FACTOR_128,
                DEFAULT_FACTOR,
                out_of_range<ADC_CLOCK<FACTOR_128,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                0 // default valid
                >::value,
            //-----------------------------------------------------------------------
            minimal<    // MIN 32 vs 64 VALID
                FACTOR_32,
                FACTOR_64,
                out_of_range<ADC_CLOCK<FACTOR_32,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                out_of_range<ADC_CLOCK<FACTOR_64,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value
                >::invalid,
                
            minimal<    // MIN 128 vs DEFAULT VALID
                FACTOR_128,
                DEFAULT_FACTOR,
                out_of_range<ADC_CLOCK<FACTOR_128,CPU_FREQ>::value,MAX_VALID,MIN_VALID>::value,
                0 // default valid
                >::invalid
            //-----------------------------------------------------------------------
            >::invalid
    >::value;
#endif

} // namespace adc_ps




#endif
