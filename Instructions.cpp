#include <include/Instructions.hpp>

// make JR and ADDIU run first
//mips program exit 
void execute(int instype, unsigned short decoded1, unsigned short decoded2, unsigned long decoded3){
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