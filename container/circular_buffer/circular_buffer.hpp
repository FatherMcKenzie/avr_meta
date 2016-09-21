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


#ifndef CB_CIRCULAR_BUFFER_CLASS_HEADER
#define CB_CIRCULAR_BUFFER_CLASS_HEADER



#ifdef UNITTEST_MODE

#define START_CRITICAL_SECTION //

#define END_CRITICAL_SECTION   //
    
#else

#ifndef START_CRITICAL_SECTION

#include <util/atomic.h>

#define START_CRITICAL_SECTION ATOMIC_BLOCK(ATOMIC_RESTORESTATE){

#define END_CRITICAL_SECTION }

#endif
    
#endif




#include <stdint.h>
#include "circular_buffer_helper.hpp"
#include "../bit_field/bit_field.hpp"
#include "../../meta/type_selector/type_selector.hpp"


#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
};

#include <cstdio>

#define DEBUG_PRINT


#endif

namespace cb
{

template
<
    unsigned SIZE_ORDER,
    typename StorValueType = uint8_t
>
class buff_state
{
    enum STATE_FIELDS
    {
        INDEX,
        SIZE
    };
    
    //static const StorValueType FIELD_SIZE = cb::SIZE_HELPER<SIZE_ORDER>::SIZE;
    
    volatile BF::bit_field<
            STATE_FIELDS
            ,BF::FIELDS<
                BF::FIELD<INDEX,  SIZE_ORDER, 0>,
                BF::FIELD<SIZE,  (SIZE_ORDER + 1), 4> //SIZE_ORDER>
                >
            ,StorValueType> data;
    
public:

    static const uint8_t BUFFER_SIZE = cb::SIZE_HELPER<SIZE_ORDER>::SIZE;

    buff_state():data(0){}
    
    uint8_t inline index()const volatile
    {
        return data.template get<INDEX>();
    }

    uint8_t inline size()const volatile
    {
        return data.template get<SIZE>();
    }
    
    uint8_t inline end()const volatile
    {
        return cb::SIZE_HELPER<SIZE_ORDER>::MASK & (data.template get<SIZE>() + data.template get<INDEX>());
    }

    void advance_size()volatile
    {
        data.template set<SIZE>(1 + data.template get<SIZE>());
    }

    void advance_index()volatile
    {
        //data.template set<INDEX>(cb::SIZE_HELPER<SIZE_ORDER>::MASK & (1 + data.template get<INDEX>()));
        data.template set<INDEX>(1 + data.template get<INDEX>()); // Mask is applied inside the bitfield.
        data.template set<SIZE>(data.template get<SIZE>() - 1);
    }
};

//===========================================================

template<unsigned SIZE_ORDER>
class buffer_state
{
    volatile uint8_t _index;
    volatile uint8_t _size;
public:

    static const uint8_t BUFFER_SIZE = cb::SIZE_HELPER<SIZE_ORDER,7>::SIZE;
    
    buffer_state()
    :_index(0)
    ,_size(0){}
    
    uint8_t inline index()const
    {
        return _index;
    }
    
    uint8_t inline size()const
    {
        return _size;
    }
    
    uint8_t inline end()const
    {
        return cb::SIZE_HELPER<SIZE_ORDER,7>::MASK & (_size + _index);
    }

    void advance_size()
    {
        ++_size;
    }

    void advance_index()
    {
        _index = (SIZE_HELPER<SIZE_ORDER,7>::MASK & ++_index);
        --_size;
    }
};


template
<
    typename ValueType,
    unsigned SIZE_ORDER,
    class STATE = typename mpl::type_selector<bool(4 > SIZE_ORDER), buff_state<SIZE_ORDER>, buffer_state<SIZE_ORDER> >
>
class circular_buffer
{ 
#ifdef UNITTEST_MODE
    template<class T> friend class tut::test_object;
#endif
    
    ValueType buffer[STATE::type::BUFFER_SIZE];

    typename STATE::type buf_state;
    
    
    circular_buffer(const circular_buffer& other);
    circular_buffer& operator = (const circular_buffer &other);
    
    inline uint8_t adjust_index(uint8_t idx)const
    {
        return (SIZE_HELPER<SIZE_ORDER,7>::MASK & idx);
    }
    
