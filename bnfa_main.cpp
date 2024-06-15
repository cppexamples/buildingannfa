#include <iostream>
#include "nfa.hpp"

int main(int argc, char* argv[]){
    std::cout<<"Hello World!"<< std::endl;
    TNFA nfa("A*A");
    nfa.G.printGraph();
}