#include "include/ProgramCounter.hpp"


void programCounter::increment(){
    if(interference == 0){
        ProgCount = ProgCount + 4;
    }
    else{
        interference = 0;
    }
    
}