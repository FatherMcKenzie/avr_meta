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

#include <cstdio>
#include <tut/tut.hpp>
#include "led_blinker.hpp"
#include "blinker_helper.hpp"

namespace
{

    enum MODE_ENUM
    {
        MODE_0,
        MODE_1,
        MODE_2,
    };
    
    enum LEDS_ENUM
    {
        GRN_LED,
        RED_LED,
    };
    
    void green_set(bool value)
    {
        printf("%s(%d)\n", __FUNCTION__, value);
    }
    
    void green_toggle()
    {
        printf("%s\n", __FUNCTION__);
    }

    void red_set(bool value)
    {
        printf("%s(%d)\n", __FUNCTION__, value);
    }

    void red_toggle()
    {
        printf("%s\n", __FUNCTION__);
    }

}


namespace tut
{ 
    struct data{};
    typedef tut::test_group<tut::data> tg;
    tg testgroup("first_test_group");
    typedef tg::object testobject;
    

    template<>
    template<>
    void testobject::test<1>()
    { 
        set_test_name("test_0001_PATTERN_SIZE BYTES");
        
        ensure_equals("PATTERN_SIZE<1>::BYTES",   led::PATTERN_SIZE<1>::BYTES, 1);
        ensure_equals("PATTERN_SIZE<8>::BYTES",   led::PATTERN_SIZE<8>::BYTES, 1);

        ensure_equals("PATTERN_SIZE<9>::BYTES",   led::PATTERN_SIZE<9>::BYTES, 2);
        ensure_equals("PATTERN_SIZE<16>::BYTES",  led::PATTERN_SIZE<16>::BYTES, 2);

        ensure_equals("PATTERN_SIZE<17>::BYTES",  led::PATTERN_SIZE<17>::BYTES, 4);
        ensure_equals("PATTERN_SIZE<32>::BYTES",  led::PATTERN_SIZE<32>::BYTES, 4);

        ensure_equals("PATTERN_SIZE<33>::BYTES",  led::PATTERN_SIZE<33>::BYTES, 8);
        ensure_equals("PATTERN_SIZE<64>::BYTES",  led::PATTERN_SIZE<64>::BYTES, 8);
        ensure_equals("PATTERN_SIZE<65>::BYTES",  led::PATTERN_SIZE<65>::BYTES, 8);
        ensure_equals("PATTERN_SIZE<128>::BYTES", led::PATTERN_SIZE<128>::BYTES, 8);
    }
    

#if 0  // SHIFT member is eliminated
    template<>
    template<>
    void testobject::test<2>()
    {
        set_test_name("test_0002 _PATTERN_SIZE SHIFT");
        
        ensure_equals("PATTERN_SIZE<1>::SHIFT",  led::PATTERN_SIZE<1>::SHIFT, 7);
        ensure_equals("PATTERN_SIZE<7>::SHIFT",  led::PATTERN_SIZE<7>::SHIFT, 1);
        ensure_equals("PATTERN_SIZE<8>::SHIFT",  led::PATTERN_SIZE<8>::SHIFT, 0);

        ensure_equals("PATTERN_SIZE<9>::SHIFT",  led::PATTERN_SIZE<9>::SHIFT, 7);
        ensure_equals("PATTERN_SIZE<15>::SHIFT", led::PATTERN_SIZE<15>::SHIFT, 1);
        ensure_equals("PATTERN_SIZE<16>::SHIFT", led::PATTERN_SIZE<16>::SHIFT, 0);

        ensure_equals("PATTERN_SIZE<17>::SHIFT", led::PATTERN_SIZE<17>::SHIFT, 15);
        ensure_equals("PATTERN_SIZE<31>::SHIFT", led::PATTERN_SIZE<31>::SHIFT, 1);
        ensure_equals("PATTERN_SIZE<32>::SHIFT", led::PATTERN_SIZE<32>::SHIFT, 0);

        ensure_equals("PATTERN_SIZE<33>::SHIFT", led::PATTERN_SIZE<33>::SHIFT, 31);
        ensure_equals("PATTERN_SIZE<63>::SHIFT", led::PATTERN_SIZE<63>::SHIFT, 1);
        ensure_equals("PATTERN_SIZE<64>::SHIFT", led::PATTERN_SIZE<64>::SHIFT, 0);
    }
#endif
 

#if 0
    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003 pattern_blinker");
        
