// Sun Mar 15 01:57:53  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef TWI_CONTROL_CLASS_HEADER
#define TWI_CONTROL_CLASS_HEADER

#include <stdint.h>
#include "../../avr_misc/avr_misc.hpp"
#include "twi_prescaler_helper.hpp"


#if defined(UNITTEST_MODE) || defined (PC_TARGET)
namespace tut
{ 
    template<class T> class test_object;
};

#include <stdarg.h>
#include <unistd.h>


#else

extern "C" {
#include <avr/io.h>
// #include <avr/interrupt.h> //?
#include <string.h>
#include <util/twi.h>

}
#endif


#if _UTIL_TWI_H_
enum SLA_RW_ENUM            /**< Data direction */
{
    SLA_READ  = TW_READ,    /**< SLA_R operation */
    SLA_WRITE = TW_WRITE    /**< SLA_W operation */
};
#else
enum SLA_RW_ENUM            /**< Data direction */
{
    SLA_READ  = 1,          /**< SLA_R operation */
    SLA_WRITE = 0           /**< SLA_W operation */
};
#endif

/** 
 * Enumeration defines maximum transaction length via TWI interface.
 * Actually data types used for data size and offset depend on
 * maximum allowed size of a single data transmission. 
 */
enum DATA_TRANSFER_SIZE
{
    SMALL_SIZE,     /**< For data transfers up to 255 bytes length. Default value */
    MEDIUM_SIZE,    /**< For data transfers from 256 to 32768 bytes */
    LARGE_SIZE      /**< For transfers greater than 32768 bytes size. It doesn't appear to be a reasonable choice for most cases */
};

#if 1

template<DATA_TRANSFER_SIZE tsize>
struct TRANSFER_SIZE
{
    typedef uint8_t type;
};

template<> struct TRANSFER_SIZE<MEDIUM_SIZE>
{
    typedef uint16_t type;
};

template<> struct TRANSFER_SIZE<LARGE_SIZE>
{
    typedef uint32_t type;
};

#endif



/** 
 * Bit 0 – TWGCE: TWI General Call Recognition Enable Bit
 * If set, this bit enables the recognition of a General Call given over the 2-wire Serial Bus.
 */
enum TWGCRE
{
    TWGC_DISABLED = 0,
    TWGC_ENABLED  = 1
};

/** 
 * Bit 0 – TWIE: TWI Interrupt Enable
 */

enum TW_INTERRUPT
{
    INTERUPT_DISABLED = 0,
    INTERUPT_ENABLED  = 1,
};


typedef void (*CallBackType)(uint8_t);

#include "../../avr_debug/avr_debug/avr_debug.hpp"

template
<
    uint32_t SCL_FREQUENCY = 400000,
    DATA_TRANSFER_SIZE data_size = SMALL_SIZE,
    class DBG = NO_DEBUG,
    TW_INTERRUPT twie = INTERUPT_ENABLED,
    TWGCRE twgcre = TWGC_DISABLED,
    uint8_t  slave_address = 0x00,  /**< the 7-bit Slave address (in the seven most significant bits of TWAR) 
                                      * to which the TWI will respond when programmed as a Slave Transmitter or Receiver,
                                      * and not needed in the Master modes. In multimaster systems, TWAR must be set in masters
                                      * which can be addressed as Slaves by other Masters.
                                      */
                                      
    uint32_t osc_freq = F_CPU       /**< F_CPU value should be defined somewere above, presumably using -D compiler option */
>
struct TWI
{ 
#ifdef UNITTEST_MODE
    template<class T> friend class tut::test_object;
#endif

    typedef twi_control::TWI_CLOCK<SCL_FREQUENCY, osc_freq> clock_control;
    typedef typename TRANSFER_SIZE<data_size>::type size_type;
    
    

#if defined(UNITTEST_MODE) || defined(PC_TARGET)
    static volatile uint8_t TWBR;
    static volatile uint8_t TWSR;
    static volatile uint8_t TWAR;
    static volatile uint8_t TWCR;
    static volatile uint8_t TWDR;
    static const uint8_t TWGCE = 0;
    static const uint8_t TWINT = 7;
    static const uint8_t TWSTA = 5;
    static const uint8_t TWEN  = 2;
    static const uint8_t TWIE  = 0;
    static const uint8_t TWSTO = 4;
    static const uint8_t TWEA  = 6;
    
