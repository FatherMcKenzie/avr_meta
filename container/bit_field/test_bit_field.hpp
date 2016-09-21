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

#include <tut/tut.hpp>
#include "bit_field.hpp"
#include <typeinfo>
#include <iostream>

// #include "typelist.hpp"


enum ALPHA_FIELDS
{
    FIELD_0,
    FIELD_1,
    FIELD_2,
    FIELD_3,
};


enum TEST_8
{
    LOW_NIBBLE,
    HI_NIBBLE,
    WHOLE,
};

enum TEST_9
{
    ALPHA,
    BETA,
    GAMMA,
    DELTA
};

template<uint8_t ID_VAL>
struct TLTEST
{
    static const uint8_t ID;
};
template<uint8_t ID_VAL>
const uint8_t TLTEST<ID_VAL>::ID = ID_VAL;



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
        set_test_name("test_0001");
        
        //BF::bit_field<uint8_t> s;
        ensure_equals("IS_SIGNED<int8_t >::value", misc::IS_SIGNED<int8_t >::value, true);
        ensure_equals("IS_SIGNED<int16_t>::value", misc::IS_SIGNED<int16_t>::value, true);
        ensure_equals("IS_SIGNED<int32_t>::value", misc::IS_SIGNED<int32_t>::value, true);
        ensure_equals("IS_SIGNED<int64_t>::value", misc::IS_SIGNED<int64_t>::value, true);
        
        ensure_equals("IS_SIGNED<uint8_t >::value", misc::IS_SIGNED<uint8_t >::value, false);
        ensure_equals("IS_SIGNED<uint16_t>::value", misc::IS_SIGNED<uint16_t>::value, false);
        ensure_equals("IS_SIGNED<uint32_t>::value", misc::IS_SIGNED<uint32_t>::value, false);
        ensure_equals("IS_SIGNED<uint64_t>::value", misc::IS_SIGNED<uint64_t>::value, false);
    } 
    

    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002");
        
        
        ensure_equals("FIELD SIZE  1", BF::FIELD_STORAGE_SIZE<1>::value, 0);
        ensure_equals("FIELD SIZE  2", BF::FIELD_STORAGE_SIZE<2>::value, 1);
        ensure_equals("FIELD SIZE  3", BF::FIELD_STORAGE_SIZE<3>::value, 1);
        ensure_equals("FIELD SIZE  4", BF::FIELD_STORAGE_SIZE<4>::value, 1);
        ensure_equals("FIELD SIZE  5", BF::FIELD_STORAGE_SIZE<5>::value, 1);
        ensure_equals("FIELD SIZE  6", BF::FIELD_STORAGE_SIZE<6>::value, 1);
        ensure_equals("FIELD SIZE  7", BF::FIELD_STORAGE_SIZE<7>::value, 1);
        ensure_equals("FIELD SIZE  8", BF::FIELD_STORAGE_SIZE<8>::value, 1);

        ensure_equals("FIELD SIZE  9", BF::FIELD_STORAGE_SIZE<9>::value,  2);
        ensure_equals("FIELD SIZE 10", BF::FIELD_STORAGE_SIZE<10>::value, 2);
        ensure_equals("FIELD SIZE 12", BF::FIELD_STORAGE_SIZE<12>::value, 2);
        ensure_equals("FIELD SIZE 15", BF::FIELD_STORAGE_SIZE<15>::value, 2);
        ensure_equals("FIELD SIZE 16", BF::FIELD_STORAGE_SIZE<16>::value, 2);

        ensure_equals("FIELD SIZE 17", BF::FIELD_STORAGE_SIZE<17>::value, 4);
        ensure_equals("FIELD SIZE 18", BF::FIELD_STORAGE_SIZE<17>::value, 4);
        ensure_equals("FIELD SIZE 31", BF::FIELD_STORAGE_SIZE<17>::value, 4);
        ensure_equals("FIELD SIZE 32", BF::FIELD_STORAGE_SIZE<17>::value, 4);

        ensure_equals("FIELD SIZE 33", BF::FIELD_STORAGE_SIZE<33>::value, 8);
        ensure_equals("FIELD SIZE 34", BF::FIELD_STORAGE_SIZE<34>::value, 8);
        ensure_equals("FIELD SIZE 48", BF::FIELD_STORAGE_SIZE<48>::value, 8);
        ensure_equals("FIELD SIZE 64", BF::FIELD_STORAGE_SIZE<64>::value, 8);

        ensure_equals("FIELD SIZE 65", BF::FIELD_STORAGE_SIZE<65>::value,  uint8_t(-1));  // TODO STATIC ASSERT
        ensure_equals("FIELD SIZE128", BF::FIELD_STORAGE_SIZE<128>::value, uint8_t(-1));  // TODO STATIC ASSERT
    }


