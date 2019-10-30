#include "memory.hpp"
#include <iostream>
#include <iterator>

//ADDED BY MARCUS NEO
void RAM::loadtoMemory(unsigned char data){
    uint32_t addr = ADDR_INSTR_OFFSET + offset;
    memory[addr] = data;
    offset++;
}

uint32_t RAM::pullfromMemory(int& ProgCount){
    uint32_t data;

    if((ProgCount-1) == (ADDR_INSTR_OFFSET + offset)){
        ProgCount = 0;
        return 1;
    }

    try{
        if(ProgCount%4 == 0){
            data = ((uint32_t)memory[ProgCount] + (uint32_t)memory[ProgCount+1]) << 8;
            data = (data + (uint32_t)memory[ProgCount+2]) << 8;
            data = (data + (uint32_t)memory[ProgCount+3]) << 8;
        }

        else{
            throw "Invalid address!";
        }
    } catch (const char* msg){
        cerr << msg << endl;
        return 1;
    }

    //else throw error: ProgCount is invalid

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

    throw "Data not found!";
}