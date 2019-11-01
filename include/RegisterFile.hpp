#ifndef REGISTERFILE_HPP
#define REGISTERFILE_HPP

class RegisterFile{
    public:
        int readRegister(int RegisterNumber);
        void writeRegister(int RegisterNumber, int input);

    private:
        int $zero;
        int $at = 0xffffffff;
        int $v0 = 0xffffffff, $v1 = 0xffffffff;
        int $a0 = 0x10000000, $a1, $a2, $a3;
        int $t0, $t1, $t2, $t3, $t4, $t5, $t6, $t7;
        int $s0, $s1, $s2, $s3, $s4, $s5, $s6, $s7;
        int $t8, $t9;
        int $k0, $k1;
        int $gp;
        int $sp;
        int $fp;
        int $ra;
        int $hi, $lo;
};

extern RegisterFile reg;

#endif