    #define TW_STATUS_MASK 0xF8
#endif

    static void init()
    {
        TWBR = clock_control::TWBR_value;
        TWSR = (0x03 & clock_control::TWPS_value);        
        //TWAR = (((0x7F & slave_address) << 1) | bit_mask<twgcre,TWGCE>::value); //not needed in Master modes
        TWCR = (bits<TWEA, TWEN>::value | bit_mask<twie,TWIE>::value);
        state = RS_IDLE;
    }
    
    static uint8_t tw_status()
    {
        return (0xF8 & TWSR);
    }
    
    static uint8_t data()
    {
        return TWDR;
    }
    
    /** 
     * Send START condition
     */
    static void send_start()
    {
        TWCR = (bits<TWINT, TWSTA, TWEN>::value | bit_mask<twie,TWIE>::value);
    }
    
    /** 
     * Transmit STOP condition
     */
#if 1
    static void send_stop()
    {
        // Note that TWINT is NOT set after a STOP condition has been sent.
        TWCR = (bits<TWINT, TWSTO, TWEN>::value | bit_mask<twie,TWIE>::value);
    }
#endif
#if 0
    enum CONTROL_ITERRUPT_AFTER_STOP
    {
        DISABLE_INTR = 0,
        ENABLE_INTR  = 1
    };
    template
    <
        CONTROL_ITERRUPT_AFTER_STOP enable_interrupt
    >
    static void send_stop<>()
    {
        // Note that TWINT is NOT set after a STOP condition has been sent.
        TWCR = (bits<TWINT, TWSTO, TWEN>::value | bit_mask<((enable_interrupt)&&(twie)),TWIE>::value);
    }
#endif
    
    /**
     * Call this function using "template" construction as follows:
     *          TW<>::template sla<ADDRESS, SLA_WRITE>(); or
     *          TW<>::template sla<ADDRESS, SLA_READ>();
     */

    /**
     * Call this function using "template" construction as follows:
     *          TW<>::template sla<SLA_WRITE>(SLAVE_ADDRESS); or
     *          TW<>::template sla<SLA_READ>(SLAVE_ADDRESS);
     */
    template
    <
        SLA_RW_ENUM direction
    >
    static void sla(uint8_t slave_addr)
    {
        TWDR = ((slave_addr << 1) | bit_mask<direction,0>::value);
        //asm("nop");
        //asm("nop");
        TWCR = (bits<TWINT, TWEN>::value | bit_mask<twie,TWIE>::value);
    }
    
    /**
     * Load data into TWDR Register.
     * Clear TWINT bit in TWCR to start transmission of data
     */
    static void load_data(uint8_t data)
    {
        TWDR = data;
        //asm("nop");
        //asm("nop");
        TWCR = (bits<TWINT, TWEN>::value | bit_mask<twie,TWIE>::value);
    }
    /**
     * Sends reply on received data byte, 
     * whether ACK or NACK transmitted depending on ack value
     */
    static void reply(uint8_t ack = 1)
    {
        TWCR = (bits<TWINT, TWEN>::value | bit_mask<twie,TWIE>::value) | ((ack) ? bit<TWEA>::value : 0);
    }
    

    /**
     * Check value of TWI Status Register. Mask prescaler bits.
     * Compares TWI Status Register value against specified state value,
     * returns TRUE if equal
     */
    static bool is_state(uint8_t expected_state)
    {
        return ((0xF8 & TWSR) == expected_state);
    }
    
    static bool is_not_state(uint8_t expected_state)
    {
        return ((0xF8 & TWSR) != expected_state);
    }
    
