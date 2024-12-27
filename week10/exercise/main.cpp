#include <iostream>
#include "exercise01.hpp"

using namespace std;

int main()
{
    Complex a(3,4);
    Complex b(2,6);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "~b = " << ~b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a - 2 = " << a - 2 << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "2 * a = " << 2 * a << std::endl;
    std::cout << "================================" << std::endl;

    Complex c = b;
    cout << "c = " << c << endl;
    cout << "b == c? " << boolalpha << (b == c) << endl;
    cout << "b != c? " << boolalpha << (b!= c) << endl;
    cout << "a == b? " << boolalpha << (a == b) << endl;
    std::cout << "================================" << std::endl;

    Complex d;
    cout <<"Enter a complex number(real part and imaginary part): " ;
    cin >> d;
    cout << "before assignment: d = " << d << endl;
    d = c;
    cout << "after assignment: d = " << d << endl;
}