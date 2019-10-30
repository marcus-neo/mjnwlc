all: main.o ./o/decodeinstruction.o ./o/Instructions.o memory.o ProgramCounter.o RegisterFile.o simulator.o instructions/add.o instructions/addi.o instructions/addiu.o instructions/addu.o instructions/andd.o instructions/andi.o instructions/beq.o instructions/bgez.o instructions/bgezal.o instructions/bgtz.o instructions/blez.o instructions/bltz.o instructions/bltzal.o instructions/bne.o instructions/div.o instructions/divu.o instructions/j.o instructions/jal.o instructions/jalr.o instructions/jr.o instructions/lb.o instructions/lbu.o instructions/lh.o instructions/lhu.o instructions/lui.o instructions/lw.o instructions/lwl.o instructions/lwr.o instructions/mfhi.o instructions/mflo.o instructions/mthi.o instructions/mtlo.o instructions/mult.o instructions/multu.o instructions/ori.o instructions/orr.o instructions/sb.o instructions/sh.o instructions/sll.o instructions/sllv.o instructions/slt.o instructions/slti.o instructions/sltiu.o instructions/sltu.o instructions/sra.o instructions/srav.o instructions/srl.o instructions/srlv.o instructions/sub.o instructions/subu.o instructions/sw.o instructions/xori.o instructions/xorr.o
	g++ main.o decodeinstruction.o Instructions.o memory.o ProgramCounter.o RegisterFile.o simulator.o instructions/add.o instructions/addi.o instructions/addiu.o instructions/addu.o instructions/andd.o instructions/andi.o instructions/beq.o instructions/bgez.o instructions/bgezal.o instructions/bgtz.o instructions/blez.o instructions/bltz.o instructions/bltzal.o instructions/bne.o instructions/div.o instructions/divu.o instructions/j.o instructions/jal.o instructions/jalr.o instructions/jr.o instructions/lb.o instructions/lbu.o instructions/lh.o instructions/lhu.o instructions/lui.o instructions/lw.o instructions/lwl.o instructions/lwr.o instructions/mfhi.o instructions/mflo.o instructions/mthi.o instructions/mtlo.o instructions/mult.o instructions/multu.o instructions/ori.o instructions/orr.o instructions/sb.o instructions/sh.o instructions/sll.o instructions/sllv.o instructions/slt.o instructions/slti.o instructions/sltiu.o instructions/sltu.o instructions/sra.o instructions/srav.o instructions/srl.o instructions/srlv.o instructions/sub.o instructions/subu.o instructions/sw.o instructions/xori.o instructions/xorr.o -o prog

main.o: main.cpp
	g++ -c main.cpp

./o/decodeinstruction.o: decodeinstruction.cpp
	g++ -c decodeinstruction.cpp

./o/Instructions.o: Instructions.cpp
	g++ -c Instructions.cpp

memory.o: memory.cpp
	g++ -c memory.cpp

ProgramCounter.o: ProgramCounter.cpp
	g++ -c ProgramCounter.cpp

RegisterFile.o: RegisterFile.cpp
	g++ -c RegisterFile.cpp

simulator.o: simulator.cpp
	g++ -c simulator.cpp

addi.o: instructions/addi.cpp
	g++ -c instructions/addi.cpp

addiu.o: instructions/addiu.cpp
	g++ -c instructions/addiu.cpp

addu.o: instructions/addu.cpp
	g++ -c instructions/addu.cpp

andd.o: instructions/andd.cpp
	g++ -c instructions/andd.cpp

andi.o: instructions/andi.cpp
	g++ -c instructions/andi.cpp

beq.o: instructions/beq.cpp
	g++ -c instructions/beq.cpp

bgez.o: instructions/bgez.cpp
	g++ -c instructions/bgez.cpp

bgezal.o: instructions/bgezal.cpp
	g++ -c instructions/bgezal.cpp

bgtz.o: instructions/bgtz.cpp
	g++ -c instructions/bgtz.cpp

blez.o: instructions/blez.cpp
	g++ -c instructions/blez.cpp

bltz.o: instructions/bltz.cpp
	g++ -c instructions/bltz.cpp

bltzal.o: instructions/bltzal.cpp
	g++ -c instructions/bltzal.cpp

bne.o: instructions/bne.cpp
	g++ -c instructions/bne.cpp

div.o: instructions/div.cpp
	g++ -c instructions/div.cpp

divu.o: instructions/divu.cpp
	g++ -c instructions/divu.cpp

j.o: instructions/j.cpp
	g++ -c instructions/j.cpp

jal.o: instructions/jal.cpp
	g++ -c instructions/jal.cpp

jalr.o: instructions/jalr.cpp
	g++ -c instructions/jalr.cpp

jr.o: instructions/jr.cpp
	g++ -c instructions/jr.cpp

lb.o: instructions/lb.cpp
	g++ -c instructions/lb.cpp

lbu.o: instructions/lbu.cpp
	g++ -c instructions/lbu.cpp

lh.o: instructions/lh.cpp
	g++ -c instructions/lh.cpp

lhu.o: instructions/lhu.cpp
	g++ -c instructions/lhu.cpp

lui.o: instructions/lui.cpp
	g++ -c instructions/lui.cpp

lw.o: instructions/lw.cpp
	g++ -c instructions/lw.cpp

lwl.o: instructions/lwl.cpp
	g++ -c instructions/lwl.cpp

lwr.o: instructions/lwr.cpp
	g++ -c instructions/lwr.cpp

mfhi.o: instructions/mfhi.cpp
	g++ -c instructions/mfhi.cpp

mflo.o: instructions/mflo.cpp
	g++ -c instructions/mflo.cpp

mthi.o: instructions/mthi.cpp
	g++ -c instructions/mthi.cpp

mtlo.o: instructions/mtlo.cpp
	g++ -c instructions/mtlo.cpp

mult.o: instructions/mult.cpp
	g++ -c instructions/mult.cpp

multu.o: instructions/multu.cpp
	g++ -c instructions/multu.cpp

ori.o: instructions/ori.cpp
	g++ -c instructions/ori.cpp

sb.o: instructions/sb.cpp
	g++ -c instructions/sb.cpp

sh.o: instructions/sh.cpp
	g++ -c instructions/sh.cpp

sll.o: instructions/sll.cpp
	g++ -c instructions/sll.cpp

sllv.o: instructions/sllv.cpp
	g++ -c instructions/sllv.cpp

slt.o: instructions/slt.cpp
	g++ -c instructions/slt.cpp

slti.o: instructions/slti.cpp
	g++ -c instructions/slti.cpp

sltiu.o: instructions/sltiu.cpp
	g++ -c instructions/sltiu.cpp

sltu.o: instructions/sltu.cpp
	g++ -c instructions/sltu.cpp

sra.o: instructions/sra.cpp
	g++ -c instructions/sra.cpp

srav.o: instructions/srav.cpp
	g++ -c instructions/srav.cpp

srl.o: instructions/srl.cpp
	g++ -c instructions/srl.cpp

srlv.o: instructions/srlv.cpp
	g++ -c instructions/srlv.cpp

sub.o: instructions/sub.cpp
	g++ -c instructions/sub.cpp

subu.o: instructions/subu.cpp
	g++ -c instructions/subu.cpp

sw.o: instructions/sw.cpp
	g++ -c instructions/sw.cpp

xori.o: instructions/xori.cpp
	g++ -c instructions/xori.cpp

xorr.o: instructions/xorr.cpp
	g++ -c instructions/xorr.cpp
	