    /**
     * Wait for TWINT Flag set.
     */
    static void wait_twint_flag()
    {
        while(!(bit<TWINT>::value & TWCR));
    }
    
#if 1
    /**
     * Transfer states
     */
    enum TWI_STATES
    {
        RS_IDLE = 0,
        RS_G_START,     //1
        RS_G_SLA_W,     //2
        RS_G_WORD_ADDR, //3
        RS_G_RSTART,    //4
        RS_G_SLA_R,     //5
        RS_G_DATA,      //6
        
        
        RS_S_START,     //7
        RS_S_SLA_W,     //8
        RS_S_WORD_ADDR, //9
        RS_S_DATA,      //A
    };
    
    static uint8_t* buffer;
    static CallBackType call_back;
    static size_type data_offset;
    static size_type length;
    
    static uint8_t SLAVE_ADDRESS;
    volatile static uint8_t state; // bit field ???
    static uint8_t BASE_ADDRESS;
    
    //volatile static uint8_t completed;  /**< Flag indicating function call completion */
    //volatile static uint8_t result;     /**< Function retval */

    volatile static uint8_t status;  /**< Flag indicating function call completion  and return value*/

    
    static uint8_t counter;
    static uint8_t initial_state;
    


#if defined(UNITTEST_MODE) || defined(PC_TARGET)

#define TW_START                    0x08
#define TW_REP_START                0x10
#define TW_MT_SLA_ACK               0x18
#define TW_MT_SLA_NACK              0x20
#define TW_MT_DATA_ACK              0x28
#define TW_MT_DATA_NACK             0x30
#define TW_MT_ARB_LOST              0x38
#define TW_MR_ARB_LOST              0x38
#define TW_MR_SLA_ACK               0x40
#define TW_MR_SLA_NACK              0x48
#define TW_MR_DATA_ACK              0x50
#define TW_MR_DATA_NACK             0x58
#define TW_ST_SLA_ACK               0xA8
#define TW_ST_ARB_LOST_SLA_ACK      0xB0
#define TW_ST_DATA_ACK              0xB8
#define TW_ST_DATA_NACK             0xC0
#define TW_ST_LAST_DATA             0xC8
#define TW_SR_SLA_ACK               0x60
#define TW_SR_ARB_LOST_SLA_ACK      0x68
#define TW_SR_GCALL_ACK             0x70
#define TW_SR_ARB_LOST_GCALL_ACK    0x78
#define TW_SR_DATA_ACK              0x80
#define TW_SR_DATA_NACK             0x88
#define TW_SR_GCALL_DATA_ACK        0x90
#define TW_SR_GCALL_DATA_NACK       0x98
#define TW_SR_STOP                  0xA0
#define TW_NO_INFO                  0xF8
#define TW_BUS_ERROR                0x00
 
#endif

// Code for debugging purposes only
#if 0
    
