#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP
#ifndef STRING
#define STRING
#include <string>
#endif

class simulator{
    public:
        void execute();
        int decodeinstruction(unsigned long bin, unsigned short& decoded1, unsigned short& decoded2, unsigned long& decoded3);

    private:
    

};

#endif