// Wed Feb 18 21:03:52  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef USART_CONTROL_CLASS_HEADER
#define USART_CONTROL_CLASS_HEADER

#include <stdint.h>
#include "../../avr_misc/avr_misc.hpp"

extern "C"
{
#include <stdio.h>
}



#ifndef UNITTEST_MODE
#include <avr/io.h>
#endif

#ifdef UNITTEST_MODE
namespace tut
{
    template<class T> class test_object;
};


#include <stdarg.h>
// #include <iostream>

#define TXB80   0
#define UPE0    2
#define DOR0    3
#define FE0     4
#define UDRIE0  5

#if 0
#define UDR0   0// – USART I/O Data Register n
#define UCSR0A 1// – USART Control and Status Register A
#define UCSR0B 2// – USART Control and Status Register n B
#define UCSR0C 3// – USART Control and Status Register n C
#define UBRR0L 4// – USART Baud Rate Registers
#define UBRR0H 5// – USART Baud Rate Registers
#define UBRR0  4// – USART Baud Rate Registers

#define UDR1   // – USART I/O Data Register n
#define UCSR1A // – USART Control and Status Register A
#define UCSR1B // – USART Control and Status Register n B
#define UCSR1C // – USART Control and Status Register n C
#define UBRR1L // – USART Baud Rate Registers
#define UBRR1H // – USART Baud Rate Registers
#define UBRR1  // – USART Baud Rate Registers

#define UDR2   // – USART I/O Data Register n
#define UCSR2A // – USART Control and Status Register A
#define UCSR2B // – USART Control and Status Register n B
#define UCSR2C // – USART Control and Status Register n C
#define UBRR2L // – USART Baud Rate Registers
#define UBRR2H // – USART Baud Rate Registers
#define UBRR2  // – USART Baud Rate Registers

#define UDR3   // – USART I/O Data Register n
#define UCSR3A // – USART Control and Status Register A
#define UCSR3B // – USART Control and Status Register n B
#define UCSR3C // – USART Control and Status Register n C
#define UBRR3L // – USART Baud Rate Registers
#define UBRR3H // – USART Baud Rate Registers
#define UBRR3  // – USART Baud Rate Registers
#endif
//=======================================================================

#endif

enum DATA_BITS
{
    DATA_BITS_5 = 0,
    DATA_BITS_6 = 1,
    DATA_BITS_7 = 2,
    DATA_BITS_8 = 3,
    DATA_BITS_9 = 7
};

enum STOP_BITS
{
    STOP_1 = 0,
    STOP_2 = 1
};

enum PARITY
{
    NO_PARITY   = 0x00,
    EVEN_PARITY = 0x02,
    ODD_PARITY  = 0x03
};

#ifndef CUSTOM_BAUD_RATE
#define CUSTOM_BAUD_RATE 9600 /**< Different value can be defined somewere above, for example using compiler -D option */
#endif

#ifndef CUSTOM_BAUD_RATE1
#define CUSTOM_BAUD_RATE1 9600 /**< Different value can be defined somewere above, for example using compiler -D option */
#endif

#ifndef CUSTOM_BAUD_RATE2
#define CUSTOM_BAUD_RATE2 9600 /**< Different value can be defined somewere above, for example using compiler -D option */
#endif

#ifndef CUSTOM_BAUD_RATE3
#define CUSTOM_BAUD_RATE3 9600 /**< Different value can be defined somewere above, for example using compiler -D option */
#endif


enum BAUD_RATE
{
    BR_2400 = 2400,
    BR_4800 = 4800,
    BR_9600 = 9600,
    BR_14400 = 14400,
    BR_19200 = 19200,
    BR_28800 = 28800,
    BR_38400 = 38400,
    BR_56000 = 56000,
    BR_57600 = 57600,
    BR_76800 = 76800,
    BR_115200 = 115200,
    BR_128000 = 128000,
    BR_153600 = 153600,
    BR_230400 = 230400,
    BR_256000 = 256000,
    BR_460800 = 460800,
    BR_921600 = 921600,
    BR_CUSTOM = CUSTOM_BAUD_RATE,
    BR_CUSTOM1 = CUSTOM_BAUD_RATE1,
    BR_CUSTOM2 = CUSTOM_BAUD_RATE2,
    BR_CUSTOM3 = CUSTOM_BAUD_RATE3
};

enum USART_MODE
{
    ASYNC_USART = 0,    /**< enum value 1 */
    SYNC_USART  = 1,    /**< enum value 1 */
    MASTER_SPI  = 3     /**< enum value 1 */
};

/**
 * Bit 0 – UCPOLn: Clock Polarity
 * This bit is used for synchronous mode only. Write this bit to zero when asynchronous mode is used.
 */
enum CLOCK_POLARITY
{
    OUT_RISING_IN_FALLING = 0,  /**< enum value 1 */
    OUT_FALLING_IN_RISING = 1   /**< enum value 1 */
};

/**
 * This bit enables the Multi-processor Communication mode. When the MPCMn bit is written to
 * one, all the incoming frames received by the USART Receiver that do not contain address infor-
 * mation will be ignored. The Transmitter is unaffected by the MPCMn setting. For more detailed
 * information see “Multi-processor Communication Mode” on page 221.
 */
enum MPCM // Multi-processor Communication mode // TODO !!!
{
    MPCM_OFF= 0,    /**< enum value 1 */
    MPCM_ON = 1,    /**< enum value 1 */
};

#if 1

#include "usart_baud_rate_register_helper.hpp"

template
<
    BAUD_RATE baud,
    uint64_t osc_freq = F_CPU //16000000L
>
struct UBRR_ASYNC
{
    static const uint16_t value;
    static const uint8_t  double_speed;
};

template<BAUD_RATE baud, uint64_t osc_freq>
const uint16_t UBRR_ASYNC<baud,osc_freq>::value = ubrr::USART_BRR<baud,osc_freq>::value;

template<BAUD_RATE baud,uint64_t osc_freq>
const uint8_t  UBRR_ASYNC<baud,osc_freq>::double_speed = ubrr::USART_BRR<baud,osc_freq>::double_speed;

