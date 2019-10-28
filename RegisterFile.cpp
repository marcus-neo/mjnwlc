#ifndef REGISTERFILE_H
#define REGISTERFILE_H
#include "RegisterFile.hpp"
#endif

unsigned long RegisterFile::rR0(){
    return R0;
}

unsigned long RegisterFile::rR1(){
    return R1;
}

unsigned long RegisterFile::rR2(){
    return R2;
}

unsigned long RegisterFile::rR3(){
    return R3;
}

unsigned long RegisterFile::rR4(){
    return R4;
}

unsigned long RegisterFile::rR5(){
    return R5;
}

void RegisterFile::wR0(unsigned long newR0){
    R0 = newR0;
}
void RegisterFile::wR1(unsigned long newR1){
    R1 = newR1;
}

void RegisterFile::wR2(unsigned long newR2){
    R1 = newR2;
}

void RegisterFile::wR3(unsigned long newR3){
    R1 = newR3;
}

void RegisterFile::wR4(unsigned long newR4){
    R1 = newR4;
}

void RegisterFile::wR5(unsigned long newR5){
    R1 = newR5;
}

