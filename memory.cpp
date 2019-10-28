#include "memory.hpp"

int32_t ram::get_value(){
    return value;
}

int32_t ram::get_address(){
    return address;
}

void ram::set_value(int32_t x){
    value = x;
}