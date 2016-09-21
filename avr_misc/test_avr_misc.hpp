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


#include <tut/tut.hpp>
#include "avr_misc.hpp"

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
    void testobject::test<1>()
    { 
        set_test_name("test_0001 uint8_t");
        
        ensure_equals("message bit", bit<-1>::value, 0);
        
        ensure_equals("message bit", bit<0>::value, 1);
        ensure_equals("message bit", bit<1>::value, 2);
        ensure_equals("message bit", bit<2>::value, 4);
        ensure_equals("message bit", bit<3>::value, 8);
        ensure_equals("message bit", bit<4>::value, 16);
        ensure_equals("message bit", bit<5>::value, 32);
        ensure_equals("message bit", bit<6>::value, 64);
        ensure_equals("message bit", bit<7>::value, 128);
        ensure_equals("message bit", bit<8>::value, 0); // expected warning: large integer implicitly truncated to unsigned type [-Woverflow]
    } 
    

    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002 uint16_t");
        
        ensure_equals("message bit uint16_t", bit<-1, uint16_t>::value, 0);
        
        ensure_equals("message bit uint16_t", bit<0,  uint16_t>::value, 1);
        ensure_equals("message bit uint16_t", bit<1,  uint16_t>::value, 2);
        ensure_equals("message bit uint16_t", bit<2,  uint16_t>::value, 4);
        ensure_equals("message bit uint16_t", bit<3,  uint16_t>::value, 8);
        ensure_equals("message bit uint16_t", bit<4,  uint16_t>::value, 16);
        ensure_equals("message bit uint16_t", bit<5,  uint16_t>::value, 32);
        ensure_equals("message bit uint16_t", bit<6,  uint16_t>::value, 64);
        ensure_equals("message bit uint16_t", bit<7,  uint16_t>::value, 128);
        ensure_equals("message bit uint16_t", bit<8,  uint16_t>::value, 256);
        ensure_equals("message bit uint16_t", bit<9,  uint16_t>::value, 512);
        ensure_equals("message bit uint16_t", bit<10, uint16_t>::value, 1024);
        ensure_equals("message bit uint16_t", bit<11, uint16_t>::value, 2048);
        ensure_equals("message bit uint16_t", bit<12, uint16_t>::value, 4096);
        ensure_equals("message bit uint16_t", bit<13, uint16_t>::value, 8192);
        ensure_equals("message bit uint16_t", bit<14, uint16_t>::value, 16384);
        ensure_equals("message bit uint16_t", bit<15, uint16_t>::value, 32768);
        ensure_equals("message bit uint16_t", bit<16, uint16_t>::value, 0); // expected warning: large integer implicitly truncated to unsigned type [-Woverflow]
    } 
    

    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003 bits uint8_t");
        
        ensure_equals("message bits uint8_t", bits<0>::value, 1);
        ensure_equals("message bits uint8_t", bits<0,1>::value, 3);
        ensure_equals("message bits uint8_t", bits<0,1,2>::value, 7);
        ensure_equals("message bits uint8_t", bits<0,1,2,3>::value, 0x0F);
        ensure_equals("message bits uint8_t", bits<0,1,2,3,4>::value, 0x1F);
        ensure_equals("message bits uint8_t", bits<0,1,2,3,4,5>::value, 0x3F);
        ensure_equals("message bits uint8_t", bits<0,1,2,3,4,5,6>::value, 0x7F);
        ensure_equals("message bits uint8_t", bits<0,1,2,3,4,5,6,7>::value, 0xFF);
        
        ensure_equals("message bits uint8_t", bits<0,1,2,3,4,5,6,7>::value, 0xFF);
        ensure_equals("message bits uint8_t", bits<1,2,3,4,5,6,7>::value, 0xFE);
        ensure_equals("message bits uint8_t", bits<2,3,4,5,6,7>::value, 0xFC);
        ensure_equals("message bits uint8_t", bits<3,4,5,6,7>::value, 0xF8);
        ensure_equals("message bits uint8_t", bits<4,5,6,7>::value, 0xF0);
        ensure_equals("message bits uint8_t", bits<5,6,7>::value, 0xE0);
        ensure_equals("message bits uint8_t", bits<6,7>::value, 0xC0);
        ensure_equals("message bits uint8_t", bits<7>::value, 0x80);
        ensure_equals("message bits uint8_t", bits<>::value, 0);
        
        ensure_equals("message bits uint8_t", bits<0,2,4,6>::value, 85);
        ensure_equals("message bits uint8_t", bits<1,3,5,7>::value, 170);
        ensure_equals("message bits uint8_t", bits<0,1,6,7>::value, 195);
        ensure_equals("message bits uint8_t", bits<0,7>::value, 129);
        ensure_equals("message bits uint8_t", bits<3,4>::value, 24);
    }
    
    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004 bits uint16_t");
        
        ensure_equals("message bits uint16_t", bits16<0>::value, 1);
        ensure_equals("message bits uint16_t", bits16<0,1>::value, 3);
        ensure_equals("message bits uint16_t", bits16<0,1,2>::value, 7);
        ensure_equals("message bits uint16_t", bits16<0,1,2,3>::value, 0x0F);
        ensure_equals("message bits uint16_t", bits16<0,1,2,3,4>::value, 0x1F);
        ensure_equals("message bits uint16_t", bits16<0,1,2,3,4,5>::value, 0x3F);
        ensure_equals("message bits uint16_t", bits16<0,1,2,3,4,5,6>::value, 0x7F);
        ensure_equals("message bits uint16_t", bits16<0,1,2,3,4,5,6,7>::value, 0xFF);
        
        ensure_equals("message bits uint16_t", bits16<1,2,3,4,5,6,7,8>::value, 510);
        ensure_equals("message bits uint16_t", bits16<2,3,4,5,6,7,8,9>::value, 1020);
        ensure_equals("message bits uint16_t", bits16<3,4,5,6,7,8,9,10>::value, 2040);
        ensure_equals("message bits uint16_t", bits16<4,5,6,7,8,9,10,11>::value, 4080);
        ensure_equals("message bits uint16_t", bits16<5,6,7,8,9,10,11,12>::value, 8160);
        ensure_equals("message bits uint16_t", bits16<6,7,8,9,10,11,12,13>::value, 16320);
        ensure_equals("message bits uint16_t", bits16<7,8,9,10,11,12,13,14>::value, 32640);

        ensure_equals("message bits uint16_t", bits16<8,9,10,11,12,13,14,15>::value, 65280);
        ensure_equals("message bits uint16_t", bits16<9,10,11,12,13,14,15>::value, 0xFE00);
        ensure_equals("message bits uint16_t", bits16<10,11,12,13,14,15>::value, 0xFC00);
        ensure_equals("message bits uint16_t", bits16<11,12,13,14,15>::value, 0xF800);
        ensure_equals("message bits uint16_t", bits16<12,13,14,15>::value, 0xF000);
        ensure_equals("message bits uint16_t", bits16<13,14,15>::value, 0xE000);
        ensure_equals("message bits uint16_t", bits16<14,15>::value, 0xC000);
        ensure_equals("message bits uint16_t", bits16<15>::value, 0x8000);
        ensure_equals("message bits uint16_t", bits16<>::value, 0);
        
        
        
        ensure_equals("message bits uint16_t", bits16<0,1,2,3,4,5,6,7>::value, 0xFF);
        ensure_equals("message bits uint16_t", bits16<1,2,3,4,5,6,7>::value, 0xFE);
        ensure_equals("message bits uint16_t", bits16<2,3,4,5,6,7>::value, 0xFC);
        ensure_equals("message bits uint16_t", bits16<3,4,5,6,7>::value, 0xF8);
        ensure_equals("message bits uint16_t", bits16<4,5,6,7>::value, 0xF0);
        ensure_equals("message bits uint16_t", bits16<5,6,7>::value, 0xE0);
        ensure_equals("message bits uint16_t", bits16<6,7>::value, 0xC0);
        ensure_equals("message bits uint16_t", bits16<7>::value, 0x80);
        ensure_equals("message bits uint16_t", bits16<>::value, 0);
        
        ensure_equals("message bits uint16_t", bits16<0,2,4,6>::value, 85);
        ensure_equals("message bits uint16_t", bits16<1,3,5,7>::value, 170);
        ensure_equals("message bits uint16_t", bits16<0,1,6,7>::value, 195);
        ensure_equals("message bits uint16_t", bits16<0,7>::value, 129);
        ensure_equals("message bits uint16_t", bits16<3,4>::value, 24);
    }

    template<>
    template<>
    void testobject::test<5>()
    { 
        set_test_name("test_0005 nobits uint8_t");
        
        
        ensure_equals("message nobits uint8_t", nobits<>::value, bits<0,1,2,3,4,5,6,7>::value);
        ensure_equals("message nobits uint8_t", nobits<0>::value, bits<1,2,3,4,5,6,7>::value);
        ensure_equals("message nobits uint8_t", nobits<0,1>::value, bits<2,3,4,5,6,7>::value);
        ensure_equals("message nobits uint8_t", nobits<0,1,2>::value, bits<3,4,5,6,7>::value);
        ensure_equals("message nobits uint8_t", nobits<0,1,2,3>::value, bits<4,5,6,7>::value);
        ensure_equals("message nobits uint8_t", nobits<0,1,2,3,4>::value, bits<5,6,7>::value);
        ensure_equals("message nobits uint8_t", nobits<0,1,2,3,4,5>::value, bits<6,7>::value);
        ensure_equals("message nobits uint8_t", nobits<0,1,2,3,4,5,6>::value, bits<7>::value);
        ensure_equals("message nobits uint8_t", nobits<0,1,2,3,4,5,6,7>::value, bits<>::value);
    }


    template<>
    template<>
    void testobject::test<6>()
    { 
        set_test_name("test_0006 compound_masks");
        
        
        ensure_equals("message compound_masks", compound_masks<>::value, 0x00);
        ensure_equals("message compound_masks", uint32_t(compound_masks<0x01>::value), 0x01);
        ensure_equals("message compound_masks", compound_masks<0x01, 0x02>::value, 0x03);
        ensure_equals("message compound_masks", compound_masks<0x01, 0x02, 0x04>::value, 0x07);
        ensure_equals("message compound_masks", compound_masks<0x01, 0x02, 0x04, 0x08>::value, 0x0F);
        ensure_equals("message compound_masks", compound_masks<0x01, 0x02, 0x04, 0x08, 0x10>::value, 0x1F);
        ensure_equals("message compound_masks", compound_masks<0x01, 0x02, 0x04, 0x08, 0x10, 0x20>::value, 0x3F);
        ensure_equals("message compound_masks", compound_masks<0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40>::value, 0x7F);
        ensure_equals("message compound_masks", compound_masks<0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80>::value, 0xFF);

        ensure_equals("message compound_masks", compound_masks<0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80>::value, 0xFE);
        ensure_equals("message compound_masks", compound_masks<0x04, 0x08, 0x10, 0x20, 0x40, 0x80>::value, 0xFC);
        ensure_equals("message compound_masks", compound_masks<0x08, 0x10, 0x20, 0x40, 0x80>::value, 0xF8);
        ensure_equals("message compound_masks", compound_masks<0x10, 0x20, 0x40, 0x80>::value, 0xF0);
        ensure_equals("message compound_masks", compound_masks<0x20, 0x40, 0x80>::value, 0xE0);
        ensure_equals("message compound_masks", compound_masks<0x40, 0x80>::value, 0xC0);
        ensure_equals("message compound_masks", compound_masks<0x80>::value, 0x80);
        
        ensure_equals("message compound_masks", compound_masks<0xFF, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80>::value, 0xFF);

    }
    
    template<>
    template<>
    void testobject::test<7>()
    { 
        set_test_name("test_0007 bit_mask");
        
        
        ensure_equals("message bit_mask", bit_mask<0,0>::value, uint8_t(0x00));
        ensure_equals("message bit_mask", bit_mask<0,1>::value, uint8_t(0x00));
        ensure_equals("message bit_mask", bit_mask<0,2>::value, uint8_t(0x00));
        ensure_equals("message bit_mask", bit_mask<0,3>::value, uint8_t(0x00));
        ensure_equals("message bit_mask", bit_mask<0,4>::value, uint8_t(0x00));
        ensure_equals("message bit_mask", bit_mask<0,5>::value, uint8_t(0x00));
        ensure_equals("message bit_mask", bit_mask<0,6>::value, uint8_t(0x00));
        ensure_equals("message bit_mask", bit_mask<0,7>::value, uint8_t(0x00));
        
        ensure_equals("message bit_mask<1,0>", bit_mask<1,0>::value, uint8_t(0x01));
        ensure_equals("message bit_mask<1,1>", bit_mask<1,1>::value, uint8_t(0x02));
        ensure_equals("message bit_mask<1,2>", bit_mask<1,2>::value, uint8_t(0x04));
        ensure_equals("message bit_mask<1,3>", bit_mask<1,3>::value, uint8_t(0x08));
        ensure_equals("message bit_mask<1,4>", bit_mask<1,4>::value, uint8_t(0x10));
        ensure_equals("message bit_mask<1,5>", bit_mask<1,5>::value, uint8_t(0x20));
        ensure_equals("message bit_mask<1,6>", bit_mask<1,6>::value, uint8_t(0x40));
        ensure_equals("message bit_mask<1,7>", bit_mask<1,7>::value, uint8_t(0x80));
    }
    
    
    template<>
    template<>
    void testobject::test<8>()
    { 
        set_test_name("test_0008 ensure range function");
        
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(0)",    misc::ensure_range<uint16_t, 4, 1000>(0),      4);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(1)",    misc::ensure_range<uint16_t, 4, 1000>(1),      4);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(2)",    misc::ensure_range<uint16_t, 4, 1000>(2),      4);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(3)",    misc::ensure_range<uint16_t, 4, 1000>(3),      4);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(4)",    misc::ensure_range<uint16_t, 4, 1000>(4),      4);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(5)",    misc::ensure_range<uint16_t, 4, 1000>(5),      5);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(10)",   misc::ensure_range<uint16_t, 4, 1000>(10),    10);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(20)",   misc::ensure_range<uint16_t, 4, 1000>(20),    20);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(30)",   misc::ensure_range<uint16_t, 4, 1000>(30),    30);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(800)",  misc::ensure_range<uint16_t, 4, 1000>(800),  800);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(998)",  misc::ensure_range<uint16_t, 4, 1000>(998),  998);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(999)",  misc::ensure_range<uint16_t, 4, 1000>(999),  999);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(1000)", misc::ensure_range<uint16_t, 4, 1000>(1000),1000);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(1001)", misc::ensure_range<uint16_t, 4, 1000>(1001),1000);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(1002)", misc::ensure_range<uint16_t, 4, 1000>(1002),1000);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(1003)", misc::ensure_range<uint16_t, 4, 1000>(1003),1000);
        ensure_equals("test ensure_range<uint16_t, 4, 1000>(1004)", misc::ensure_range<uint16_t, 4, 1000>(1004),1000);
        

    }
    
    
    template<>
    template<>
    void testobject::test<9>()
    { 
        set_test_name("test_0009 make_32_bit_value function");
        
        /*
            template<typename ValueType, typename ByteType>
            ValueType make_32_bit_value(ByteType byte_3, ByteType byte_2, ByteType byte_1, ByteType byte_0)
            {
                return ((byte_3 << 24) | (byte_2 << 16) | (byte_1 << 8) | byte_0);
            }
        */
        
        // -25264513
        // 2172748161
        
        uint8_t temp[4];
        uint32_t value = 2172748161;
        
        temp[0] = byte_3<uint32_t,uint8_t>(value);
        temp[1] = byte_2<uint32_t,uint8_t>(value);
        temp[2] = byte_1<uint32_t,uint8_t>(value);
        temp[3] = byte_0<uint32_t,uint8_t>(value);
        
        ensure_equals("make_32_bit_value<uint32_t, uint8_t> 2172748161", make_32_bit_value<uint32_t, uint8_t>(temp[0], temp[1], temp[2], temp[3]), value);
        
        value = -25264513;
        
        temp[0] = byte_3<uint32_t,uint8_t>(value);
        temp[1] = byte_2<uint32_t,uint8_t>(value);
        temp[2] = byte_1<uint32_t,uint8_t>(value);
        temp[3] = byte_0<uint32_t,uint8_t>(value);
        
        ensure_equals("make_32_bit_value<uint32_t, uint8_t> -25264513;", make_32_bit_value<uint32_t, uint8_t>(temp[0], temp[1], temp[2], temp[3]), value);
        
        
        int32_t val = -25264513;
        
        temp[0] = byte_3<uint32_t,uint8_t>(val);
        temp[1] = byte_2<uint32_t,uint8_t>(val);
        temp[2] = byte_1<uint32_t,uint8_t>(val);
        temp[3] = byte_0<uint32_t,uint8_t>(val);
        
        ensure_equals("make_32_bit_value<int32_t, uint8_t> -25264513", make_32_bit_value<int32_t, uint8_t>(temp[0], temp[1], temp[2], temp[3]), val);

        val = static_cast<int32_t>(0x81818181);
        
        temp[0] = byte_3<uint32_t,uint8_t>(val);
        temp[1] = byte_2<uint32_t,uint8_t>(val);
        temp[2] = byte_1<uint32_t,uint8_t>(val);
        temp[3] = byte_0<uint32_t,uint8_t>(val);
        
        ensure_equals("make_32_bit_value<int32_t, uint8_t> 0x81818181", make_32_bit_value<int32_t, uint8_t>(temp[0], temp[1], temp[2], temp[3]), val);

        val = -321;
        
        temp[0] = byte_3<uint32_t,uint8_t>(val);
        temp[1] = byte_2<uint32_t,uint8_t>(val);
        temp[2] = byte_1<uint32_t,uint8_t>(val);
        temp[3] = byte_0<uint32_t,uint8_t>(val);
        
        ensure_equals("make_32_bit_value<int32_t, uint8_t> 0x81818181", make_32_bit_value<int32_t, uint8_t>(temp[0], temp[1], temp[2], temp[3]), val);

        val = 32767;
        
        temp[0] = byte_3<uint32_t,uint8_t>(val);
        temp[1] = byte_2<uint32_t,uint8_t>(val);
        temp[2] = byte_1<uint32_t,uint8_t>(val);
        temp[3] = byte_0<uint32_t,uint8_t>(val);
        
        ensure_equals("make_32_bit_value<int32_t, uint8_t> 0x81818181", make_32_bit_value<int32_t, uint8_t>(temp[0], temp[1], temp[2], temp[3]), val);
    }
} 
