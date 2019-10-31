all: main.o ./o/decodeinstruction.o ./o/Instructions.o memory.o ProgramCounter.o RegisterFile.o simulator.o instructions/r_type.o instructions/j_type.o instructions/i_type.o
	g++ main.o decodeinstruction.o Instructions.o memory.o ProgramCounter.o RegisterFile.o simulator.o instructions/r_type.o instructions/j_type.o instructions/i_type.o -o prog

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

r_type.o: instructions/r_type.cpp
	g++ -c instructions/r_type.cpp

j_type.o: instructions/j_type.cpp
	g++ -c instructions/j_type.cpp

i_type.o: instructions/i_type.cpp
	g++ -c instructions/i_type.cpp

run:
	./prog

clean:
	rm *.o prog