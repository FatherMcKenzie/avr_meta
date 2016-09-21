// Tue Oct 20 02:05:25  2015
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
#include "circular_buffer.hpp"

#include "circular_buffer_helper.hpp"

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
        
        cb::circular_buffer<int,2> s;
        s.debug();
        ensure_equals("append", s.append(1), true);
        s.debug();
        ensure_equals("append", s.append(2), true);
        s.debug();
        ensure_equals("append", s.append(3), true);
        s.debug();
        ensure_equals("append", s.append(4), true);
        s.debug();
        ensure_equals("append", s.append(5), false);
        s.debug();
        
        printf("\n=========================================\n");
        
        printf("Val = %d\n", s.pop());
        s.debug();
        
        printf("Val = %d\n", s.pop());
        s.debug();
        
        printf("Val = %d\n", s.pop());
        s.debug();
        
        printf("Val = %d\n", s.pop());
        s.debug();
        
        printf("Val = %d\n", s.pop());
        s.debug();

    } 
    
    template<>
    template<>
    void testobject::test<3>()
    { 
        set_test_name("test_0003");
        
        
        printf("\n================== TEST 3 =======================\n");
        
        cb::circular_buffer<unsigned,2> s;
        s.debug();
        ensure_equals("append", s.append(1), true);
        s.debug();
        ensure_equals("append", s.append(2), true);
        s.debug();
        ensure_equals("append", s.append(3), true);
        s.debug();
        ensure_equals("append", s.append(4), true);
        s.debug();
        ensure_equals("append", s.append(5), false);
        s.debug();

        printf("\n=========================================\n");
        
        unsigned value = -1;
        
        ensure_equals("pop", s.pop(value), true);
        printf("\nValue : %d\n", value);
        ensure_equals("value", value, 1);
        s.debug();
    
        ensure_equals("pop", s.pop(value), true);
        printf("\nValue : %d\n", value);
        ensure_equals("value", value, 2);
        s.debug();

        ensure_equals("append", s.append(7), true);
        s.debug();
        
        
        ensure_equals("pop", s.pop(value), true);
        printf("\nValue : %d\n", value);
        ensure_equals("value", value, 3);
        s.debug();
    
        ensure_equals("pop", s.pop(value), true);
        printf("\nValue : %d\n", value);
        ensure_equals("value", value, 4);
        s.debug();
    
        ensure_equals("pop", s.pop(value), true);
        printf("\nValue : %d\n", value);
        ensure_equals("value", value, 7);
        s.debug();
    
        ensure_equals("pop", s.pop(value), false);
        printf("\nValue : %d\n", value);
        ensure_equals("value", value, 7);
        s.debug();
    } 

    
    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004");
        
        cb::circular_buffer<unsigned,3> s;
        
        printf("\n=================== TEST 4 ======================\n");

        s.debug();
        ensure_equals("message", s.append(1), true);

        s.debug();
        ensure_equals("message", s.append(2), true);

        s.debug();
        ensure_equals("message", s.append(3), true);

        s.debug();
        ensure_equals("message", s.append(4), true);

        s.debug();
        ensure_equals("message", s.append(5), true);

        s.debug();
        ensure_equals("message", s.append(6), true);

        s.debug();
        ensure_equals("message", s.append(7), true);

        s.debug();
        ensure_equals("message", s.append(8), true);

        s.debug();
        ensure_equals("message", s.append(9), false);
        
        s.debug();
        
        printf("\n=================== TEST 4 1 ======================\n");

        unsigned value = -1;
        
        ensure_equals("pop", s.pop(value), true);
        printf("\nValue : %d\n", value);
        ensure_equals("value", value, 1);
        s.debug();

        ensure_equals("pop", s.pop(value), true);
        printf("\nValue : %d\n", value);
        ensure_equals("value", value, 2);
        s.debug();

        ensure_equals("pop", s.pop(value), true);
        printf("\nValue : %d\n", value);
        ensure_equals("value", value, 3);
        s.debug();

        ensure_equals("pop", s.pop(value), true);
        printf("\nValue : %d\n", value);
        ensure_equals("value", value, 4);
        s.debug();

        ensure_equals("pop", s.pop(value), true);
        printf("\nValue : %d\n", value);
        ensure_equals("value", value, 5);
        s.debug();

        ensure_equals("pop", s.pop(value), true);
        printf("\nValue : %d\n", value);
        ensure_equals("value", value, 6);
        s.debug();

        ensure_equals("pop", s.pop(value), true);
        printf("\nValue : %d\n", value);
        ensure_equals("value", value, 7);
        s.debug();

        ensure_equals("pop", s.pop(value), true);
        printf("\nValue : %d\n", value);
        ensure_equals("value", value, 8);
        s.debug();

        ensure_equals("pop", s.pop(value), false);
        printf("\nValue : %d\n", value);
        ensure_equals("value", value, 8);
        s.debug();
        
        printf("\n=================== TEST 4 2 ======================\n");

        value = -1;
        
        s.debug();
        ensure_equals("message", s.append(9), true);

        s.debug();
        ensure_equals("message", s.append(10), true);
        
        s.debug();
        
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 9);
        s.debug();

        ensure_equals("message", s.append(11), true);

        s.debug();
        ensure_equals("message", s.append(12), true);
        
        s.debug();
        
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 10);
        s.debug();


        ensure_equals("message", s.append(13), true);

        s.debug();
        ensure_equals("message", s.append(14), true);
        
        s.debug();
        
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 11);
        s.debug();

        ensure_equals("message", s.append(15), true);

        s.debug();
        ensure_equals("message", s.append(16), true);
        
        s.debug();
        
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 12);
        s.debug();


    } 


    template<>
    template<>
    void testobject::test<5>()
    { 
        set_test_name("test_0005");
        
        cb::circular_buffer<unsigned,4> s;
        
        printf("\n=================== TEST 5 ======================\n");

        s.debug();
        ensure_equals("message", s.append(1), true);

        s.debug();
        ensure_equals("message", s.append(2), true);

        s.debug();
        ensure_equals("message", s.append(3), true);

        s.debug();
        ensure_equals("message", s.append(4), true);

        s.debug();
        ensure_equals("message", s.append(5), true);

        s.debug();
        ensure_equals("message", s.append(6), true);

        s.debug();
        ensure_equals("message", s.append(7), true);

        s.debug();
        ensure_equals("message", s.append(8), true);

        s.debug();
        ensure_equals("message", s.append(9), true);

        s.debug();
        ensure_equals("message", s.append(10), true);

        s.debug();
        ensure_equals("message", s.append(11), true);

        s.debug();
        ensure_equals("message", s.append(12), true);

        s.debug();
        ensure_equals("message", s.append(13), true);

        s.debug();
        ensure_equals("message", s.append(14), true);

        s.debug();
        ensure_equals("message", s.append(15), true);

        s.debug();
        ensure_equals("message", s.append(16), true);

        s.debug();
        ensure_equals("message", s.append(17), false);
        
        printf("\n=================== TEST 5 1 ======================\n");

        unsigned value = -1;
        
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 1);
        
        s.debug();
        ensure_equals("message", s.append(17), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 2);
        
        s.debug();
        ensure_equals("message", s.append(18), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 3);
        
        s.debug();
        ensure_equals("message", s.append(19), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 4);
        
        s.debug();
        ensure_equals("message", s.append(20), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 5);
        
        s.debug();
        ensure_equals("message", s.append(21), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 6);
        
        s.debug();
        ensure_equals("message", s.append(22), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 7);
        
        s.debug();
        ensure_equals("message", s.append(23), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 8);
        
        s.debug();
        ensure_equals("message", s.append(24), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 9);
        
        s.debug();
        ensure_equals("message", s.append(25), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 10);
        
        s.debug();
        ensure_equals("message", s.append(26), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 11);
        
        s.debug();
        ensure_equals("message", s.append(27), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 12);
        
        s.debug();
        ensure_equals("message", s.append(28), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 13);
        
        s.debug();
        ensure_equals("message", s.append(29), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 14);
        
        s.debug();
        ensure_equals("message", s.append(30), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 15);
        
        s.debug();
        ensure_equals("message", s.append(31), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 16);
        
        s.debug();
        ensure_equals("message", s.append(32), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        ensure_equals("pop", s.pop(value), true);
        printf("Value : %d\n", value);
        ensure_equals("value", value, 17);
        
        s.debug();
        ensure_equals("message", s.append(33), true);
        ensure_equals("message", s.append(99), false);
        
        s.debug();
        
    }

} 
