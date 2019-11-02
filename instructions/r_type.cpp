#include "../include/Instructions.hpp"
#include "../include/RegisterFile.hpp"
#include "../include/ProgramCounter.hpp"
#include <iostream>
using namespace std;

void sll(unsigned short& rd, unsigned short rt, unsigned short shamt){
    reg.writeRegister(rd, reg.readRegister(rt) << shamt);
}

void srl(unsigned short& rd, unsigned short rt, unsigned short shamt){
    reg.writeRegister(rd, reg.readRegister(rt) >> shamt);
}

void sra(unsigned short& rd, unsigned short rt, unsigned short shamt){
    if((reg.readRegister(rt) & 0x80000000) > 0){
        int temp = reg.readRegister(rt) >> shamt;
        int sign = 0;

        for(int i=0; i<shamt; i++){
            sign++;
            sign = sign << 1;
        }
        sign = sign << (31-shamt);

        reg.writeRegister(rd, temp | sign);
    }

    else{
        reg.writeRegister(rd, reg.readRegister(rt) >> shamt);
    }
}

void sllv(unsigned short& rd, unsigned short rt, unsigned short rs){
    reg.writeRegister(rd, reg.readRegister(rt) << reg.readRegister(rs));
}

void srlv(unsigned short& rd, unsigned short rt, unsigned short rs){
    reg.writeRegister(rd, reg.readRegister(rt) >> reg.readRegister(rs));
}

void srav(unsigned short& rd, unsigned short rt, unsigned short rs){
    if((reg.readRegister(rt) & 0x80000000) > 0){
        int temp = reg.readRegister(rt) >> reg.readRegister(rs);
        int sign = 0;

        for(int i=0; i<reg.readRegister(rs); i++){
            sign++;
            sign = sign << 1;
        }
        sign = sign << (31-reg.readRegister(rs));

        reg.writeRegister(rd, temp | sign);
    }

    else{
        reg.writeRegister(rd, reg.readRegister(rt) >> reg.readRegister(rs));
    }
}

