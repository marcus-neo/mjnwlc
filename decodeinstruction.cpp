#include "include/decodeinstruction.hpp"
#include <iostream>
using namespace std;

int decodeinstruction(unsigned long bin, unsigned short& decoded1, unsigned short& decoded2, unsigned long& decoded3){
    unsigned short opcode = bin >> 26;
    
    if(opcode == 0){
        unsigned short function = bin & 0b111111;
        unsigned short rd = (bin << 6) >> 27;
        rd = rd & 0b11111;
        unsigned short rs = (bin << 11) >> 27;
        rs = rs & 0b11111;
        unsigned long rt = (bin << 16) >> 27;
        rt = rt & 0b11111;
        unsigned long shamt = (bin << 21) >> 27;
        shamt = shamt & 0b11111;
        
        switch(function){
            case 1:
                return 0;
                break;
            case 0:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = shamt;
                return 1;
                break;
            case 2:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = shamt;
                return 2;
                break;
            case 3:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = shamt;
                return 3;
                break;
            case 4:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = rs;
                return 4;
                break;
            case 6:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = rs;
                return 5;
                break;
            case 7:
                decoded1 = rd;
                decoded2 = rt;
                decoded3 = rs;
                return 6;
                break;
            case 8:
                decoded1 = rs;
                return 7;
                break;
            case 9:
                decoded1 = rd;
                decoded2 = rs;
                return 8;
                break;
            case 12:
                return 9;
                break;
            case 16:
                decoded1 = rd;
                return 10;
                break;
            case 17:
                decoded1 = rs;
                return 11;
                break;
            case 18:
                decoded1 = rd;
                return 12;
                break;
            case 19:
                decoded1 = rs;
                return 13;
                break;
            case 24:
                decoded1 = rs;
                decoded2 = rt;
                return 14;
                break;
            case 25:
                decoded1 = rs;
                decoded2 = rt;
                return 15;
                break;
            case 26:
                decoded1 = rs;
                decoded2 = rt;
                return 16;
                break;
            case 27:
                decoded1 = rs;
                decoded2 = rt;
                return 17;
                break;
            case 32:
                decoded1 = rd;
                cout << "decoded1 test here = " << decoded1 << endl << endl;
                decoded2 = rs;
                decoded3 = rt;
                return 18;
                break;
            case 33:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 19;
                break;
            case 34:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;  
                return 20;
                break;
            case 35:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 21;
                break;
            case 36:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 22;
                break;
            case 37:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 23;
                break;
            case 38:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 24;
                break;
            case 42:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 25;
                break;
            case 43:
                decoded1 = rd;
                decoded2 = rs;
                decoded3 = rt;
                return 26;
                break;
        }
    }
    else if (opcode == 2 || opcode == 3){
        unsigned long decoded3 = bin & 0x03ffff;
        switch(opcode){
            case 2:
                return 30;
                break;
            case 3:
                return 31;
                break;
        }
    }
    else{
        unsigned short rs = (bin << 6) >> 27;
        unsigned short rt = (bin << 12) >> 27;
        unsigned long imm = bin & 0xffff;
        
        switch (opcode){
            case 1:
                switch(rt){
                    case 1:
                        decoded1 = rs;
                        decoded3 = imm;
                        return 40;
                        break;
                    case 17:
                        decoded1 = rs;
                        decoded3 = imm;
                        return 41;
                        break;
                    case 0:
                        decoded1 = rs;
                        decoded3 = imm;
                        return 42;
                        break;
                    case 16:
                        decoded1 = rs;
                        decoded3 = imm;
                        return 43;
                        break;
                }
            case 4:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 - imm;
                return 44;
                break;
            case 5:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 45;
                break;
            case 6:
                decoded1 = rs;
                decoded3 = imm;
                return 46;
                break;
            case 7:
                decoded1 = rs;
                decoded3 = imm;
                return 47;
                break;
            case 8:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 48;
                break;
            case 9:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 49;
                break;
            case 10:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 50;
                break;
            case 11:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 51;
                break;
            case 12:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 52;
                break;
            case 13:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 53;
                break;
            case 14:
                decoded1 = rs;
                decoded2 = rt;
                decoded3 = imm;
                return 54;
                break;
            case 15:
                decoded1 = rt;
                decoded3 = imm;
                return 55;
                break;
            case 32:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 56;
                break;
            case 33:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 57;
                break;
            case 34:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 58;
                break;
            case 35:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 59;
                break;
            case 36:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 60;
                break;
            case 37:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 61;
                break;
            case 40:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 62;
                break;
            case 41:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 63;
                break;
            case 42:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 64;
                break;
            case 43:
                decoded1 = rt;
                decoded2 = rs;
                decoded3 = imm;
                return 65;
                break;
        }
    }
}