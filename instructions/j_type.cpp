#include "../include/Instructions.hpp"
#include "../include/RegisterFile.hpp"
#include "../include/ProgramCounter.hpp"
#include <iostream>
using namespace std;

void j(unsigned int address){
    try{
        if(address%4 == 0 && address >= 0x10000000 && address < 0x11000000){
            delayins();
            PC.ProgCount = (PC.ProgCount & 0xF0000000) | (address << 2);
            PC.interference = 1;
        }

        else{
            throw "Invalid address!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }
}

void jal(unsigned int address){
    try{
        if(address%4 == 0 && address >= 0x10000000 && address < 0x11000000){
            delayins();
            reg.writeRegister(31, PC.ProgCount+4);
            PC.ProgCount = (PC.ProgCount & 0xF0000000) | (address << 2);
            PC.interference = 1;
        }

        else{
            throw "Invalid address!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }
}
