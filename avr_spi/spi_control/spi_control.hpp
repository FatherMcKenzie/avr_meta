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


#ifndef SPI_CONTROL_CLASS_HEADER
#define SPI_CONTROL_CLASS_HEADER

#include <stdint.h>
#include "../../avr_misc/avr_misc.hpp"

#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
}; 
#endif

namespace spi
{

/**
 * DORD: Data Order
 */

enum SPI_DATA_ORDER
{
    MSB_FIRST = 0, /**< the MSB of the data word is transmitted first. */
    LSB_FIRST = 1  /**< the LSB of the data word is transmitted first. */
};

//=============================================================================
/**
 * CPOL: Clock Polarity
 * When this bit is written to one, SCK is high when idle. When CPOL is written to zero, SCK is low when idle. 
 * Refer to Figure 21-3 on page 201 and Figure 21-4 on page 201 for an example. 
 * The CPOL functionality is summarized in Table 21-3.
 */
enum SPI_CLOCK_POLARITY
{
    IDLE_LOW  = 0, /**< SCK is low when idle. */
    IDLE_HIGH = 1, /**< SCK is high when idle. */
};

/**
 * CPHA: Clock Phase
The settings of the Clock Phase bit (CPHA) determine if data is sampled on the leading (first) or
trailing (last) edge of SCK. Refer to Figure 21-3 on page 201 and Figure 21-4 on page 201 for an
example. The CPOL functionality is summarized in Table 21-4.
 */
enum SPI_CLOCK_PHASE
{
    SAMPLE_LEADING_EDGE  = 0, /**< Data is sampled on the leading (first) edge of SCK. */
    SAMPLE_TRAILING_EDGE = 1  /**< Data is sampled on the trailing (last) edge of SCK. */
};

/**
 * This is just another way to control shift clock phase and polarity.
 */
enum SPI_CLOCK_MODE
{
    MODE_0 = 0, /**< SCK is low when idle.  Data is sampled on the leading (first) edge of SCK.*/
    MODE_1 = 1, /**< SCK is low when idle.  Data is sampled on the trailing (last) edge of SCK.*/
    MODE_2 = 2, /**< SCK is high when idle. Data is sampled on the leading (first) edge of SCK.*/
    MODE_3 = 3  /**< SCK is high when idle. Data is sampled on the trailing (last) edge of SCK.*/
};
//=============================================================================
template
<
    SPI_CLOCK_POLARITY cpol = IDLE_LOW,
    SPI_CLOCK_PHASE phase = SAMPLE_LEADING_EDGE
>
struct SCK_CTRL
{
    static const uint8_t SPCR_mask;
};
template<SPI_CLOCK_POLARITY cpol,SPI_CLOCK_PHASE phase>
const uint8_t SCK_CTRL<cpol,phase>::SPCR_mask = (bit_mask<cpol,3>::value | bit_mask<phase,2>::value);
//------------------------------------------------------------------------------

/**
 * This is just more compact way to control shift clock phase and polarity.
 * Uses one template parameter instead of two.
 */
template
<
    SPI_CLOCK_MODE mode = MODE_0
>
struct SCK_MODE
{
    static const uint8_t SPCR_mask;
};

template<SPI_CLOCK_MODE mode>
const uint8_t SCK_MODE<mode>::SPCR_mask = ((0x03 & mode) << 2);
//================================================================================


/**
 * SPIE: SPI Interrupt Enable
 * control whether the SPI interrupt to be executed if SPIF bit in the SPSR Register is set and 
 * if the Global Interrupt Enable bit in SREG is set.
 */
enum SPI_INTERRUPT
{
    INTR_DISABLED = 0, /**< Disables interrupt */
    INTR_ENABLED  = 1, /**< Enables interrupt */
};

/**
 * SPR1, SPR0: SPI Clock Rate Select 1 and 0
 */
enum MASTER_CLOCK_RATE_SELECT
{
    FOSC_DIV_4      = 0,
    FOSC_DIV_16     = 1,
    FOSC_DIV_64     = 2,
    FOSC_DIV_128    = 3,
};

/**
 * SPI2X: Double SPI Speed Bit
 * When this bit is written logic one the SPI speed (SCK Frequency) will be doubled when the SPI
 * is in Master mode (see Table 21-5). This means that the minimum SCK period will be two CPU
 * clock periods. When the SPI is configured as Slave, the SPI is only guaranteed to work at f osc /4
 * or lower.
 */
enum SPI_DOUBLE_SPEED
{
    SINGLE_SPEED = 0, /**<  */
    DOUBLE_SPEED = 1, /**<  the SPI speed (SCK Frequency) will be doubled when the SPI is in Master mode. */
};

// =============== MASTER ANS SLAVE MODES ===============
struct SLAVE
{
    static const uint8_t SPCR_mask = 0;
    static const uint8_t SPSR_mask = 0;
    
    static void reenable_master_mode(){}
};

template
<
    SPI_DOUBLE_SPEED dbl_speed = SINGLE_SPEED,
    MASTER_CLOCK_RATE_SELECT clkrs = FOSC_DIV_4
>
struct MASTER
{
    static const uint8_t SPCR_mask;
    static const uint8_t SPSR_mask;
    
