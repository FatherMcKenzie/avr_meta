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


#ifndef ADC_CONTROL_CLASS_HEADER
#define ADC_CONTROL_CLASS_HEADER

#include <stdint.h>

#include "../../avr_misc/avr_misc.hpp"


#ifndef UNITTEST_MODE
extern "C"
{
#include <avr/io.h>
}
#endif


#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
}; 
#endif

namespace adc
{

/**< ADC Voltage Reference
 * The reference voltage for the ADC (V REF ) indicates the conversion range for the ADC. Single
 * ended channels that exceed V REF will result in codes close to 0x3FF. V REF can be selected as
 * either AVCC, internal 1.1V reference, internal 2.56V reference or external AREF pin.
 * AVCC is connected to the ADC through a passive switch. The internal 1.1V reference is generated 
 * from the internal bandgap reference (VBG) through an internal amplifier. In either case, the
 * external AREF pin is directly connected to the ADC, and the reference voltage can be made
 * more immune to noise by connecting a capacitor between the AREF pin and ground. V REF can
 * also be measured at the AREF pin with a high impedant voltmeter. Note that V REF is a high
 * impedant source, and only a capacitive load should be connected in a system. The Internal
 * 2.56V reference is generated from the 1.1V reference.
 * If the user has a fixed voltage source connected to the AREF pin, the user may not use the other
 * reference voltage options in the application, as they will be shorted to the external voltage. If no
 * external voltage is applied to the AREF pin, the user may switch between AVCC, 1.1V and
 * 2.56V as reference selection. The first ADC conversion result after switching reference voltage
 * source may be inaccurate, and the user is advised to discard this result.
 * If differential channels are used, the selected reference should not be closer to AVCC than
 * indicated in “ADC Characteristics – Preliminary Data” on page 377.
 * 
 * 
 * Note: If 10x or 200x gain is selected, only 2.56V should be used as Internal Voltage Reference. 
 * For differential conversion, only 1.1V cannot be used as internal voltage reference.
 */
 
enum VOLTAGE_REF //Voltage reference selections
{
    AREF = 0,       /**< AREF, Internal V REF turned off */
    AVCC = 1,       /**< AVCC with external capacitor at AREF pin */
    INT_1_1V = 2,   /**< Internal 1.1V Voltage Reference with external capacitor at AREF pin */
    INT_2_6V = 3    /**< Internal 2.56V Voltage Reference with external capacitor at AREF pin */
};

// Single Ended Input
enum SINGLE_CHANNEL_INPUT         /**< Single Ended Input select */
{
    SINGLE_ADC_0 = 0x00,
    SINGLE_ADC_1 = 0x01,
    SINGLE_ADC_2 = 0x02,
    SINGLE_ADC_3 = 0x03,
    SINGLE_ADC_4 = 0x04,
    SINGLE_ADC_5 = 0x05,
    SINGLE_ADC_6 = 0x06,
    SINGLE_ADC_7 = 0x07,
    SINGLE_ADC_8 = 0x20,
    SINGLE_ADC_9 = 0x21,
    SINGLE_ADC10 = 0x22,
    SINGLE_ADC11 = 0x23,
    SINGLE_ADC12 = 0x24,
    SINGLE_ADC13 = 0x25,
    SINGLE_ADC14 = 0x26,
    SINGLE_ADC15 = 0x27,
    SINGLE_1V_VBG = 0x1E,   /**< 1.1V (V BG) */
    SINGLE_0V_GND = 0X1F,   /**< 0V (GND) */
    //SINGLE_RES_0 = 0x3E,    /**< Reserved */
    //SINGLE_RES_1 = 0x3F,    /**< Reserved */
};

template
<
    SINGLE_CHANNEL_INPUT single_input
>
struct SINGLE_ENDED
{
    static const uint8_t MUX_value;  /**<  ADC Multiplexer Selection Register MUX 5:0 */
};

template<SINGLE_CHANNEL_INPUT single_input>
const uint8_t SINGLE_ENDED<single_input>::MUX_value = static_cast<uint8_t>(0x3F & single_input);

//======================================================================================
#include "adc_control_helper.hpp"
//======================================================================================

/**
 * When using differential channels, certain aspects of the conversion need to be taken into consideration.
 * see p. 281
 */

template
<
    DIFF_POSITIVE_INPUT pos,
    DIFF_NEGATIVE_INPUT neg,
    DIFF_GAIN gain = GAIN_1x
>
struct DIFFERENTIAL
{
    static const uint8_t MUX_value;  /**<  ADC Multiplexer Selection Register MUX 5:0 */
};

template<DIFF_POSITIVE_INPUT pos,DIFF_NEGATIVE_INPUT neg,DIFF_GAIN gain>
const uint8_t DIFFERENTIAL<pos,neg,gain>::MUX_value = diff_helper<pos,neg,gain>::ADMUX_value;

/**
 * The ADLAR bit affects the presentation of the ADC conversion result in the ADC Data Register.
 * Write one to ADLAR to left adjust the result. Otherwise, the result is right adjusted. Changing the
 * ADLAR bit will affect the ADC Data Register immediately, regardless of any ongoing conversions. 
 * For a complete description of this bit, see “ADCL and ADCH – The ADC Data Register” on page 294.
 */

enum RESULT_ADJUST /**< ADC Left Adjust Result */
{
    RIGHT_ADJUST = 0,   /**< the result is right adjusted */
    LEFT_ADJUST  = 1    /**< the result is left adjusted */
};


struct AUTO_TRG_DISABLED //Auto Trigger// ADATE: ADC Auto Trigger Enable
{
    //static const unsigned enabled = 0;
    static const uint8_t ADCSRA_mask = 0;
    static const uint8_t ADCSRB_mask = 0;
};


enum TRIGGER_SOURCE
{
    FREE_RUNNING_MODE = 0,  /**< Free Running mode - Free running mode cannot be used for differential channels (see chapter “Differential Channels” on page 281). */
    ANALOG_COMPARATOR,      /**< Analog Comparator */
    EXT_INT_0,              /**< External Interrupt Request 0 */
    TIMER_CNTR0_MATCH_A,    /**< Timer/Counter0 Compare Match A */
    TIMER_CNTR0_OVFL,       /**< Timer/Counter0 Overflow */
    TIMER_CNTR1_MATCH_B,    /**< Timer/Counter1 Compare Match B */
    TIMER_CNTR1_OVFL,       /**< Timer/Counter1 Overflow */
    TIMER_CNTR1_EVENT       /**< Timer/Counter1 Capture Event */
};

template
<
    TRIGGER_SOURCE src
>
struct AUTO_TRG_ENABLED //Auto Trigger// ADATE: ADC Auto Trigger Enable
{
    //static const unsigned enabled = 1;
    static const uint8_t ADCSRA_mask = bit<5>::value; //Bit 5 – ADATE: ADC Auto Trigger Enable
    static const uint8_t ADCSRB_mask;
};

//template<TRIGGER_SOURCE src>
//const uint8_t AUTO_TRG_ENABLED<src>::ADCSRA_mask = bit<>::value; //Bit 5 – ADATE: ADC Auto Trigger Enable

template<TRIGGER_SOURCE src>
const uint8_t AUTO_TRG_ENABLED<src>::ADCSRB_mask = (0x07 & src);



/**
 * By default, the successive approximation circuitry requires an input clock frequency between
 * 50kHz and 200kHz. If a lower resolution than 10 bits is needed, the input clock frequency to the
 * ADC can be as high as 1000kHz to get a higher sample rate.
 */
enum PS_DIV_FACTOR_VAL // ADC Prescaler Select - determines the division factor between the XTAL frequency and the input clock to the ADC
{
    DIV_2   = 1,
    DIV_4   = 2,
    DIV_8   = 3,
    DIV_16  = 4,
    DIV_32  = 5,
    DIV_64  = 6,
    DIV_128 = 7
};

/**< xxxxxxxxxxxxxxxxxxxxxxxxxx */


#ifndef F_CPU
#define F_CPU 16000000L
#endif


template
<
    PS_DIV_FACTOR_VAL factor = DIV_128
>
struct PS_DIV_FACTOR
{
    static const uint8_t value;
};

template<PS_DIV_FACTOR_VAL factor>
const uint8_t PS_DIV_FACTOR<factor>::value = factor;


/**< 
 * By default, the successive approximation circuitry requires an input clock frequency between 50kHz and 200kHz.
 * If a lower resolution than 10 bits is needed, the input clock frequency to the ADC can be as high as 1000kHz to get a higher sample rate.
 */

template
<
    uint64_t MAX_VALID = 200000,        /**< Maximal acceptable approximation clock frequency. Default value is 200 kHz. 
                                         * If a lower resolution than 10 bits is needed, the input clock frequency to the
                                         * ADC can be higher than 200kHz to get a higher sample rate. */
    uint64_t MIN_VALID = 50000,         /**< Minimal successive approximation clock frequency. Default value is 50 kHz */
    uint64_t DEFAULT_FACTOR = DIV_128,  /**< Prescaler factor value used in the case when provided combination CPU clock and prescaler results in out of range ADC clock frequency. */
    uint64_t CPU_FREQ = F_CPU           /**< CPU clock frequency. F_CPU value should be defined above, supposedly with the GCC -D command line option (-DF_CPU=16000000L) */
>
struct PS_MAX_VALID
{
    static const uint8_t value;
};

template<uint64_t MAX_VALID,uint64_t MIN_VALID,uint64_t DEFAULT_FACTOR,uint64_t CPU_FREQ>
const uint8_t PS_MAX_VALID<MAX_VALID,MIN_VALID,DEFAULT_FACTOR,CPU_FREQ>::value = adc_ps::max_valid_helper<MAX_VALID,MIN_VALID,DEFAULT_FACTOR,CPU_FREQ>::value;


/** 
 * When these values specified, the digital input buffers on the corresponding ADC pins are disabled. 
 * The corresponding PIN Register bit will always read as zero when this bit is set. When an
 * analog signal is applied to the ADC15:0 pin and the digital input from this pin is not needed, these
 * values should be specified to reduce power consumption in the digital input buffers. 
 */

enum INPUT_CTRL /**< Digital Input Disable Register */
{
    NO_CTRL = 0,        /**< Enable the digital input buffer */
    DIN_ADC_0 = (1 <<  0),  /**< Controls the digital input buffer on the ADC0 pin */
    DIN_ADC_1 = (1 <<  1),  /**< Controls the digital input buffer on the ADC1 pin */
    DIN_ADC_2 = (1 <<  2),  /**< Controls the digital input buffer on the ADC2 pin */
    DIN_ADC_3 = (1 <<  3),  /**< Controls the digital input buffer on the ADC3 pin */
    DIN_ADC_4 = (1 <<  4),  /**< Controls the digital input buffer on the ADC4 pin */
    DIN_ADC_5 = (1 <<  5),  /**< Controls the digital input buffer on the ADC5 pin */
    DIN_ADC_6 = (1 <<  6),  /**< Controls the digital input buffer on the ADC6 pin */
    DIN_ADC_7 = (1 <<  7),  /**< Controls the digital input buffer on the ADC7 pin */
    DIN_ADC_8 = (1 <<  8),  /**< Controls the digital input buffer on the ADC8 pin */
    DIN_ADC_9 = (1 <<  9),  /**< Controls the digital input buffer on the ADC9 pin */
    DIN_ADC10 = (1 << 10),  /**< Controls the digital input buffer on the ADC10 pin */
    DIN_ADC11 = (1 << 11),  /**< Controls the digital input buffer on the ADC11 pin */
    DIN_ADC12 = (1 << 12),  /**< Controls the digital input buffer on the ADC12 pin */    
    DIN_ADC13 = (1 << 13),  /**< Controls the digital input buffer on the ADC13 pin */
    DIN_ADC14 = (1 << 14),  /**< Controls the digital input buffer on the ADC14 pin */
    DIN_ADC15 = (1 << 15),  /**< Controls the digital input buffer on the ADC15 pin */
};

#if 1
template
<
   INPUT_CTRL input0 = adc::NO_CTRL,
   INPUT_CTRL input1 = adc::NO_CTRL,
   INPUT_CTRL input2 = adc::NO_CTRL,
   INPUT_CTRL input3 = adc::NO_CTRL,
   INPUT_CTRL input4 = adc::NO_CTRL,
   INPUT_CTRL input5 = adc::NO_CTRL,
   INPUT_CTRL input6 = adc::NO_CTRL,
   INPUT_CTRL input7 = adc::NO_CTRL,
   INPUT_CTRL input8 = adc::NO_CTRL,
   INPUT_CTRL input9 = adc::NO_CTRL,
   INPUT_CTRL inputa = adc::NO_CTRL,
   INPUT_CTRL inputb = adc::NO_CTRL,
   INPUT_CTRL inputc = adc::NO_CTRL,
   INPUT_CTRL inputd = adc::NO_CTRL,
   INPUT_CTRL inpute = adc::NO_CTRL,
   INPUT_CTRL inputf = adc::NO_CTRL
>
struct DIGITAL_INPUT_DISABLE
{
    static const uint8_t reg0_val;
    static const uint8_t reg2_val;
};

template<INPUT_CTRL input0,INPUT_CTRL input1,INPUT_CTRL input2,INPUT_CTRL input3,INPUT_CTRL input4,INPUT_CTRL input5,INPUT_CTRL input6,INPUT_CTRL input7,
         INPUT_CTRL input8,INPUT_CTRL input9,INPUT_CTRL inputa,INPUT_CTRL inputb,INPUT_CTRL inputc,INPUT_CTRL inputd,INPUT_CTRL inpute,INPUT_CTRL inputf>
const uint8_t DIGITAL_INPUT_DISABLE<input0,input1,input2,input3,input4,input5,input6,input7,input8,input9,inputa,inputb,inputc,inputd,inpute,inputf>::reg0_val = 
        double_compound_mask<input0,input1,input2,input3,input4,input5,input6,input7,input8,input9,inputa,inputb,inputc,inputd,inpute,inputf>::low_value;

template<INPUT_CTRL input0,INPUT_CTRL input1,INPUT_CTRL input2,INPUT_CTRL input3,INPUT_CTRL input4,INPUT_CTRL input5,INPUT_CTRL input6,INPUT_CTRL input7,
         INPUT_CTRL input8,INPUT_CTRL input9,INPUT_CTRL inputa,INPUT_CTRL inputb,INPUT_CTRL inputc,INPUT_CTRL inputd,INPUT_CTRL inpute,INPUT_CTRL inputf>
const uint8_t DIGITAL_INPUT_DISABLE<input0,input1,input2,input3,input4,input5,input6,input7,input8,input9,inputa,inputb,inputc,inputd,inpute,inputf>::reg2_val = 
        double_compound_mask<input0,input1,input2,input3,input4,input5,input6,input7,input8,input9,inputa,inputb,inputc,inputd,inpute,inputf>::high_value;


template
<
   INPUT_CTRL input0 = adc::NO_CTRL,
   INPUT_CTRL input1 = adc::NO_CTRL,
   INPUT_CTRL input2 = adc::NO_CTRL,
   INPUT_CTRL input3 = adc::NO_CTRL,
   INPUT_CTRL input4 = adc::NO_CTRL,
   INPUT_CTRL input5 = adc::NO_CTRL,
   INPUT_CTRL input6 = adc::NO_CTRL,
   INPUT_CTRL input7 = adc::NO_CTRL,
   INPUT_CTRL input8 = adc::NO_CTRL,
   INPUT_CTRL input9 = adc::NO_CTRL,
   INPUT_CTRL inputa = adc::NO_CTRL,
   INPUT_CTRL inputb = adc::NO_CTRL,
   INPUT_CTRL inputc = adc::NO_CTRL,
   INPUT_CTRL inputd = adc::NO_CTRL,
   INPUT_CTRL inpute = adc::NO_CTRL,
   INPUT_CTRL inputf = adc::NO_CTRL
>
struct DIGITAL_INPUT_ENABLE
{
    static const uint8_t reg0_val;
    static const uint8_t reg2_val;
};
template<INPUT_CTRL input0,INPUT_CTRL input1,INPUT_CTRL input2,INPUT_CTRL input3,INPUT_CTRL input4,INPUT_CTRL input5,INPUT_CTRL input6,INPUT_CTRL input7,
         INPUT_CTRL input8,INPUT_CTRL input9,INPUT_CTRL inputa,INPUT_CTRL inputb,INPUT_CTRL inputc,INPUT_CTRL inputd,INPUT_CTRL inpute,INPUT_CTRL inputf>
const uint8_t DIGITAL_INPUT_ENABLE<input0,input1,input2,input3,input4,input5,input6,input7,input8,input9,inputa,inputb,inputc,inputd,inpute,inputf>::reg0_val = 
        static_cast<uint8_t>(~double_compound_mask<input0,input1,input2,input3,input4,input5,input6,input7,input8,input9,inputa,inputb,inputc,inputd,inpute,inputf>::low_value);

template<INPUT_CTRL input0,INPUT_CTRL input1,INPUT_CTRL input2,INPUT_CTRL input3,INPUT_CTRL input4,INPUT_CTRL input5,INPUT_CTRL input6,INPUT_CTRL input7,
         INPUT_CTRL input8,INPUT_CTRL input9,INPUT_CTRL inputa,INPUT_CTRL inputb,INPUT_CTRL inputc,INPUT_CTRL inputd,INPUT_CTRL inpute,INPUT_CTRL inputf>
const uint8_t DIGITAL_INPUT_ENABLE<input0,input1,input2,input3,input4,input5,input6,input7,input8,input9,inputa,inputb,inputc,inputd,inpute,inputf>::reg2_val = 
        static_cast<uint8_t>(~double_compound_mask<input0,input1,input2,input3,input4,input5,input6,input7,input8,input9,inputa,inputb,inputc,inputd,inpute,inputf>::high_value);
#endif

template
<
    uint8_t dev_enable = ENABLE,        /**< enables the ADC. Turning the ADC off while a conversion is in progress, will terminate this conversion. */
    uint8_t interrupt  = ENABLE,        /**< enables ADC interrupt, when the I-bit in SREG is set, the ADC Conversion Complete Interrupt is activated. */
    RESULT_ADJUST adj = RIGHT_ADJUST    /**< affects the presentation of the ADC conversion result in the ADC Data Register. Default value adjusts the result right. */
>
struct DEVICE_CTRL
{
    static const uint8_t ADMIX_mask;  // Bit 5 – ADLAR: ADC Left Adjust Result
    static const uint8_t ADCSRA_mask; // Bit 7 – ADEN: ADC Enable, Bit 3 – ADIE: ADC Interrupt Enable
};

template<uint8_t dev_enable,uint8_t interrupt,RESULT_ADJUST adj>
const uint8_t DEVICE_CTRL<dev_enable,interrupt,adj>::ADMIX_mask = bit_mask<adj,5>::value;

template<uint8_t dev_enable,uint8_t interrupt,RESULT_ADJUST adj>
const uint8_t DEVICE_CTRL<dev_enable,interrupt,adj>::ADCSRA_mask = (bit_mask<dev_enable,7>::value | bit_mask<interrupt,3>::value);

//====================================================================================================

template
<
    class input_select,                             /**< selects which combination of analog inputs are connected to the ADC. possible options are SINGLE_ENDED or DIFFERENTIAL */
    class digital_input = DIGITAL_INPUT_DISABLE<>,  /**< specifies ADC pins whose digital input buffers should be disabled */
    class auto_trigger = AUTO_TRG_DISABLED,         /**< auto trigger control */
    class device_ctrl = DEVICE_CTRL<>,              /**< controls interrupt, device enabling and result adjusting */
    VOLTAGE_REF voltage_ref = AVCC,                 /**< specifies the voltage reference for the ADC */
    class prescaler = PS_MAX_VALID<>                /**< specifies prescaler values. Possible options are PS_DIV_FACTOR and PS_MAX_VALID */
>
struct ADC_CONTROL
{
    static const uint8_t ADMUX_value;   // ADC Multiplexer Selection Register
    static const uint8_t ADCSRB_value;  // ADC Control and Status Register B
    static const uint8_t ADCSRA_value;  // ADC Control and Status Register A
    
#ifndef UNITTEST_MODE