// TODO :: SYNC MASTER MODE UBRR
//const uint16_t UBRR<baud, osc_freq, SYNC_MASTER>::value = ((((osc_freq / baud) + 1) >> 1) - 1);
//const uint16_t UBRR<baud, osc_freq, SYNC_MASTER>::value = (((osc_freq / baud) >> 1) - 1);

#endif

template
<
    BAUD_RATE baud = BR_9600,
    DATA_BITS data_bits = DATA_BITS_8,
    PARITY parity = NO_PARITY,
    STOP_BITS stop_bits = STOP_1,
    uint64_t osc_freq = F_CPU, // 16000000, // F_CPU should be defined somewhere before (presumably in makefile with -D directive)
    USART_MODE usart_mode = ASYNC_USART,
    CLOCK_POLARITY uspol = OUT_RISING_IN_FALLING // This is used for synchronous mode only (Ignored in async mode).
>
struct FRAME_CONTROL
{
    const static uint8_t UBRRH_value;
    const static uint8_t UBRRL_value;

    // TODO : replace constant values with bits' mnemonics

    static const uint8_t UCSRnA_mask;
    static const uint8_t UCSRnB_mask;
    static const uint8_t UCSRnC_mask;
};

// UBRRH
template<BAUD_RATE baud,DATA_BITS data_bits,PARITY parity,STOP_BITS stop_bits,uint64_t osc_freq,USART_MODE usart_mode,CLOCK_POLARITY uspol>
const uint8_t FRAME_CONTROL<baud,data_bits,parity,stop_bits,osc_freq,usart_mode,uspol>::UBRRH_value = HIGH_BYTE<UBRR_ASYNC<baud, osc_freq>::value>::value;

// UBRRL
template<BAUD_RATE baud,DATA_BITS data_bits,PARITY parity,STOP_BITS stop_bits,uint64_t osc_freq,USART_MODE usart_mode,CLOCK_POLARITY uspol>
const uint8_t FRAME_CONTROL<baud,data_bits,parity,stop_bits,osc_freq,usart_mode,uspol>::UBRRL_value = LOW_BYTE <UBRR_ASYNC<baud, osc_freq>::value>::value;


//  UCSRnA_mask
/**
 * Bit 1 – U2Xn: Double the USART Transmission Speed
 * This bit only has effect for the asynchronous operation. Write this bit to zero when using synchronous operation.
 * 
 * JUST FOR MSPI mode !!! // TODO
 * p.238
 * Bit 4:0 - Reserved Bits in MSPI mode
 * When in MSPI mode, these bits are reserved for future use. 
 * For compatibility with future devices, these bits must be written to zero when UCSRnA is written.
 * 
 */
template<BAUD_RATE baud,DATA_BITS data_bits,PARITY parity,STOP_BITS stop_bits,uint64_t osc_freq,USART_MODE usart_mode,CLOCK_POLARITY uspol>
const uint8_t FRAME_CONTROL<baud,data_bits,parity,stop_bits,osc_freq,usart_mode,uspol>::UCSRnA_mask = 
                //((ASYNC_USART == usart_mode) ? ((0x01 & UBRR_ASYNC<baud, osc_freq>::double_speed) << 1) : 0);
                bit_mask<((ASYNC_USART == usart_mode) && UBRR_ASYNC<baud, osc_freq>::double_speed),1>::value;


//  UCSRnB_mask
/**
 * JUST FOR MSPI mode !!! // TODO
 * Bit 2:0 - Reserved Bits in MSPI mode
 * When in MSPI mode, these bits are reserved for future use. For compatibility with future devices,
 * these bits must be written to zero when UCSRnB is written.
 */
template<BAUD_RATE baud,DATA_BITS data_bits,PARITY parity,STOP_BITS stop_bits,uint64_t osc_freq,USART_MODE usart_mode,CLOCK_POLARITY uspol>
const uint8_t FRAME_CONTROL<baud,data_bits,parity,stop_bits,osc_freq,usart_mode,uspol>::UCSRnB_mask = ((0x04 & data_bits));

//  UCSRnC_mask
/**
 * Bit 0 – UCPOLn: Clock Polarity
 * This bit is used for synchronous mode only. Write this bit to zero when asynchronous mode is used. 
 * The UCPOLn bit sets the relationship between data output change and data input sample, and the synchronous clock (XCKn).
 * 
 * JUST FOR MSPI mode !!! // TODO
 * Bit 5:3 - Reserved Bits in MSPI mode
 * When in MSPI mode, these bits are reserved for future use. For compatibility with future devices,
 * these bits must be written to zero when UCSRnC is written.
 */
template<BAUD_RATE baud,DATA_BITS data_bits,PARITY parity,STOP_BITS stop_bits,uint64_t osc_freq,USART_MODE usart_mode,CLOCK_POLARITY uspol>
const uint8_t FRAME_CONTROL<baud,data_bits,parity,stop_bits,osc_freq,usart_mode,uspol>::UCSRnC_mask =
        compound_masks<
                ((0x03 & usart_mode)    << 6),
                ((0x03 & parity)        << 4),
                ((0x01 & stop_bits)     << 3),
                ((0x03 & data_bits)     << 1),
                (((SYNC_USART == usart_mode) ? 0x01 : 0x00) & uspol) // (0x01 & uspol)  
                >::value;


// TRANSMITTER/ RECEIVER =================================================================================================

// interrupts
/**
 * A USART Receive Complete interrupt will be generated only if the RXCIEn bit is written to one,
 * the Global Interrupt Flag in SREG is written to one and the RXCn bit in UCSRnA is set.
 */
enum RXCIEn
{
    RXCI_DISABLED = 0,  /**< RX Complete Interrupt disabled*/
    RXCI_ENABLED,       /**< RX Complete Interrupt enabled*/
};

/**
 * TXCIEn: TX Complete Interrupt Enable n
 * Controls interrupt on the TXCn Flag. A USART Transmit Complete interrupt
 * will be generated only if the TXCIEn bit is written to one, the Global Interrupt Flag in SREG is
 * written to one and the TXCn bit in UCSRnA is set.
 */
enum TXCIEn
{
    TXCI_DISABLED = 0,  /**< TX Complete Interrupt disabled*/
    TXCI_ENABLED        /**< TX Complete Interrupt enabled*/
};

