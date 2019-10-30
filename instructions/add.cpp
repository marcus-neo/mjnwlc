#include <include/Instructions.hpp>
#include <include/RegisterFile.hpp>

void add(unsigned short& rd, unsigned short rs, unsigned short rt){
    reg.writeRegister(rd, reg.readRegister(rs) + reg.readRegister(rt));
}