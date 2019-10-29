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
#ifndef MEMORY_HPP
#define MEMORY_HPP
#include "memory.hpp"
#endif

using namespace std;

main(){
    cout << "hello" << endl;
    fstream file;
    u_char n;
    file.open("binary3.bin", ios::in | ios::binary);
    file.seekg(0, file.end);
    int lengthofbin = file.tellg();
    file.seekg(0, file.beg);
    
    
    for (int i=0; i<lengthofbin; i++){
        file.read((char *) (&n), sizeof(n));
        loadtoMemory(n);
        cout  << (int32_t)n << endl;
    }
    
    return 0;

}