        typedef led::pattern_blinker<uint8_t> q;
        ensure_equals("pattern_blinker<uint8_t>::byte_index 0", q::byte_index(0),  0);
        ensure_equals("pattern_blinker<uint8_t>::byte_index 7", q::byte_index(7),  0);
        ensure_equals("pattern_blinker<uint8_t>::byte_index 8", q::byte_index(8),  0);
        
        typedef led::pattern_blinker<uint16_t> s;
        ensure_equals("pattern_blinker<uint16_t>::byte_index 0", s::byte_index(0),  1);
        ensure_equals("pattern_blinker<uint16_t>::byte_index 7", s::byte_index(7),  1);
        
        ensure_equals("pattern_blinker<uint16_t>::byte_index 8", s::byte_index(8),  0);
        ensure_equals("pattern_blinker<uint16_t>::byte_index 15",s::byte_index(15), 0);
        
        typedef led::pattern_blinker<uint32_t> t;
        ensure_equals("pattern_blinker<uint32_t>::byte_index 0", t::byte_index(0),  3);
        ensure_equals("pattern_blinker<uint32_t>::byte_index 7", t::byte_index(7),  3);

        ensure_equals("pattern_blinker<uint32_t>::byte_index 8", t::byte_index(8),  2);
        ensure_equals("pattern_blinker<uint32_t>::byte_index 15", t::byte_index(15), 2);
        
        ensure_equals("pattern_blinker<uint32_t>::byte_index 16", t::byte_index(16), 1);
        ensure_equals("pattern_blinker<uint32_t>::byte_index 23", t::byte_index(23), 1);

        ensure_equals("pattern_blinker<uint32_t>::byte_index 24", t::byte_index(24), 0);
        ensure_equals("pattern_blinker<uint32_t>::byte_index 31", t::byte_index(31), 0);
        
        typedef led::pattern_blinker<uint64_t> r;
        ensure_equals("pattern_blinker<uint64_t>::byte_index 0", r::byte_index(0),  7);
        ensure_equals("pattern_blinker<uint64_t>::byte_index 7", r::byte_index(7),  7);

        ensure_equals("pattern_blinker<uint64_t>::byte_index 8", r::byte_index(8),  6);
        ensure_equals("pattern_blinker<uint64_t>::byte_index 15", r::byte_index(15),  6);

        ensure_equals("pattern_blinker<uint64_t>::byte_index 16", r::byte_index(16),  5);
        ensure_equals("pattern_blinker<uint64_t>::byte_index 23", r::byte_index(23),  5);

        ensure_equals("pattern_blinker<uint64_t>::byte_index 24", r::byte_index(24),  4);
        ensure_equals("pattern_blinker<uint64_t>::byte_index 31", r::byte_index(31),  4);

        ensure_equals("pattern_blinker<uint64_t>::byte_index 32", r::byte_index(32),  3);
        ensure_equals("pattern_blinker<uint64_t>::byte_index 39", r::byte_index(39),  3);

        ensure_equals("pattern_blinker<uint64_t>::byte_index 40", r::byte_index(40),  2);
        ensure_equals("pattern_blinker<uint64_t>::byte_index 47", r::byte_index(47),  2);

        ensure_equals("pattern_blinker<uint64_t>::byte_index 48", r::byte_index(48),  1);
        ensure_equals("pattern_blinker<uint64_t>::byte_index 55", r::byte_index(55),  1);

