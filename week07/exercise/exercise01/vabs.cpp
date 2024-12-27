#include <iostream>
#include <cmath> 
#include "vabs.h"

using namespace std;

bool vabs(int *p, int n)
{
    /*
        TODO: 
        1.check whether the pointer is valid
        2.compute the absolute value for every element of an array
    */
    if (p != nullptr)
    {
        for (int i = 0; i < n; i++)
        {
            (*(p + i))= std::abs(*(p + i));
        }
        return true;
    }
    return false;
}

bool vabs(float *p, int n)
{
    if (p != nullptr)
    {
        for (int i = 0; i < n; i++)
        {
            (*(p + i))= std::abs(*(p + i));
        }
        return true;
    }
    return false;
}

bool vabs(double *p, int n)
{
    if (p != nullptr)
    {
        for (int i = 0; i < n; i++)
        {
            (*(p + i))= std::abs(*(p + i));
        }
        return true;
    }
    return false;
}