    inline bool is_full()const
    {
        //return (SIZE_HELPER<SIZE_ORDER,7>::SIZE <= buf_state.size());
        //return (SIZE_HELPER<SIZE_ORDER,7>::MAX_VALUE < buf_state.size());
        
        return (~SIZE_HELPER<SIZE_ORDER,7>::MAX_VALUE & buf_state.size());
        
    }
    
    uint8_t inline start()const
    {
        return buf_state.index();
    }
    
    uint8_t inline end()const
    {
        //return adjust_index(buf_state.end()); // Should be done in buffer state class
        return buf_state.end();
    }
public:
    
    /**
     * \brief Brief description which ends at this dot.
     * 
     * Details follow here.
     */
    
    /**
     * default constructor
     */
    circular_buffer():buf_state(){}
    
    uint8_t inline size()const
    {
#if 1 //warning: control reaches end of non-void function [-Wreturn-type]
        uint8_t result;
        START_CRITICAL_SECTION
        result = buf_state.size();
        END_CRITICAL_SECTION
        return result;
#else
        START_CRITICAL_SECTION
        return buf_state.size();
        END_CRITICAL_SECTION
#endif
    }
    
    bool inline empty()const
    {
#if 1 //warning: control reaches end of non-void function [-Wreturn-type]
        bool result;
        START_CRITICAL_SECTION
        result = !buf_state.size();
        END_CRITICAL_SECTION
        return result;
#else
        START_CRITICAL_SECTION
        return !buf_state.size();
        END_CRITICAL_SECTION
#endif
    }
    
    inline bool full()const
    {
#if 1 //warning: control reaches end of non-void function [-Wreturn-type]
        bool result;
        START_CRITICAL_SECTION
        result = is_full();
        END_CRITICAL_SECTION
        return result;
#else
        START_CRITICAL_SECTION
        return is_full();
        END_CRITICAL_SECTION
#endif
    }
    
    bool append(const ValueType& value)
    {
        if(is_full())
        {
#ifdef DEBUG_PRINT
            printf("\n>%s(%d) FAIL\n", __FUNCTION__, int(value));
#endif
            return false;
        }

#ifdef DEBUG_PRINT
        printf("\n>%s(%d)\n", __FUNCTION__, int(value));
#endif
        
        START_CRITICAL_SECTION
        
        //buffer[adjust_index(buf_state.end())] = value;
        buffer[buf_state.end()] = value;
        
        buf_state.advance_size();
        END_CRITICAL_SECTION
        return true;
    }
    
    ValueType pop()
    {
        ValueType result;
        START_CRITICAL_SECTION
        
        //if(empty()) return ValueType();
        if(!buf_state.size())
        {
#ifdef DEBUG_PRINT
            printf("\n>%s() FAIL\n", __FUNCTION__);
#endif
            return ValueType();
        }

#ifdef DEBUG_PRINT
        printf("\n>%s()\n", __FUNCTION__);
#endif
        
        result = buffer[start()];
        buf_state.advance_index();
        END_CRITICAL_SECTION
        return result;
    }

    bool pop(ValueType& value)
    {
        START_CRITICAL_SECTION
        
        //if(empty()) return false;
        if(!buf_state.size())
        {
#ifdef DEBUG_PRINT
        printf("\n>%s() FAIL\n", __FUNCTION__);
#endif
            return false;
        }
        
#ifdef DEBUG_PRINT
        printf("\n>%s()\n", __FUNCTION__);
#endif

        value = buffer[start()];
        buf_state.advance_index();
        END_CRITICAL_SECTION
        return true;
    }
    
#ifdef UNITTEST_MODE
    void debug()const
    {
        /*
        printf("circular_buffer data\n");
        printf("max     size = %d\n", SIZE_HELPER<SIZE_ORDER>::SIZE);
        printf("current size = %d\n", size());
        printf("start index  = %d\n", start());
        printf("end   index  = %d\n", end());
        */
        
        printf("DEBUG: SIZE:%2d  START:%2d   LEN:%2d   END:%2d\n", STATE::type::BUFFER_SIZE, start(), buf_state.size(), end());
        for(uint8_t i = 0; i < size(); ++i)
        {
            uint8_t index  = adjust_index(start() + i);
            printf("    buf[%d] = %2d\n", index, buffer[index]);
        }
        
    }
#endif
}; 



} // cb namespace
#endif

