// Tue Oct 20 10:07:59  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//


#ifndef MPL_TRAVERSE_CLASS_HEADER
#define MPL_TRAVERSE_CLASS_HEADER

#include "../func_param_type/func_param_type.hpp"


#ifdef UNITTEST_MODE
namespace tut
{ 
    template<class T> class test_object;
}; 
#endif


namespace mpl
{

struct EMPTY_CONT{};


/**
 * forw and back templates create a code that performs multiple calls of EXECUTOR's EXEC() or EXEC1(param) function
 * with different values of INDEX template parameter.
 * An EXECUTOR template template parameter should be defined as
 * \code
        template
        <
            unsigned INDEX,
            class CONTAINER,
            typename PT
        >
        struct EXECUTOR
        {
            static inline void EXEC1(typename mpl::PARAM<PT>::type)
            {
            }
        }; 
 * \endcode
 *
 * forw template calls EXECUTOR with INDEX values from 0 to INDEX-1, whereas
 * back template calls EXECUTOR with INDEX values in opposite order, from INDEX-1 to 0
 */
 





// Forward traversing
template
<
    template <unsigned,class,typename> class EXECUTOR,
    unsigned INDEX,
    class CONTAINER = EMPTY_CONT,
    typename ParamType = unsigned
>
struct forw
{
    static inline void TRAVERSE()
    {
        forw<EXECUTOR, INDEX-1, CONTAINER,ParamType>::TRAVERSE();
        EXECUTOR<INDEX-1, CONTAINER,ParamType>::EXEC();
    }

    static inline void TRAVERSE1(typename mpl::PARAM<ParamType>::type value)
    {
        forw<EXECUTOR, INDEX-1, CONTAINER,ParamType>::TRAVERSE1(value);
        EXECUTOR<INDEX-1, CONTAINER,ParamType>::EXEC1(value);
    }
    
    static inline void TRAVERSE2(ParamType* value)
    {
        forw<EXECUTOR, INDEX-1, CONTAINER,ParamType>::TRAVERSE2(value);
        EXECUTOR<INDEX-1, CONTAINER,ParamType>::EXEC1(value);
    }

    static inline void TRAVERSE3(ParamType value)
    {
        forw<EXECUTOR, INDEX-1, CONTAINER,ParamType>::TRAVERSE3(value);
        EXECUTOR<INDEX-1, CONTAINER,ParamType>::EXEC1(value);
    }
};
    

template
<
    template <unsigned,class,typename> class EXECUTOR,
    class CONTAINER,
    typename ParamType
>
struct forw<EXECUTOR,0,CONTAINER,ParamType>
{
    static inline void TRAVERSE(){}
    static inline void TRAVERSE1(typename mpl::PARAM<ParamType>::type){}
    static inline void TRAVERSE2(ParamType*){}
    static inline void TRAVERSE3(ParamType){}
};

//==============

// Backward traversing
template
<
    template <unsigned,class,typename> class EXECUTOR,
    unsigned INDEX,
    class CONTAINER = EMPTY_CONT,
    typename ParamType = unsigned
>
struct back
{
    static inline void TRAVERSE()
    {
        EXECUTOR<INDEX-1, CONTAINER,ParamType>::EXEC();
        back<EXECUTOR, INDEX-1, CONTAINER,ParamType>::TRAVERSE();
    }

    static inline void TRAVERSE1(typename mpl::PARAM<ParamType>::type value)
    {
        EXECUTOR<INDEX-1, CONTAINER,ParamType>::EXEC1(value);
        back<EXECUTOR, INDEX-1, CONTAINER,ParamType>::TRAVERSE1(value);
    }
};
    

template
<
    template <unsigned,class,typename> class EXECUTOR,
    class CONTAINER,
    typename ParamType
>
struct back<EXECUTOR,0,CONTAINER,ParamType>
{
    static inline void TRAVERSE(){}
    static inline void TRAVERSE1(typename mpl::PARAM<ParamType>::type){}
};




} // mpl namespace
#endif



