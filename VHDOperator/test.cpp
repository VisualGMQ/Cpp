#include <iostream>
#include "VHD.hpp"
using namespace std;

int main(int argc, char** argv){
    FixedVHD vhd("Learn-ASM.vhd");
    cout<<vhd;
    return 0;
}