        ensure_equals("pattern_blinker<uint64_t>::byte_index 56", r::byte_index(56),  0);
        ensure_equals("pattern_blinker<uint64_t>::byte_index 63", r::byte_index(63),  0);
    } 


    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004");
        
        typedef led::pattern_blinker<uint64_t> Q;
        
        const uint64_t pattern = 0x0102030405060708;
        
        ensure_equals("get_byte 0", Q::get_byte(0, pattern), 0x08);
        ensure_equals("get_byte 1", Q::get_byte(1, pattern), 0x07);
        ensure_equals("get_byte 2", Q::get_byte(2, pattern), 0x06);
        ensure_equals("get_byte 3", Q::get_byte(3, pattern), 0x05);
        ensure_equals("get_byte 4", Q::get_byte(4, pattern), 0x04);
        ensure_equals("get_byte 5", Q::get_byte(5, pattern), 0x03);
        ensure_equals("get_byte 6", Q::get_byte(6, pattern), 0x02);
        ensure_equals("get_byte 7", Q::get_byte(7, pattern), 0x01);
    } 


    template<>
    template<>
    void testobject::test<5>()
    { 
        set_test_name("test_0005 bit mask");
        
        typedef led::pattern_blinker<uint64_t> P;
        
        ensure_equals("bit_mask 0", P::bit_mask(0), 0x80);
        ensure_equals("bit_mask 1", P::bit_mask(1), 0x40);
        ensure_equals("bit_mask 2", P::bit_mask(2), 0x20);
        ensure_equals("bit_mask 3", P::bit_mask(3), 0x10);
        ensure_equals("bit_mask 4", P::bit_mask(4), 0x08);
        ensure_equals("bit_mask 5", P::bit_mask(5), 0x04);
        ensure_equals("bit_mask 6", P::bit_mask(6), 0x02);
        ensure_equals("bit_mask 7", P::bit_mask(7), 0x01);

        ensure_equals("bit_mask  8", P::bit_mask( 8), 0x80);
        ensure_equals("bit_mask  9", P::bit_mask( 9), 0x40);
        ensure_equals("bit_mask 10", P::bit_mask(10), 0x20);
        ensure_equals("bit_mask 11", P::bit_mask(11), 0x10);
        ensure_equals("bit_mask 12", P::bit_mask(12), 0x08);
        ensure_equals("bit_mask 13", P::bit_mask(13), 0x04);
        ensure_equals("bit_mask 14", P::bit_mask(14), 0x02);
        ensure_equals("bit_mask 15", P::bit_mask(15), 0x01);
    } 
#endif

#if 1
    template<>
    template<>
    void testobject::test<12>()
    { 
        set_test_name("test_0012");
        
        printf("\nSTART TEST\n");
        
        typedef led::led_blinker<
                    MODE_ENUM,
                    LEDS_ENUM,
                    led::LEDS<
                        LEDS_ENUM,
                        led::LED<GRN_LED,&green_set,&green_toggle>,
                        led::LED<RED_LED,&red_set,&red_toggle>
                    >,
                    led::MODES<
                        led::MODE<
                            MODE_0,
                            LEDS_ENUM,
                            led::BLINK_PATTERN<GRN_LED, led::binary<1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1> >,   // 0xFF00FF00>,
                            led::BLINK_PATTERN<RED_LED, led::binary<0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1> >    // 0x00FF00FF>
                            >,
                        
                        led::MODE<
                            MODE_1,
                            LEDS_ENUM,
                            //led::BLINK_PATTERN<GRN_LED, led::binary<1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1> >, //0xF0F0F0F0>,
                            //led::BLINK_PATTERN<RED_LED, led::binary<0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1> > //0x0F0F0F0F>

                            //led::BLINK_PATTERN<GRN_LED, led::binary<0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1> >, //0xF0F0F0F0>,
                            //led::BLINK_PATTERN<RED_LED, led::binary<1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1> > //0x0F0F0F0F>

                            led::BLINK_PATTERN<RED_LED, led::binary<1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1> >, //0x0F0F0F0F>
                            led::BLINK_PATTERN<GRN_LED, led::binary<0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1> > //0xF0F0F0F0>,
                            >,

                        led::MODE<
                            MODE_2,
                            LEDS_ENUM,
                            led::BLINK_PATTERN<GRN_LED, led::binary<1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1> >, //0xCCCCCCCC>,
                            led::BLINK_PATTERN<RED_LED, led::binary<0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1> > //0x33333333>
                            >
                        >
                        ,32
                        ,led::MODE_STORAGE<MODE_ENUM>
                        //,MODE_0
                        > LED_BLINKER;
        
        
        LED_BLINKER lb_test;

        printf("\n===============================\n");
        for(uint8_t modeval = 0; modeval < 3; ++ modeval)
        {
            lb_test.set_mode(modeval);
            printf("\n ======== MODE%d ========== \n", modeval);
            for(uint8_t i = 0; i < 32; ++i)
            {
                lb_test.timer_event();
                printf("\t----- tick:%d\n", i);
                //printf("-------------------------------\n");
            }
        }

    }
