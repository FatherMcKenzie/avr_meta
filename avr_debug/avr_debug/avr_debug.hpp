// Mon Jul 27 22:23:50  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef AVR_DEBUG_CLASS_HEADER
#define AVR_DEBUG_CLASS_HEADER

#include <stdint.h>

#ifndef UNITTEST_MODE

#ifndef PC_TARGET

extern "C"
{
#include <util/delay.h>
#include <stdio.h>
}

#endif
#endif




#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
};

#include <stdarg.h>
#endif

#ifdef PC_TARGET
#include <stdarg.h>
#endif


namespace
{
struct NO_DEBUG
{
    static uint8_t dbg_func(uint8_t value){return value;}
    static uint8_t dbg_func(const char* /*fname*/, uint8_t value){return value;}
    static uint8_t print(const char* , ...){return 0;}
    static uint8_t send(const uint8_t* /*data*/, uint16_t /*data_size*/){return 0;}
};


template
<
    class SENDER
>
struct AVR_DEBUG
{
    static uint8_t dbg_func(uint8_t value)
    {
        SENDER::print("%c\n", ((value) ? '-' : '+'));
        return value;
    }

    static uint8_t dbg_func(const char* fname, uint8_t value)
    {
        SENDER::print("%s %c\n", fname, ((value) ? '-' : '+'));
        return value;
    }
    
    static uint8_t print(const char* fmt, ...)
    {
        SENDER::disable_UDR_interrupt();
        va_list ap;
        va_start(ap, fmt);
        uint8_t retval = SENDER::_vprintf(fmt, ap);
        va_end(ap);
        SENDER::enable_UDR_interrupt();
        return retval;
    }
    static uint8_t send(const uint8_t* data, uint16_t data_size)
    {
        return SENDER::send(data, data_size);
    }
};

}

#endif
