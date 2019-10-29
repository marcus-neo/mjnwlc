#include <string>
#include <iostream>
#include <fstream>
#include "simulator.hpp"
#include "memory.hpp"
#include "Instructions.hpp"


void simulator::execute(){
    int ProgCount = 124124912094; //PUT THIS TO A GLOBAL VARIABLE IN THE FUTURE
    RAM r;
    instructions ins;
    unsigned char address;
    unsigned long binaryinstruction;
    unsigned short decoded1;
    unsigned short decoded2;
    unsigned long decoded3;
    int instructiontype;
    while(ProgCount != 0){
        binaryinstruction = r.pullfromMemory(int& ProgCount);
        instructiontype = decodeinstruction(binaryinstruction, decoded1, decoded2, decoded3);
        ins.execute(instructiontype, decoded1, decoded2, decoded3);
        
    }

}

int decodeinstruction(unsigned long bin, unsigned short& decoded1, unsigned short& decoded2, unsigned long decoded3){
    unsigned short opcode = bin >> 26;
    
    if(opcode == 0){
        unsigned short function = bin & 0b111111;
        unsigned short rs = (bin << 6) >> 27;
        unsigned short rt = (bin << 6) >> 27;
        unsigned short rd = (bin << 17) >> 27;
        unsigned short shamt = (bin << 22) >> 27;
        
        switch(function){
            case 0:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = shamt;
                return 0;
                break;
            case 2:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = shamt;
                return 1;
                break;
            case 3:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = shamt;
                return 2;
                break;
            case 4:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = rs;
                return 3;
                break;
            case 6:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = rs;
                return 4;
                break;
            case 7:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = rs;
                return 5;
                break;
            case 8:
                decoded1 = rs;
                return 6;
                break;
            case 9:
                decoded1 = rd;
                decoded2 = rs;
                return 7;
                break;
            case 12:
                return 8;
                break;
            case 16:
                decoded1 = rd;
                return 9;
                break;
            case 17:
                decoded1 = rs;
                return 10;
                break;
            case 18:
                decoded1 = rd;
                return 11;
                break;
            case 19:
                decoded1 = rs;
                return 12;
                break;
            case 24:
                decoded1 = rs;
                decoded2 = rt;
                return 13;
                break;
            case 25:
                decoded1 = rs;
                decoded2 = rt;
                return 14;
                break;
            case 26:
                decoded1 = rs;
                decoded2 = rt;
                return 15;
                break;
            case 27:
                decoded1 = rs;
                decoded2 = rt;
                return 16;
                break;
            case 32:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 17;
                break;
            case 33:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 18;
                break;
            case 34:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;  
                return 19;
                break;
            case 35:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 20;
                break;
            case 36:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 21;
                break;
            case 37:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 22;
                break;
            case 38:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 23;
                break;
            case 42:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 24;
                break;
            case 43:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 25;
                break;
        }
    }
    else if (opcode == 2 || opcode == 3){

    }
}

//Implementing Register File