    static uint8_t repr_state(uint8_t astate, char* data, uint8_t size)
    {
        switch(astate)
        {
        case RS_IDLE:
            return snprintf(data, size, "IDLE");
            break;
        case RS_G_START:
            return snprintf(data, size, "G_START");
            break;
        case RS_G_SLA_W:
            return snprintf(data, size, "G_SLAW");
            break;
        case RS_G_WORD_ADDR:
            return snprintf(data, size, "G_W_ADDR");
            break;
        case RS_G_RSTART:
            return snprintf(data, size, "G_RSTART");
            break;
        case RS_G_SLA_R:
            return snprintf(data, size, "G_SLAR");
            break;
        case RS_G_DATA:
            return snprintf(data, size, "G_DATA");
            break;
        //case RS_G_STOP:
        //    return snprintf(data, size, "xxxx");
        //    break;
        case RS_S_START:
            return snprintf(data, size, "S_START");
            break;
        case RS_S_SLA_W:
            return snprintf(data, size, "S_SLAW");
            break;
        case RS_S_WORD_ADDR:
            return snprintf(data, size, "S_W_ADDR");
            break;
        case RS_S_DATA:
            return snprintf(data, size, "S_DATA");
            break;
        default:
            ;
        }
        return snprintf(data, size, "UNKNO");
    }
    
    
    static uint8_t repr_twi(uint8_t twi_state, char* data, uint8_t size)
    {
        switch(twi_state)
        {
        case TW_START:                    //0x08 start condition transmitted
            return snprintf(data, size, "START");
            break;
        case TW_REP_START:                //0x10 repeated start condition transmitted
            return snprintf(data, size, "R_START");
            break;
        case TW_MT_SLA_ACK:               //0x18 SLA+W transmitted, ACK received
            return snprintf(data, size, "MT_SLA_A");
            break;
        case TW_MT_SLA_NACK:              //0x20 SLA+W transmitted, NACK received 
            return snprintf(data, size, "MT_SLA_N");
            break;
        case TW_MT_DATA_ACK:              //0x28 data transmitted, ACK received 
            return snprintf(data, size, "MT_DT_A");
            break;
        case TW_MT_DATA_NACK:             //0x30 data transmitted, NACK received 
            return snprintf(data, size, "MT_DT_N");
            break;
        case TW_MT_ARB_LOST:              //0x38 arbitration lost in SLA+W or data
            return snprintf(data, size, "Mx_ARB");
            break;
        //case TW_MR_ARB_LOST:              //0x38 arbitration lost in SLA+R or NACK
        //    return snprintf(data, size, "xxxx");
        //    break;
        case TW_MR_SLA_ACK:               //0x40 SLA+R transmitted, ACK received 
            return snprintf(data, size, "MR_SLA_A");
            break;
        case TW_MR_SLA_NACK:              //0x48 SLA+R transmitted, NACK received 
            return snprintf(data, size, "MR_SLA_N");
            break;
        case TW_MR_DATA_ACK:              //0x50 data received, ACK returned 
            return snprintf(data, size, "MR_DT_A");
            break;
        case TW_MR_DATA_NACK:             //0x58 data received, NACK returned
            return snprintf(data, size, "MR_DT_N");
            break;
        // slave
        case TW_ST_SLA_ACK:               //0xA8 SLA+R received, ACK returned 
            return snprintf(data, size, "ST_SLA_A");
            break;
        case TW_ST_ARB_LOST_SLA_ACK:      //0xB0 arbitration lost in SLA+RW, SLA+R received, ACK returned 
            return snprintf(data, size, "ST_ARB_SLA_A");
            break;
        case TW_ST_DATA_ACK:              //0xB8 data transmitted, ACK received 
            return snprintf(data, size, "ST_DT_A");
            break;
        case TW_ST_DATA_NACK:             //0xC0 data transmitted, NACK received 
            return snprintf(data, size, "ST_DT_N");
            break;
        case TW_ST_LAST_DATA:             //0xC8 last data byte transmitted, ACK received 
            return snprintf(data, size, "ST_LST_DT");
            break;
        case TW_SR_SLA_ACK:               //0x60 SLA+W received, ACK returned 
            return snprintf(data, size, "SR_SLA_A");
            break;
        case TW_SR_ARB_LOST_SLA_ACK:      //0x68 arbitration lost in SLA+RW, SLA+W received, ACK returned 
            return snprintf(data, size, "SR_ARB_SLA_A");
            break;
        case TW_SR_GCALL_ACK:             //0x70 general call received, ACK returned
            return snprintf(data, size, "SR_GEN");
            break;
        case TW_SR_ARB_LOST_GCALL_ACK:    //0x78 arbitration lost in SLA+RW, general call received, ACK returned 
            return snprintf(data, size, "SR_ARB_GEN");
            break;
        case TW_SR_DATA_ACK:              //0x80 data received, ACK returned 
            return snprintf(data, size, "SR_DT_A");
            break;
        case TW_SR_DATA_NACK:             //0x88 data received, NACK returned 
            return snprintf(data, size, "SR_DT_N");
            break;
        case TW_SR_GCALL_DATA_ACK:        //0x90 general call data received, ACK returned 
            return snprintf(data, size, "SR_GEN_DT_A");
            break;
        case TW_SR_GCALL_DATA_NACK:       //0x98 general call data received, NACK returned 
            return snprintf(data, size, "SR_GEN_DT_N");
            break;
        case TW_SR_STOP:                  //0xA0 stop or repeated start condition received while selected
            return snprintf(data, size, "SR_STOP");
            break;
        case TW_NO_INFO:                  //0xF8 no state information available 
            return snprintf(data, size, "NO_INFO");
            break;
        case TW_BUS_ERROR:                //0x00 illegal start or stop condition
            return snprintf(data, size, "BUS_ERR");
            break;
        default:
            ;
        }
        return snprintf(data, size, "TW_UN");
    }
    