/**
 * UDRIEn: USART Data Register Empty Interrupt Enable n
 * Controls interrupt on the UDREn Flag. A Data Register Empty interrupt will
 * be generated only if the UDRIEn bit is written to one, the Global Interrupt Flag in SREG is written
 * to one and the UDREn bit in UCSRnA is set.
 */
enum UDRIEn
{
    UDRI_DISABLED = 0,  /**< USART Data Register Empty Interrupt disabled*/
    UDRI_ENABLED        /**< USART Data Register Empty Interrupt enabled*/
};


struct RECEIVER_DISABLED
{
};

struct TRANSMITTER_DISABLED
{
};


enum USART_ID
{
    USART0 = 0,
    USART1,
    USART2,
    USART3,
};

/**
 * USART_RECEIVER
 */
template
<
    uint8_t RX_BUFFER_SIZE = 32,
    RXCIEn rxci_enable = RXCI_ENABLED,  // RX Complete Interrupt
    MPCM mpc_mode = MPCM_OFF            // Multi-processor Communication mode (Receiver only)
>
struct USART_RECEIVER
{
    static const uint8_t BUFFER_SIZE;
    static const uint8_t UCSRnB_mask;   // Receiver Enable | TX Complete Interrupt Enable
    static const uint8_t UCSRnA_mask;   // Multi-processor Communication mode
};

template<uint8_t RX_BUFFER_SIZE, RXCIEn rxci_enable, MPCM mpc_mode>
const uint8_t USART_RECEIVER<RX_BUFFER_SIZE, rxci_enable, mpc_mode>::BUFFER_SIZE = RX_BUFFER_SIZE;

template<uint8_t RX_BUFFER_SIZE, RXCIEn rxci_enable, MPCM mpc_mode>
const uint8_t USART_RECEIVER<RX_BUFFER_SIZE, rxci_enable, mpc_mode>::UCSRnB_mask =
                compound_masks<
                    bit_mask<rxci_enable,7>::value, // Bit 7 – RXCIEn: RX Complete Interrupt Enable n
                    bit<4>::value                   // Bit 4 – RXENn: Receiver Enable n
                >::value;

template<uint8_t RX_BUFFER_SIZE, RXCIEn rxci_enable, MPCM mpc_mode>
const uint8_t USART_RECEIVER<RX_BUFFER_SIZE, rxci_enable, mpc_mode>::UCSRnA_mask = bit_mask<mpc_mode, 0>::value; // MPCMn bit Multi-processor Communication mode


#if 1
template
<
    USART_ID id,
    class RECEIVER_INFO
>
struct USART_RECEIVER_HELPER
{
    static const uint8_t BUFFER_SIZE;
    static const uint8_t UCSRnB_mask;   // Receiver Enable | TX Complete Interrupt Enable
    static const uint8_t UCSRnA_mask;   // Multi-processor Communication mode
    static volatile uint8_t buffer[RECEIVER_INFO::BUFFER_SIZE];
};

template<USART_ID id,class RECEIVER_INFO>
const uint8_t USART_RECEIVER_HELPER<id,RECEIVER_INFO>::BUFFER_SIZE = RECEIVER_INFO::BUFFER_SIZE;
template<USART_ID id,class RECEIVER_INFO>
const uint8_t USART_RECEIVER_HELPER<id,RECEIVER_INFO>::UCSRnB_mask = RECEIVER_INFO::UCSRnB_mask;   // Receiver Enable | TX Complete Interrupt Enable
template<USART_ID id,class RECEIVER_INFO>
const uint8_t USART_RECEIVER_HELPER<id,RECEIVER_INFO>::UCSRnA_mask = RECEIVER_INFO::UCSRnA_mask;   // Multi-processor Communication mode
template<USART_ID id,class RECEIVER_INFO>
volatile uint8_t USART_RECEIVER_HELPER<id,RECEIVER_INFO>::buffer[RECEIVER_INFO::BUFFER_SIZE];

// empty specialization

template<USART_ID id>
struct USART_RECEIVER_HELPER<id,RECEIVER_DISABLED>
{
    static const uint8_t BUFFER_SIZE;
    static const uint8_t UCSRnB_mask;   // Receiver Enable | TX Complete Interrupt Enable
    static const uint8_t UCSRnA_mask;   // Multi-processor Communication mode
};

template<USART_ID id>
const uint8_t USART_RECEIVER_HELPER<id,RECEIVER_DISABLED>::BUFFER_SIZE = 0;
template<USART_ID id>
const uint8_t USART_RECEIVER_HELPER<id,RECEIVER_DISABLED>::UCSRnB_mask = 0;
template<USART_ID id>
const uint8_t USART_RECEIVER_HELPER<id,RECEIVER_DISABLED>::UCSRnA_mask = 0;
#endif



template
<
    unsigned TX_BUFFER_SIZE = 32,
    UDRIEn udri_enable = UDRI_ENABLED,  // USART Data Register Empty Interrupt
    TXCIEn txci_enable = TXCI_DISABLED,  // TX Complete Interrupt
    typename size_type = uint8_t
>
struct USART_TRANSMITTER
{
    typedef size_type SIZE_TYPE;
    static const size_type BUFFER_SIZE;
    static const uint8_t UCSRnB_mask;
};

template<unsigned TX_BUFFER_SIZE,UDRIEn udri_enable,TXCIEn txci_enable,typename size_type>
const uint8_t USART_TRANSMITTER<TX_BUFFER_SIZE,udri_enable,txci_enable,size_type>::UCSRnB_mask =
                compound_masks<
                    bit_mask<txci_enable,6>::value, // Bit 6 – TXCIEn: TX Complete Interrupt Enable n
                    bit_mask<udri_enable,5>::value, // Bit 5 – UDRIEn: USART Data Register Empty Interrupt Enable n
                    bit<3>::value                   // Bit 3 – TXENn:  Transmitter Enable n
                >::value;

template<unsigned TX_BUFFER_SIZE,UDRIEn udri_enable,TXCIEn txci_enable,typename size_type>
const size_type USART_TRANSMITTER<TX_BUFFER_SIZE,udri_enable,txci_enable,size_type>::BUFFER_SIZE = TX_BUFFER_SIZE;



