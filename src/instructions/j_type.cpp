#include "../include/Instructions.hpp"
#include "../include/RegisterFile.hpp"
#include "../include/ProgramCounter.hpp"
#include <iostream>
using namespace std;

void j(unsigned int address){
    delayins();
    PC.ProgCount = ((PC.ProgCount & 0xF0000000) | (address << 2));
}

void jal(unsigned int address){
    reg.writeRegister(31, PC.ProgCount+8);
    cout << "Progcount + 8" << PC.ProgCount + 8 << endl;
    delayins();
    PC.ProgCount = (PC.ProgCount & 0xF0000000) | (address << 2);

    cout << "Register 31 " << hex << reg.readRegister(31) << endl;
    cout << "Register 2 " << reg.readRegister(2) << endl;

}
