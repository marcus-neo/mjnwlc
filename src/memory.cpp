#include "include/memory.hpp"
#include <iostream>
#include <vector>

RAM::RAM(){

}

RAM::~RAM(){
    //cerr << "Clearing RAM and stack memory" << endl;
}

void RAM::loadtoMemory(unsigned char binstr){
    unsigned int addr = ADDR_INSTR_OFFSET + offset;

    try{
        if(addr < ADDR_INSTR_OFFSET || addr >= (ADDR_INSTR_OFFSET + ADDR_INSTR_LENGTH)){
            throw "Accessing out of bounds memory!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }

    memory[offset] = binstr;
    offset++;
}

unsigned int RAM::pullfromMemory(unsigned int& ProgCount){
    unsigned int data;

    if((ProgCount-1) == (ADDR_INSTR_OFFSET + offset)){
        ProgCount = 0;
        return 1;
    }

    try{
        if(ProgCount < ADDR_INSTR_OFFSET || ProgCount > (ADDR_INSTR_OFFSET + offset)){
            throw "Accessing out of bounds memory!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }

    unsigned int addr = ProgCount - ADDR_INSTR_OFFSET;

    try{
        if(ProgCount%4 == 0){
            data = (((unsigned int)memory[addr] << 8) + (unsigned int)memory[addr+1]) << 8;
            data = (data + (unsigned int)memory[addr+2]) << 8;
            data = data + (unsigned int)memory[addr+3];
        }

        else{
            throw "Invalid address!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }

    return data;
}

unsigned int RAM::get_addr(){
    return (ADDR_INSTR_OFFSET + offset);
}

void RAM::loadtoStack(unsigned int addr, unsigned int data, int num){
    try{
        if(addr < ADDR_DATA_OFFSET || addr >= (ADDR_DATA_OFFSET + ADDR_DATA_LENGTH)){
            throw "Accessing out of bounds memory!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }

    unsigned int lsb = data << 24 >> 24;
    unsigned int xlsb = data << 16 >> 24;
    unsigned int xmsb = data << 8 >> 24;
    unsigned int msb = data >> 24;

    unsigned int index = addr - ADDR_DATA_OFFSET;

    if(num == 0){
        stack[index] = lsb;
    }

    else if(num == 1){
        try{
            if(addr%2 == 0){
                stack[index] = xlsb;
                stack[index+1] = lsb;
            }

            else{
                throw "Invalid address!";
            }
        } catch(const char* msg){
            cerr << msg << endl;
            exit(-11);
        }
    }

    else if(num == 2){
        try{
            if(addr%4 == 0){
                stack[index] = msb;
                stack[index+1] = xmsb;
                stack[index+2] = xlsb;
                stack[index+3] = lsb;
            }

            else{
                throw "Invalid address!";
            }
        } catch(const char* msg){
            cerr << msg << endl;
            exit(-11);
        }
    }
}

unsigned int RAM::getfromStack(unsigned int addr, int num){
    unsigned int data;

    try{
        if(addr < ADDR_DATA_OFFSET || addr >= (ADDR_DATA_OFFSET + ADDR_DATA_LENGTH)){
            throw "Accessing out of bounds memory!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }

    unsigned int index = addr - ADDR_DATA_OFFSET;

    if(num == 0){
        data = stack[index];
    }

    else if(num == 1){
        try{
            if(addr%2 == 0){
                data = (stack[index] << 8) + stack[index+1];
            }

            else{
                throw "Invalid address!";
            }
        } catch(const char* msg){
            cerr << msg << endl;
            exit(-11);
        }
    }

    else if(num == 2){
        try{
            if(addr%4 == 0){
                data = ((stack[index] << 8) + stack[index+1]) << 8;
                data = (data + stack[index+2]) << 8;
                data = data + stack[index+3];
            }

            else{
                throw "Invalid address!";
            }
        } catch(const char* msg){
            cerr << msg << endl;
            exit(-11);
        }
    }

    return data;
}

/* unsigned int RAM::getchar(){
    unsigned char x = 'a';

    cout << "Enter a character:" << endl;
    cin >> x;

    if(x)

    }
}

void RAM::putchar(){

} */