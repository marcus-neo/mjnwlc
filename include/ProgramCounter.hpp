#ifndef PROGRAMCOUNTER_HPP
#define PROGRAMCOUNTER_HPP

class programCounter{
    public:
        void increment();
        unsigned long ProgCount;
        bool interference = 0; 
};

extern programCounter PC;

#endif