    static void debug_print(uint8_t astate, uint8_t twi_state)
    {
        enum{STATE_BUFFER_SIZE = 14, TWSTATE_BUFFER_SIZE = 25,};
        char state_buff[STATE_BUFFER_SIZE];
        char twstate_buff[TWSTATE_BUFFER_SIZE];
        
        repr_state(astate, state_buff, STATE_BUFFER_SIZE);
        repr_twi(twi_state, twstate_buff, TWSTATE_BUFFER_SIZE);
        
        DBG::print("%s:%s\n", state_buff, twstate_buff);
    }
#endif

    //static const uint8_t MAX_ITER = 200; // SHOULD BE CALCULATED somehow ... based on F_CPU and length???
    
    enum  REQUIRED_ACTION_ENUM
    {
        NO_ACTION, // == in progress
        ACT_QUIT,
        ACT_RESTART,
        ACT_BEGIN,
        ACT_ERROR,
        ACT_ERROR_NO_STOP,
    };
    
    static void interrupt_handler()
    {
        uint8_t twi_status = tw_status();
        //debug_print(state, twi_status);
        switch(process_state(twi_status))
        {
        case NO_ACTION: // IN PROGRESS
            break;
        case ACT_QUIT:
            state = RS_IDLE;
            //completed = 1;
            //result = ((length == data_offset) ? 0 : -1);
            
            status = ((length == data_offset) ? 0x80 : 0xFF);
            
            send_stop();
            if(call_back) (*call_back)(0x7F & status);
            break;
        case ACT_RESTART:
            if(MAX_ITER < ++counter)
            {
                state = RS_IDLE;
                //completed   =  1;
                //result      = -1;
                status = 0xFF;
                if(call_back) (*call_back)(0x7F);
                // no stop ???
                
                send_stop();
                //if(bit<TWINT>::value & TWCR) TWCR = (bits<TWINT, TWEN>::value | bit_mask<twie,TWIE>::value);
                
                break;
            }
            /* FALLTHROUGH */
        case ACT_BEGIN:
            state = initial_state;
            //completed   =  0;
            //result = -1;
            
            status = 0x7F;
            
            send_start();
            break;
        case ACT_ERROR:
            send_stop();
            /* FALLTHROUGH */
        case ACT_ERROR_NO_STOP:
        default:
            state = RS_IDLE;
            //completed   =  1;
            //result      = -1;
            status = 0xFF;
            if(call_back) (*call_back)(0x7F);
            if(bit<TWINT>::value & TWCR) TWCR = (bits<TWINT, TWEN>::value | bit_mask<twie,TWIE>::value);
            break;
        }
    }

