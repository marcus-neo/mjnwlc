#include "../include/Instructions.hpp"
#include "../include/RegisterFile.hpp"
#include <iostream>

using namespace std;

void add(unsigned short& rd, unsigned short rs, unsigned short rt){
    reg.writeRegister(rd, reg.readRegister(rs) + reg.readRegister(rt));
    cout << endl;
    cout << "rs = " << reg.readRegister(rs) << endl;
    cout << "rt = " << reg.readRegister(rt) << endl;

    cout << "rd = " << reg.readRegister(rd) << endl;
    cout << endl;

}