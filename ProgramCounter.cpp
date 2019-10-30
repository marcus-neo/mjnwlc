#ifndef PROGRAMCOUNTER_HPP
#define PROGRAMCOUNTER_HPP
#include "include/ProgramCounter.hpp"
#endif

void ProgramCounter::jump(unsigned long jump_by){
    PC = PC + jump_by;
}