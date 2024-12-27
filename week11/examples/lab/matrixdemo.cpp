#include <iostream>
#include <memory>
#include "matrix.h"

int main()
{
    Matrix m1(3,8);
    Matrix m2(4,8);

    m2 = m1;
    m1.setElement(1,2, 4.5f);
    std::cout << m2.getElement(1,2) << std::endl;

    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;

    Matrix a(3,4);
    Matrix b(3,4);
    a.setElement(1,2, 3.0f);
    b.setElement(2,3, 4.0f);

    std::cout << "a is:" << std::endl;
    std::cout << a << std::endl;
    std::cout << "b is:" << std::endl;
    std::cout << b << std::endl;

    Matrix c = a + b;
    std::cout << "c is:" << std::endl;
    std::cout << c << std::endl;
    Matrix d = a;
    std::cout << "Before assignment,d is:" << std::endl;
    std::cout << d << std::endl;
    d = b;
    std::cout << "After assignment,d is:" << std::endl;
    std::cout << d << std::endl;

    return 0;
}