#if 1 // commented in typelist.hpp 
    template<>
    template<>
    void testobject::test<5>()
    { 
        set_test_name("test_0005");
        
        typedef TL::TYPELIST_04(uint8_t, uint16_t, uint32_t, uint64_t) UNSIGNED_TYPES;
        
        ensure_equals("TYPE AT 0", sizeof(TL::type_at<0, UNSIGNED_TYPES>::type), 1);
        ensure_equals("TYPE AT 1", sizeof(TL::type_at<1, UNSIGNED_TYPES>::type), 2);
        ensure_equals("TYPE AT 2", sizeof(TL::type_at<2, UNSIGNED_TYPES>::type), 4);
        ensure_equals("TYPE AT 3", sizeof(TL::type_at<3, UNSIGNED_TYPES>::type), 8);
        //ensure_equals("TYPE AT 4", sizeof(TL::type_at<4, UNSIGNED_TYPES>::type), -1); // Compile time error 
        
    }
#endif

    template<>
    template<>
    void testobject::test<6>()
    { 
        set_test_name("test_0006");
        

        
        typedef TLTEST<0> TT0;
        typedef TLTEST<1> TT1;
        typedef TLTEST<2> TT2;
        typedef TLTEST<3> TT3;
        typedef TLTEST<42> TT42;
        
        typedef TL::TYPELIST_05(TT0, TT1, TT2, TT3, TT42) TEST_TYPES;
        
        ensure_equals("FIND ID 0", TL::find_id<size_t, 0, TEST_TYPES>::type::ID, 0);
        ensure_equals("FIND ID 1", TL::find_id<size_t, 1, TEST_TYPES>::type::ID, 1);
        ensure_equals("FIND ID 2", TL::find_id<size_t, 2, TEST_TYPES>::type::ID, 2);
        ensure_equals("FIND ID 3", TL::find_id<size_t, 3, TEST_TYPES>::type::ID, 3);
        ensure_equals("FIND ID 42", TL::find_id<size_t, 42, TEST_TYPES>::type::ID, 42);
        //ensure_equals("FIND ID -1", TL::find_id<size_t, -1, TEST_TYPES>::type::ID, 00); // Compile time error 
    }

    template<>
    template<>
    void testobject::test<7>()
    { 
        set_test_name("test_0007");
        typedef BF::bit_field<ALPHA_FIELDS,
                        BF::FIELDS<
                            BF::FIELD<FIELD_0, 2, 0>,
                            BF::FIELD<FIELD_1, 1, 2>,
                            BF::FIELD<FIELD_2, 3, 3>,
                            BF::FIELD<FIELD_3, 2, 6>
                            >
                        > TEST_7_BITFIELD;
        TEST_7_BITFIELD s;
        
        ensure_equals("message", s.get<FIELD_0>(), 0);
        ensure_equals("message", s.get<FIELD_1>(), false);
        ensure_equals("message", s.get<FIELD_2>(), 0);
        ensure_equals("message", s.get<FIELD_3>(), 0);

        
        s.set<FIELD_0>(2);
        s.set<FIELD_1>(true);
        s.set<FIELD_2>(5);
        s.set<FIELD_3>(5);
        
        ensure_equals("message", s.get<FIELD_0>(), 2);
        ensure_equals("message", s.get<FIELD_1>(), true);
        ensure_equals("message", s.get<FIELD_2>(), 5);
        ensure_equals("message", s.get<FIELD_3>(), 1);
        
        // 11/25/2015 Constructor test
        
        ensure_equals("construction", TEST_7_BITFIELD::make<FIELD_0>(3),  3);
        ensure_equals("construction", TEST_7_BITFIELD::make<FIELD_1>(76), (1 << 2));
        ensure_equals("construction", TEST_7_BITFIELD::make<FIELD_2>(5),  (5 << 3));
        ensure_equals("construction", TEST_7_BITFIELD::make<FIELD_3>(2),  (2 << 6));
        
        
        TEST_7_BITFIELD test_value0(TEST_7_BITFIELD::make<FIELD_0>(2) | TEST_7_BITFIELD::make<FIELD_1>(false) | TEST_7_BITFIELD::make<FIELD_2>(5) | TEST_7_BITFIELD::make<FIELD_3>(2));
        ensure_equals("construction", (uint16_t)test_value0.int_value,  (uint16_t)0x00AA);

        TEST_7_BITFIELD test_value1(TEST_7_BITFIELD::make<FIELD_0>(5) /*b01*/ | TEST_7_BITFIELD::make<FIELD_1>(42 == 42) | TEST_7_BITFIELD::make<FIELD_2>(2) | TEST_7_BITFIELD::make<FIELD_3>(9)/*b01*/);
        ensure_equals("construction", (uint16_t)test_value1.int_value,  (uint16_t)0x55);
        
    }

    // overlapped bitfields
    // full length bitfields
    
    template<>
    template<>
    void testobject::test<8>()
    {
        set_test_name("test_0008");
        
        BF::bit_field<TEST_8,
                        BF::FIELDS<
                            BF::FIELD<LOW_NIBBLE, 4, 0>,
                            BF::FIELD<HI_NIBBLE,  4, 4>,
                            BF::FIELD<WHOLE,      8, 0>
                            >
                        > q;
        
        ensure_equals("LOW_NIBBLE", q.get<LOW_NIBBLE>(), 0);
        ensure_equals("HI_NIBBLE ", q.get<HI_NIBBLE>(),  0);
        ensure_equals("WHOLE     ", q.get<WHOLE>(),      0);
        
        q.set<LOW_NIBBLE>(0xB);
        q.set<HI_NIBBLE>(0xA);
        
        ensure_equals("LOW_NIBBLE", q.get<LOW_NIBBLE>(), 0x0B);
        ensure_equals("HI_NIBBLE ", q.get<HI_NIBBLE>(),  0x0A);
        ensure_equals("WHOLE     ", q.get<WHOLE>(),      0xAB);
        
    }

    // zero width bitfields
    template<>
    template<>
    void testobject::test<9>()
    {
        set_test_name("test_0009");
        BF::bit_field<TEST_9,
                        BF::FIELDS<
                            BF::FIELD<ALPHA, 8, 0>,
                            BF::FIELD<BETA,  8, 8>,
                            BF::FIELD<GAMMA, 0, 4>,
                            BF::FIELD<DELTA, 16,0>
                            >,
                            uint16_t
                        > a;
                        
        ensure_equals("ALPHA", a.get<ALPHA>(), 0);
        ensure_equals("BETA ", a.get<BETA>(),  0);
        ensure_equals("GAMMA", a.get<GAMMA>(), 0);
        ensure_equals("DELTA", a.get<DELTA>(), 0);
        
        a.set<ALPHA>(0xBA);
        a.set<BETA> (0xAB);
        a.set<GAMMA>(42);
        
        ensure_equals("ALPHA", a.get<ALPHA>(), 0xBA);
        ensure_equals("BETA ", a.get<BETA>(),  0xAB);
        ensure_equals("GAMMA", a.get<GAMMA>(), 0);
        ensure_equals("DELTA", a.get<DELTA>(), 0xABBA);
        
    }
    
    template<>
    template<>
    void testobject::test<10>()
    {
        set_test_name("test_0010");
        
        set_test_name("test_0007");
        BF::bit_field<ALPHA_FIELDS,
                        BF::FIELDS<
                            BF::FIELD<FIELD_0, 2, 0>,
                            BF::FIELD<FIELD_1, 1, 2>,
                            BF::FIELD<FIELD_2, 3, 3>,
                            BF::FIELD<FIELD_3, 2, 6>
                            >
                        ,volatile uint8_t
                        > s;
        
        ensure_equals("message", s.get<FIELD_0>(), 0);
        ensure_equals("message", s.get<FIELD_1>(), false);
        ensure_equals("message", s.get<FIELD_2>(), 0);
        ensure_equals("message", s.get<FIELD_3>(), 0);

        
        s.set<FIELD_0>(2);
        s.set<FIELD_1>(true);
        s.set<FIELD_2>(5);
        s.set<FIELD_3>(5);
        
        ensure_equals("message", s.get<FIELD_0>(), 2);
        ensure_equals("message", s.get<FIELD_1>(), true);
        ensure_equals("message", s.get<FIELD_2>(), 5);
        ensure_equals("message", s.get<FIELD_3>(), 1);
    }

    template<>
    template<>
    void testobject::test<11>()
    {
        set_test_name("test_0011");
        
        set_test_name("test_0007");
        volatile BF::bit_field<ALPHA_FIELDS,
                        BF::FIELDS<
                            BF::FIELD<FIELD_0, 2, 0>,
                            BF::FIELD<FIELD_1, 1, 2>,
                            BF::FIELD<FIELD_2, 3, 3>,
                            BF::FIELD<FIELD_3, 2, 6>
                            >
                        > s;
        
        ensure_equals("message", s.get<FIELD_0>(), 0);
        ensure_equals("message", s.get<FIELD_1>(), false);
        ensure_equals("message", s.get<FIELD_2>(), 0);
        ensure_equals("message", s.get<FIELD_3>(), 0);

        
        s.set<FIELD_0>(2);
        s.set<FIELD_1>(true);
        s.set<FIELD_2>(5);
        s.set<FIELD_3>(5);
        
        ensure_equals("message", s.get<FIELD_0>(), 2);
        ensure_equals("message", s.get<FIELD_1>(), true);
        ensure_equals("message", s.get<FIELD_2>(), 5);
        ensure_equals("message", s.get<FIELD_3>(), 1);
    }
} 
