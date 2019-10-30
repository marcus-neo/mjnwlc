#include <Instructions.hpp>

// make JR and ADDIU run first
//mips program exit 
void instructions::execute(int instype, unsigned short decoded1, unsigned short decoded2, unsigned long decoded3){
    switch(instype){
        case 0:
            return;
            break;
        case 1:
            sll(decoded1, decoded2, decoded3);
            return;
            break;
        case 2:
            srl(decoded1, decoded2, decoded3);
            return;
            break;
        case 3:
            sra(decoded1, decoded2, decoded3);
            return;
            break;
        case 4:
            sllv(decoded1, decoded2, decoded3);
            return;
            break;
        case 5:
            srlv(decoded1, decoded2, decoded3);
            return;
            break;
        case 6:
            srav(decoded1, decoded2, decoded3);
            return;
            break;
        case 7:
            jr(decoded1);
            return;
            break;
        case 8:
            jalr(decoded1, decoded2);
            return;
            break;
        case 9:
            return;
            break;
        //syscall
    
        case 10:
            mfhi(decoded1);
            return;
            break;
    
        case 11:
            mthi(decoded1);
            return;
            break;
    
        case 12:
            mflo(decoded1);
            return;
            break;
        case 13:
            mtlo(decoded1);
            return;
            break;
        case 14:
            mult(decoded1, decoded2);
            return;
            break;
        case 15:
            multu(decoded1, decoded2);
            return;
            break;
        case 16:
            div(decoded1, decoded2);
            return;
            break;
        case 17:
            divu(decoded1, decoded2);
            return;
            break;
        case 18:
            add(decoded1, decoded2, decoded3);
            return;
            break;
        case 19:
            addu(decoded1, decoded2, decoded3);
            return;
            break;
        case 20:
            sub(decoded1, decoded2, decoded3);
            return;
            break;
        case 21:
            subu(decoded1, decoded2, decoded3);
            return;
            break;
        case 22:
            andd(decoded1, decoded2, decoded3);
            return;
            break;
        case 23:
            orr(decoded1, decoded2, decoded3);
            return;
            break;
        case 24:
            xorr(decoded1, decoded2, decoded3);
            return;
            break;   
        case 25:
            slt(decoded1, decoded2, decoded3);
            return;
            break;
        case 26:
            sltu(decoded1, decoded2, decoded3);
            return;
            break;
        case 30:
            j(decoded3);
            return;
            break;
        case 31:
            jal(decoded3);
            return;
            break;
        case 40:
            bgez(decoded1, decoded3);
            return;
            break;
        case 41:
            bgezal(decoded1, decoded3);
            return;
            break;
        case 42:
            bltz(decoded1, decoded3);
            return;
            break;
        case 43:
            bltzal(decoded1, decoded3);
            return;
            break;
        case 44:
            beq(decoded1, decoded2, decoded3);
            return;
            break;
        case 45:
            bne(decoded1, decoded2, decoded3);
            return;
            break;
        case 46:
            blez(decoded1, decoded3);
            return;
            break;
        case 47:
            bgtz(decoded1, decoded3);
            return;
            break;
        case 48:
            addi(decoded2, decoded1, decoded3);
            return;
            break;
        case 49:
            addiu(decoded2, decoded1, decoded3);
            return;
            break;
        case 50:
            slti(decoded2, decoded1, decoded3);
            return;
            break;
        case 51:
            sltiu(decoded2, decoded1, decoded3);
            return;
            break;
        case 52:
            andi(decoded2, decoded1, decoded3);
            return;
            break;
        case 53:
            ori(decoded2, decoded1, decoded3);
            return;
            break;
        case 54:
            xori(decoded2, decoded1, decoded3);
            return;
            break;
        case 55:
            lui(decoded1, decoded3);
            return;
            break;
        case 56:
            lb(decoded1, decoded2, decoded3);
            return;
            break;
        case 57:
            lh(decoded1, decoded2, decoded3);
            return;
            break;
        case 58:
            lw(decoded1, decoded2, decoded3);
            return;
            break;
        case 59:
            lwl(decoded1, decoded2, decoded3);
            return;
            break;
        case 60:
            lwr(decoded1, decoded2, decoded3);
            return;
            break;
        case 61:
            lbu(decoded1, decoded2, decoded3);
            return;
            break;
        case 62:
            lhu(decoded1, decoded2, decoded3);
            return;
            break;
        case 63:
            sb(decoded1, decoded2, decoded3);
            return;
            break;
        case 64:
            sh(decoded1, decoded2, decoded3);
            return;
            break;
        case 65:
            sw(decoded1, decoded2, decoded3);
            return;
            break;
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