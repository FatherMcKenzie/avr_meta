//Mon Nov  2 23:49:30 MSK 2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef LED_CLASS_HELPER_HEADER
#define LED_CLASS_HELPER_HEADER

namespace led
{

template
<
    unsigned VAL0,
    unsigned VAL1
>
struct MIN
{
    static const unsigned value; 
};
template<unsigned VAL0,unsigned VAL1>
const unsigned MIN<VAL0,VAL1>::value = ((VAL0 < VAL1) ? VAL0 : VAL1);
    
template
<
    uint8_t SIZE_BYTES
>
struct PATTERN_TYPE
{
    typedef bool type;
};

#define DECLARE_PATTERN_TYPE(SIZE,OUTTYPE)  template<> struct PATTERN_TYPE<SIZE>{typedef OUTTYPE type;};
DECLARE_PATTERN_TYPE(1, uint8_t)
DECLARE_PATTERN_TYPE(2, uint16_t)
DECLARE_PATTERN_TYPE(4, uint32_t)
DECLARE_PATTERN_TYPE(8, uint64_t)
    
template
<
    uint8_t TICKS_NUM
>
struct PATTERN_SIZE
{
    static const uint8_t BYTES;
    //static const uint8_t SHIFT;
    static const uint8_t MAXTICK;
};

template<uint8_t TICKS_NUM>
const uint8_t PATTERN_SIZE<TICKS_NUM>::BYTES = ((9 > TICKS_NUM) ? 1 : ((17 > TICKS_NUM) ? 2 : ((33 > TICKS_NUM) ? 4 : 8)));

//template<uint8_t TICKS_NUM>
//const uint8_t PATTERN_SIZE<TICKS_NUM>::SHIFT = (BYTES << 3) - TICKS_NUM;

template<uint8_t TICKS_NUM>
const uint8_t PATTERN_SIZE<TICKS_NUM>::MAXTICK = led::MIN<TICKS_NUM, 64>::value - 1;
//=========================================================

template
<
    uint8_t MAX_VALUE
>
class TICK
{
    uint8_t tick;
    TICK(const TICK&);
    TICK& operator = (const TICK&);
public:
    TICK():tick(0){}
    void inline reset(){tick = 0;}
    void inline advance(){if(MAX_VALUE < ++tick) tick = 0;}
    uint8_t get()const{return tick;}
};

//=========================================================
// Forward traversing
struct EMPTY_CONT{};

template
<
    typename ParmType,
    ParmType ParmVal,
    template <ParmType,unsigned,class,typename> class EXECUTOR,
    unsigned INDEX,
    class CONTAINER = EMPTY_CONT,
    typename ParamType = uint8_t
>
struct traverse
{
    static inline void TRAVERSE(ParamType value)
    {
        traverse<ParmType,ParmVal,EXECUTOR,INDEX-1,CONTAINER,ParamType>::TRAVERSE(value);
        EXECUTOR<ParmVal, INDEX-1, CONTAINER,ParamType>::EXEC(value);
    }
};

template
<
    typename ParmType,
    ParmType ParmVal,
    template <ParmType,unsigned,class,typename> class EXECUTOR,
    class CONTAINER,
    typename ParamType
>
struct traverse<ParmType,ParmVal,EXECUTOR,0,CONTAINER,ParamType>
{
    static inline void TRAVERSE(ParamType){}
};

//=========================================================




}

#endif
