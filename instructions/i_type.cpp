#include "../include/memory.hpp"
#include "../include/Instructions.hpp"
#include "../include/RegisterFile.hpp"
#include "../include/ProgramCounter.hpp"
#include <iostream>
using namespace std;

void beq(unsigned short rs, unsigned short rt, unsigned short imm){
    if(reg.readRegister(rs) == reg.readRegister(rt)){
        int ximm = imm << 2;

        if((ximm & 0x20000) > 0){
            ximm = ximm | 0xFFFC0000;
        }

        delayins();
        PC.ProgCount += (ximm);

    }
}

void bne(unsigned short rs, unsigned short rt, unsigned short imm){
    if(reg.readRegister(rs) != reg.readRegister(rt)){
        int ximm = imm << 2;

        if((ximm & 0x20000) > 0){
            ximm = ximm | 0xFFFC0000;
        }

        delayins();
        PC.ProgCount += (ximm);
    }
}

void blez(unsigned short rs, unsigned short imm){
    if(reg.readRegister(rs) <= 0){
        int ximm = imm << 2;

        if((ximm & 0x20000) > 0){
            ximm = ximm | 0xFFFC0000;
        }

        delayins();
        PC.ProgCount += (ximm);
    }
}

void bgtz(unsigned short rs, unsigned short imm){
    if(reg.readRegister(rs) > 0){
        int ximm = imm << 2;

        if((ximm & 0x20000) > 0){
            ximm = ximm | 0xFFFC0000;
        }

        delayins();
        PC.ProgCount += (ximm);
    }
}

void bltz(unsigned short rs, unsigned short imm){
    if((reg.readRegister(rs) & 0x80000000) > 0){
        int ximm = imm << 2;

        if((ximm & 0x20000) > 0){
            ximm = ximm | 0xFFFC0000;
        }

        delayins();
        PC.ProgCount += (ximm);
    }
}

void bltzal(unsigned short rs, unsigned short imm){
    if(reg.readRegister(rs) < 0){
        int ximm = imm << 2;

        if((ximm & 0x20000) > 0){
            ximm = ximm | 0xFFFC0000;
        }

        delayins();
        reg.writeRegister(31, PC.ProgCount+4);
        PC.ProgCount += (ximm);
    }
}

void bgez(unsigned short rs, unsigned short imm){
    if(reg.readRegister(rs) >= 0){
        int ximm = imm << 2;

        if((ximm & 0x20000) > 0){
            ximm = ximm | 0xFFFC0000;
        }

        delayins();
        PC.ProgCount += (ximm);
    }
}

void bgezal(unsigned short rs, unsigned short imm){
    if(reg.readRegister(rs) >= 0){
        int ximm = imm << 2;

        if((ximm & 0x20000) > 0){
            ximm = ximm | 0xFFFC0000;
        }

        delayins();
        reg.writeRegister(31, PC.ProgCount+4);
        PC.ProgCount += (ximm);
    }
}

void addi(unsigned short rt, unsigned short rs, signed short imm){
    int xs, ximm=imm, sum;

    if((imm & 0x8000) > 0){
        ximm = imm | 0xFFFF0000;
    }

    if(((reg.readRegister(rs) & 0x80000000) > 0) && ((imm & 0x8000) > 0)){
        xs = -reg.readRegister(rs);
        ximm = -ximm;
        sum = xs+ximm;

        if(sum > (unsigned)0x80000000){
            cerr << "Error: Arithmetic overflow occurred!" << endl;
            exit(-10);
        }

        else{
            reg.writeRegister(rt, -sum);
        }
    }

    else{
        sum = reg.readRegister(rs) + imm;

        if(((reg.readRegister(rs) > 0) && (imm > 0) && sum < 0) || ((reg.readRegister(rs) < 0) && (imm < 0) && sum > 0)){
            cerr << "Arithmetic error!" << endl;
            exit(-10);
        }

        reg.writeRegister(rt, sum);
    }
}

void addiu(unsigned short rt, unsigned short rs, unsigned short imm){
    int ximm=imm;

    if((imm & 0x8000) > 0){
        ximm = imm | 0xFFFF0000;
    }

    reg.writeRegister(rt, (unsigned)reg.readRegister(rs) + ximm);
}

