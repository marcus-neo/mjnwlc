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
    int ximm=imm;

    if((imm & 0x8000) > 0){
        ximm = imm | 0xFFFF0000;
    }

    if((unsigned)reg.readRegister(rs) < (unsigned)ximm){
        reg.writeRegister(rt, 1);
    }

    else{
        reg.writeRegister(rt, 0);
    }
}

void andi(unsigned short rt, unsigned short rs, unsigned short imm){
    int ximm = imm & 0xFFFF;
    reg.writeRegister(rt, (reg.readRegister(rs) & ximm));
}

void ori(unsigned short rt, unsigned short rs, unsigned short imm){
    int ximm = imm & 0xFFFF;
    reg.writeRegister(rt, (reg.readRegister(rs) | ximm));
}

void xori(unsigned short rt, unsigned short rs, unsigned short imm){
    int ximm = imm & 0xFFFF;
    reg.writeRegister(rt, (reg.readRegister(rs) ^ ximm));
}

void lui(unsigned short rt, unsigned short imm){
    int ximm=imm;

    if((imm & 0x8000) > 0){
        ximm = ximm | 0xFFFF0000;
    }

    reg.writeRegister(rt, (ximm << 16));
}

void lb(unsigned short rt, unsigned short rs, unsigned short imm){
    int byte, ximm=imm;

    if((imm & 0x8000) > 0){
        ximm = ximm | 0xFFFF0000;
    }

    try{
        byte = r.getfromStack(reg.readRegister(rs)+ximm, 0);

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
    int hw, ximm=imm;

    if((imm & 0x8000) > 0){
        ximm = ximm | 0xFFFF0000;
    }

    try{
        hw = r.getfromStack(reg.readRegister(rs)+ximm, 1);

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
    int byte, ximm=imm;

    if((imm & 0x8000) > 0){
        ximm = ximm | 0xFFFF0000;
    }

    try{
        byte = r.getfromStack(reg.readRegister(rs)+ximm, 0);

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
    int hw, ximm=imm;

    if((imm & 0x8000) > 0){
        ximm = ximm | 0xFFFF0000;
    }

    try{
        hw = r.getfromStack(reg.readRegister(rs)+ximm, 1);

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
    int ximm=imm;

    if((imm & 0x8000) > 0){
        ximm = ximm | 0xFFFF0000;
    }

    r.loadtoStack(reg.readRegister(rs)+ximm, byte, 0);
}

void sh(unsigned short rt, unsigned short rs, unsigned short imm){
    int hw = reg.readRegister(rt) & 0xFFFF;
    int ximm=imm;

    if((imm & 0x8000) > 0){
        ximm = ximm | 0xFFFF0000;
    }

    r.loadtoStack(reg.readRegister(rs)+ximm, hw, 1);
}

void sw(unsigned short rt, unsigned short rs, unsigned short imm){
    int ximm=imm;

    if((imm & 0x8000) > 0){
        ximm = ximm | 0xFFFF0000;
    }

    r.loadtoStack(reg.readRegister(rs)+ximm, reg.readRegister(rt), 2);
}

void lw(unsigned short rt,   unsigned short rs, unsigned short imm){
    int ximm=imm;

    if((imm & 0x8000) > 0){
        ximm = ximm | 0xFFFF0000;
    }

    reg.writeRegister(rt, r.getfromStack(reg.readRegister(rs)+ximm, 2));
}

void lwl(unsigned short rt, unsigned short rs, unsigned short imm){
    int ximm=imm;

    if((imm & 0x8000) > 0){
        ximm = ximm | 0xFFFF0000;
    }

    unsigned int addr = reg.readRegister(rs) + ximm;

    switch(addr%4){
        unsigned int temp;
        case 0: reg.writeRegister(rt, r.getfromStack(addr, 2));
                return;

        case 1: temp = r.getfromStack(addr-1, 2) << 8;
                temp = temp | (reg.readRegister(rt) & 0xFF);
                reg.writeRegister(rt, temp);
                return;

        case 2: temp = r.getfromStack(addr-2, 2) << 16;
                temp = temp | (reg.readRegister(rt) & 0xFFFF);
                reg.writeRegister(rt, temp);
                return;

        case 3: temp = r.getfromStack(addr-3, 2) << 24;
                temp = temp | (reg.readRegister(rt) & 0xFFFFFF);
                reg.writeRegister(rt, temp);
                return;
    }
}

void lwr(unsigned short rt, unsigned short rs, unsigned short imm){
    int ximm=imm;

    if((imm & 0x8000) > 0){
        ximm = ximm | 0xFFFF0000;
    }

    unsigned int addr = reg.readRegister(rs) + ximm;

    switch(addr%4){
        unsigned int temp;
        case 0: temp = r.getfromStack(addr, 2) >> 24;
                temp = temp | (reg.readRegister(rt) & 0xFFFFFF00);
                reg.writeRegister(rt, temp);
                return;

        case 1: temp = r.getfromStack(addr-1, 2) >> 16;
                temp = temp | (reg.readRegister(rt) & 0xFFFF0000);
                reg.writeRegister(rt, temp);
                return;

        case 2: temp = r.getfromStack(addr-2, 2) >> 8;
                temp = temp | (reg.readRegister(rt) & 0xFFFFFF00);
                reg.writeRegister(rt, temp);
                return;

        case 3: reg.writeRegister(rt, r.getfromStack(addr-3, 2));
                return;
    }
}