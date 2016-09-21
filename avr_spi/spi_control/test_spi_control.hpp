// Wed Sep 02 09:58:15  2015
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
#include "spi_control.hpp"

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
        set_test_name("test_0001 MASTER SPCR_mask");
        
        //typedef spi::SPI_CONTROL<> spii;
        //ensure_equals("MASTER<SINGLE_SPEED, FOSC_DIV_4>::SPCR_mask", spi::MASTER<spi::SINGLE_SPEED, spi::FOSC_DIV_4>::SPCR_mask, 0x10);
        ensure_equals("MASTER<SINGLE_SPEED, FOSC_DIV_4>::SPCR_mask", spi::MASTER<spi::SINGLE_SPEED, spi::FOSC_DIV_4>::SPCR_mask, 0x10);
        ensure_equals("MASTER<SINGLE_SPEED, FOSC_DIV_16>::SPCR_mask", spi::MASTER<spi::SINGLE_SPEED, spi::FOSC_DIV_16>::SPCR_mask, 0x11);
        ensure_equals("MASTER<SINGLE_SPEED, FOSC_DIV_64>::SPCR_mask", spi::MASTER<spi::SINGLE_SPEED, spi::FOSC_DIV_64>::SPCR_mask, 0x12);
        ensure_equals("MASTER<SINGLE_SPEED, FOSC_DIV_128>::SPCR_mask", spi::MASTER<spi::SINGLE_SPEED, spi::FOSC_DIV_128>::SPCR_mask, 0x13);
        ensure_equals("MASTER<DOUBLE_SPEED, FOSC_DIV_4>::SPCR_mask", spi::MASTER<spi::DOUBLE_SPEED, spi::FOSC_DIV_4>::SPCR_mask, 0x10);
        ensure_equals("MASTER<DOUBLE_SPEED, FOSC_DIV_16>::SPCR_mask", spi::MASTER<spi::DOUBLE_SPEED, spi::FOSC_DIV_16>::SPCR_mask, 0x11);
        ensure_equals("MASTER<DOUBLE_SPEED, FOSC_DIV_64>::SPCR_mask", spi::MASTER<spi::DOUBLE_SPEED, spi::FOSC_DIV_64>::SPCR_mask, 0x12);
        ensure_equals("MASTER<DOUBLE_SPEED, FOSC_DIV_128>::SPCR_mask", spi::MASTER<spi::DOUBLE_SPEED, spi::FOSC_DIV_128>::SPCR_mask, 0x13);

    } 
    

    template<>
    template<>
    void testobject::test<2>()
    { 
        set_test_name("test_0002 MASTER SPSR_mask");
        
        ensure_equals("MASTER<SINGLE_SPEED, FOSC_DIV_4>::SPSR_mask",   spi::MASTER<spi::SINGLE_SPEED, spi::FOSC_DIV_4>::SPSR_mask,   0);
        ensure_equals("MASTER<SINGLE_SPEED, FOSC_DIV_16>::SPSR_mask",  spi::MASTER<spi::SINGLE_SPEED, spi::FOSC_DIV_16>::SPSR_mask,  0);
        ensure_equals("MASTER<SINGLE_SPEED, FOSC_DIV_64>::SPSR_mask",  spi::MASTER<spi::SINGLE_SPEED, spi::FOSC_DIV_64>::SPSR_mask,  0);
        ensure_equals("MASTER<SINGLE_SPEED, FOSC_DIV_128>::SPSR_mask", spi::MASTER<spi::SINGLE_SPEED, spi::FOSC_DIV_128>::SPSR_mask, 0);
        ensure_equals("MASTER<DOUBLE_SPEED, FOSC_DIV_4>::SPSR_mask",   spi::MASTER<spi::DOUBLE_SPEED, spi::FOSC_DIV_4>::SPSR_mask,   1);
        ensure_equals("MASTER<DOUBLE_SPEED, FOSC_DIV_16>::SPSR_mask",  spi::MASTER<spi::DOUBLE_SPEED, spi::FOSC_DIV_16>::SPSR_mask,  1);
        ensure_equals("MASTER<DOUBLE_SPEED, FOSC_DIV_64>::SPSR_mask",  spi::MASTER<spi::DOUBLE_SPEED, spi::FOSC_DIV_64>::SPSR_mask,  1);
        ensure_equals("MASTER<DOUBLE_SPEED, FOSC_DIV_128>::SPSR_mask", spi::MASTER<spi::DOUBLE_SPEED, spi::FOSC_DIV_128>::SPSR_mask, 1);
    } 
    

    template<>
    template<>
    void testobject::test<4>()
    { 
        set_test_name("test_0004");
        
        //ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_0>,INTR_ENABLED>::SPCR_value", (uint16_t)spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_0>,spi::INTR_DISABLED>::SPCR_value, 0x50);
        /*
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_0>,INTR_DISABLED>::SPCR_value", (uint16_t)spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_0>,spi::INTR_DISABLED>::SPCR_value, 0x50);
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_0>,INTR_ENABLED>::SPCR_value", (uint16_t)spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_0>,spi::INTR_ENABLED>::SPCR_value, 0xd0);
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_1>,INTR_DISABLED>::SPCR_value", (uint16_t)spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_1>,spi::INTR_DISABLED>::SPCR_value, 0x54);
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_1>,INTR_ENABLED>::SPCR_value", (uint16_t)spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_1>,spi::INTR_ENABLED>::SPCR_value, 0xd4);
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_2>,INTR_DISABLED>::SPCR_value", (uint16_t)spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_2>,spi::INTR_DISABLED>::SPCR_value, 0x58);
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_2>,INTR_ENABLED>::SPCR_value", (uint16_t)spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_2>,spi::INTR_ENABLED>::SPCR_value, 0xd8);
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_3>,INTR_DISABLED>::SPCR_value", (uint16_t)spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_3>,spi::INTR_DISABLED>::SPCR_value, 0x5c);
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_3>,INTR_ENABLED>::SPCR_value", (uint16_t)spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_3>,spi::INTR_ENABLED>::SPCR_value, 0xdc);
        */
        
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_0>,INTR_DISABLED>::SPCR_value", spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_0>,spi::INTR_DISABLED>::SPCR_value, 0x50);
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_0>,INTR_ENABLED>::SPCR_value",  spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_0>,spi::INTR_ENABLED>::SPCR_value,  0xd0);
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_1>,INTR_DISABLED>::SPCR_value", spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_1>,spi::INTR_DISABLED>::SPCR_value, 0x54);
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_1>,INTR_ENABLED>::SPCR_value",  spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_1>,spi::INTR_ENABLED>::SPCR_value,  0xd4);
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_2>,INTR_DISABLED>::SPCR_value", spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_2>,spi::INTR_DISABLED>::SPCR_value, 0x58);
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_2>,INTR_ENABLED>::SPCR_value",  spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_2>,spi::INTR_ENABLED>::SPCR_value,  0xd8);
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_3>,INTR_DISABLED>::SPCR_value", spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_3>,spi::INTR_DISABLED>::SPCR_value, 0x5c);
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_MODE<MODE_3>,INTR_ENABLED>::SPCR_value",  spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_MODE<spi::MODE_3>,spi::INTR_ENABLED>::SPCR_value,  0xdc);

    }
    

    template<>
    template<>
    void testobject::test<5>()
    { 
        set_test_name("test_0005");
        
        //ensure_equals("SPI_CONTROL<MASTER<>,SCK_CTRL<IDLE_LOW, SAMPLE_LEADING_EDGE>,INTR_DISABLED>::SPCR_value", spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_CTRL<spi::IDLE_LOW, spi::SAMPLE_LEADING_EDGE>,spi::INTR_DISABLED>::SPCR_value, 0x50);

        ensure_equals("SPI_CONTROL<MASTER<>,SCK_CTRL<IDLE_LOW, SAMPLE_LEADING_EDGE>,INTR_DISABLED>::SPCR_value",
                spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_CTRL<spi::IDLE_LOW, spi::SAMPLE_LEADING_EDGE>,spi::INTR_DISABLED>::SPCR_value, 0x50);
                
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_CTRL<IDLE_LOW, SAMPLE_LEADING_EDGE>,INTR_ENABLED>::SPCR_value",
                spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_CTRL<spi::IDLE_LOW, spi::SAMPLE_LEADING_EDGE>,spi::INTR_ENABLED>::SPCR_value, 0xd0);
                
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_CTRL<IDLE_LOW, SAMPLE_TRAILING_EDGE>,INTR_DISABLED>::SPCR_value",
                spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_CTRL<spi::IDLE_LOW, spi::SAMPLE_TRAILING_EDGE>,spi::INTR_DISABLED>::SPCR_value, 0x54);
                
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_CTRL<IDLE_LOW, SAMPLE_TRAILING_EDGE>,INTR_ENABLED>::SPCR_value",
                spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_CTRL<spi::IDLE_LOW, spi::SAMPLE_TRAILING_EDGE>,spi::INTR_ENABLED>::SPCR_value, 0xd4);
                
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_CTRL<IDLE_HIGH, SAMPLE_LEADING_EDGE>,INTR_DISABLED>::SPCR_value",
                spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_CTRL<spi::IDLE_HIGH, spi::SAMPLE_LEADING_EDGE>,spi::INTR_DISABLED>::SPCR_value, 0x58);
                
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_CTRL<IDLE_HIGH, SAMPLE_LEADING_EDGE>,INTR_ENABLED>::SPCR_value",
                spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_CTRL<spi::IDLE_HIGH, spi::SAMPLE_LEADING_EDGE>,spi::INTR_ENABLED>::SPCR_value, 0xd8);
                
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_CTRL<IDLE_HIGH, SAMPLE_TRAILING_EDGE>,INTR_DISABLED>::SPCR_value",
                spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_CTRL<spi::IDLE_HIGH, spi::SAMPLE_TRAILING_EDGE>,spi::INTR_DISABLED>::SPCR_value, 0x5c);
                
        ensure_equals("SPI_CONTROL<MASTER<>,SCK_CTRL<IDLE_HIGH, SAMPLE_TRAILING_EDGE>,INTR_ENABLED>::SPCR_value",
                spi::SPI_CONTROL<spi::MASTER<>,spi::SCK_CTRL<spi::IDLE_HIGH, spi::SAMPLE_TRAILING_EDGE>,spi::INTR_ENABLED>::SPCR_value, 0xdc);
    } 
} 
