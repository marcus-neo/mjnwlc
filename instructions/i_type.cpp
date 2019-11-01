#include "../include/Instructions.hpp"
#include "../include/RegisterFile.hpp"
#include "../include/ProgramCounter.hpp"
#include <iostream>
using namespace std;

void beq(unsigned short rs, unsigned short rt, unsigned short imm){
    if(reg.readRegister(rs) == reg.readRegister(rt)){
        delayins();
        PC.ProgCount += (imm << 2);
    }
}

void bne(unsigned short rs, unsigned short rt, unsigned short imm){
    if(reg.readRegister(rs) != reg.readRegister(rt)){
        delayins();
        PC.ProgCount += (imm << 2);
    }
}

void blez(unsigned short rs, unsigned short imm){
    if(reg.readRegister(rs) <= 0){
        delayins();
        PC.ProgCount += (imm << 2);
    }
}

void bgtz(unsigned short rs, unsigned short imm){
    if(reg.readRegister(rs) > 0){
        delayins();
        PC.ProgCount += (imm << 2);
    }
}

void bltz(unsigned short rs, unsigned short imm){
    if(reg.readRegister(rs) < 0){
        delayins();
        PC.ProgCount += (imm << 2);
    }
}

void bltzal(unsigned short rs, unsigned short imm){
    if(reg.readRegister(rs) < 0){
        delayins();
        reg.writeRegister(31, PC.ProgCount+4);
        PC.ProgCount += (imm << 2);
    }
}

void bgez(unsigned short rs, unsigned short imm){
    if(reg.readRegister(rs) >= 0){
        delayins();
        PC.ProgCount += (imm << 2);
    }
}

void bgezal(unsigned short rs, unsigned short imm){
    if(reg.readRegister(rs) >= 0){
        delayins();
        reg.writeRegister(31, PC.ProgCount+4);
        PC.ProgCount += (imm << 2);
    }
}

void addi(unsigned short rt, unsigned short rs, unsigned short imm){
    if(((reg.readRegister(rs) & 0x80000000) > 0) && ((imm & 0x80000000) > 0)){
        reg.writeRegister(rt, reg.readRegister(rs) + imm);


        if((reg.readRegister(rt) & 0x80000000) == 0){
            cout << "Error: Arithmetic overflow occurred!" << endl;
            exit(-10);
        }
    }

    else{
        reg.writeRegister(rt, reg.readRegister(rs) + imm);

        if((reg.readRegister(rt) & 0x80000000) > 0){
            cout << "Error: Arithmetic overflow occurred!" << endl;
            exit(-10);
        }
    }
}

void addiu(unsigned short rt, unsigned short rs, unsigned short imm){
    reg.writeRegister(rt, (unsigned)(reg.readRegister(rs) + imm));

    if((reg.readRegister(rs) >= 0 && imm >= 0 && reg.readRegister(rt) < 0) || (reg.readRegister(rs) < 0 && imm < 0 && reg.readRegister(rt) >= 0)){
        cout << "Error: Arithmetic overflow occurred!" << endl;
        exit(-10);
    }
}

void slti(unsigned short rt, unsigned short rs, unsigned short imm){
    if((signed)reg.readRegister(rs) < (signed)imm){
        reg.writeRegister(rt, 1);
    }

    else{
        reg.writeRegister(rt, 0);
    }
}

void sltiu(unsigned short rt, unsigned short rs, unsigned short imm){
    if((unsigned)reg.readRegister(rs) < (unsigned)imm){
        reg.writeRegister(rt, 1);
    }

    else{
        reg.writeRegister(rt, 0);
    }
}

void andi(unsigned short rt, unsigned short rs, unsigned short imm){
    reg.writeRegister(rt, (reg.readRegister(rs) & imm));
}

void ori(unsigned short rt, unsigned short rs, unsigned short imm){
    reg.writeRegister(rt, (reg.readRegister(rs) | imm));
}

void xori(unsigned short rt, unsigned short rs, unsigned short imm){
    reg.writeRegister(rt, (reg.readRegister(rs) ^ imm));
}

void lui(unsigned short rt, unsigned short imm){
    reg.writeRegister(rt, (imm << 16));
}

void lb(unsigned short rt, unsigned short rs, unsigned short imm){

}
void lh(unsigned short rt, unsigned short rs, unsigned short imm){

}
void lbu(unsigned short rt, unsigned short rs, unsigned short imm){

}
void lhu(unsigned short rt, unsigned short rs, unsigned short imm){

}
void sb(unsigned short rt, unsigned short rs, unsigned short imm){

}
void sh(unsigned short rt, unsigned short rs, unsigned short imm){

}
void sw(unsigned short rt, unsigned short rs, unsigned short imm){

}
void lw(unsigned short rt, unsigned short rs, unsigned short imm){

}
void lwl(unsigned short rt, unsigned short rs, unsigned short imm){

}
void lwr(unsigned short rt, unsigned short rs, unsigned short imm){

}