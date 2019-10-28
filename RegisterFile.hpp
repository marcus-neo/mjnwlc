

class RegisterFile{
    private: 
    unsigned long R0, R1, R2, R3, R4, R5, R6, R7;
    unsigned long R8, R9, R10, R11, R12, R13, R14, R15;
    unsigned long R16, R17, R18, R19, R20, R21, R22, R23;
    unsigned long R24, R25, R26, R27, R28, R29, R30, R31;

    public:
    unsigned long rR0();
    unsigned long rR1();
    unsigned long rR2();
    unsigned long rR3();
    unsigned long rR4();
    unsigned long rR5();

    void wR0(unsigned long newR0);
    void wR1(unsigned long newR1);
    void wR2(unsigned long newR2);
    void wR3(unsigned long newR3);
    void wR4(unsigned long newR4);
    void wR5(unsigned long newR5); 
    

};