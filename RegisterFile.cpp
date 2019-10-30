#ifndef REGISTERFILE_H
#define REGISTERFILE_H
#include "include/RegisterFile.hpp"
#endif



unsigned long RegisterFile::readRegister(int RegisterNumber){
    switch(RegisterNumber){
        case 0:
            return $zero;
            break;
        case 1:
            return $at;
            break;
        case 2:
            return $v0;
            break;
        case 3:
            return $v1;
            break;
        case 4:
            return $a0;
            break;
        case 5:
            return $a1;
            break;
        case 6:
            return $a2;
            break;
        case 7:
            return $a3;
            break;
        case 8:
            return $t0;
            break;
        case 9:
            return $t1;
            break;
        case 10:
            return $t2;
            break;
        case 11:
            return $t3;
            break;
        case 12:
            return $t4;
            break;
        case 13:
            return $t5; 
            break;
        case 14:
            return $t6;
            break;
        case 15:
            return $t7;
            break;
        case 16:
            return $s0;
            break;
        case 17:
            return $s1;
            break;
        case 18:
            return $s2;
            break;
        case 19:
            return $s3;
            break;
        case 20:
            return $s4;
            break;
        case 21:
            return $s5;
            break;
        case 22:
            return $s6;
            break;
        case 23:
            return $s7;
            break;
        case 24:
            return $t8;
            break;
        case 25:
            return $t9;
            break;
        case 26:
            return $k0;
            break;
        case 27:
            return $k1;
            break;
        case 28:
            return $gp;
            break;
        case 29:
            return $sp;
            break;
        case 30:
            return $fp;
            break;
        case 31:
            return $ra;
            break;
    }
}

void RegisterFile::writeRegister(int RegisterNumber, unsigned long input){
    switch(RegisterNumber){
        case 0:
            break;
        case 1:
            $at = input;
            break;
        case 2:
            $v0 = input;
            break;
        case 3:
            $v1 = input;
            break;
        case 4:
            $a0 = input;
            break;
        case 5:
            $a1 = input;
            break;
        case 6:
            $a2 = input;
            break;
        case 7:
            $a3 = input;
            break;
        case 8:
            $t0 = input;
            break;
        case 9:
            $t1 = input;
            break;
        case 10:
            $t2 = input;
            break;
        case 11:
            $t3 = input;
            break;
        case 12:
            $t4 = input;
            break;
        case 13:
            $t5 = input;
            break;
        case 14:
            $t6 = input;
            break;
        case 15:
            $t7 = input;
            break;
        case 16:
            $s0 = input;
            break;    
        case 17:
            $s1 = input;
            break;
        case 18:
            $s2 = input;
            break;
        case 19:
            $s3 = input;
            break;
        case 20:
            $s4 = input;
            break;
        case 21:
            $s5 = input;
            break;
        case 22:
            $s6 = input;
            break;
        case 23:
            $s7 = input;
            break;
        case 24:
            $t8 = input;
            break;
        case 25:
            $t9 = input;
            break;
        case 26:
            $k0 = input;
            break;
        case 27:
            $k1 = input;
            break;
        case 28:
            $gp = input;
            break;
        case 29:
            $sp = input;
            break;
        case 30:
            $fp = input;
            break;
        case 31:
            $ra = input;
            break;
    }
}


