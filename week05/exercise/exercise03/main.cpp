#include <iostream>
#include "stuinfo.hpp"

using namespace std;

int main()
{
    //TODO:Write a main.cpp which contains main() and
    //demonstrate all the features of the prototyped functions.
    stuinfo stu[5];

    inputstu(stu, 5);
    showstu(stu, 5);
    
    return 0;
}