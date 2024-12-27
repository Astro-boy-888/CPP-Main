#include <iostream>
#include "fib.hpp"
using namespace std;

int main()
{
    int n = 1;

    cout << "Please input a positive integer: ";
    cin >> n;

    if (n >= 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << fib(i) << " ";
        }
        cout << endl;
    }
    else
        return 0;

    return 0;
}