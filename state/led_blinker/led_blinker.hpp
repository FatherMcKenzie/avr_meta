// Tue Oct 27 12:02:33  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//

#include <stdint.h>

#include "../../meta/typelist/typelist.hpp"
#include "../../meta/traverse/traverse.hpp"

#include "blinker_helper.hpp"

#include "led_switch_helper.hpp"
#include "led_pattern_helper.hpp"


#ifndef LED_LED_BLINKER_CLASS_HEADER
#define LED_LED_BLINKER_CLASS_HEADER

#include <stdint.h>

#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
};

#include <cstdio>

#endif


namespace led
{

typedef void (*LED_CONTRL_FUNC_TYPE)(bool); // LEDs controlling functions
typedef void (*LED_TOGGLE_FUNC_TYPE)();

template
<
    uint8_t LED_ID,
    LED_CONTRL_FUNC_TYPE pin_set_func, // LED SET    function
    LED_TOGGLE_FUNC_TYPE pin_tgl_func  // LED TOGGLE  function
>
struct LED
{
    //static void inline set(bool value){pin_set_func(value);}
    //static void inline toggle(){pin_tgl_func();}

    static const uint8_t ID;
    
    template<uint8_t PatternLength>
    static void process_tick(uint8_t offset, typename led::PATTERN_TYPE<led::PATTERN_SIZE<PatternLength>::BYTES>::type pattern_val)
    {
        typedef typename led::PATTERN_TYPE<led::PATTERN_SIZE<PatternLength>::BYTES>::type PAT_TYPE;
        
        if(0 == offset) pin_set_func(static_cast<PAT_TYPE>(1 & pattern_val));
        else 
        if(bool((static_cast<PAT_TYPE>(1) <<    offset ) & pattern_val) ^ 
           bool((static_cast<PAT_TYPE>(1) << (offset-1)) & pattern_val))
               pin_tgl_func();
    }

    template<uint8_t PatternLength,typename led::PATTERN_TYPE<led::PATTERN_SIZE<PatternLength>::BYTES>::type pattern_val>
    static void process_tick(uint8_t offset)
    {
        typedef typename led::PATTERN_TYPE<led::PATTERN_SIZE<PatternLength>::BYTES>::type PAT_TYPE;
        
        if(!offset)
            pin_set_func(static_cast<PAT_TYPE>(1) & pattern_val);
        else
            if((static_cast<PAT_TYPE>(1) << offset) & led::XOR<PAT_TYPE,pattern_val,ROTATED<PatternLength,pattern_val>::LEFT>::value) 
                pin_tgl_func();
    }
};
template<uint8_t LED_ID,LED_CONTRL_FUNC_TYPE pin_set_func,LED_TOGGLE_FUNC_TYPE pin_tgl_func>
const uint8_t LED<LED_ID,pin_set_func,pin_tgl_func>::ID = LED_ID;


template
<
    typename LED_ID_TYPE,
    class pin0 = TL::LIST_TERM, //LED
    class pin1 = TL::LIST_TERM, //LED
    class pin2 = TL::LIST_TERM, //LED
    class pin3 = TL::LIST_TERM, //LED
    class pin4 = TL::LIST_TERM, //LED
    class pin5 = TL::LIST_TERM, //LED
    class pin6 = TL::LIST_TERM, //LED
    class pin7 = TL::LIST_TERM  //LED
>
struct LEDS
{
    typedef typename TL::ITEMS_8<pin0,pin1,pin2,pin3,pin4,pin5,pin6,pin7>::ITEMLIST LIST;
    static const uint8_t SIZE;

    template<LED_ID_TYPE led_id, uint8_t PatternLength>
    static void inline process_tick(uint8_t offset, typename led::PATTERN_TYPE<led::PATTERN_SIZE<PatternLength>::BYTES>::type pattern_val)
    {
        TL::find_id<LED_ID_TYPE, led_id, LIST>::type::template process_tick<PatternLength>(offset, pattern_val);
    }

