// Fri Feb 27 11:56:04  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//

#include <tut/tut.hpp>
#include "adc_control.hpp"

using namespace adc;

namespace tut
{ 
    
    struct data
    { 
    }; 
    
    typedef tut::test_group<tut::data> tg;
    tg testgroup("first_test_group");
    
    typedef tg::object testobject;
    
    template<>
    template<>
    void testobject::test<0>()
    { 
        set_test_name("test_0000 single channel");
        
        ensure_equals("test single channel SINGLE_ADC_0>", adc::SINGLE_ENDED<adc::SINGLE_ADC_0>::MUX_value, uint8_t(0b000000));
        ensure_equals("test single channel SINGLE_ADC_1>", adc::SINGLE_ENDED<adc::SINGLE_ADC_1>::MUX_value, uint8_t(0b000001));
        ensure_equals("test single channel SINGLE_ADC_2>", adc::SINGLE_ENDED<adc::SINGLE_ADC_2>::MUX_value, uint8_t(0b000010));
        ensure_equals("test single channel SINGLE_ADC_3>", adc::SINGLE_ENDED<adc::SINGLE_ADC_3>::MUX_value, uint8_t(0b000011));
        ensure_equals("test single channel SINGLE_ADC_4>", adc::SINGLE_ENDED<adc::SINGLE_ADC_4>::MUX_value, uint8_t(0b000100));
        ensure_equals("test single channel SINGLE_ADC_5>", adc::SINGLE_ENDED<adc::SINGLE_ADC_5>::MUX_value, uint8_t(0b000101));
        ensure_equals("test single channel SINGLE_ADC_6>", adc::SINGLE_ENDED<adc::SINGLE_ADC_6>::MUX_value, uint8_t(0b000110));
        ensure_equals("test single channel SINGLE_ADC_7>", adc::SINGLE_ENDED<adc::SINGLE_ADC_7>::MUX_value, uint8_t(0b000111));
        
        
        ensure_equals("test single channel SINGLE_ADC_8>", adc::SINGLE_ENDED<adc::SINGLE_ADC_8>::MUX_value, uint8_t(0b100000));
        ensure_equals("test single channel SINGLE_ADC_9>", adc::SINGLE_ENDED<adc::SINGLE_ADC_9>::MUX_value, uint8_t(0b100001));
        ensure_equals("test single channel SINGLE_ADC10>", adc::SINGLE_ENDED<adc::SINGLE_ADC10>::MUX_value, uint8_t(0b100010));
        ensure_equals("test single channel SINGLE_ADC11>", adc::SINGLE_ENDED<adc::SINGLE_ADC11>::MUX_value, uint8_t(0b100011));
        ensure_equals("test single channel SINGLE_ADC12>", adc::SINGLE_ENDED<adc::SINGLE_ADC12>::MUX_value, uint8_t(0b100100));
        ensure_equals("test single channel SINGLE_ADC13>", adc::SINGLE_ENDED<adc::SINGLE_ADC13>::MUX_value, uint8_t(0b100101));
        ensure_equals("test single channel SINGLE_ADC14>", adc::SINGLE_ENDED<adc::SINGLE_ADC14>::MUX_value, uint8_t(0b100110));
        ensure_equals("test single channel SINGLE_ADC15>", adc::SINGLE_ENDED<adc::SINGLE_ADC15>::MUX_value, uint8_t(0b100111));
    } 



#if 1
    template<>
    template<>
    void testobject::test<1>()
    { 
        set_test_name("test_0001 differential NEG_ADC_1, GAIN_1x");
        
        ensure_equals("test differential<POS_ADC_0, NEG_ADC_1, GAIN_1x>", diff_helper<POS_ADC_0, NEG_ADC_1, GAIN_1x, true>::ADMUX_value, uint8_t(0b010000));
        ensure_equals("test differential<POS_ADC_1, NEG_ADC_1, GAIN_1x>", diff_helper<POS_ADC_1, NEG_ADC_1, GAIN_1x, true>::ADMUX_value, uint8_t(0b010001));
        ensure_equals("test differential<POS_ADC_2, NEG_ADC_1, GAIN_1x>", diff_helper<POS_ADC_2, NEG_ADC_1, GAIN_1x, true>::ADMUX_value, uint8_t(0b010010));
        ensure_equals("test differential<POS_ADC_3, NEG_ADC_1, GAIN_1x>", diff_helper<POS_ADC_3, NEG_ADC_1, GAIN_1x, true>::ADMUX_value, uint8_t(0b010011));
        ensure_equals("test differential<POS_ADC_4, NEG_ADC_1, GAIN_1x>", diff_helper<POS_ADC_4, NEG_ADC_1, GAIN_1x, true>::ADMUX_value, uint8_t(0b010100));
        ensure_equals("test differential<POS_ADC_5, NEG_ADC_1, GAIN_1x>", diff_helper<POS_ADC_5, NEG_ADC_1, GAIN_1x, true>::ADMUX_value, uint8_t(0b010101));
        ensure_equals("test differential<POS_ADC_6, NEG_ADC_1, GAIN_1x>", diff_helper<POS_ADC_6, NEG_ADC_1, GAIN_1x, true>::ADMUX_value, uint8_t(0b010110));
        ensure_equals("test differential<POS_ADC_7, NEG_ADC_1, GAIN_1x>", diff_helper<POS_ADC_7, NEG_ADC_1, GAIN_1x, true>::ADMUX_value, uint8_t(0b010111));

        //ensure_equals("test differential<POS_ADC_8, NEG_ADC_1, GAIN_1x>", diff_helper<POS_ADC_8, NEG_ADC_1, GAIN_1x, true>::ADMUX_value, uint8_t(0b010111)); // compile time error expected
        //ensure_equals("test differential<POS_ADC15, NEG_ADC_1, GAIN_1x>", diff_helper<POS_ADC15, NEG_ADC_1, GAIN_1x, true>::ADMUX_value, uint8_t(0b010111)); // compile time error expected

    } 
    


    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002  differential NEG_ADC_2, GAIN_1x");
        
