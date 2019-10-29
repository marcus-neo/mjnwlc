#include "memory.hpp"
#include <iostream>
#include <iterator>

//ADDED BY MARCUS NEO
void RAM::loadtoMemory(unsigned char data){
    uint32_t addr = ADDR_INSTR_OFFSET + offset;
    memory[addr] = data;
    offset++;
}

unsigned char RAM::pullfromMemory(uint32_t address){
    unsigned char data;
    if(address%4 == 0){
        data = memory[address]+memory[address+1]+memory[address+2]+memory[address+3];
    }

    offset-=4;

    memory.erase(address+3);
    memory.erase(address+2);
    memory.erase(address+1);
    memory.erase(address);

    //else throw error: address is invalid

    return data;
}
//END ADD

uint32_t RAM::get_addr(uint32_t data){
    unordered_map<int, unsigned char>::iterator it;

    for(it = memory.begin(); it != memory.end(); it++){
        if(it->second == data){
            return it->first;
        }
    }

    return -1;
    //else throw error: data not found
}