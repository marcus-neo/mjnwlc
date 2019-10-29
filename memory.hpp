#ifndef MEMORY_HPP
#define MEMORY_HPP
#include <cstdlib>
#include <unordered_map>
using namespace std;

class RAM{
    public:
        RAM();
        unordered_map<int, unsigned char> memory;
        //ADDED BY MARCUS NEO
        void loadtoMemory(unsigned char load);
        uint32_t pullfromMemory(int& ProgCount);
        //END ADD
        uint32_t get_addr(uint32_t data);

        static const uint32_t ADDR_NULL_OFFSET = 0x00000000;
        static const uint32_t ADDR_NULL_LENGTH = 0x4;
        static const uint32_t ADDR_INSTR_OFFSET = 0x10000000;
        static const uint32_t ADDR_INSTR_LENGTH = 0x1000000;
        static const uint32_t ADDR_DATA_OFFSET = 0x20000000;
        static const uint32_t ADDR_DATA_LENGTH = 0x4000000;
        static const uint32_t ADDR_GETC_OFFSET = 0x30000000;
        static const uint32_t ADDR_GETC_LENGTH = 0x4;
        static const uint32_t ADDR_PUTC_OFFSET = 0x30000004;
        static const uint32_t ADDR_PUTC_LENGTH = 0x4;

    private:
        int32_t value;
        int32_t offset=0;
};

#endif