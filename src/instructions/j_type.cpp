#include "../include/Instructions.hpp"
#include "../include/RegisterFile.hpp"
#include "../include/ProgramCounter.hpp"
#include <iostream>
using namespace std;

void j(unsigned int address){
    delayins();
    cout << hex << PC.ProgCount << endl;
    cout << (PC.ProgCount & 0xF0000000) << endl;
    cout << address<< endl;
    PC.ProgCount = ((PC.ProgCount & 0xF0000000) | (address << 2));
    cout << PC.ProgCount << endl;
}

void jal(unsigned int address){
    delayins();
    reg.writeRegister(31, PC.ProgCount+4);
    PC.ProgCount = (PC.ProgCount & 0xF0000000) | (address << 2);
}
