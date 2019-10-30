#include <string>
#include <iostream>
#include <fstream>
#include "simulator.hpp"
#include "memory.hpp"
#include "Instructions.hpp"
#include "decodeinstruction.hpp"


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
        binaryinstruction = r.pullfromMemory(ProgCount);
        instructiontype = decodeinstruction(binaryinstruction, decoded1, decoded2, decoded3);
        ins.execute(instructiontype, decoded1, decoded2, decoded3);
        
    }

}



//Implementing Register File