    inline static void init()
    {
        DIDR0  = digital_input::reg0_val;
        DIDR1  = digital_input::reg2_val;

        ADMUX  = ADMUX_value;
        ADCSRB = ADCSRB_value;
        ADCSRA = ADCSRA_value;
    }
    
    // TODO make single function with parameter ???
    /**< 
     * The ADC does not consume power when ADEN is cleared, so it is recommended 
     * to switch off the ADC before entering power saving sleep modes. 
     */
    static void inline enable()
    {
        ADCSRA |= bit<ADEN>::value;
    }

    static void inline disable()
    {
        ADCSRA &= nobits<ADEN>::value;
    }
    
    static void inline interrupt_enable()
    {
        ADCSRA |= bit<ADIE>::value;
    }

    static void inline interrupt_disable()
    {
        ADCSRA &= nobits<ADIE>::value;
    }
    
    static void inline start_conversion()
    {
        ADCSRA |= bit<ADSC>::value;
        //ADCSRA = bit<ADSC>::value; // ????????????????
    }

    static void inline auto_triggering_enable()
    {
        ADCSRA |= bit<ADATE>::value;
    }

    static void inline auto_triggering_disable()
    {
        ADCSRA &= nobits<ADATE>::value;
    }
    
    template<adc::SINGLE_CHANNEL_INPUT channel>
    static uint16_t inline sync_read_channel()
    {
        // clear interrupt flag
        if(bit<ADIF>::value & ADCSRA) ADCSRA |= bit<ADIF>::value;
        // Select channel
        ADMUX = ((0x07 & channel) | (0xF8 & ADMUX_value));
        // Start conversion
        //ADCSRA |= bit<ADSC>::value;
        start_conversion();
        // waiting for completion
        while(bit<ADSC>::value & ADCSRA);
        // clear interrupt flag
        if(bit<ADIF>::value & ADCSRA) ADCSRA |= bit<ADIF>::value;
        // read value
        return ADC;
    }
    
    
    //static void select_input(); // single/differential ???
    
#endif //UNITTEST_MODE
};

template<class input_select,class digital_input,class auto_trigger,class device_ctrl,VOLTAGE_REF voltage_ref,class prescaler>
const uint8_t ADC_CONTROL<input_select,digital_input,auto_trigger,device_ctrl,voltage_ref,prescaler>::ADMUX_value = compound_masks<
                                    ((0x03 & voltage_ref) << 6),        // Bit 7:6 – REFS1:0: Reference Selection Bits
                                    device_ctrl::ADMIX_mask,            // Bit 5 – ADLAR: ADC Left Adjust Result
                                    (0x1F & input_select::MUX_value)    // Bits 4:0 – MUX4:0: Analog Channel and Gain Selection Bits
                                >::value;
        
template<class input_select,class digital_input,class auto_trigger,class device_ctrl,VOLTAGE_REF voltage_ref,class prescaler>
const uint8_t ADC_CONTROL<input_select,digital_input,auto_trigger,device_ctrl,voltage_ref,prescaler>::ADCSRB_value = compound_masks<
                                    bit_mask<(0x20 & input_select::MUX_value),3>::value, // Bit 3  /*MUX5*/ – MUX5: Analog Channel and Gain Selection Bit
                                    auto_trigger::ADCSRB_mask                              // Bit 2:0 – ADTS2:0: ADC Auto Trigger Source
                                >::value;

template<class input_select,class digital_input,class auto_trigger,class device_ctrl,VOLTAGE_REF voltage_ref,class prescaler>
const uint8_t ADC_CONTROL<input_select,digital_input,auto_trigger,device_ctrl,voltage_ref,prescaler>::ADCSRA_value = compound_masks<
                                    device_ctrl::ADCSRA_mask,   // Bit 7 – ADEN: ADC Enable, Bit 3 – ADIE: ADC Interrupt Enable
                                                                // Bit 6 – ADSC: ADC Start Conversion
                                    auto_trigger::ADCSRA_mask,  // Bit 5 – ADATE: ADC Auto Trigger Enable
                                                                // Bit 4 – ADIF: ADC Interrupt Flag
                                    (0x07 & prescaler::value)   // Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits 
                                    // ADC Prescaler Select - determines the division factor between the XTAL frequency and the input clock to the ADC
                                >::value;

} //namespace adc
#endif
