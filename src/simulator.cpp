#include <iostream>
#include "include/simulator.hpp"
#include "include/memory.hpp"
#include "include/Instructions.hpp"
#include "include/decodeinstruction.hpp"
#include "include/RegisterFile.hpp"
#include "include/ProgramCounter.hpp"
using namespace std;

void simulator::execute(){
    //PUT THIS TO A GLOBAL VARIABLE IN THE FUTURE
    unsigned int binaryinstruction;
    unsigned short decoded1;
    unsigned short decoded2;
    unsigned int decoded3;
    int instructiontype;
    PC.ProgCount = r.ADDR_INSTR_OFFSET;

    while(PC.ProgCount != 0){
        // for(it=r.memory.begin(); it!=r.memory.end(); it++){
        //     cout << "[ " << hex << it->first << " " <<  (int)it->second << " ]" << dec << endl;
        // }
        //cout << "pulling from memory" << endl;
        binaryinstruction = r.pullfromMemory(PC.ProgCount);
        //cout << "ProgCount is: " << PC.ProgCount << endl;
        //cout << "binary instruction is " << binaryinstruction << endl << endl;
        //cout << "decoding instruction" << endl;
        // cout << "initial r1 is " << reg.readRegister(1) << endl;
        // cout << "initial r2 is " << reg.readRegister(2) << endl;
        // cout << "initial r3 is " << reg.readRegister(3) << endl;

        instructiontype = decodeinstruction(binaryinstruction, decoded1, decoded2, decoded3);
        //cout << "instruction number is: " << instructiontype << endl;
        //cout << "decoded1 = " << decoded1 << endl;
        //cout << "decoded2 = " << decoded2 << endl;
        //cout << "decoded3 = " << decoded3 << endl;

        //cout << "executing instruction" << endl;
        insexecute(instructiontype, decoded1, decoded2, decoded3);
        //cout << "instruction successfully executed" << endl;
        //cout << "r1 = " << reg.readRegister(1) << endl;
        //cout << "r2 = " << reg.readRegister(2) << endl;
        PC.increment();
    }

    try{
        if(PC.ProgCount != 0){
            throw "Internal error!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-20);
    }
}

//Implementing Register File


