#include <string>
#include <iostream>
#include <fstream>
#include "include/simulator.hpp"
#include "include/memory.hpp"
#include "include/Instructions.hpp"
#include "include/decodeinstruction.hpp"
#include "include/RegisterFile.hpp"
#include "include/ProgramCounter.hpp"
using namespace std;

void simulator::execute(){
     //PUT THIS TO A GLOBAL VARIABLE IN THE FUTURE
    unsigned char address;
    unsigned long binaryinstruction;
    unsigned short decoded1;
    unsigned short decoded2;
    unsigned long decoded3;
    int instructiontype;
    ProgCount = r.ADDR_INSTR_OFFSET;
    int i=0;

    while(ProgCount != 0 && i<3){
        cout << "pulling from memory" << endl;
        binaryinstruction = r.pullfromMemory(ProgCount);
        cout << "binary instruction is " << binaryinstruction << endl << endl;
        cout << "decoding instruction" << endl;
        cout << "initial r1 is " << reg.readRegister(1) << endl;
        cout << "initial r2 is " << reg.readRegister(2) << endl;
        cout << "initial r3 is " << reg.readRegister(3) << endl;

        instructiontype = decodeinstruction(binaryinstruction, decoded1, decoded2, decoded3);
        cout << "instruction number is: " << instructiontype << endl;
        cout << "decoded1 = " << decoded1 << endl;
        cout << "decoded2 = " << decoded2 << endl;
        cout << "decoded3 = " << decoded3 << endl;

        cout << "executing instruction" << endl;
        insexecute(instructiontype, decoded1, decoded2, decoded3);
        cout << "instruction successfully executed" << endl;
        cout << "ProgCount is: " << endl;
        ProgCount+=4;
        i++;
    }
}

//Implementing Register File