    static void reenable_master_mode()
    {
#ifndef UNITTEST_MODE
#ifndef PC_TARGET
        SPCR |= bit<4>::value;
#endif // UNITTEST_MODE
#endif
    }
};

template<SPI_DOUBLE_SPEED dbl_speed, MASTER_CLOCK_RATE_SELECT clkrs>
const uint8_t MASTER<dbl_speed, clkrs>::SPCR_mask = bit<4>::value | // Bit 4 – MSTR: Master/Slave Select
                                                    0x03 & clkrs;   // Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0

template<SPI_DOUBLE_SPEED dbl_speed, MASTER_CLOCK_RATE_SELECT clkrs>
const uint8_t MASTER<dbl_speed, clkrs>::SPSR_mask = bit_mask<dbl_speed, 0>::value; // Bit 0 – SPI2X: Double SPI Speed Bit
// =============== MASTER ANS SLAVE MODES ===============


struct DEFAULT_PIN_CTRL
{
};



// TODO !!!! SLAVE SELECT CONTROL!!!!!
template
<
    class mode = MASTER<>,
    class sck_ctrl = SCK_MODE<MODE_0>, // or SCK_CTRL<IDLE_LOW, SAMPLE_LEADING_EDGE>
    SPI_INTERRUPT intr = INTR_DISABLED,
    class pin_control = DEFAULT_PIN_CTRL, // TODO!!!
    SPI_DATA_ORDER dorder = MSB_FIRST
>
struct SPI_CONTROL
{
    static const uint8_t SPCR_value;
    static const uint8_t SPSR_value;
    
    static void inline init()
    {
        pin_control::init();
        
        SPCR = SPCR_value;
        SPSR = SPSR_value;
        //SPDR = 0;
    }
    
    /**
     * If SS is configured as an input and is driven low while MSTR is set, MSTR will be cleared,
     * and SPIF in SPSR will become set. The user will then have to set MSTR to re-enable SPI Master mode.
     */
    static void inline reenable_master_mode()
    {
        mode::reenable_master_mode();
    }

//===============================================================================================================

#if defined(UNITTEST_MODE) || defined(PC_TARGET)
    static volatile uint8_t SPCR;
    static volatile uint8_t SPDR;
    static volatile uint8_t SPSR;
    static volatile uint8_t SPIF;
#endif

    static inline void wait_for_ready()
    {
        while (!(SPSR & (1 << SPIF))) {}
    }

    static uint8_t receive()
    {
        SPDR = 0xFF;
        wait_for_ready();
        return SPDR;
    }
    
    static uint8_t receive(uint8_t* buf, uint16_t n) 
    {
        for(uint16_t i = 0; i < n; ++i)
        {
            SPDR = 0xFF;
            wait_for_ready();
            *(buf + i) = SPDR;
        }
        return 0;
    }
    
    static void send(uint8_t data) 
    {
        SPDR = data;
        wait_for_ready();
    }

    static void send(const uint8_t* buf , uint16_t n) 
    {
        for(uint16_t i = 0; i < n; ++i)
        {
            SPDR = *(buf + i);
            wait_for_ready();
        }
    }

    static void exch(uint8_t* out, const uint8_t* in, uint16_t size)
    {
        for(uint16_t i = 0; i < size; ++i)
        {
            SPDR = *(in + i);
            wait_for_ready();
            *(out + i) = SPDR;
        }
    }

    static inline uint8_t exch(uint8_t cmd)
    {
        SPDR = cmd;
        wait_for_ready();
        return SPDR;
    }
    
    template<uint8_t cmd>
    static inline uint8_t exch()
    {
        SPDR = cmd;
        wait_for_ready();
        return SPDR;
    }

};

#if defined(UNITTEST_MODE) || defined(PC_TARGET)
template<class mode,class sck_ctrl,SPI_INTERRUPT intr,class pin_control,SPI_DATA_ORDER dorder>
volatile uint8_t SPI_CONTROL<mode,sck_ctrl,intr,pin_control,dorder>::SPDR;

template<class mode,class sck_ctrl,SPI_INTERRUPT intr,class pin_control,SPI_DATA_ORDER dorder>
volatile uint8_t SPI_CONTROL<mode,sck_ctrl,intr,pin_control,dorder>::SPSR;

template<class mode,class sck_ctrl,SPI_INTERRUPT intr,class pin_control,SPI_DATA_ORDER dorder>
volatile uint8_t SPI_CONTROL<mode,sck_ctrl,intr,pin_control,dorder>::SPIF;
#endif


template<class mode,class sck_ctrl,SPI_INTERRUPT intr,class pin_control,SPI_DATA_ORDER dorder>
const uint8_t SPI_CONTROL<mode,sck_ctrl,intr,pin_control,dorder>::SPCR_value = 
                                    bit_mask<intr, 7>::value    |   // Bit 7 – SPIE: SPI Interrupt Enable
                                    bit<6>::value               |   // Bit 6 – SPE: SPI Enable
                                    bit_mask<dorder, 5>::value  |   // Bit 5 – DORD: Data Order
                                    
                                    sck_ctrl::SPCR_mask         |   // Bit 3 – CPOL: Clock Polarity, Bit 2 – CPHA: Clock Phase
                                    
                                    mode::SPCR_mask;

template<class mode,class sck_ctrl,SPI_INTERRUPT intr,class pin_control,SPI_DATA_ORDER dorder>
const uint8_t SPI_CONTROL<mode,sck_ctrl,intr,pin_control,dorder>::SPSR_value = mode::SPSR_mask;


} //ns spi

#endif