#endif
    

    template<>
    template<>
    void testobject::test<16>()
    { 
        set_test_name("test_0016_ROTATED");
        
        
        //led::ROTATED<8, 0b10110010>
        ensure_equals("led::ROTATED<8, 0b10110010>::LEFT ",   (uint32_t)led::ROTATED<8, 0b10110010>::LEFT,  (uint32_t)0b01100101);
        ensure_equals("led::ROTATED<8, 0b10110010>::RIGHT",   (uint32_t)led::ROTATED<8, 0b10110010>::RIGHT, (uint32_t)0b01011001);
        ensure_equals("led::ROTATED<8, 0b01011001>::LEFT ",   (uint32_t)led::ROTATED<8, 0b01011001>::LEFT,  (uint32_t)0b10110010);
        ensure_equals("led::ROTATED<8, 0b01011001>::RIGHT",   (uint32_t)led::ROTATED<8, 0b01011001>::RIGHT, (uint32_t)0b10101100);


        ensure_equals("led::ROTATED<9, 0b110110010>::LEFT ",   (uint32_t)led::ROTATED<9, 0b110110010UL>::LEFT,  (uint32_t)0b101100101UL);
        ensure_equals("led::ROTATED<9, 0b110110010>::RIGHT",   (uint32_t)led::ROTATED<9, 0b110110010UL>::RIGHT, (uint32_t)0b011011001UL);
        ensure_equals("led::ROTATED<9, 0b010110011>::LEFT ",   (uint32_t)led::ROTATED<9, 0b010110011UL>::LEFT,  (uint32_t)0b101100110UL);
        ensure_equals("led::ROTATED<9, 0b010110011>::RIGHT",   (uint32_t)led::ROTATED<9, 0b010110011UL>::RIGHT, (uint32_t)0b101011001UL);

        ensure_equals("led::ROTATED<17, 0b01001100011100001>::LEFT ",   (uint32_t)led::ROTATED<17, 0b01001100011100001>::LEFT,  (uint32_t)0b10011000111000010);
        ensure_equals("led::ROTATED<17, 0b01001100011100001>::RIGHT",   (uint32_t)led::ROTATED<17, 0b01001100011100001>::RIGHT, (uint32_t)0b10100110001110000);
        ensure_equals("led::ROTATED<17, 0b10110011100011110>::LEFT ",   (uint32_t)led::ROTATED<17, 0b10110011100011110>::LEFT,  (uint32_t)0b01100111000111101);
        ensure_equals("led::ROTATED<17, 0b10110011100011110>::RIGHT",   (uint32_t)led::ROTATED<17, 0b10110011100011110>::RIGHT, (uint32_t)0b01011001110001111);

    }

}