    template<LED_ID_TYPE led_id, uint8_t PatternLength, typename led::PATTERN_TYPE<led::PATTERN_SIZE<PatternLength>::BYTES>::type pattern_val>
    static void inline process_tick(uint8_t offset)
    {
        TL::find_id<LED_ID_TYPE, led_id, LIST>::type::template process_tick<PatternLength, pattern_val>(offset);
    }
};
template<typename LED_ID_TYPE,class pin0,class pin1,class pin2,class pin3,class pin4,class pin5,class pin6,class pin7>
const uint8_t LEDS<LED_ID_TYPE,pin0,pin1,pin2,pin3,pin4,pin5,pin6,pin7>::SIZE = TL::ITEMS_8<pin0,pin1,pin2,pin3,pin4,pin5,pin6,pin7>::LENGTH;

template
<
    uint8_t LED_ID,
    class pattern_def // binary<0,1,0,1,1,0,0 ... >
>
struct BLINK_PATTERN
{
    static const uint8_t ID; // Led ID
    static const uint64_t pattern;
};

template<uint8_t LED_ID,class pattern_def>
const uint8_t BLINK_PATTERN<LED_ID,pattern_def>::ID = LED_ID;

template<uint8_t LED_ID,class pattern_def>
const uint64_t BLINK_PATTERN<LED_ID,pattern_def>::pattern = pattern_def::value;


template
<
    uint8_t MODE_ID,
    typename LED_ID_TYPE,
    class led0_pattern = TL::LIST_TERM, //BLINK_PATTERN
    class led1_pattern = TL::LIST_TERM, //BLINK_PATTERN
    class led2_pattern = TL::LIST_TERM, //BLINK_PATTERN
    class led3_pattern = TL::LIST_TERM, //BLINK_PATTERN
    class led4_pattern = TL::LIST_TERM, //BLINK_PATTERN
    class led5_pattern = TL::LIST_TERM, //BLINK_PATTERN
    class led6_pattern = TL::LIST_TERM, //BLINK_PATTERN
    class led7_pattern = TL::LIST_TERM  //BLINK_PATTERN
>
struct MODE
{
    typedef typename TL::ITEMS_8<led0_pattern,led1_pattern,led2_pattern,led3_pattern,led4_pattern,led5_pattern,led6_pattern,led7_pattern>::ITEMLIST PATTERN_LIST;
    static const uint8_t ID;
};

template<uint8_t MODE_ID,typename LED_ID_TYPE,class led0_pattern,class led1_pattern,class led2_pattern,class led3_pattern,class led4_pattern,class led5_pattern,class led6_pattern,class led7_pattern>
const uint8_t MODE<MODE_ID,LED_ID_TYPE,led0_pattern,led1_pattern,led2_pattern,led3_pattern,led4_pattern,led5_pattern,led6_pattern,led7_pattern>::ID = MODE_ID;

template
<
#if 1
    class mode_0 = TL::LIST_TERM, // MODE
    class mode_1 = TL::LIST_TERM, // MODE
    class mode_2 = TL::LIST_TERM, // MODE
    class mode_3 = TL::LIST_TERM, // MODE
    class mode_4 = TL::LIST_TERM, // MODE
    class mode_5 = TL::LIST_TERM, // MODE
    class mode_6 = TL::LIST_TERM, // MODE
    class mode_7 = TL::LIST_TERM, // MODE
    class mode_8 = TL::LIST_TERM, // MODE
    class mode_9 = TL::LIST_TERM, // MODE
    class mode_A = TL::LIST_TERM, // MODE
    class mode_B = TL::LIST_TERM, // MODE
    class mode_C = TL::LIST_TERM, // MODE
    class mode_D = TL::LIST_TERM, // MODE
    class mode_E = TL::LIST_TERM, // MODE
    class mode_F = TL::LIST_TERM, // MODE
    class mode10 = TL::LIST_TERM, // MODE
    class mode11 = TL::LIST_TERM, // MODE
    class mode12 = TL::LIST_TERM, // MODE
    class mode13 = TL::LIST_TERM, // MODE
    class mode14 = TL::LIST_TERM, // MODE
    class mode15 = TL::LIST_TERM, // MODE
    class mode16 = TL::LIST_TERM, // MODE
    class mode17 = TL::LIST_TERM, // MODE
    class mode18 = TL::LIST_TERM, // MODE
    class mode19 = TL::LIST_TERM, // MODE
    class mode1A = TL::LIST_TERM, // MODE
    class mode1B = TL::LIST_TERM, // MODE
    class mode1C = TL::LIST_TERM, // MODE
    class mode1D = TL::LIST_TERM, // MODE
    class mode1E = TL::LIST_TERM, // MODE
    class mode1F = TL::LIST_TERM  // MODE
#endif
>
struct MODES // Just a container for modes
{
    typedef typename TL::ITEMS<mode_0,mode_1,mode_2,mode_3,mode_4,mode_5,mode_6,mode_7,mode_8,mode_9,mode_A,mode_B,mode_C,mode_D,mode_E,mode_F,
                               mode10,mode11,mode12,mode13,mode14,mode15,mode16,mode17,mode18,mode19,mode1A,mode1B,mode1C,mode1D,mode1E,mode1F>::ITEMLIST MODELIST;
    static const uint8_t SIZE;
};

template<class mode_0,class mode_1,class mode_2,class mode_3,class mode_4,class mode_5,class mode_6,class mode_7,class mode_8,class mode_9,class mode_A,class mode_B,class mode_C,class mode_D,class mode_E,class mode_F,
         class mode10,class mode11,class mode12,class mode13,class mode14,class mode15,class mode16,class mode17,class mode18,class mode19,class mode1A,class mode1B,class mode1C,class mode1D,class mode1E,class mode1F>
const uint8_t MODES<mode_0,mode_1,mode_2,mode_3,mode_4,mode_5,mode_6,mode_7,mode_8,mode_9,mode_A,mode_B,mode_C,mode_D,mode_E,mode_F,
                    mode10,mode11,mode12,mode13,mode14,mode15,mode16,mode17,mode18,mode19,mode1A,mode1B,mode1C,mode1D,mode1E,mode1F>::SIZE = 
        TL::ITEMS<mode_0,mode_1,mode_2,mode_3,mode_4,mode_5,mode_6,mode_7,mode_8,mode_9,mode_A,mode_B,mode_C,mode_D,mode_E,mode_F,
                     mode10,mode11,mode12,mode13,mode14,mode15,mode16,mode17,mode18,mode19,mode1A,mode1B,mode1C,mode1D,mode1E,mode1F>::LENGTH;
//=========================================================================
template
<
    typename RestrictType,
    RestrictType initial_state = RestrictType()
>
class MODE_STORAGE
{
#ifdef UNITTEST_MODE
    template<class T> friend class tut::test_object;
#endif
    uint8_t mode;
    MODE_STORAGE(const MODE_STORAGE&);
    MODE_STORAGE& operator = (const MODE_STORAGE &);
public:
    MODE_STORAGE():mode(initial_state){};
    bool inline set(uint8_t value)
    {
        if(value == mode) return false;
        mode = static_cast<RestrictType>(value);
        return true;
    }
    uint8_t inline get()const {return mode;}
};
//=========================================================================
template
<
    typename ModeType,  // The type representing mode ID
    typename LedType,   // The type representing led  ID
    class leds,         // LEDS  definition
    class modes,        // MODES definition
    uint8_t  TICKS_NUMBER = 32, // Indication repetition period / number of ticks
    class mode_storage = led::MODE_STORAGE<ModeType>   // Type of object that stores mode value
    //ModeType initial_mode = TL::type_at<0, typename modes::MODELIST>::type::ID  // Initial mode - by default gets value of the mode with 0 index (the first in definition list)
>
class led_blinker
{
#ifdef UNITTEST_MODE
    template<class T> friend class tut::test_object;
#endif
    mode_storage mode;
    TICK<PATTERN_SIZE<TICKS_NUMBER>::MAXTICK> tick;
    