        ensure_equals("test differential<POS_ADC_0, NEG_ADC_2, GAIN_1x>", diff_helper<POS_ADC_0, NEG_ADC_2, GAIN_1x, true>::ADMUX_value, uint8_t(0b011000));
        ensure_equals("test differential<POS_ADC_1, NEG_ADC_2, GAIN_1x>", diff_helper<POS_ADC_1, NEG_ADC_2, GAIN_1x, true>::ADMUX_value, uint8_t(0b011001));
        ensure_equals("test differential<POS_ADC_2, NEG_ADC_2, GAIN_1x>", diff_helper<POS_ADC_2, NEG_ADC_2, GAIN_1x, true>::ADMUX_value, uint8_t(0b011010));
        ensure_equals("test differential<POS_ADC_3, NEG_ADC_2, GAIN_1x>", diff_helper<POS_ADC_3, NEG_ADC_2, GAIN_1x, true>::ADMUX_value, uint8_t(0b011011));
        ensure_equals("test differential<POS_ADC_4, NEG_ADC_2, GAIN_1x>", diff_helper<POS_ADC_4, NEG_ADC_2, GAIN_1x, true>::ADMUX_value, uint8_t(0b011100));
        ensure_equals("test differential<POS_ADC_5, NEG_ADC_2, GAIN_1x>", diff_helper<POS_ADC_5, NEG_ADC_2, GAIN_1x, true>::ADMUX_value, uint8_t(0b011101));
        
        //ensure_equals("test differential<POS_ADC_6, NEG_ADC_2, GAIN_1x>", diff_helper<POS_ADC_6, NEG_ADC_2, GAIN_1x, true>::ADMUX_value, uint8_t(0b011101)); // compile time error expected
        //ensure_equals("test differential<POS_ADC15, NEG_ADC_2, GAIN_1x>", diff_helper<POS_ADC15, NEG_ADC_2, GAIN_1x, true>::ADMUX_value, uint8_t(0b011101)); // compile time error expected
    } 
    

    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003   differential NEG_ADC_9, GAIN_1x");
        
        ensure_equals("test differential<POS_ADC_8, NEG_ADC_9, GAIN_1x>", diff_helper<POS_ADC_8, NEG_ADC_9, GAIN_1x, true>::ADMUX_value, uint8_t(0b110000));
        ensure_equals("test differential<POS_ADC_9, NEG_ADC_9, GAIN_1x>", diff_helper<POS_ADC_9, NEG_ADC_9, GAIN_1x, true>::ADMUX_value, uint8_t(0b110001));
        ensure_equals("test differential<POS_ADC10, NEG_ADC_9, GAIN_1x>", diff_helper<POS_ADC10, NEG_ADC_9, GAIN_1x, true>::ADMUX_value, uint8_t(0b110010));
        ensure_equals("test differential<POS_ADC11, NEG_ADC_9, GAIN_1x>", diff_helper<POS_ADC11, NEG_ADC_9, GAIN_1x, true>::ADMUX_value, uint8_t(0b110011));
        ensure_equals("test differential<POS_ADC12, NEG_ADC_9, GAIN_1x>", diff_helper<POS_ADC12, NEG_ADC_9, GAIN_1x, true>::ADMUX_value, uint8_t(0b110100));
        ensure_equals("test differential<POS_ADC13, NEG_ADC_9, GAIN_1x>", diff_helper<POS_ADC13, NEG_ADC_9, GAIN_1x, true>::ADMUX_value, uint8_t(0b110101));
        ensure_equals("test differential<POS_ADC14, NEG_ADC_9, GAIN_1x>", diff_helper<POS_ADC14, NEG_ADC_9, GAIN_1x, true>::ADMUX_value, uint8_t(0b110110));
        ensure_equals("test differential<POS_ADC15, NEG_ADC_9, GAIN_1x>", diff_helper<POS_ADC15, NEG_ADC_9, GAIN_1x, true>::ADMUX_value, uint8_t(0b110111));
        
        //ensure_equals("test differential<POS_ADC_7, NEG_ADC_9, GAIN_1x>", diff_helper<POS_ADC_7, NEG_ADC_9, GAIN_1x, true>::ADMUX_value, uint8_t(0b110000)); // compile time error expected
        //ensure_equals("test differential<POS_ADC_0, NEG_ADC_9, GAIN_1x>", diff_helper<POS_ADC_0, NEG_ADC_9, GAIN_1x, true>::ADMUX_value, uint8_t(0b110000)); // compile time error expected
    } 
    

    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004 differential NEG_ADC10, GAIN_1x");
        
        ensure_equals("test differential<POS_ADC_8, NEG_ADC10, GAIN_1x>", diff_helper<POS_ADC_8, NEG_ADC10, GAIN_1x, true>::ADMUX_value, uint8_t(0b111000));
        ensure_equals("test differential<POS_ADC_9, NEG_ADC10, GAIN_1x>", diff_helper<POS_ADC_9, NEG_ADC10, GAIN_1x, true>::ADMUX_value, uint8_t(0b111001));
        ensure_equals("test differential<POS_ADC10, NEG_ADC10, GAIN_1x>", diff_helper<POS_ADC10, NEG_ADC10, GAIN_1x, true>::ADMUX_value, uint8_t(0b111010));
        ensure_equals("test differential<POS_ADC11, NEG_ADC10, GAIN_1x>", diff_helper<POS_ADC11, NEG_ADC10, GAIN_1x, true>::ADMUX_value, uint8_t(0b111011));
        ensure_equals("test differential<POS_ADC12, NEG_ADC10, GAIN_1x>", diff_helper<POS_ADC12, NEG_ADC10, GAIN_1x, true>::ADMUX_value, uint8_t(0b111100));
        ensure_equals("test differential<POS_ADC13, NEG_ADC10, GAIN_1x>", diff_helper<POS_ADC13, NEG_ADC10, GAIN_1x, true>::ADMUX_value, uint8_t(0b111101));
        
        
        //ensure_equals("test differential<POS_ADC_7, NEG_ADC10, GAIN_1x>", diff_helper<POS_ADC_7, NEG_ADC10, GAIN_1x, true>::ADMUX_value, uint8_t(0b0)); // compile time error expected
        //ensure_equals("test differential<POS_ADC14, NEG_ADC10, GAIN_1x>", diff_helper<POS_ADC14, NEG_ADC10, GAIN_1x, true>::ADMUX_value, uint8_t(0b0)); // compile time error expected
    } 