void jr(unsigned short rs){
    try{
        if(reg.readRegister(rs)%4 == 0 && reg.readRegister(rs) >= 0x10000000 && reg.readRegister(rs) < 0x11000000 || reg.readRegister(rs) == 0){
            PC.ProgCount = reg.readRegister(rs);
            PC.interference = 1;
        }

        else{
            throw "Invalid address!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }
}

void jalr(unsigned short& rd, unsigned short rs){
    try{
        if(reg.readRegister(rs)%4 == 0 && reg.readRegister(rs) >= 0x10000000 && reg.readRegister(rs) < 0x11000000){
            delayins();
            reg.writeRegister(31, PC.ProgCount+4);
            PC.ProgCount = (PC.ProgCount & 0xF0000000) | (reg.readRegister(rs) << 2);
            PC.interference = 1;
        }

        else{
            throw "Invalid address!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-11);
    }
}

void mfhi(unsigned short& rd){
    reg.writeRegister(rd, reg.readRegister(32));
}

void mthi(unsigned short rs){
    reg.writeRegister(32, reg.readRegister(rs));
}

void mflo(unsigned short& rd){
    reg.writeRegister(rd, reg.readRegister(33));
}

void mtlo(unsigned short rs){
    reg.writeRegister(33, reg.readRegister(rs));
}

void mult(signed short rs, signed short rt){
    int xs = reg.readRegister(rs);
    int xt = reg.readRegister(rt);

    if((reg.readRegister(rs) & 0x80000000) > 1){
        xs = -reg.readRegister(rs);
    }

    if((reg.readRegister(rt) & 0x80000000) > 1){
        xt = -reg.readRegister(rt);
    }

    signed long product = xs * xt;
    
    
}

void multu(unsigned short rs, unsigned short rt){
    unsigned long product = reg.readRegister(rs) * reg.readRegister(rt);
    reg.writeRegister(32, (product & 0xFFFFFFFF00000000) >> 32);
    reg.writeRegister(33, product & 0xFFFFFFFF);
}

void div(signed short rs, signed short rt){

}
void divu(unsigned short rs, unsigned short rt){

}
void add(unsigned short& rd, unsigned short rs, unsigned short rt){
    if(((reg.readRegister(rs) & 0x80000000) > 0) && ((reg.readRegister(rt)) & 0x80000000) > 0){
        reg.writeRegister(rd, reg.readRegister(rs) + reg.readRegister(rt));


        if((reg.readRegister(rd) & 0x80000000) == 0){
            cout << "Error: Arithmetic overflow occurred!" << endl;
            exit(-10);
        }
    }

    else{
        reg.writeRegister(rd, reg.readRegister(rs) + reg.readRegister(rt));

        if((reg.readRegister(rd) & 0x80000000) > 0){
            cout << "Error: Arithmetic overflow occurred!" << endl;
            exit(-10);
        }
    }

    cout << endl;
    cout << "rs = " << reg.readRegister(rs) << endl;
    cout << "rt = " << reg.readRegister(rt) << endl;
    cout << "rd = " << reg.readRegister(rd) << endl;
    cout << endl;
}

void addu(unsigned short& rd, unsigned short rs, unsigned short rt){
    reg.writeRegister(rd, (unsigned)(reg.readRegister(rs) + reg.readRegister(rt)));

    if((reg.readRegister(rs) >= 0 && reg.readRegister(rt) >= 0 && reg.readRegister(rd) < 0) || (reg.readRegister(rs) < 0 && reg.readRegister(rt) < 0 && reg.readRegister(rd) >= 0)){
        cout << "Error: Arithmetic overflow occurred!" << endl;
        exit(-10);
    }

    cout << endl;
    cout << "rs = " << reg.readRegister(rs) << endl;
    cout << "rt = " << reg.readRegister(rt) << endl;
    cout << "rd = " << reg.readRegister(rd) << endl;
    cout << endl;
}

void sub(unsigned short& rd, unsigned short rs, unsigned short rt){
    reg.writeRegister(rd, (reg.readRegister(rs) - reg.readRegister(rt)));

    if(((reg.readRegister(rs) & 0x80000000) > 0) && ((reg.readRegister(rt) & 0x80000000) == 0) && ((reg.readRegister(rd) & 0x80000000) == 0)){
        cout << "Error: Arithmetic overflow occurred!" << endl;
        exit(-10);
    }

    else if(((reg.readRegister(rs) & 0x80000000) == 0) && ((reg.readRegister(rt) & 0x80000000) > 0) && ((reg.readRegister(rd) & 0x80000000) > 0)){
        cout << "Error: Arithmetic overflow occurred!" << endl;
        exit(-10);
    }
}

void subu(unsigned short& rd, unsigned short rs, unsigned short rt){
    if(reg.readRegister(rs) < reg.readRegister(rt)){
        cout << "Error: Arithmetic overflow occurred!" << endl;
        exit(-10);
    }

    else{
        reg.writeRegister(rd, (reg.readRegister(rs) - reg.readRegister(rt)));
    }
}

void andd(unsigned short& rd, unsigned short rs, unsigned short rt){
    reg.writeRegister(rd, (reg.readRegister(rs) & reg.readRegister(rt)));
}

void orr(unsigned short& rd, unsigned short rs, unsigned short rt){
    reg.writeRegister(rd, (reg.readRegister(rs) | reg.readRegister(rt)));
}

void xorr(unsigned short& rd, unsigned short rs, unsigned short rt){
    reg.writeRegister(rd, (reg.readRegister(rs) ^ reg.readRegister(rt)));
}

void slt(unsigned short& rd, unsigned short rs, unsigned short rt){
    if((signed)reg.readRegister(rs) < (signed)reg.readRegister(rt)){
        reg.writeRegister(rd, 1);
    }

    else{
        reg.writeRegister(rd, 0);
    }
}

void sltu(unsigned short& rd, unsigned short rs, unsigned short rt){
    if((unsigned)reg.readRegister(rs) < (unsigned)reg.readRegister(rt)){
        reg.writeRegister(rd, 1);
    }

    else{
        reg.writeRegister(rd, 0);
    }
}
