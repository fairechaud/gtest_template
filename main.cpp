#include <iostream>
#include "LibraryCode.hpp"

int main (int argc, char **argv){
    int s = sum(2,3);
    std::cout << "Main application\n";
    std::cout << "sum is " << s << '\n';
    return 0;
}