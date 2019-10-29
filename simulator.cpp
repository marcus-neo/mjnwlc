#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif

#include "simulator.hpp"
#include "memory.hpp"
#include "Instructions.hpp"

int decodeinstruction(unsigned char binaryinstruction, unsigned short& decoded1, unsigned short& decoded2, unsigned long& decoded3){

}

void simulator::execute(){
    int PC = 124124912094; //PUT THIS TO A GLOBAL VARIABLE IN THE FUTURE
    RAM r;
    unsigned char address;
    string binaryinstruction;
    unsigned short decoded1;
    unsigned short decoded2;
    unsigned long decoded3;
    int instructiontype;
    while(PC != 0){
        binaryinstruction = r.pullfromMemory(address);
        instructiontype = decodeinstruction(binaryinstruction, decoded1, decoded2, decoded3);
        
    }

}

//Implementing Register File