#if 1
template
<
    USART_ID id,
    class TRANSMITTER_INFO
>
struct USART_TRANSMITTER_HELPER
{
    typedef typename TRANSMITTER_INFO::SIZE_TYPE SIZE_TYPE;
    
    static const typename TRANSMITTER_INFO::SIZE_TYPE BUFFER_SIZE;
    static volatile typename TRANSMITTER_INFO::SIZE_TYPE bytes_to_send;
    static volatile typename TRANSMITTER_INFO::SIZE_TYPE bytes_sent;
    static uint8_t buffer[TRANSMITTER_INFO::BUFFER_SIZE];
    static const uint8_t UCSRnB_mask;

    static void flush()
    {
        bytes_to_send = 0;
        bytes_sent = 0;
    }
};

template<USART_ID id,class TRANSMITTER_INFO>
const typename TRANSMITTER_INFO::SIZE_TYPE USART_TRANSMITTER_HELPER<id,TRANSMITTER_INFO>::BUFFER_SIZE = TRANSMITTER_INFO::BUFFER_SIZE;

template<USART_ID id,class TRANSMITTER_INFO>
volatile typename TRANSMITTER_INFO::SIZE_TYPE USART_TRANSMITTER_HELPER<id,TRANSMITTER_INFO>::bytes_to_send = 0;

template<USART_ID id,class TRANSMITTER_INFO>
volatile typename  TRANSMITTER_INFO::SIZE_TYPE USART_TRANSMITTER_HELPER<id,TRANSMITTER_INFO>::bytes_sent = 0;

template<USART_ID id,class TRANSMITTER_INFO>
uint8_t USART_TRANSMITTER_HELPER<id,TRANSMITTER_INFO>::buffer[TRANSMITTER_INFO::BUFFER_SIZE];

template<USART_ID id,class TRANSMITTER_INFO>
const uint8_t USART_TRANSMITTER_HELPER<id,TRANSMITTER_INFO>::UCSRnB_mask = TRANSMITTER_INFO::UCSRnB_mask;

// EMPTY specialization
template<USART_ID id>
struct USART_TRANSMITTER_HELPER<id,TRANSMITTER_DISABLED>
{
    typedef uint8_t SIZE_TYPE;
    
    static const uint8_t BUFFER_SIZE;
    static const uint8_t UCSRnB_mask;

    static void flush(){}
};
template<USART_ID id>
const uint8_t USART_TRANSMITTER_HELPER<id,TRANSMITTER_DISABLED>::BUFFER_SIZE = 0;
template<USART_ID id>
const uint8_t USART_TRANSMITTER_HELPER<id,TRANSMITTER_DISABLED>::UCSRnB_mask = 0;
#endif


#ifndef UNITTEST_MODE

template
<
    USART_ID id
>
struct USART_UNIT
{
    static inline uint8_t  UDR(){return UDR0;}   // – USART I/O Data Register n
    static inline void set_UDR(uint8_t value){UDR0 = value;}

    /**
     * p.217
     * The USART Receiver has three Error Flags: Frame Error (FEn), Data OverRun (DORn) and
     * Parity Error (UPEn). All can be accessed by reading UCSRnA.
     * Another equality for the Error Flags is that they can not be altered by software doing a write to the flag location. 
     * However, all flags must be set to zero when the UCSRnA is written for upward compatibility of future USART implementations.
     * 
     * p.213
     * For compatibility with future devices, always write (Data Register Empty (UDREn) Flag) to zero when writing the UCSRnA Register.
     * 
     * p.217
     * For compatibility with future devices, always set this bit (The Frame Error (FEn) Flag) to zero when writing to UCSRnA.
     * p.223
     * Bit 4 – FEn: Frame Error
     * Always set this bit to zero when writing to UCSRnA.
     * 
     * p.217
     * * For compatibility with future devices, always write this bit (The Data OverRun (DORn) Flag) to zero when writing to UCSRnA.
     * p.214
     * Bit 3 – DORn: Data OverRun
     * Always set this bit to zero when writing to UCSRnA.
     * 
     * p.217
     * If Parity Check is not enabled the UPEn bit will always be read zero.
     * For compatibility with future devices, always set this bit (Parity Error (UPEn) Flag) to zero when writing to UCSRnA. 
     * For more details see “Parity Bit Calculation” on page 210 and “Parity Checker” on page 217.
     * p.224
     * Bit 2 – UPEn: USART Parity Error
     * Always set this bit to zero when writing to UCSRnA.
     * 
     * #define UDRE0   5
     * #define FE0     4
     * #define DOR0    3
     * #define UPE0    2
     * 
     * **************************************************************************** TODO !!!
     * p.224 // TODO
     * Bit 1 – U2Xn: Double the USART Transmission Speed
     * This bit only has effect for the asynchronous operation. Write this bit to zero when using synchronous operation. See FRAME_CONTROL
     * 
     * p.238  When in MSPI mode!!!! // TODO
     * Bit 4:0 - Reserved Bits in MSPI mode
     * When in MSPI mode, these bits are reserved for future use. 
     * For compatibility with future devices, these bits must be written to zero when UCSRnA is written.
     */
    static inline uint8_t  UCSRA(){return UCSR0A;} // – USART Control and Status Register A
    static inline void set_UCSRA(uint8_t value){UCSR0A = nobits<5/*UDREn*/, 4/*FEn*/, 3/*DORn*/, 2/*UPEn*/>::value & value;}

    /**
     * When in MSPI mode!!!! // TODO
     * p.239
     * Bit 2:0 - Reserved Bits in MSPI mode
     * When in MSPI mode, these bits are reserved for future use. For compatibility with future devices,
     * these bits must be written to zero when UCSRnB is written.
     */
    static inline uint8_t  UCSRB(){return UCSR0B;} // – USART Control and Status Register n B
    static inline void set_UCSRB(uint8_t value){UCSR0B = value;}

    /**
     * When in MSPI mode!!!! // TODO
     * p.239
     * Bit 5:3 - Reserved Bits in MSPI mode
     * When in MSPI mode, these bits are reserved for future use. For compatibility with future devices,
     * these bits must be written to zero when UCSRnC is written.
     */
    static inline uint8_t  UCSRC(){return UCSR0C;} // – USART Control and Status Register n C
    static inline void set_UCSRC(uint8_t value){UCSR0C = value;}