#endif


#if 1
    template<>
    template<>
    void testobject::test<5>()
    { 
        set_test_name("test_0005 differential GAIN_10x");
        
        ensure_equals("test differential<POS_ADC_0, NEG_ADC_0, GAIN_10x>", diff_helper<POS_ADC_0, NEG_ADC_0, GAIN_10x, true>::ADMUX_value, uint8_t(0b001000));
        ensure_equals("test differential<POS_ADC_1, NEG_ADC_0, GAIN_10x>", diff_helper<POS_ADC_1, NEG_ADC_0, GAIN_10x, true>::ADMUX_value, uint8_t(0b001001));

        ensure_equals("test differential<POS_ADC_2, NEG_ADC_2, GAIN_10x>", diff_helper<POS_ADC_2, NEG_ADC_2, GAIN_10x, true>::ADMUX_value, uint8_t(0b001100));
        ensure_equals("test differential<POS_ADC_3, NEG_ADC_2, GAIN_10x>", diff_helper<POS_ADC_3, NEG_ADC_2, GAIN_10x, true>::ADMUX_value, uint8_t(0b001101));

        ensure_equals("test differential<POS_ADC_8, NEG_ADC_8, GAIN_10x>", diff_helper<POS_ADC_8, NEG_ADC_8, GAIN_10x, true>::ADMUX_value, uint8_t(0b101000)); // 101000
        ensure_equals("test differential<POS_ADC_9, NEG_ADC_8, GAIN_10x>", diff_helper<POS_ADC_9, NEG_ADC_8, GAIN_10x, true>::ADMUX_value, uint8_t(0b101001)); // 101001

        ensure_equals("test differential<POS_ADC10, NEG_ADC10, GAIN_10x>", diff_helper<POS_ADC10, NEG_ADC10, GAIN_10x, true>::ADMUX_value, uint8_t(0b101100)); // 101100
        ensure_equals("test differential<POS_ADC11, NEG_ADC10, GAIN_10x>", diff_helper<POS_ADC11, NEG_ADC10, GAIN_10x, true>::ADMUX_value, uint8_t(0b101101)); // 101101
        
        // TODO
        // ensure_equals("test differential<POS_ADC_2, NEG_ADC_0, GAIN_10x>", diff_helper<POS_ADC_2, NEG_ADC_0, GAIN_10x, true>::ADMUX_value, uint8_t(0b001000)); // compile time error
        
    }


    template<>
    template<>
    void testobject::test<6>()
    { 
        set_test_name("test_0006 differential GAIN_200x");
        
        ensure_equals("test differential<POS_ADC_0, NEG_ADC_0, GAIN_200x>", diff_helper<POS_ADC_0, NEG_ADC_0, GAIN_200x, true>::ADMUX_value, uint8_t(0b001010));
        ensure_equals("test differential<POS_ADC_1, NEG_ADC_0, GAIN_200x>", diff_helper<POS_ADC_1, NEG_ADC_0, GAIN_200x, true>::ADMUX_value, uint8_t(0b001011));

        ensure_equals("test differential<POS_ADC_2, NEG_ADC_2, GAIN_200x>", diff_helper<POS_ADC_2, NEG_ADC_2, GAIN_200x, true>::ADMUX_value, uint8_t(0b001110));
        ensure_equals("test differential<POS_ADC_3, NEG_ADC_2, GAIN_200x>", diff_helper<POS_ADC_3, NEG_ADC_2, GAIN_200x, true>::ADMUX_value, uint8_t(0b001111));

        ensure_equals("test differential<POS_ADC_8, NEG_ADC_8, GAIN_200x>", diff_helper<POS_ADC_8, NEG_ADC_8, GAIN_200x, true>::ADMUX_value, uint8_t(0b101010)); // 101010
        ensure_equals("test differential<POS_ADC_9, NEG_ADC_8, GAIN_200x>", diff_helper<POS_ADC_9, NEG_ADC_8, GAIN_200x, true>::ADMUX_value, uint8_t(0b101011)); // 101011

        ensure_equals("test differential<POS_ADC10, NEG_ADC10, GAIN_200x>", diff_helper<POS_ADC10, NEG_ADC10, GAIN_200x, true>::ADMUX_value, uint8_t(0b101110)); // 101110
        ensure_equals("test differential<POS_ADC11, NEG_ADC10, GAIN_200x>", diff_helper<POS_ADC11, NEG_ADC10, GAIN_200x, true>::ADMUX_value, uint8_t(0b101111)); // 101111
    }


