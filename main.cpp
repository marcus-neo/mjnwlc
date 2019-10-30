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

#include "include/memory.hpp"
#include "include/simulator.hpp"
using namespace std;

RAM r;

int main(){
    fstream file;
    unsigned char n;

    try{
        file.open("binary3.bin", ios::in | ios::binary);

        if (!file.is_open()) {
            throw "Error opening binary file!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(EXIT_FAILURE);
    }

    file.seekg(0, file.end);
    int lengthofbin = file.tellg();
    file.seekg(0, file.beg);

    for (int i=0; i<lengthofbin; i++){
        file.read((char *) (&n), sizeof(n));
        r.loadtoMemory(n);
        cout  << (int32_t)n << endl;
    }

    simulator S;
    S.execute(r);

    cout << "Simulator has finished execution successfully" << endl;
    return 0;
}