    led_blinker(const led_blinker&);
    led_blinker& operator = (const led_blinker &);
    
#if 1
    // AVR Memory Usage  for Device: atmega2560
    // Program:     488 bytes (0.2% Full) instead of Program:     552 bytes (0.2% Full)
    
    // AVR Memory Usage Device: atmega328p
    // Program:     350 bytes (1.1% Full) instead of Program:     414 bytes (1.3% Full)
    
    template
    <
        ModeType MODE_ID,
        unsigned  LED_INDEX,
        class LED_CONT,
        typename PT = uint8_t
    >
    struct LEDS_PROCESSOR
    {
        static inline void EXEC(PT tick_val)
        {
            typedef typename TL::find_id<ModeType, MODE_ID, typename modes::MODELIST>::type MODE_TYPE;
            typedef typename TL::find_id<LedType, static_cast<LedType>(TL::type_at<LED_INDEX, typename leds::LIST>::type::ID), typename MODE_TYPE::PATTERN_LIST>::type BLINK_PATTERN;
            typedef typename led::PATTERN_TYPE<led::PATTERN_SIZE<TICKS_NUMBER>::BYTES>::type PAT_TYPE;
            
            leds::template process_tick<
                    static_cast<LedType>(TL::type_at<LED_INDEX, typename leds::LIST>::type::ID),
                    TICKS_NUMBER,
                    static_cast<PAT_TYPE>(mask<TICKS_NUMBER,0,PAT_TYPE>::value & BLINK_PATTERN::pattern)
                    >(tick_val);
        }
    };
#endif

    template
    <
        ModeType MODE_ID, 
        typename ParamType = uint8_t
    >
    struct MODES_PROCESSOR
    {
        static void inline mode_process(ParamType offset_val)
        {
            //traverse_leds<MODE_ID>(offset_val);
            led::traverse<ModeType, MODE_ID, LEDS_PROCESSOR, leds::SIZE, typename leds::LIST, uint8_t>::TRAVERSE(offset_val);
        }
    };
    
    void set_leds()
    {
        led::switch_helper<ModeType, uint8_t, MODES_PROCESSOR, typename modes::MODELIST, modes::SIZE>::process(mode.get(), tick.get());
    }
    
public:

    led_blinker()
    :mode()
    ,tick(){set_leds();}
    
    void inline set_mode(uint8_t new_mode)
    {
        if(mode.set(new_mode))
        {
            tick.reset();
            set_leds();
        }
    }
    
    void inline timer_event()
    {
        tick.advance();
        set_leds();
    };
};

} // led namespace
#endif