#endif 


    template<>
    template<>
    void testobject::test<8>()
    { 
        set_test_name("test_0008 max_valid_helper");
        
        const uint64_t KHZ = 1000;
        const uint64_t MHZ = KHZ * KHZ;
        
        const uint64_t MIN = 50000;     // 50 Hz
        const uint64_t MAX = 200000;    //200 Hz
        
        //std::cout << adc_ps::max_valid_helper<MAX,MIN,CPU_F_16M>::value << ", 16m / val = " << CPU_F_16M / adc_ps::max_valid_helper<MAX,MIN,CPU_F_16M>::value << std::endl;
        
        const uint64_t DEFAULT_FACTOR = 42;
        
        // 50 KHz
        const uint64_t CPU_F_50K = 50 * KHZ;  // 50 KHz
        ensure_equals("max_valid_helper<MAX,MIN,CPU_F_50K>  DEFAULT", adc_ps::max_valid_helper<MAX,MIN,DEFAULT_FACTOR,CPU_F_50K>::value, DEFAULT_FACTOR);
        
        // 100 KHz
        const uint64_t CPU_F_100K = 100 * KHZ;  // 100 KHz
        ensure_equals("max_valid_helper<MAX,MIN,CPU_F_100K>", adc_ps::max_valid_helper<MAX,MIN,DEFAULT_FACTOR,CPU_F_100K>::value, DIV_2);
        
        // 1 MHz
        const uint64_t CPU_F_1M = MHZ;  // 1 MHz
        ensure_equals("max_valid_helper<MAX,MIN,CPU_F_1M>", adc_ps::max_valid_helper<MAX,MIN,DEFAULT_FACTOR,CPU_F_1M>::value, DIV_8);

        // 2 MHz
        const uint64_t CPU_F_2M = 2 * MHZ;  // 2 MHz
        ensure_equals("max_valid_helper<MAX,MIN,CPU_F_2M>", adc_ps::max_valid_helper<MAX,MIN,DEFAULT_FACTOR,CPU_F_2M>::value, DIV_16);

        // 4 MHz
        const uint64_t CPU_F_4M = 4 * MHZ;  // 4 MHz
        ensure_equals("max_valid_helper<MAX,MIN,CPU_F_4M>", adc_ps::max_valid_helper<MAX,MIN,DEFAULT_FACTOR,CPU_F_4M>::value, DIV_32);

        // 8 MHz
        const uint64_t CPU_F_8M = 8 * MHZ;  // 8 MHz
        ensure_equals("max_valid_helper<MAX,MIN,CPU_F_8M>", adc_ps::max_valid_helper<MAX,MIN,DEFAULT_FACTOR,CPU_F_8M>::value, DIV_64);

        // 16 MHz
        const uint64_t CPU_F_16M = 16 * MHZ;  // 16 MHz
        ensure_equals("max_valid_helper<MAX,MIN,CPU_F_16M>", adc_ps::max_valid_helper<MAX,MIN,DEFAULT_FACTOR,CPU_F_16M>::value, DIV_128);

        const uint64_t CPU_F_20M = 20 * MHZ;  // 20 MHz
        ensure_equals("max_valid_helper<MAX,MIN,CPU_F_20M>", adc_ps::max_valid_helper<MAX,MIN,DEFAULT_FACTOR,CPU_F_20M>::value, DIV_128);


        const uint64_t CPU_F_32M = 32 * MHZ;  // 20 MHz
        ensure_equals("max_valid_helper<MAX,MIN,CPU_F_32M> DEFAULT", adc_ps::max_valid_helper<MAX,MIN,DEFAULT_FACTOR,CPU_F_32M>::value, DEFAULT_FACTOR);
    }



    template<>
    template<>
    void testobject::test<16>()
    { 
        set_test_name("test_0016 ADC_CTRL");
        
#if 0
        //RIGHT_ADJUST = 0,   /**< the result is right adjusted */
        //LEFT_ADJUST  = 1    /**< the result is left adjusted */

        template
        <
            uint8_t dev_enable = ENABLE, /**< enables the ADC. Turning the ADC off while a conversion is in progress, will terminate this conversion. */
            uint8_t interrupt  = ENABLE, /**< enables ADC interrupt, when the I-bit in SREG is set, the ADC Conversion Complete Interrupt is activated. */
            ADLAR adj = RIGHT_ADJUST     /**< affects the presentation of the ADC conversion result in the ADC Data Register. Default value adjusts the result right. */
        >
        struct ADC_CTRL
#endif
        // ADMIX_mask  // 0x20
        ensure_equals("test DEVICE_CTRL<>::ADMIX_mask", DEVICE_CTRL<>::ADMIX_mask, uint8_t(0x00));
        
        ensure_equals("test DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>::ADMIX_mask", DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>::ADMIX_mask, uint8_t(0x00));
        ensure_equals("test DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>::ADMIX_mask",  DEVICE_CTRL<ENABLE,ENABLE, LEFT_ADJUST>::ADMIX_mask, uint8_t(0x20));
        ensure_equals("test DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>::ADMIX_mask", DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>::ADMIX_mask, uint8_t(0x00));
        ensure_equals("test DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>::ADMIX_mask",  DEVICE_CTRL<ENABLE,ENABLE, LEFT_ADJUST>::ADMIX_mask, uint8_t(0x20));
        ensure_equals("test DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>::ADMIX_mask", DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>::ADMIX_mask, uint8_t(0x00));
        ensure_equals("test DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>::ADMIX_mask",  DEVICE_CTRL<ENABLE,ENABLE, LEFT_ADJUST>::ADMIX_mask, uint8_t(0x20));
        ensure_equals("test DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>::ADMIX_mask", DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>::ADMIX_mask, uint8_t(0x00));
        ensure_equals("test DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>::ADMIX_mask",  DEVICE_CTRL<ENABLE,ENABLE, LEFT_ADJUST>::ADMIX_mask, uint8_t(0x20));
        
        // ADCSRA_mask // 0x80 // 0x08
        ensure_equals("test DEVICE_CTRL<>::ADCSRA_mask", DEVICE_CTRL<>::ADCSRA_mask, uint8_t(0x88));
        
        ensure_equals("test DEVICE_CTRL< ENABLE, ENABLE,RIGHT_ADJUST>::ADCSRA_mask", DEVICE_CTRL< ENABLE, ENABLE,RIGHT_ADJUST>::ADCSRA_mask, uint8_t(0x88));
        ensure_equals("test DEVICE_CTRL< ENABLE, ENABLE, LEFT_ADJUST>::ADCSRA_mask", DEVICE_CTRL< ENABLE, ENABLE, LEFT_ADJUST>::ADCSRA_mask, uint8_t(0x88));
        ensure_equals("test DEVICE_CTRL< ENABLE,DISABLE,RIGHT_ADJUST>::ADCSRA_mask", DEVICE_CTRL< ENABLE,DISABLE,RIGHT_ADJUST>::ADCSRA_mask, uint8_t(0x80));
        ensure_equals("test DEVICE_CTRL< ENABLE,DISABLE, LEFT_ADJUST>::ADCSRA_mask", DEVICE_CTRL< ENABLE,DISABLE, LEFT_ADJUST>::ADCSRA_mask, uint8_t(0x80));
        ensure_equals("test DEVICE_CTRL<DISABLE, ENABLE,RIGHT_ADJUST>::ADCSRA_mask", DEVICE_CTRL<DISABLE, ENABLE,RIGHT_ADJUST>::ADCSRA_mask, uint8_t(0x08));
        ensure_equals("test DEVICE_CTRL<DISABLE, ENABLE, LEFT_ADJUST>::ADCSRA_mask", DEVICE_CTRL<DISABLE, ENABLE, LEFT_ADJUST>::ADCSRA_mask, uint8_t(0x08));
        ensure_equals("test DEVICE_CTRL<DISABLE,DISABLE,RIGHT_ADJUST>::ADCSRA_mask", DEVICE_CTRL<DISABLE,DISABLE,RIGHT_ADJUST>::ADCSRA_mask, uint8_t(0x00));
        ensure_equals("test DEVICE_CTRL<DISABLE,DISABLE, LEFT_ADJUST>::ADCSRA_mask", DEVICE_CTRL<DISABLE,DISABLE, LEFT_ADJUST>::ADCSRA_mask, uint8_t(0x00));
    }


    template<>
    template<>
    void testobject::test<18>()
    { 
        set_test_name("test_0018 DIGITAL_INPUT_DISABLE");
        
        //DIGITAL_INPUT_DISABLE<>::reg0_val
        //DIGITAL_INPUT_DISABLE<>::reg2_val
        
        
        // DIGITAL_INPUT_DISABLE<>::reg0_val
        ensure_equals("test DIGITAL_INPUT_DISABLE<>::reg0_val", DIGITAL_INPUT_DISABLE<>::reg0_val, uint8_t(0x00));
        
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_0>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC_0>::reg0_val, uint8_t(0x01));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_0,DIN_ADC_1>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC_0,DIN_ADC_1>::reg0_val, uint8_t(0x03));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2>::reg0_val, uint8_t(0x07));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2,DIN_ADC_3>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2,DIN_ADC_3>::reg0_val, uint8_t(0x0F));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_1,DIN_ADC_2,DIN_ADC_3,DIN_ADC_4>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC_1,DIN_ADC_2,DIN_ADC_3,DIN_ADC_4>::reg0_val, uint8_t(0x1E));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_2,DIN_ADC_3,DIN_ADC_4,DIN_ADC_5>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC_2,DIN_ADC_3,DIN_ADC_4,DIN_ADC_5>::reg0_val, uint8_t(0x3C));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_3,DIN_ADC_4,DIN_ADC_5,DIN_ADC_6>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC_3,DIN_ADC_4,DIN_ADC_5,DIN_ADC_6>::reg0_val, uint8_t(0x78));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_4,DIN_ADC_5,DIN_ADC_6,DIN_ADC_7>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC_4,DIN_ADC_5,DIN_ADC_6,DIN_ADC_7>::reg0_val, uint8_t(0xF0));

        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_5,DIN_ADC_6,DIN_ADC_7,DIN_ADC_8>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC_5,DIN_ADC_6,DIN_ADC_7,DIN_ADC_8>::reg0_val, uint8_t(0xE0));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_6,DIN_ADC_7,DIN_ADC_8,DIN_ADC_9>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC_6,DIN_ADC_7,DIN_ADC_8,DIN_ADC_9>::reg0_val, uint8_t(0xC0));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_7,DIN_ADC_8,DIN_ADC_9,DIN_ADC10>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC_7,DIN_ADC_8,DIN_ADC_9,DIN_ADC10>::reg0_val, uint8_t(0x80));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_8,DIN_ADC_9,DIN_ADC10,DIN_ADC11>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC_8,DIN_ADC_9,DIN_ADC10,DIN_ADC11>::reg0_val, uint8_t(0x00));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_9,DIN_ADC10,DIN_ADC11,DIN_ADC12>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC_9,DIN_ADC10,DIN_ADC11,DIN_ADC12>::reg0_val, uint8_t(0x00));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC10,DIN_ADC11,DIN_ADC12,DIN_ADC13>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC10,DIN_ADC11,DIN_ADC12,DIN_ADC13>::reg0_val, uint8_t(0x00));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC11,DIN_ADC12,DIN_ADC13,DIN_ADC14>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC11,DIN_ADC12,DIN_ADC13,DIN_ADC14>::reg0_val, uint8_t(0x00));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC12,DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC12,DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg0_val, uint8_t(0x00));
        
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg0_val, uint8_t(0x00));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC14,DIN_ADC15>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC14,DIN_ADC15>::reg0_val, uint8_t(0x00));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC15>::reg0_val", DIGITAL_INPUT_DISABLE<DIN_ADC15>::reg0_val, uint8_t(0x00));
        

        // DIGITAL_INPUT_DISABLE<>::reg2_val
        ensure_equals("test DIGITAL_INPUT_DISABLE<>::reg2_val", DIGITAL_INPUT_DISABLE<>::reg2_val, uint8_t(0x00));
        
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_0>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC_0>::reg2_val, uint8_t(0x00));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_0,DIN_ADC_1>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC_0,DIN_ADC_1>::reg2_val, uint8_t(0x00));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2>::reg2_val, uint8_t(0x00));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2,DIN_ADC_3>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2,DIN_ADC_3>::reg2_val, uint8_t(0x00));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_1,DIN_ADC_2,DIN_ADC_3,DIN_ADC_4>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC_1,DIN_ADC_2,DIN_ADC_3,DIN_ADC_4>::reg2_val, uint8_t(0x00));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_2,DIN_ADC_3,DIN_ADC_4,DIN_ADC_5>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC_2,DIN_ADC_3,DIN_ADC_4,DIN_ADC_5>::reg2_val, uint8_t(0x00));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_3,DIN_ADC_4,DIN_ADC_5,DIN_ADC_6>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC_3,DIN_ADC_4,DIN_ADC_5,DIN_ADC_6>::reg2_val, uint8_t(0x00));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_4,DIN_ADC_5,DIN_ADC_6,DIN_ADC_7>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC_4,DIN_ADC_5,DIN_ADC_6,DIN_ADC_7>::reg2_val, uint8_t(0x00));

        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_5,DIN_ADC_6,DIN_ADC_7,DIN_ADC_8>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC_5,DIN_ADC_6,DIN_ADC_7,DIN_ADC_8>::reg2_val, uint8_t(0x01));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_6,DIN_ADC_7,DIN_ADC_8,DIN_ADC_9>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC_6,DIN_ADC_7,DIN_ADC_8,DIN_ADC_9>::reg2_val, uint8_t(0x03));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_7,DIN_ADC_8,DIN_ADC_9,DIN_ADC10>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC_7,DIN_ADC_8,DIN_ADC_9,DIN_ADC10>::reg2_val, uint8_t(0x07));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_8,DIN_ADC_9,DIN_ADC10,DIN_ADC11>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC_8,DIN_ADC_9,DIN_ADC10,DIN_ADC11>::reg2_val, uint8_t(0x0F));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC_9,DIN_ADC10,DIN_ADC11,DIN_ADC12>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC_9,DIN_ADC10,DIN_ADC11,DIN_ADC12>::reg2_val, uint8_t(0x1E));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC10,DIN_ADC11,DIN_ADC12,DIN_ADC13>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC10,DIN_ADC11,DIN_ADC12,DIN_ADC13>::reg2_val, uint8_t(0x3C));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC11,DIN_ADC12,DIN_ADC13,DIN_ADC14>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC11,DIN_ADC12,DIN_ADC13,DIN_ADC14>::reg2_val, uint8_t(0x78));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC12,DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC12,DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg2_val, uint8_t(0xF0));
        
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg2_val, uint8_t(0xE0));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC14,DIN_ADC15>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC14,DIN_ADC15>::reg2_val, uint8_t(0xC0));
        ensure_equals("test DIGITAL_INPUT_DISABLE<DIN_ADC15>::reg2_val", DIGITAL_INPUT_DISABLE<DIN_ADC15>::reg2_val, uint8_t(0x80));
    }



    template<>
    template<>
    void testobject::test<19>()
    { 
        set_test_name("test_0019 DIGITAL_INPUT_ENABLE");
        
        //DIGITAL_INPUT_ENABLE<>::reg0_val
        //DIGITAL_INPUT_ENABLE<>::reg2_val
        
        
        // DIGITAL_INPUT_ENABLE<>::reg0_val
        ensure_equals("test DIGITAL_INPUT_ENABLE<>::reg0_val", DIGITAL_INPUT_ENABLE<>::reg0_val, uint8_t(0xFF));
        
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_0>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC_0>::reg0_val, uint8_t(0xFE));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_0,DIN_ADC_1>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC_0,DIN_ADC_1>::reg0_val, uint8_t(0xFC));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2>::reg0_val, uint8_t(0xF8));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2,DIN_ADC_3>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2,DIN_ADC_3>::reg0_val, uint8_t(0xF0));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_1,DIN_ADC_2,DIN_ADC_3,DIN_ADC_4>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC_1,DIN_ADC_2,DIN_ADC_3,DIN_ADC_4>::reg0_val, uint8_t(0xE1));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_2,DIN_ADC_3,DIN_ADC_4,DIN_ADC_5>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC_2,DIN_ADC_3,DIN_ADC_4,DIN_ADC_5>::reg0_val, uint8_t(0xC3));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_3,DIN_ADC_4,DIN_ADC_5,DIN_ADC_6>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC_3,DIN_ADC_4,DIN_ADC_5,DIN_ADC_6>::reg0_val, uint8_t(0x87));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_4,DIN_ADC_5,DIN_ADC_6,DIN_ADC_7>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC_4,DIN_ADC_5,DIN_ADC_6,DIN_ADC_7>::reg0_val, uint8_t(0x0F));

        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_5,DIN_ADC_6,DIN_ADC_7,DIN_ADC_8>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC_5,DIN_ADC_6,DIN_ADC_7,DIN_ADC_8>::reg0_val, uint8_t(0x1F));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_6,DIN_ADC_7,DIN_ADC_8,DIN_ADC_9>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC_6,DIN_ADC_7,DIN_ADC_8,DIN_ADC_9>::reg0_val, uint8_t(0x3F));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_7,DIN_ADC_8,DIN_ADC_9,DIN_ADC10>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC_7,DIN_ADC_8,DIN_ADC_9,DIN_ADC10>::reg0_val, uint8_t(0x7F));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_8,DIN_ADC_9,DIN_ADC10,DIN_ADC11>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC_8,DIN_ADC_9,DIN_ADC10,DIN_ADC11>::reg0_val, uint8_t(0xFF));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_9,DIN_ADC10,DIN_ADC11,DIN_ADC12>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC_9,DIN_ADC10,DIN_ADC11,DIN_ADC12>::reg0_val, uint8_t(0xFF));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC10,DIN_ADC11,DIN_ADC12,DIN_ADC13>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC10,DIN_ADC11,DIN_ADC12,DIN_ADC13>::reg0_val, uint8_t(0xFF));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC11,DIN_ADC12,DIN_ADC13,DIN_ADC14>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC11,DIN_ADC12,DIN_ADC13,DIN_ADC14>::reg0_val, uint8_t(0xFF));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC12,DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC12,DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg0_val, uint8_t(0xFF));
        
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg0_val, uint8_t(0xFF));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC14,DIN_ADC15>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC14,DIN_ADC15>::reg0_val, uint8_t(0xFF));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC15>::reg0_val", DIGITAL_INPUT_ENABLE<DIN_ADC15>::reg0_val, uint8_t(0xFF));
        

        // DIGITAL_INPUT_ENABLE<>::reg2_val
        ensure_equals("test DIGITAL_INPUT_ENABLE<>::reg2_val", DIGITAL_INPUT_ENABLE<>::reg2_val, uint8_t(0xFF));
        
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_0>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC_0>::reg2_val, uint8_t(0xFF));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_0,DIN_ADC_1>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC_0,DIN_ADC_1>::reg2_val, uint8_t(0xFF));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2>::reg2_val, uint8_t(0xFF));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2,DIN_ADC_3>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC_0,DIN_ADC_1,DIN_ADC_2,DIN_ADC_3>::reg2_val, uint8_t(0xFF));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_1,DIN_ADC_2,DIN_ADC_3,DIN_ADC_4>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC_1,DIN_ADC_2,DIN_ADC_3,DIN_ADC_4>::reg2_val, uint8_t(0xFF));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_2,DIN_ADC_3,DIN_ADC_4,DIN_ADC_5>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC_2,DIN_ADC_3,DIN_ADC_4,DIN_ADC_5>::reg2_val, uint8_t(0xFF));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_3,DIN_ADC_4,DIN_ADC_5,DIN_ADC_6>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC_3,DIN_ADC_4,DIN_ADC_5,DIN_ADC_6>::reg2_val, uint8_t(0xFF));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_4,DIN_ADC_5,DIN_ADC_6,DIN_ADC_7>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC_4,DIN_ADC_5,DIN_ADC_6,DIN_ADC_7>::reg2_val, uint8_t(0xFF));

        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_5,DIN_ADC_6,DIN_ADC_7,DIN_ADC_8>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC_5,DIN_ADC_6,DIN_ADC_7,DIN_ADC_8>::reg2_val, uint8_t(0xFE));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_6,DIN_ADC_7,DIN_ADC_8,DIN_ADC_9>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC_6,DIN_ADC_7,DIN_ADC_8,DIN_ADC_9>::reg2_val, uint8_t(0xFC));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_7,DIN_ADC_8,DIN_ADC_9,DIN_ADC10>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC_7,DIN_ADC_8,DIN_ADC_9,DIN_ADC10>::reg2_val, uint8_t(0xF8));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_8,DIN_ADC_9,DIN_ADC10,DIN_ADC11>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC_8,DIN_ADC_9,DIN_ADC10,DIN_ADC11>::reg2_val, uint8_t(0xF0));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC_9,DIN_ADC10,DIN_ADC11,DIN_ADC12>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC_9,DIN_ADC10,DIN_ADC11,DIN_ADC12>::reg2_val, uint8_t(0xE1));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC10,DIN_ADC11,DIN_ADC12,DIN_ADC13>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC10,DIN_ADC11,DIN_ADC12,DIN_ADC13>::reg2_val, uint8_t(0xC3));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC11,DIN_ADC12,DIN_ADC13,DIN_ADC14>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC11,DIN_ADC12,DIN_ADC13,DIN_ADC14>::reg2_val, uint8_t(0x87));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC12,DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC12,DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg2_val, uint8_t(0x0F));
        
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC13,DIN_ADC14,DIN_ADC15>::reg2_val, uint8_t(0x1F));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC14,DIN_ADC15>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC14,DIN_ADC15>::reg2_val, uint8_t(0x3F));
        ensure_equals("test DIGITAL_INPUT_ENABLE<DIN_ADC15>::reg2_val", DIGITAL_INPUT_ENABLE<DIN_ADC15>::reg2_val, uint8_t(0x7F));
    }



    template<>
    template<>
    void testobject::test<20>()
    { 
        set_test_name("test_0020 ADC ADMUX_value");
        

#if 0
template
<
    class input_select,                             /**< selects which combination of analog inputs are connected to the ADC. possible options are SINGLE_ENDED or DIFFERENTIAL */
    class digital_input = DIGITAL_INPUT_DISABLE<>,  /**< specifies ADC pins whose digital input buffers should be disabled */
    class auto_trigger = AUTO_TRG_DISABLED,         /**< auto trigger control */
    class device_ctrl = DEVICE_CTRL<>,               /**< controls interrupt, device enabling and result adjusting */
    VOLTAGE_REF voltage_ref = AVCC,                 /**< specifies the voltage reference for the ADC */
    class prescaler = PS_MAX_VALID<>                /**< specifies prescaler values. Possible options are PS_DIV_FACTOR and PS_MAX_VALID */
>
struct ADC_CONTROL
#endif

    typedef DIGITAL_INPUT_ENABLE<> DID;
    typedef AUTO_TRG_DISABLED ATD;
#if 1
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_0>, DID, AREF, DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_0>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>, AREF >::ADMUX_value, uint8_t(0x00));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_4>, DID, AREF, DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_4>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>, AREF >::ADMUX_value, uint8_t(0x04));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_8>, DID, AREF, DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_8>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>, AREF >::ADMUX_value, uint8_t(0x00));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC15>, DID, AREF, DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC15>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,RIGHT_ADJUST>, AREF >::ADMUX_value, uint8_t(0x07));

        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_0>, DID, AREF, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_0>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, AREF >::ADMUX_value, uint8_t(0x20));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_4>, DID, AREF, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_4>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, AREF >::ADMUX_value, uint8_t(0x24));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_8>, DID, AREF, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_8>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, AREF >::ADMUX_value, uint8_t(0x20));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC15>, DID, AREF, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC15>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, AREF >::ADMUX_value, uint8_t(0x27));


        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_0>, DID, AVCC, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_0>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, AVCC >::ADMUX_value, uint8_t(0x60));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_4>, DID, AVCC, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_4>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, AVCC >::ADMUX_value, uint8_t(0x64));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_8>, DID, AVCC, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_8>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, AVCC >::ADMUX_value, uint8_t(0x60));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC15>, DID, AVCC, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC15>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, AVCC >::ADMUX_value, uint8_t(0x67));

        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_0>, DID, INT_1_1V, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_0>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, INT_1_1V >::ADMUX_value, uint8_t(0xA0));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_4>, DID, INT_1_1V, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_4>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, INT_1_1V >::ADMUX_value, uint8_t(0xA4));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_8>, DID, INT_1_1V, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_8>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, INT_1_1V >::ADMUX_value, uint8_t(0xA0));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC15>, DID, INT_1_1V, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC15>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, INT_1_1V >::ADMUX_value, uint8_t(0xA7));

        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_0>, DID, INT_2_6V, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_0>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, INT_2_6V >::ADMUX_value, uint8_t(0xE0));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_4>, DID, INT_2_6V, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_4>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, INT_2_6V >::ADMUX_value, uint8_t(0xE4));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_8>, DID, INT_2_6V, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC_8>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, INT_2_6V >::ADMUX_value, uint8_t(0xE0));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC15>, DID, INT_2_6V, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>", ADC_CONTROL<SINGLE_ENDED<adc::SINGLE_ADC15>, DID, ATD, DEVICE_CTRL<ENABLE,ENABLE,LEFT_ADJUST>, INT_2_6V >::ADMUX_value, uint8_t(0xE7));
