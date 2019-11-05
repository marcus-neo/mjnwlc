#ifndef MEMORY_HPP
#define MEMORY_HPP
#include <cstdlib>
#include <vector>
using namespace std;

class RAM{
    public:
        RAM();
        ~RAM();

        static const unsigned int ADDR_NULL_OFFSET = 0x00000000;
        static const unsigned int ADDR_NULL_LENGTH = 0x4;
        //CPU can store up to 2^22 (4194304) instructions
        static const unsigned int ADDR_INSTR_OFFSET = 0x10000000;
        static const unsigned int ADDR_INSTR_LENGTH = 0x1000000;
        //RAM can store up to 2^24 (16777216) 32-bit data
        static const unsigned int ADDR_DATA_OFFSET = 0x20000000;
        static const unsigned int ADDR_DATA_LENGTH = 0x4000000;
        static const unsigned int ADDR_GETC_OFFSET = 0x30000000;
        static const unsigned int ADDR_GETC_LENGTH = 0x4;
        static const unsigned int ADDR_PUTC_OFFSET = 0x30000004;
        static const unsigned int ADDR_PUTC_LENGTH = 0x4;

        vector<unsigned char> memory;
        vector<int> stack;

        void loadtoMemory(unsigned char binstr);
        unsigned int pullfromMemory(unsigned int& ProgCount);
        unsigned int get_addr();
        void loadtoStack(unsigned int addr, unsigned int data);
        unsigned int getfromStack(unsigned int addr);

    private:
        int32_t value;
        int32_t offset=0;
};

extern RAM r;

#endif