    static inline uint8_t  UBRRL(){return UBRR0L;} // – USART Baud Rate Registers
    static inline void set_UBRRL(uint8_t value){UBRR0L = value;}

    /**
     * Bit 15:12 – Reserved Bits
     * These bits are reserved for future use. For compatibility with future devices, these bit must be
     * written to zero when UBRRH is written.
     */
    static inline uint8_t  UBRRH(){return UBRR0H;} // – USART Baud Rate Registers
    static inline void set_UBRRH(uint8_t value){UBRR0H = 0x0F & value;}

    //static uint16_t UBRR(){return UBRR0;}  // – USART Baud Rate Registers
    //static inline void set_UBRR(const uint16_t& value){UBRR0 = value;}
};

#ifdef UDR1
template<>
struct USART_UNIT<USART1>
{
    static inline uint8_t  UDR(){return UDR1;}   // – USART I/O Data Register n
    static inline void set_UDR(uint8_t value){UDR1 = value;}

    /**
     * p.213
     * For compatibility with future devices, always write (Data Register Empty (UDREn) Flag) to zero when writing the UCSRnA Register.
     * 
     * p.217
     * The USART Receiver has three Error Flags: Frame Error (FEn), Data OverRun (DORn) and Parity Error (UPEn). 
     * All can be accessed by reading UCSRnA.
     * Another equality for the Error Flags is that they can not be altered by software doing a write to the flag location. 
     * However, all flags must be set to zero when the UCSRnA is written for upward compatibility of future USART implementations.
     */
    static inline uint8_t  UCSRA(){return UCSR1A;} // – USART Control and Status Register A
    static inline void set_UCSRA(uint8_t value){UCSR1A = nobits<5/*UDREn*/, 4/*FEn*/, 3/*DORn*/, 2/*UPEn*/>::value & value;}

    static inline uint8_t  UCSRB(){return UCSR1B;} // – USART Control and Status Register n B
    static inline void set_UCSRB(uint8_t value){UCSR1B = value;}

    static inline uint8_t  UCSRC(){return UCSR1C;} // – USART Control and Status Register n C
    static inline void set_UCSRC(uint8_t value){UCSR1C = value;}

    static inline uint8_t  UBRRL(){return UBRR1L;} // – USART Baud Rate Registers
    static inline void set_UBRRL(uint8_t value){UBRR1L = value;}

    /**
     * Bit 15:12 – Reserved Bits
     * These bits are reserved for future use. For compatibility with future devices, these bit must be
     * written to zero when UBRRH is written.
     */
    static inline uint8_t  UBRRH(){return UBRR1H;} // – USART Baud Rate Registers
    static inline void set_UBRRH(uint8_t value){UBRR1H = 0x0F & value;}

    //static uint16_t UBRR(){return UBRR1;}  // – USART Baud Rate Registers
    //static inline void set_UBRR(const uint16_t& value){UBRR1 = value;}
};
#endif //UDR1

#ifdef UDR2
template<>
struct USART_UNIT<USART2>
{
    static inline uint8_t  UDR(){return UDR2;}   // – USART I/O Data Register n
    static inline void set_UDR(uint8_t value){UDR2 = value;}

    /**
     * p.213
     * For compatibility with future devices, always write (Data Register Empty (UDREn) Flag) to zero when writing the UCSRnA Register.
     * 
     * p.217
     * The USART Receiver has three Error Flags: Frame Error (FEn), Data OverRun (DORn) and Parity Error (UPEn). 
     * All can be accessed by reading UCSRnA.
     * Another equality for the Error Flags is that they can not be altered by software doing a write to the flag location. 
     * However, all flags must be set to zero when the UCSRnA is written for upward compatibility of future USART implementations.
     */
    static inline uint8_t  UCSRA(){return UCSR2A;} // – USART Control and Status Register A
    static inline void set_UCSRA(uint8_t value){UCSR2A = nobits<5/*UDREn*/, 4/*FEn*/, 3/*DORn*/, 2/*UPEn*/>::value & value;}

    static inline uint8_t  UCSRB(){return UCSR2B;} // – USART Control and Status Register n B
    static inline void set_UCSRB(uint8_t value){UCSR2B = value;}

    static inline uint8_t  UCSRC(){return UCSR2C;} // – USART Control and Status Register n C
    static inline void set_UCSRC(uint8_t value){UCSR2C = value;}

    static inline uint8_t  UBRRL(){return UBRR2L;} // – USART Baud Rate Registers
    static inline void set_UBRRL(uint8_t value){UBRR2L = value;}

    /**
     * Bit 15:12 – Reserved Bits
     * These bits are reserved for future use. For compatibility with future devices, these bit must be
     * written to zero when UBRRH is written.
     */
    static inline uint8_t  UBRRH(){return UBRR2H;} // – USART Baud Rate Registers
    static inline void set_UBRRH(uint8_t value){UBRR2H = 0x0F & value;}

    //static uint16_t UBRR(){return UBRR2;}  // – USART Baud Rate Registers
    //static inline void set_UBRR(const uint16_t& value){UBRR2 = value;}
};
#endif //UDR2

#ifdef UDR3
template<>
struct USART_UNIT<USART3>
{
    static inline uint8_t  UDR(){return UDR3;}   // – USART I/O Data Register n
    static inline void set_UDR(uint8_t value){UDR3 = value;}

    /**
     * p.213
     * For compatibility with future devices, always write (Data Register Empty (UDREn) Flag) to zero when writing the UCSRnA Register.
     * 
     * p.217
     * The USART Receiver has three Error Flags: Frame Error (FEn), Data OverRun (DORn) and Parity Error (UPEn). 
     * All can be accessed by reading UCSRnA.
     * Another equality for the Error Flags is that they can not be altered by software doing a write to the flag location. 
     * However, all flags must be set to zero when the UCSRnA is written for upward compatibility of future USART implementations.
     */
    static inline uint8_t  UCSRA(){return UCSR3A;} // – USART Control and Status Register A
    static inline void set_UCSRA(uint8_t value){UCSR3A = nobits<5/*UDREn*/, 4/*FEn*/, 3/*DORn*/, 2/*UPEn*/>::value & value;}