    static uint8_t process_state(uint8_t twi_status)
    {
        switch(state)
        {
        // MASTER RECEIVER MODE
        case RS_G_START:
            switch(twi_status)
            {
            case TW_START:
            case TW_REP_START:
                sla<SLA_WRITE>(SLAVE_ADDRESS);
                state  = RS_G_SLA_W;
                break;
            case TW_MT_ARB_LOST:
                return ACT_BEGIN;
            default:
                return ACT_ERROR_NO_STOP; /* error: not in start condition */ /* NB: do /not/ send stop condition */
            }
            break;
        case RS_G_SLA_W:
            switch(twi_status)
            {
            case TW_MT_SLA_ACK:
                state = RS_G_WORD_ADDR;
                load_data(BASE_ADDRESS);
                break;
            case TW_MT_SLA_NACK:  /* nack during select: device busy writing */ /* Note [11] */
                return ACT_RESTART;
            case TW_MT_ARB_LOST:  /* re-arbitrate */
                return ACT_BEGIN;
            default:
                return ACT_ERROR; /* must send stop condition */
            }
            break;
        case RS_G_WORD_ADDR:
            switch(twi_status)
            {
            case TW_MT_DATA_ACK:
                state = RS_G_RSTART;
                send_start();
                break;
            case TW_MT_DATA_NACK:
                return ACT_QUIT;
            case TW_MT_ARB_LOST:
                return ACT_BEGIN;
            default:
                return ACT_ERROR; /* must send stop condition */
            }
            break;
        case RS_G_RSTART:
            switch(twi_status)
            {
            case TW_START:
            case TW_REP_START:
                state = RS_G_SLA_R;
                sla<SLA_READ>(SLAVE_ADDRESS);
                break;
            case TW_MT_ARB_LOST:
                return ACT_BEGIN;
            default:
                return ACT_ERROR;
            }
            break;
        case RS_G_SLA_R:
            switch(twi_status)
            {
            case TW_MR_SLA_ACK:
                state = RS_G_DATA;
                data_offset = 0;
                reply(1 < length);
                break;
            case TW_MR_SLA_NACK:
                return ACT_QUIT;
            case TW_MR_ARB_LOST:
                return ACT_BEGIN;
            default:
                return ACT_ERROR;
            }
            break;
        case RS_G_DATA: // TODO
            switch(twi_status)
            {
            case TW_MR_DATA_ACK:
                *(buffer + data_offset++) = data(); // get next data byte
                reply(1 < (length - data_offset));  // MORE THAN ONE BYTE REMAINS TO READ
                break;
            case TW_MR_DATA_NACK:
                *(buffer + data_offset++) = data();
                return ACT_QUIT;
            default:
                return ACT_ERROR;
            }
            break;
            
        // MASTER TRANSMITTER MODE
        case RS_S_START:
            switch(twi_status)
            {
            case TW_START:
            case TW_REP_START:
                state = RS_S_SLA_W;
                sla<SLA_WRITE>(SLAVE_ADDRESS);
                break;
            case TW_MT_ARB_LOST:
                return ACT_BEGIN;
            default:
                return ACT_ERROR_NO_STOP; /* error: not in start condition */ /* NB: do /not/ send stop condition */
            }
            break;
        case RS_S_SLA_W:
            switch(twi_status)
            {
            case TW_MT_SLA_ACK:
                state = RS_S_WORD_ADDR;
                data_offset = 0;
                load_data(BASE_ADDRESS);
                break;
            case TW_MT_SLA_NACK:
                return ACT_RESTART;
            case TW_MT_ARB_LOST:
                return ACT_BEGIN;
            default:
                return ACT_ERROR; /* must send stop condition */
            }
            break;
        case RS_S_WORD_ADDR:
            switch(twi_status)
            {
            case TW_MT_DATA_ACK:
                state = RS_S_DATA; 
                load_data(*(buffer + data_offset++)); // sending first data byte
                break;
            case TW_MT_DATA_NACK:
                return ACT_QUIT;
            case TW_MT_ARB_LOST:
                return ACT_BEGIN;
            default:
                return ACT_ERROR; /* must send stop condition */
            }
            break;
        case RS_S_DATA:// send remaining data bytes
            switch(twi_status)
            {
            case TW_MT_DATA_ACK:
                if(data_offset < length)
                {
                    load_data(*(buffer + data_offset++));
                    break;
                }
                else
                    return ACT_QUIT;
            case TW_MT_DATA_NACK: /* device write protected -- Note [16] */
            default:
                return ACT_ERROR;
            }
            break;
        case RS_IDLE:
        default:
            if(bit<TWINT>::value & TWCR) TWCR = (bits<TWINT, TWEN>::value | bit_mask<twie,TWIE>::value);
        }
        return NO_ACTION;
    }
    

//==================================== Public interface ===============================================

    enum
    {
        MAX_ITER = 200 // SHOULD BE CALCULATED somehow ... based on F_CPU and length???
    };

