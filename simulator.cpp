#ifndef STRING
#define STRING
#include <string>
#endif 

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP
#include <simulator.hpp>
#endif

#ifndef MEMORY_HPP
#define MEMORY_HPP
#include <memory.hpp>
#endif

int main(int argc, char *argv[]){
    //1. open the file 
    //2. Loop
        //2a. Read the first line
        //2b. Convert the instruction into binary
        //2c. Store the first line into memory 
        //2d. Move to second line
        // Loop

    //1. open the file:
    ifstream f(argv[1], ios::binary | ios::in);
    int input;
    while(f >> input){
        
    }
    
}


//Implementing Register File