    static inline uint8_t  UCSRB(){return UCSR3B;} // – USART Control and Status Register n B
    static inline void set_UCSRB(uint8_t value){UCSR3B = value;}

    static inline uint8_t  UCSRC(){return UCSR3C;} // – USART Control and Status Register n C
    static inline void set_UCSRC(uint8_t value){UCSR3C = value;}

    static inline uint8_t  UBRRL(){return UBRR3L;} // – USART Baud Rate Registers
    static inline void set_UBRRL(uint8_t value){UBRR3L = value;}

    /**
     * Bit 15:12 – Reserved Bits
     * These bits are reserved for future use. For compatibility with future devices, these bit must be
     * written to zero when UBRRH is written.
     */
    static inline uint8_t  UBRRH(){return UBRR3H;} // – USART Baud Rate Registers
    static inline void set_UBRRH(uint8_t value){UBRR3H = 0x0F & value;}

    //static uint16_t UBRR(){return UBRR3;}  // – USART Baud Rate Registers
    //static inline void set_UBRR(const uint16_t& value){UBRR3 = value;}
};
#endif //UDR3

#else
// Just for unittests

template
<
    USART_ID id
>
struct USART_UNIT
{
    static inline uint8_t  UDR(){return 0;}   // – USART I/O Data Register n
    static inline void set_UDR(uint8_t){}

    //For compatibility with future devices, always write (Data Register Empty (UDREn) Flag) to zero when writing the UCSRnA Register. // TODO!!!
    static inline uint8_t  UCSRA(){return 0;} // – USART Control and Status Register A
    static inline void set_UCSRA(uint8_t){} // unit.set_UCSRB(bit<UDRIE0>::value | unit.UCSRB());

    static inline uint8_t  UCSRB(){return 0;} // – USART Control and Status Register n B
    static inline void set_UCSRB(uint8_t){}

    static inline uint8_t  UCSRC(){return 0;} // – USART Control and Status Register n C
    static inline void set_UCSRC(uint8_t){}

    static inline uint8_t  UBRRL(){return 0;} // – USART Baud Rate Registers
    static inline void set_UBRRL(uint8_t){}

    static inline uint8_t  UBRRH(){return 0;} // – USART Baud Rate Registers
    static inline void set_UBRRH(uint8_t){}

};

#endif //UNITTEST




template
<
    USART_ID id,
    class usart_ctrl    = FRAME_CONTROL<>,
    class receiver      = USART_RECEIVER<>,
    class transmitter   = USART_TRANSMITTER<>
>
struct USART
{
    typedef typename transmitter::SIZE_TYPE size_type;
    static USART_UNIT<id> unit;
    typedef usart_ctrl  CONTROL;
    
    typedef USART_RECEIVER_HELPER<id, receiver>         RECEIVER;
    typedef USART_TRANSMITTER_HELPER<id,transmitter>    TRANSMITTER;
    

    // methods
    /**
     * doc2549.pdf p.210
     * For interrupt driven USART operation, the Global Interrupt Flag should be cleared 
     * (and interrupts globally disabled) when doing the initialization: cli()
     * 
     * Before doing a re-initialization with changed baud rate or frame format, be sure that there are no
     * ongoing transmissions during the period the registers are changed. The TXCn Flag can be used
     * to check that the Transmitter has completed all transfers, and the RXC Flag can be used to
     * check that there are no unread data in the receive buffer. Note that the TXCn Flag must be
     * cleared before each transmission (before UDRn is written) if it is used for this purpose.
     */
    //static void inline init()
    static void inline init() __attribute__((always_inline))
    {
        unit.set_UBRRL(CONTROL::UBRRL_value);
        unit.set_UBRRH(CONTROL::UBRRH_value);

        /**
         * doc2549.pdf p.213
         * The Data Register Empty (UDREn) Flag indicates whether the transmit buffer is ready to receive
         * new data. This bit is set when the transmit buffer is empty, and cleared when the transmit buffer
         * contains data to be transmitted that has not yet been moved into the Shift Register. For compat-
         * ibility with future devices, always write this bit to zero when writing the UCSRnA Register.
         * 
         * * p.224
         * Bit 1 – U2Xn: Double the USART Transmission Speed ????
         * This bit only has effect for the asynchronous operation. Write this bit to zero when using synchronous operation. ??????
         * 
         * 
         * p.238  When in MSPI mode!!!!
         * Bit 4:0 - Reserved Bits in MSPI mode
         * When in MSPI mode, these bits are reserved for future use. 
         * For compatibility with future devices, these bits must be written to zero when UCSRnA is written.
         */
        unit.set_UCSRA(compound_masks<RECEIVER::UCSRnA_mask, CONTROL::UCSRnA_mask>::value);
        unit.set_UCSRB(compound_masks<RECEIVER::UCSRnB_mask, TRANSMITTER::UCSRnB_mask, CONTROL::UCSRnB_mask>::value);
        unit.set_UCSRC(CONTROL::UCSRnC_mask);
        TRANSMITTER::bytes_to_send = 0;
    }
    
    static void flush()
    {
        uint8_t status = unit.UCSRA();
        if(bit<7 /*RXCn*/>::value & status){uint8_t junk = unit.UDR(); static_cast<void>(junk);}
        if(bit<6 /*TXCn*/>::value & status){unit.set_UCSRA(bit<6 /*TXCn*/>::value);}
        
        //RECEIVER::flush();
        TRANSMITTER::flush();
    }

    static void transmit_byte(uint8_t data)
    {
        /* Wait for empty transmit buffer */
        //while(!(bit<UDRE0>::value & unit.UCSRA())); // just for case if transmitter interrupts disabled
        
        if(bit<6/*RXC*/>::value & unit.UCSRA()) unit.set_UCSRA(bit<6/*RXC*/>::value);

        /* Put data into buffer, sends the data */
        unit.set_UDR(data);
    }

