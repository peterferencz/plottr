#pragma once

#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "Console.hpp"

template<typename T, typename U>
void expect_eq(T v1, U v2){
    if(v1 == v2){ return; }
    Console::destroy();

#ifdef DEBUG    
    std::cerr << "Values didn't match! (" << __FILE__ << " at line " << __LINE__ << ")" << std::endl;
    
    #endif
    
    throw "***";
}