    /* 
     * Function write_to
     * Desc     attempts to become twi bus master and write a
     *          series of bytes to a device on the bus
     * Input    base_addr: 7bit i2c device address
     *          data_src: pointer to byte array
     *          block_size: number of bytes in array
     *          send_stop: boolean indicating whether or not to send a stop at the end
     * Output   0 .. success
     *          1 .. length to long for buffer
     *          2 .. address send, NACK received
     *          3 .. data send, NACK received
     *          4 .. other twi error (lost bus arbitration, bus error, ..)
     */
    static uint8_t write_to(uint8_t base_addr, const uint8_t* data_src, size_type block_size, uint8_t slave_addr, CallBackType callbackfunc = 0)
    {
        if(RS_IDLE != state) return 1;
        TWCR = bits<TWINT, TWEN>::value;
        
        BASE_ADDRESS = base_addr;
        SLAVE_ADDRESS = slave_addr;
        length = block_size;
        buffer = const_cast<uint8_t*>(data_src);
        call_back = callbackfunc;
        
        counter = 0;
        state = RS_S_START;
        initial_state = state;
        
        //completed   =  0;
        //result = -1;
        status = 0x7F;
        
        send_start();
        
        return 0;
    }
    
    /* 
     * Function read_from
     * Desc     attempts to become twi bus master and read a
     *          series of bytes from a device on the bus
     * Input    base_addr: 7bit i2c device address
     *          data_dest: pointer to byte array
     *          block_size: number of bytes to read into array
     *          send_stop: Boolean indicating whether to send a stop at the end
     * Output   number of bytes read
     */
    
    static uint8_t read_from(uint8_t base_addr, uint8_t* data_dest, size_type block_size, uint8_t slave_addr, CallBackType callbackfunc = 0)
    {
        if(RS_IDLE != state) return 1;
        TWCR = bits<TWINT, TWEN>::value;
        
        BASE_ADDRESS = base_addr;
        SLAVE_ADDRESS = slave_addr;
        length = block_size;
        buffer = data_dest;
        call_back = callbackfunc;
        
        counter = 0;
        state = RS_G_START;
        initial_state = state;
        
        //completed   =  0;
        //result = -1;
        status = 0x7F;
        
        send_start();
        
        return 0;
    }
    
   
    static void call_back_fn(uint8_t retval)
    {
        //completed = 0xFF;
        //result = retval;
        status = 0x80 | (0x7F & retval);
    }
    
    
    static uint8_t write_to_sync(uint8_t slave_addr, uint8_t base_addr, size_type block_size, const uint8_t* data)
    {
        uint8_t tries = 4;
        while(tries--)
        {
            if(write_to(base_addr, data, block_size, slave_addr, 0))
            {
                // seems like we nww some delay here
                asm("nop");
                asm("nop");
                continue;
            }
            
            while(!(0x80 & status)) asm("nop"); // ?????????? limit now loops number ?
            if(!(0x7F & status)) return 0;
        }
        return -1;
    }

    static uint8_t read_from_sync(uint8_t slave_addr, uint8_t base_addr, size_type block_size, uint8_t* data)
    {
        uint8_t tries = 4;
        while(tries--)
        {
            if(read_from(base_addr, data, block_size, slave_addr, 0))
            {
                // delay 
                asm("nop");
                asm("nop");
                continue;
            }
            
            while(!(0x80 & status)) asm("nop"); // ?????????? limit now loops number ?
            if(!(0x7F & status)) return 0;
        }
        return -1;
    }
    

#endif

}; 
#if 1
//template<uint32_t SCL_FREQUENCY, DATA_TRANSFER_SIZE data_size, class DBG, TW_INTERRUPT twie, TWGCRE twgcre, uint8_t  slave_address, uint32_t osc_freq>
//volatile uint8_t TWI<SCL_FREQUENCY, data_size, DBG, twie, twgcre, slave_address, osc_freq>::completed = 0;

//template<uint32_t SCL_FREQUENCY, DATA_TRANSFER_SIZE data_size, class DBG, TW_INTERRUPT twie, TWGCRE twgcre, uint8_t  slave_address, uint32_t osc_freq>
//volatile uint8_t TWI<SCL_FREQUENCY, data_size, DBG, twie, twgcre, slave_address, osc_freq>::result = 0;


template<uint32_t SCL_FREQUENCY, DATA_TRANSFER_SIZE data_size, class DBG, TW_INTERRUPT twie, TWGCRE twgcre, uint8_t  slave_address, uint32_t osc_freq>
volatile uint8_t TWI<SCL_FREQUENCY, data_size, DBG, twie, twgcre, slave_address, osc_freq>::status = 0x7F;

