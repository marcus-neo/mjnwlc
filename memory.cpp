#include "include/memory.hpp"
#include <iostream>
#include <iterator>

RAM::RAM(){
    for(int i=ADDR_INSTR_OFFSET; i<(ADDR_INSTR_OFFSET+0x1000000); i+=4){
        memory[i] = '\0';
    }

    for(int i=ADDR_DATA_OFFSET; i<(ADDR_DATA_OFFSET+0x4000000); i+=4){
        stack[i] = 0;
    }
}

void RAM::loadtoMemory(unsigned char data){
    unsigned long addr = ADDR_INSTR_OFFSET + offset;
    memory[addr] = data;
    offset++;
}

unsigned long RAM::pullfromMemory(int& ProgCount){
    unsigned long data;

    if((ProgCount-1) == (ADDR_INSTR_OFFSET + offset)){
        ProgCount = 0;
        return 1;
    }

    try{
        if(ProgCount%4 == 0){
            data = ((unsigned long)memory[ProgCount] + (unsigned long)memory[ProgCount+1]) << 8;
            data = (data + (unsigned long)memory[ProgCount+2]) << 8;
            data = (data + (unsigned long)memory[ProgCount+3]) << 8;
        }

        else{
            throw "Invalid address!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        return 1;
    }

    return data;
}

unsigned long RAM::get_addr(unsigned long data){
    unordered_map<int, unsigned char>::iterator it;

    for(it = memory.begin(); it != memory.end(); it++){
        if(it->second == data){
            return it->first;
        }
    }
    try{
        throw "Data not found!";
    } catch(const char* msg){
        cerr << msg << endl;
        return 1;
    }
}

void RAM::jump(int& ProgCount, unsigned long addr){
    try{
        if(addr%4 == 0){
            ProgCount = addr;
        }

        else{
            throw "Invalid address!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        return;
    }
}