#endif
    }
    
    template<>
    template<>
    void testobject::test<21>()
    { 
        set_test_name("test_0021 ADC ADCSRB_value");
        typedef DIGITAL_INPUT_ENABLE<> DID;
        
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<FREE_RUNNING_MODE> >::ADCSRB",    ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<FREE_RUNNING_MODE> >::ADCSRB_value,   uint8_t(0x00));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<ANALOG_COMPARATOR> >::ADCSRB",    ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<ANALOG_COMPARATOR> >::ADCSRB_value,   uint8_t(0x01));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<EXT_INT_0> >::ADCSRB",            ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<EXT_INT_0> >::ADCSRB_value,           uint8_t(0x02));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<TIMER_CNTR0_MATCH_A> >::ADCSRB",  ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<TIMER_CNTR0_MATCH_A> >::ADCSRB_value, uint8_t(0x03));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<TIMER_CNTR0_OVFL> >::ADCSRB",     ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<TIMER_CNTR0_OVFL> >::ADCSRB_value,    uint8_t(0x04));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<TIMER_CNTR1_MATCH_B> >::ADCSRB",  ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<TIMER_CNTR1_MATCH_B> >::ADCSRB_value, uint8_t(0x05));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<TIMER_CNTR1_OVFL> >::ADCSRB",     ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<TIMER_CNTR1_OVFL> >::ADCSRB_value,    uint8_t(0x06));
        ensure_equals("test ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<TIMER_CNTR1_EVENT> >::ADCSRB",    ADC_CONTROL<SINGLE_ENDED<SINGLE_ADC_0>, DID, AUTO_TRG_ENABLED<TIMER_CNTR1_EVENT> >::ADCSRB_value,   uint8_t(0x07));
    }


} 
