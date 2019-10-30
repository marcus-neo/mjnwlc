#ifndef MEMORY_HPP
#define MEMORY_HPP
#include <cstdlib>
#include <unordered_map>
using namespace std;

class RAM{
    public:
        RAM();
        ~RAM();

        unordered_map<int, unsigned char> memory;
        unordered_map<int, unsigned long> stack;

        static const unsigned long ADDR_NULL_OFFSET = 0x00000000;
        static const unsigned long ADDR_NULL_LENGTH = 0x4;
        //CPU can store up to 2^22 (4194304) instructions
        static const unsigned long ADDR_INSTR_OFFSET = 0x10000000;
        static const unsigned long ADDR_INSTR_LENGTH = 0x1000000;
        //RAM can store up to 2^24 (16777216) 32-bit data
        static const unsigned long ADDR_DATA_OFFSET = 0x20000000;
        static const unsigned long ADDR_DATA_LENGTH = 0x4000000;
        static const unsigned long ADDR_GETC_OFFSET = 0x30000000;
        static const unsigned long ADDR_GETC_LENGTH = 0x4;
        static const unsigned long ADDR_PUTC_OFFSET = 0x30000004;
        static const unsigned long ADDR_PUTC_LENGTH = 0x4;

        void loadtoMemory(unsigned char binstr);
        unsigned long pullfromMemory(unsigned long& ProgCount);
        unsigned long get_addr(unsigned long data);
        void jump(int& ProgCount, unsigned long addr);
        void loadtoStack(unsigned long data);
        unsigned long getfromStack(unsigned long addr);

    private:
        int32_t value;
        int32_t offset=0;
        int32_t sp=0;
};

#endif