    /**
     * doc2549.pdf p.217
     * When the Receive Complete Interrupt Enable (RXCIEn) in UCSRnB is set, the USART Receive
     * Complete interrupt will be executed as long as the RXCn Flag is set (provided that global inter-
     * rupts are enabled). When interrupt-driven data reception is used, the receive complete routine
     * must read the received data from UDRn in order to clear the RXCn Flag, otherwise a new 
     * interrupt will occur once the interrupt routine terminates.
     */
    static uint8_t  receive_byte()
    {
        /* Wait for data to be received */
        //while(!(bit<RXC0>::value & unit.UCSRA())); // just for case if receiver interrupt disabled
        /* Get and return received data from buffer */
        return unit.UDR();
    }
    
    /**
     * p.217
     * The USART Receiver has three Error Flags: Frame Error (FEn), Data OverRun (DORn) and
     * Parity Error (UPEn). All can be accessed by reading UCSRnA. Common for the Error Flags is
     * that they are located in the receive buffer together with the frame for which they indicate the
     * error status. Due to the buffering of the Error Flags, the UCSRnA must be read before the
     * receive buffer (UDRn), since reading the UDRn I/O location changes the buffer read location.
     * Another equality for the Error Flags is that they can not be altered by software doing a write to
     * the flag location.
     */
    static uint8_t  receive_byte(uint8_t& data_byte)
    {
        uint8_t status = unit.UCSRA(); //UCSRnA;
        data_byte = unit.UDR();
        return bits<4/*FEn: Frame Error*/, 
                    3/*DORn: Data OverRun*/, 
                    2/*UPEn: USART Parity Error*/
                    >::value & status;
    }
    
    static void transmit_9_bit(uint16_t data)
    {
        /* Wait for empty transmit buffer */
        //while(!(bit<UDRE0>::value & unit.UCSRA())); // just fo case if transmitter interrupts is disabled
        /* Copy 9th bit to TXB8 */
        unit.set_UCSRB(nobits<TXB80>::value & unit.UCSRB());
        if(bit<8,uint16_t>::value & data) unit.set_UCSRnB(bit<TXB80>::value | unit.UCSRnB());

        /* Put data into buffer, sends the data */
        unit.set_UDR(data);
    }

    static uint16_t receive_9_bit()
    {
        /* Wait for data to be received */
        //while(!(bit<RXC0>::value & unit.UCSRA())); // just for case if receiver interrupt is disabled

        /* Get status and 9th bit, then data from buffer */
        uint8_t status   = unit.UCSRA();
        uint8_t res_high = unit.UCSRB();
        uint8_t res_low  = unit.UDR();

        /* If error, return -1 */
        if(bits<FE0, DOR0, UPE0>::value & status) return -1;

        /* Filter the 9th bit, then return */
        res_high = bit<0>::value & (res_high >> 1);
        return ((res_high << 8) | res_low);
    }

    // transmit next byte
    /**
     * doc2549.pdf p.214
     * UDREn is cleared by writing UDRn. When interrupt-driven data
     * transmission is used, the Data Register Empty interrupt routine must either write new data to
     * UDRn in order to clear UDREn or disable the Data Register Empty interrupt, otherwise a new
     * interrupt will occur once the interrupt routine terminates.
     */
    static void USART_UDRE_handler()
    {
        if(TRANSMITTER::bytes_sent < TRANSMITTER::bytes_to_send)
        {
            transmit_byte(*(TRANSMITTER::buffer + TRANSMITTER::bytes_sent++));
        }
        
        if(TRANSMITTER::bytes_to_send <= TRANSMITTER::bytes_sent)
        {
            // There no operations on bytes_to_send/bytes_sent need here,
            // these variables are handled in prepare_buffer function
            
            disable_UDR_interrupt();
            //if(syncronous_operation) send_ready_callback();
        }
    }
    
    static inline void disable_UDR_interrupt()
    {
        __asm__ volatile ("" ::: "memory");
        unit.set_UCSRB(inv_bit<5/*UDRIEn*/>::value & unit.UCSRB());
    }
    
    static inline void enable_UDR_interrupt()
    {
        unit.set_UCSRB(bit<5/*UDRIEn*/>::value | unit.UCSRB());
        __asm__ volatile ("" ::: "memory");
    }
#if 0
0000014e <disable_UDR_interrupt>:
 14e:	e1 ec       	ldi	r30, 0xC1	; 193
 150:	f0 e0       	ldi	r31, 0x00	; 0
 152:	80 81       	ld	r24, Z
 154:	8f 7d       	andi	r24, 0xDF	; 223
 156:	80 83       	st	Z, r24
 158:	08 95       	ret


00000142 <enable_UDR_interrupt>:
 142:	e1 ec       	ldi	r30, 0xC1	; 193
 144:	f0 e0       	ldi	r31, 0x00	; 0
 146:	80 81       	ld	r24, Z
 148:	80 62       	ori	r24, 0x20	; 32
 14a:	80 83       	st	Z, r24
 14c:	08 95       	ret
#endif
    
    static inline bool prepare_buffer()
    {
        if(TRANSMITTER::bytes_sent >= TRANSMITTER::bytes_to_send) // Is there remaining bytes in buffer?
        {
            // NOPE!!!
            TRANSMITTER::bytes_to_send = 0;
            TRANSMITTER::bytes_sent = 0;
        }
        else // Yes
        {
            if(TRANSMITTER::bytes_sent) // Is there bytes already sent?
            {
                // move data
                //===================================
                size_type remaining = TRANSMITTER::bytes_to_send - TRANSMITTER::bytes_sent;
                for(TRANSMITTER::bytes_to_send = 0 ; TRANSMITTER::bytes_to_send < remaining; ++TRANSMITTER::bytes_to_send)
                    *(TRANSMITTER::buffer + TRANSMITTER::bytes_to_send) = *(TRANSMITTER::buffer + TRANSMITTER::bytes_to_send + TRANSMITTER::bytes_sent);
                //===================================
                TRANSMITTER::bytes_sent = 0;
            }
        }
        return (TRANSMITTER::bytes_to_send < TRANSMITTER::BUFFER_SIZE);
    }

