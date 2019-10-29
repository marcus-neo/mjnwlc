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

#include "memory.hpp"
#include "simulator.hpp"
using namespace std;

main(){

    RAM r;
    fstream file;
    u_char n;
    file.open("binary3.bin", ios::in | ios::binary);
    file.seekg(0, file.end);
    int lengthofbin = file.tellg();
    file.seekg(0, file.beg);
    
    
    for (int i=0; i<lengthofbin; i++){
        file.read((char *) (&n), sizeof(n));
        r.loadtoMemory(n);
        cout  << (int32_t)n << endl;
    }

    simulator S;
    S.execute();
    
    return 0;

}