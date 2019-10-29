#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(){
    cout << "hello" << endl;
    fstream file;
    unsigned int n;
    int file_position = 0;
    file.open("binary2.bin", ios::in | ios::binary);
    file.read((char*)& n, sizeof(n));
    cout << n << endl;
    
    
return 0;
}