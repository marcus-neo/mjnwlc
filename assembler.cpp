#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char *argv[]){
if(argc < 2){
    cout << "Please enter a file name to open" << endl;
    return 1;
}

string operation, input1, input2, input3;

ifstream infile;
infile.open(argv[1]);
    while(infile >> operation >> input1 >> input2 >> input3){
        
    }

}