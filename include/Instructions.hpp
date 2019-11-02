#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
void add(unsigned short& rd, unsigned short rs, unsigned short rt);
void addi(unsigned short rt, unsigned short rs, signed short imm);
void addiu(unsigned short rt, unsigned short rs, unsigned short imm);
void addu(unsigned short& rd, unsigned short rs, unsigned short rt);
void andd(unsigned short& rd, unsigned short rs, unsigned short rt);
void andi(unsigned short rt, unsigned short rs, unsigned short imm);
void beq(unsigned short rs, unsigned short rt, unsigned short imm);
void bgez(unsigned short rs, unsigned short imm);
void bgezal(unsigned short rs, unsigned short imm);
void bgtz(unsigned short rs, unsigned short imm);
void blez(unsigned short rs, unsigned short imm);
void bltz(unsigned short rs, unsigned short imm);
void bltzal(unsigned short rs, unsigned short imm);
void bne(unsigned short rs, unsigned short rt, unsigned short imm);
void div(unsigned short rs, unsigned short rt);
void divu(unsigned short rs, unsigned short rt);
void j(unsigned int address);
void jalr(unsigned short& rd, unsigned short rs);
void jal(unsigned int address);
void jr(unsigned short rs);
void syscall();
void lb(unsigned short rt, unsigned short rs, unsigned short imm);
void lbu(unsigned short rt, unsigned short rs, unsigned short imm);
void lh(unsigned short rt, unsigned short rs, unsigned short imm);
void lhu(unsigned short rt, unsigned short rs, unsigned short imm);
void lui(unsigned short rt, unsigned short imm);
void lw(unsigned short rt, unsigned short rs, unsigned short imm);
void lwl(unsigned short rt, unsigned short rs, unsigned short imm);
void lwr(unsigned short rt, unsigned short rs, unsigned short imm);
void mfhi(unsigned short& rd);
void mflo(unsigned short& rd);
void mthi(unsigned short rs);
void mtlo(unsigned short rs);
void mult(unsigned short rs, unsigned short rt);
void multu(unsigned short rs, unsigned short rt);
void orr(unsigned short& rd, unsigned short rs, unsigned short rt);
void ori(unsigned short rt, unsigned short rs, unsigned short imm);
void sb(unsigned short rt, unsigned short rs, unsigned short imm);
void sh(unsigned short rt, unsigned short rs, unsigned short imm);
void sll(unsigned short& rd, unsigned short rt, unsigned short shamt);
void sllv(unsigned short& rd, unsigned short rt, unsigned short rs);
void slt(unsigned short& rd, unsigned short rs, unsigned short rt);
void slti(unsigned short rt, unsigned short rs, unsigned short imm);
void sltiu(unsigned short rt, unsigned short rs, unsigned short imm);
void sltu(unsigned short& rd, unsigned short rs, unsigned short rt);
void sra(unsigned short& rd, unsigned short rt, unsigned short shamt);
void srav(unsigned short& rd, unsigned short rt, unsigned short rs);
void srl(unsigned short& rd, unsigned short rt, unsigned short shamt);
void srlv(unsigned short& rd, unsigned short rt, unsigned short rs);
void sub(unsigned short& rd, unsigned short rs, unsigned short rt);
void subu(unsigned short& rd, unsigned short rs, unsigned short rt);
void sw(unsigned short rt, unsigned short rs, unsigned short imm);
void xorr(unsigned short& rd, unsigned short rs, unsigned short rt);
void xori(unsigned short rt, unsigned short rs, unsigned short imm);
void insexecute(int instype, unsigned short decoded1, unsigned short decoded2, unsigned int decoded3);
void delayins();

#endif