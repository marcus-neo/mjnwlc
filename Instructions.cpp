#include <Instructions.hpp>

// make JR and ADDIU run first
//mips program exit 
void instructions::execute(unsigned long input){
    unsigned short opcode = input >> 26;
    
    if(opcode == 0){
        unsigned short function = input & 0b111111;
        unsigned short rs = (input << 6) >> 27;
        unsigned short rt = (input << 12) >> 27;
        unsigned short rd = (input << 17) >> 27;
        unsigned short shamt = (input << 22) >> 27; 

        if(function == 0){
            sll(rd, rt, shamt);
        }
        else if(function == 2){
            srl(rd, rt, shamt);
        }
        else if (function == 3){
            sra(rd, rt, shamt);
        }
        else if (function == 4){
            sllv(rd, rt, rs);
        }
        else if (function == 6){
            srlv(rd, rt, rs);
        }
        else if (function == 7){
            srav(rd, rt, rs);
        }
        else if (function == 8){
            jr(rs);
        }
        else if (function == 9){
            jalr(rd, rs);
        }
        else if (function == 12){
            //syscall
        }
        else if (function == 16){
            mfhi(rd);
        }
        else if (function == 17){
            mthi(rs);
        }
        else if (function == 18){
            mflo(rd);
        }
        else if (function == 19){
            mtlo(rs);
        }
        else if (function == 24){
            mult(rs, rt);
        }
        else if (function == 25){
            multu(rs, rt);
        }
        else if (function == 26){
            div(rs,rt);
        }
        else if (function == 27){
            divu(rs, rt);
        }
        else if (function == 32){
            add(rd, rs, rt);
        }
        else if (function == 33){
            addu(rd, rs, rt);
        }
        else if (function == 34){
            sub(rd, rs, rt);
        }
        else if (function == 35){
            subu(rd, rs, rt);
        }
        else if (function == 36){
            andd(rd, rs, rt);
        }
        else if (function == 37){
            orr(rd, rs, rt);
        }
        else if (function == 38){
            xorr(rd, rs, rt);   
        }
        else if (function == 42){
            slt(rd, rs, rt);
        }
        else if (function == 43){
            sltu(rd, rs, rt);
        }
    }
    else if(opcode == 2 || opcode == 3){
        unsigned long address = input & 0x03ffff;
        if(opcode == 2){
            j(address);
        }
        else if(opcode == 3){
            jal(address);
        }
    }
    else{
        unsigned short rs = (input << 6) >> 27;
        unsigned short rt = (input << 12) >> 27;
        unsigned short imm = input & 0xffff; 
        if(opcode == 1){
            if(rt == 0b00001){
                bgez(rs, imm);
            }
            else if (rt == 0b10001){
                bgezal(rs, imm);
            }
            else if (rt == 0b00000){
                bltz(rs, imm);
            }
            else if (rt == 0b10000){
                bltzal(rs, imm);
            }
            //error code for this section
            //else{
            //    return 1000;
            //}
        }
        if(opcode == 4){
            beq(rs, rt, imm);
        }
        else if(opcode == 5){
            bne(rs, rt, imm);
        }
        else if(opcode == 6){
            blez(rs, imm);
        }
        else if(opcode == 7){
            bgtz(rs, imm);
        }
        else if(opcode == 8){
            addi(rt, rs, imm);
        }
        else if(opcode == 9){
            addiu(rt, rs, imm);
        }
        else if(opcode == 10){
            slti(rt, rs, imm);
        }
        else if(opcode == 11){
            sltiu(rt, rs, imm);
        }
        else if(opcode == 12){
            andi(rt, rs, imm);
        }
        else if(opcode == 13){
            ori(rt, rs, imm);
        }
        else if(opcode == 14){
            xori(rt, rs, imm);
        }
        else if(opcode == 15){
            lui(rt, imm);
        }
        else if(opcode == 32){
            lb(rt, imm, rs);
        }
        else if(opcode == 33){
            lh(rt, imm, rs);
        }
        else if(opcode == 34){
            lw(rt, imm, rs);
        }
        else if(opcode == 36){
            lbu(rt, imm, rs);
        }
        else if(opcode == 37){
            lhu(rt, imm, rs);
        }
        else if(opcode == 40){
            sb(rt, imm, rs);
        }
        else if(opcode == 41){
            sh(rt, imm, rs);
        }
        else if(opcode == 43){
            sw(rt, imm, rs);
        }
    }
}

void instructions::add(unsigned short& rd, unsigned short rs, unsigned short rt){

}
void instructions::addi(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::addiu(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::addu(unsigned short& rd, unsigned short rs, unsigned short rt){

}
void instructions::andd(unsigned short& rd, unsigned short rs, unsigned short rt){

}
void instructions::andi(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::beq(unsigned short rs, unsigned short rt, unsigned short imm){

}
void instructions::bgez(unsigned short rs, unsigned short imm){

}
void instructions::bgezal(unsigned short rs, unsigned short imm){

}
void instructions::bgtz(unsigned short rs, unsigned short imm){

}
void instructions::blez(unsigned short rs, unsigned short imm){

}
void instructions::bltz(unsigned short rs, unsigned short imm){

}
void instructions::bltzal(unsigned short rs, unsigned short imm){

}
void instructions::bne(unsigned short rs, unsigned short rt, unsigned short imm){

}
void instructions::div(signed short rs, signed short rt){

}
void instructions::divu(unsigned short rs, unsigned short rt){

}
void instructions::j(unsigned short address){

}
void instructions::jalr(unsigned short& rd, unsigned short rs){

}
void instructions::jal(unsigned short address){

}
void instructions::jr(unsigned short rs){

}
void instructions::syscall(){

}
void instructions::lb(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::lbu(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::lh(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::lhu(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::lui(unsigned short rt, unsigned short imm){

}
void instructions::lw(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::lwl(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::lwr(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::mfhi(unsigned short& rd){

}
void instructions::mflo(unsigned short& rd){

}
void instructions::mthi(unsigned short rs){

}
void instructions::mtlo(unsigned short rs){

}
void instructions::mult(signed short rs, signed short rt){

}
void instructions::multu(unsigned short rs, unsigned short rt){

}
void instructions::orr(unsigned short& rd, unsigned short rs, unsigned short rt){

}
void instructions::ori(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::sb(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::sh(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::sll(unsigned short& rd, unsigned short rt, unsigned short shamt){

}
void instructions::sllv(unsigned short& rd, unsigned short rt, unsigned short rs){

}
void instructions::slt(unsigned short& rd, unsigned short rs, unsigned short rt){

}
void instructions::slti(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::sltiu(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::sltu(unsigned short& rd, unsigned short rs, unsigned short rt){

}
void instructions::sra(unsigned short& rd, unsigned short rt, unsigned short shamt){

}
void instructions::srav(unsigned short& rd, unsigned short rt, unsigned short rs){

}
void instructions::srl(unsigned short& rd, unsigned short rt, unsigned short shamt){
    
}
void instructions::srlv(unsigned short& rd, unsigned short rt, unsigned short rs){

}
void instructions::sub(unsigned short& rd, unsigned short rs, unsigned short rt){

}
void instructions::subu(unsigned short& rd, unsigned short rs, unsigned short rt){
    
}
void instructions::sw(unsigned short rt, unsigned short rs, unsigned short imm){

}
void instructions::xorr(unsigned short& rd, unsigned short rs, unsigned short rt){

}
void instructions::xori(unsigned short rt, unsigned short rs, unsigned short imm){

}