//=========================================

template<uint32_t SCL_FREQUENCY, DATA_TRANSFER_SIZE data_size, class DBG, TW_INTERRUPT twie, TWGCRE twgcre, uint8_t  slave_address, uint32_t osc_freq>
uint8_t TWI<SCL_FREQUENCY, data_size, DBG, twie, twgcre, slave_address, osc_freq>::SLAVE_ADDRESS = 0;

template<uint32_t SCL_FREQUENCY, DATA_TRANSFER_SIZE data_size, class DBG, TW_INTERRUPT twie, TWGCRE twgcre, uint8_t  slave_address, uint32_t osc_freq>
volatile uint8_t TWI<SCL_FREQUENCY, data_size, DBG, twie, twgcre, slave_address, osc_freq>::state = RS_IDLE;

//template<uint32_t SCL_FREQUENCY, DATA_TRANSFER_SIZE data_size, class DBG, TW_INTERRUPT twie, TWGCRE twgcre, uint8_t  slave_address, uint32_t osc_freq>
//volatile uint8_t TWI<SCL_FREQUENCY, data_size, DBG, twie, twgcre, slave_address, osc_freq>::stop_after_transaction = 0;


template<uint32_t SCL_FREQUENCY, DATA_TRANSFER_SIZE data_size, class DBG, TW_INTERRUPT twie, TWGCRE twgcre, uint8_t  slave_address, uint32_t osc_freq>
uint8_t TWI<SCL_FREQUENCY, data_size, DBG, twie, twgcre, slave_address, osc_freq>::BASE_ADDRESS = 0;

template<uint32_t SCL_FREQUENCY, DATA_TRANSFER_SIZE data_size, class DBG, TW_INTERRUPT twie, TWGCRE twgcre, uint8_t  slave_address, uint32_t osc_freq>
typename TRANSFER_SIZE<data_size>::type TWI<SCL_FREQUENCY, data_size, DBG, twie, twgcre, slave_address, osc_freq>::length = 0;

template<uint32_t SCL_FREQUENCY, DATA_TRANSFER_SIZE data_size, class DBG, TW_INTERRUPT twie, TWGCRE twgcre, uint8_t  slave_address, uint32_t osc_freq>
uint8_t* TWI<SCL_FREQUENCY, data_size, DBG, twie, twgcre, slave_address, osc_freq>::buffer = 0;

template<uint32_t SCL_FREQUENCY, DATA_TRANSFER_SIZE data_size, class DBG, TW_INTERRUPT twie, TWGCRE twgcre, uint8_t  slave_address, uint32_t osc_freq>
CallBackType TWI<SCL_FREQUENCY, data_size, DBG, twie, twgcre, slave_address, osc_freq>::call_back = 0;

template<uint32_t SCL_FREQUENCY, DATA_TRANSFER_SIZE data_size, class DBG, TW_INTERRUPT twie, TWGCRE twgcre, uint8_t  slave_address, uint32_t osc_freq>
typename TRANSFER_SIZE<data_size>::type TWI<SCL_FREQUENCY, data_size, DBG, twie, twgcre, slave_address, osc_freq>::data_offset = 0;

template<uint32_t SCL_FREQUENCY, DATA_TRANSFER_SIZE data_size, class DBG, TW_INTERRUPT twie, TWGCRE twgcre, uint8_t  slave_address, uint32_t osc_freq>
uint8_t TWI<SCL_FREQUENCY, data_size, DBG, twie, twgcre, slave_address, osc_freq>::counter = 0;

template<uint32_t SCL_FREQUENCY, DATA_TRANSFER_SIZE data_size, class DBG, TW_INTERRUPT twie, TWGCRE twgcre, uint8_t  slave_address, uint32_t osc_freq>
uint8_t TWI<SCL_FREQUENCY, data_size, DBG, twie, twgcre, slave_address, osc_freq>::initial_state = RS_IDLE;

#endif


#if 0
ISR(TWI_vect)
{
    interrupt_handler();
}
#endif

#endif