void slti(unsigned short rt, unsigned short rs, unsigned short imm){
    int ximm=imm;

    if((imm & 0x8000) > 0){
        ximm = imm | 0xFFFF0000;
    }

    if((signed)reg.readRegister(rs) < (signed)ximm){
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
    int ximm=imm;

    if((imm & 0x8000) > 0){
        ximm = ximm | 0xFFFF0000;
    }

    reg.writeRegister(rt, (ximm << 16));
}

void lb(unsigned short rt, unsigned short rs, unsigned short imm){
    int byte;

    try{
        byte = r.getfromStack(reg.readRegister(rs)+imm, num);

        if((byte & 0xFFFFFF00) > 0){
            throw "Invalid address!";
        }

        else{
            if((byte & 0x80) > 0){
                byte = byte | 0xFFFFFF00;
            }
            reg.writeRegister(rt, byte);
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }
}

void lh(unsigned short rt, unsigned short rs, unsigned short imm){
    int hw;

    try{
        hw = r.getfromStack(reg.readRegister(rs)+imm);

        if((hw & 0xFFFF0000) > 0){
            throw "Invalid instruction! Memory does not contain a byte!";
        }

        else{
            if((hw & 0x8000) > 0){
                hw = hw | 0xFFFF0000;
            }
            reg.writeRegister(rt, hw);
        }
    } catch(const char* msg){
        cerr << msg << endl;
    }
}

void lbu(unsigned short rt, unsigned short rs, unsigned short imm){
    int byte;

    try{
        byte = r.getfromStack(reg.readRegister(rs)+imm);

        if((byte & 0xFFFFFF00) > 0){
            throw "Invalid instruction! Memory does not contain a byte!";
        }

        else{
            reg.writeRegister(rt, byte);
        }
    } catch(const char* msg){
        cerr << msg << endl;
    }
}

void lhu(unsigned short rt, unsigned short rs, unsigned short imm){
    int hw;

    try{
        hw = r.getfromStack(reg.readRegister(rs)+imm);

        if((hw & 0xFFFF0000) > 0){
            throw "Invalid instruction! Memory does not contain a byte!";
        }

        else{
            reg.writeRegister(rt, hw);
        }
    } catch(const char* msg){
        cerr << msg << endl;
    }
}

void sb(unsigned short rt, unsigned short rs, unsigned short imm){
    int byte = reg.readRegister(rt) & 0xFF;
    r.loadtoStack(reg.readRegister(rs)+imm, byte);
}

void sh(unsigned short rt, unsigned short rs, unsigned short imm){
    int hw = reg.readRegister(rt) & 0xFFFF;
    r.loadtoStack(reg.readRegister(rs)+imm, hw);
}

void sw(unsigned short rt, unsigned short rs, unsigned short imm){
    r.loadtoStack(reg.readRegister(rs)+imm, reg.readRegister(rt));
}

void lw(unsigned short rt, unsigned short rs, unsigned short imm){
    reg.writeRegister(rt, r.getfromStack(reg.readRegister(rs)+imm));
}

void lwl(unsigned short rt, unsigned short rs, unsigned short imm){
    unsigned int addr = reg.readRegister(rs) + imm;

    switch(addr%4){
        unsigned int temp;
        case 0: reg.writeRegister(rt, r.getfromStack(reg.readRegister(rs)+imm));
                return;

        case 1: temp = r.getfromStack(reg.readRegister(rs)+imm) << 8;
                temp = temp | (reg.readRegister(rt) & 0xFF);
                reg.writeRegister(rt, temp);
                return;

        case 2: temp = r.getfromStack(reg.readRegister(rs)+imm) << 16;
                temp = temp | (reg.readRegister(rt) & 0xFFFF);
                reg.writeRegister(rt, temp);
                return;

        case 3: temp = r.getfromStack(reg.readRegister(rs)+imm) << 24;
                temp = temp | (reg.readRegister(rt) & 0xFFFFFF);
                reg.writeRegister(rt, temp);
                return;
    }
}

void lwr(unsigned short rt, unsigned short rs, unsigned short imm){
    unsigned int addr = reg.readRegister(rs) + imm;

    switch(addr%4){
        unsigned int temp;
        case 0: temp = r.getfromStack(reg.readRegister(rs)+imm) >> 24;
                temp = temp | (reg.readRegister(rt) & 0xFFFFFF00);
                reg.writeRegister(rt, temp);
                return;

        case 1: temp = r.getfromStack(reg.readRegister(rs)+imm) >> 16;
                temp = temp | (reg.readRegister(rt) & 0xFFFF0000);
                reg.writeRegister(rt, temp);
                return;

        case 2: temp = r.getfromStack(reg.readRegister(rs)+imm) >> 8;
                temp = temp | (reg.readRegister(rt) & 0xFFFFFF00);
                reg.writeRegister(rt, temp);
                return;

        case 3: reg.writeRegister(rt, r.getfromStack(reg.readRegister(rs)+imm));
                return;
    }
}