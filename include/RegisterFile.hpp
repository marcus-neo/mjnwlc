#ifndef REGISTERFILE_HPP
#define REGISTERFILE_HPP



class RegisterFile{
    private: 
    unsigned long $zero;
    unsigned long $at = 5;
    unsigned long $v0 = 7, $v1 = 9;
    unsigned long $a0, $a1, $a2, $a3;
    unsigned long $t0, $t1, $t2, $t3, $t4, $t5, $t6, $t7;
    unsigned long $s0, $s1, $s2, $s3, $s4, $s5, $s6, $s7;
    unsigned long $t8, $t9;
    unsigned long $k0, $k1;
    unsigned long $gp;
    unsigned long $sp;
    unsigned long $fp;
    unsigned long $ra;

    public:
    unsigned long readRegister(int RegisterNumber);
    void writeRegister(int RegisterNumber, unsigned long input);
    

};

extern RegisterFile reg;

#endif