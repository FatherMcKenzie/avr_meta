// Wed Nov  4 23:31:35 MSK 2015
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
#include "../../avr_misc/avr_misc.hpp"

#ifndef LED_PATTERN_HELPER_HEADER
#define LED_PATTERN_HELPER_HEADER

namespace led
{
namespace
{
template
<
    bool bit0 = 0,
    bool bit1 = 0,
    bool bit2 = 0,
    bool bit3 = 0,
    bool bit4 = 0,
    bool bit5 = 0,
    bool bit6 = 0,
    bool bit7 = 0
>
struct byte_val
{
    static const uint8_t value;
};

template<bool bit0,bool bit1,bool bit2,bool bit3,bool bit4,bool bit5,bool bit6,bool bit7>
const uint8_t byte_val<bit0,bit1,bit2,bit3,bit4,bit5,bit6,bit7>::value =    bit_mask<bit0,0>::value |
                                                                            bit_mask<bit1,1>::value |
                                                                            bit_mask<bit2,2>::value |
                                                                            bit_mask<bit3,3>::value |
                                                                            bit_mask<bit4,4>::value |
                                                                            bit_mask<bit5,5>::value |
                                                                            bit_mask<bit6,6>::value |
                                                                            bit_mask<bit7,7>::value;

template<>
struct byte_val<0,0,0,0,0,0,0,0>{static const uint8_t value;};
const uint8_t byte_val<0,0,0,0,0,0,0,0>::value = 0;

} // namespace

template
<
    bool bit00 = 0,bool bit01 = 0,bool bit02 = 0,bool bit03 = 0,bool bit04 = 0,bool bit05 = 0,bool bit06 = 0,bool bit07 = 0,
    bool bit08 = 0,bool bit09 = 0,bool bit10 = 0,bool bit11 = 0,bool bit12 = 0,bool bit13 = 0,bool bit14 = 0,bool bit15 = 0,
    bool bit16 = 0,bool bit17 = 0,bool bit18 = 0,bool bit19 = 0,bool bit20 = 0,bool bit21 = 0,bool bit22 = 0,bool bit23 = 0,
    bool bit24 = 0,bool bit25 = 0,bool bit26 = 0,bool bit27 = 0,bool bit28 = 0,bool bit29 = 0,bool bit30 = 0,bool bit31 = 0,
    bool bit32 = 0,bool bit33 = 0,bool bit34 = 0,bool bit35 = 0,bool bit36 = 0,bool bit37 = 0,bool bit38 = 0,bool bit39 = 0,
    bool bit40 = 0,bool bit41 = 0,bool bit42 = 0,bool bit43 = 0,bool bit44 = 0,bool bit45 = 0,bool bit46 = 0,bool bit47 = 0,
    bool bit48 = 0,bool bit49 = 0,bool bit50 = 0,bool bit51 = 0,bool bit52 = 0,bool bit53 = 0,bool bit54 = 0,bool bit55 = 0,
    bool bit56 = 0,bool bit57 = 0,bool bit58 = 0,bool bit59 = 0,bool bit60 = 0,bool bit61 = 0,bool bit62 = 0,bool bit63 = 0
>
struct binary
{
    typedef byte_val<bit00,bit01,bit02,bit03,bit04,bit05,bit06,bit07> BYTE0;
    typedef byte_val<bit08,bit09,bit10,bit11,bit12,bit13,bit14,bit15> BYTE1;
    typedef byte_val<bit16,bit17,bit18,bit19,bit20,bit21,bit22,bit23> BYTE2;
    typedef byte_val<bit24,bit25,bit26,bit27,bit28,bit29,bit30,bit31> BYTE3;
    typedef byte_val<bit32,bit33,bit34,bit35,bit36,bit37,bit38,bit39> BYTE4;
    typedef byte_val<bit40,bit41,bit42,bit43,bit44,bit45,bit46,bit47> BYTE5;
    typedef byte_val<bit48,bit49,bit50,bit51,bit52,bit53,bit54,bit55> BYTE6;
    typedef byte_val<bit56,bit57,bit58,bit59,bit60,bit61,bit62,bit63> BYTE7;

    static const uint64_t value;
};
template<   bool bit00,bool bit01,bool bit02,bool bit03,bool bit04,bool bit05,bool bit06,bool bit07,
            bool bit08,bool bit09,bool bit10,bool bit11,bool bit12,bool bit13,bool bit14,bool bit15,
            bool bit16,bool bit17,bool bit18,bool bit19,bool bit20,bool bit21,bool bit22,bool bit23,
            bool bit24,bool bit25,bool bit26,bool bit27,bool bit28,bool bit29,bool bit30,bool bit31,
            bool bit32,bool bit33,bool bit34,bool bit35,bool bit36,bool bit37,bool bit38,bool bit39,
            bool bit40,bool bit41,bool bit42,bool bit43,bool bit44,bool bit45,bool bit46,bool bit47,
            bool bit48,bool bit49,bool bit50,bool bit51,bool bit52,bool bit53,bool bit54,bool bit55,
            bool bit56,bool bit57,bool bit58,bool bit59,bool bit60,bool bit61,bool bit62,bool bit63>

const uint64_t  binary<bit00,bit01,bit02,bit03,bit04,bit05,bit06,bit07,
                bit08,bit09,bit10,bit11,bit12,bit13,bit14,bit15,
                bit16,bit17,bit18,bit19,bit20,bit21,bit22,bit23,
                bit24,bit25,bit26,bit27,bit28,bit29,bit30,bit31,
                bit32,bit33,bit34,bit35,bit36,bit37,bit38,bit39,
                bit40,bit41,bit42,bit43,bit44,bit45,bit46,bit47,
                bit48,bit49,bit50,bit51,bit52,bit53,bit54,bit55,
                bit56,bit57,bit58,bit59,bit60,bit61,bit62,bit63>::value = BYTE0::value |
                                                                         (BYTE1::value <<  8) |
                                                                         (BYTE2::value << 16) |
                                                                         (BYTE3::value << 24) |
                                                                         (BYTE4::value << 32) |
                                                                         (BYTE5::value << 40) |
                                                                         (BYTE6::value << 48) |
                                                                         (BYTE7::value << 56);
struct always_ON
{
    static const uint64_t value = uint64_t(~0);//-1;
};

struct always_OFF
{
    static const uint64_t value = 0;
};

}

#endif