    /**
     * @brief Copy data into the transmitter buffer
     * Places data into the transmitter buffer.
     * If there is unsent bytes in buffer, moves them to the buffer starting address at first.
     * returns number of bytes placed to the buffer, not necessary all bytes provided.
     * @param[in] data null-terminated array of bytes to send (C style string)
     * @return    number of bytes actually placed into the bufer
     */
    static size_type send(const char* data)
    {
        disable_UDR_interrupt();
        size_type pos = 0;
        if(prepare_buffer())
        {
            for(; *(data + pos) && (TRANSMITTER::bytes_to_send < TRANSMITTER::BUFFER_SIZE); ++TRANSMITTER::bytes_to_send, ++pos)
                *(TRANSMITTER::buffer + TRANSMITTER::bytes_to_send) = *(data + pos);
        }
        enable_UDR_interrupt();
        return pos;
    }
    

    /**
     * @brief Copy data into the transmitter buffer
     * Places data into the transmitter buffer.
     * If there is unsent bytes in buffer, moves them to the buffer starting address at first.
     * Returns number of bytes placed to the buffer, not necessary all bytes provided.
     * @param[in] data array of bytes to send
     * @param[in] size number of bytes to send
     * @return    number of bytes actually placed into the bufer
     */
    static size_type send(const uint8_t* data, size_type data_size)
    {
        disable_UDR_interrupt();
        size_type pos = 0;
        if(prepare_buffer())
        {
            const size_type max_bytes = misc::min(data_size, static_cast<size_type>(TRANSMITTER::BUFFER_SIZE - TRANSMITTER::bytes_to_send));
            
            for(; (pos < max_bytes); ++TRANSMITTER::bytes_to_send, ++pos)
                *(TRANSMITTER::buffer + TRANSMITTER::bytes_to_send) = *(data + pos);
        }
        enable_UDR_interrupt();
        return pos;
    }

    /**
     * Internal function intended for use in variable argument list printf function,
     * it should be called with UDI interrupt disabled.
     */
    static inline size_type _vprintf(const char* fmt, va_list ap)
    {
        size_type result = 0;
        if(prepare_buffer())
        {
            const size_type bytes_remain = (TRANSMITTER::BUFFER_SIZE - TRANSMITTER::bytes_to_send);
            
            // vsnprintf returns the number of characters that would have been written to s if there were enough space.
            result = misc::min<size_type>(bytes_remain, vsnprintf((char*)(TRANSMITTER::buffer + TRANSMITTER::bytes_to_send), bytes_remain, fmt, ap));
            TRANSMITTER::bytes_to_send += result;
        }
        return result;
    }

    static size_type print(const char* fmt, ...)
    {
        disable_UDR_interrupt();
        va_list ap;
        va_start(ap, fmt);
        size_type retval = _vprintf(fmt, ap);
        va_end(ap);
        enable_UDR_interrupt();
        return retval;
    }

#ifndef UNITTEST_MODE
    static size_type print_P(const char* fmt, ...)
    {
        disable_UDR_interrupt();
        size_type result = 0;
        if(prepare_buffer())
        {
            //vsnprintf returns the number of characters that would have been written to buffer if there were enough space.
            const size_type remain = (TRANSMITTER::BUFFER_SIZE - TRANSMITTER::bytes_to_send);
            va_list ap;
            va_start(ap, fmt);
            result = misc::min(remain, vsnprintf_P((char*)(TRANSMITTER::buffer + TRANSMITTER::bytes_to_send), remain, fmt, ap));
            va_end(ap);
            TRANSMITTER::bytes_to_send += result;
        }
        enable_UDR_interrupt();
        return result;
    }
#endif

#if 0
    /**
     * Bit 7 – RXCIEn: RX Complete Interrupt Enable n
     * Writing this bit to one enables interrupt on the RXCn Flag. A USART Receive Complete interrupt
     * will be generated only if the RXCIEn bit is written to one, the Global Interrupt Flag in SREG is
     * written to one and the RXCn bit in UCSRnA is set.
     * 
     * Bit 6 – TXCIEn: TX Complete Interrupt Enable n
     * Writing this bit to one enables interrupt on the TXCn Flag. A USART Transmit Complete interrupt
     * will be generated only if the TXCIEn bit is written to one, the Global Interrupt Flag in SREG is
     * written to one and the TXCn bit in UCSRnA is set.
     * 
     * Bit 5 – UDRIEn: USART Data Register Empty Interrupt Enable n
     * Writing this bit to one enables interrupt on the UDREn Flag. A Data Register Empty interrupt will
     * be generated only if the UDRIEn bit is written to one, the Global Interrupt Flag in SREG is written
     * to one and the UDREn bit in UCSRnA is set.
     * 
     * @brief Set/reset interrupts enable bits
     * Sets ENABLED USART interrupts and resets DISABLED USART interrupts in single operation
     * template parameters:
     * @param udrien - value of UDRIEn enumeration - UDRI_DISABLED or UDRI_ENABLED
     * @param rxien  - value of RXCIEn enumeration - RXCI_DISABLED or RXCI_ENABLED
     * @param txcien - value of TXCIEn enumeration - TXCI_DISABLED or TXCI_ENABLED
     * 
     *    Example usage:
     * 
     * \code
     *      set_interrupt<UDRI_ENABLED, RXCI_ENABLED, TXCI_DISABLED>();
     * \endcode
     *
     * Will disable TX Complete Interrupt and enable RX Complete and USART Data Register Empty Interrupt
     * 
     *  or
     * \code
     *      set_interrupt<UDRI_DISABLED, RXCI_ENABLED, TXCI_DISABLED>();
     * \endcode
     *
     * Will disable TX Complete and USART Data Register Empty Interrupt and enable RX Complete Interrupt
     * 
     */
    template<UDRIEn udrien, RXCIEn rxien, TXCIEn txcien>
    static void set_interrupt()
    {
        unit.set_UCSRB(compound_masks<bit_mask<udrien, 5>::value, bit_mask<rxien, 7>::value, bit_mask<txcien, 6>::value>::value |           // set   ENABLED  bits
                      (inv_compound_masks<bit_mask<!udrien, 5>::value, bit_mask<!rxien, 7>::value, bit_mask<!txcien, 6>::value>::value &    // clear DISABLED bits
                       unit.UCSRB()));
    }
#endif
};



#endif


