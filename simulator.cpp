#include <string>
#include <iostream>
#include <fstream>
#include "include/simulator.hpp"
#include "include/memory.hpp"
#include "include/Instructions.hpp"
#include "include/decodeinstruction.hpp"

void simulator::execute(RAM& r){
    int ProgCount = r.ADDR_INSTR_OFFSET; //PUT THIS TO A GLOBAL VARIABLE IN THE FUTURE
    instructions ins;
    unsigned char address;
    unsigned long binaryinstruction;
    unsigned short decoded1;
    unsigned short decoded2;
    unsigned long decoded3;
    int instructiontype;

    while(ProgCount != 0){
        binaryinstruction = r.pullfromMemory(ProgCount);
        instructiontype = decodeinstruction(binaryinstruction, decoded1, decoded2, decoded3);
        ins.execute(instructiontype, decoded1, decoded2, decoded3);

    }

}



//Implementing Register File


