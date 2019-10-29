#include "memory.hpp"
#include <iostream>

int32_t RAM::get_value(){
    return value;
}

void RAM:: set_addr(){
    memory[addr] = value;
}

int32_t RAM::get_addr(){
    return addr;
}

void RAM::set_value(int32_t x){
    value = x;
}
//ADDED BY MARCUS NEO
void RAM::loadtoMemory(u_char load){
    //load into memory, memory pointer ++ 
}
unsigned int RAM::pullfromMemory(u_char address){
    //pull the data from memory
}
//END ADD 