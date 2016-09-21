// Tue Feb 17 02:01:13  2015
//
//          Copyright "Axiom" Ltd 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// smart.axiom24.ru
// smart@axiom24.ru
//

// Created by Class creator script


#include "test_avr_misc.hpp"
#include <tut/tut_reporter.hpp>
#include <iostream>


namespace tut
{ 
    test_runner_singleton runner;
} 

int main()
{ 
    tut::reporter reporter;
    tut::runner.get().set_callback(&reporter);
    
    tut::runner.get().run_tests();
    
    return !reporter.all_ok();
} 
