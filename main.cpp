#include <iostream>

main(){
    unsigned long input = 0xFFFFFFFF;
    unsigned short output = input >> 26;
    std::cout << std:: dec << output << std:: endl;
    system ("Pause");
    return 0;
}