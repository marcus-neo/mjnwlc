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

RAM::~RAM(){
    cout << "Clearing RAM and stack memory" << endl;
}

void RAM::loadtoMemory(unsigned char binstr){
    unsigned long addr = ADDR_INSTR_OFFSET + offset;
    memory[addr] = binstr;
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

void RAM::loadtoStack(unsigned long data){
    unsigned long lsb = data << 24 >> 24;
    unsigned long xlsb = data << 16 >> 24;
    unsigned long xmsb = data << 8 >> 24;
    unsigned long msb = data >> 24;
    unsigned long addr = ADDR_DATA_OFFSET + sp;

    stack[addr] = msb;
    stack[addr+1] = xmsb;
    stack[addr+2] = xlsb;
    stack[addr+3] = lsb;

    sp+=4;
}

unsigned long RAM::getfromStack(){

}