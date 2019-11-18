#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif
#include <string>

#include "include/memory.hpp"
#include "include/simulator.hpp"
#include "include/RegisterFile.hpp"
#include "include/ProgramCounter.hpp"
using namespace std;

RegisterFile reg;
programCounter PC;
RAM r;
simulator S;

int main(int argc, char** argv){
    //cout << "prog started" << endl << endl;
    fstream file;
    unsigned char n;
    //cout << "Opening binary" << endl << endl;
    try{
        if(argc < 2){
            file.open("bin/test/temp.bin", ios::in | ios::binary);
        }

        else{
            file.open(argv[1], ios::in | ios::binary);
        }

        if(!file.is_open()){
            throw "Error opening binary file!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(-20);
    }

    file.seekg(0, file.end);
    int lengthofbin = file.tellg();
    file.seekg(0, file.beg);

    for(int i=0; i<lengthofbin; i++){
        file.read((char *) (&n), sizeof(n));
        r.loadtoMemory(n);
    }

    S.execute();
    return (reg.readRegister(2) & 0xFF);
}