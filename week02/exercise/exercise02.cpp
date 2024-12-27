#include <iostream>

int main() 
{
    int a = 56789 * 23456789;
    std::cout << "a = " << a << std::endl;
    /*
    warning: integer overflow in expression of type ‘int’ results in ‘647728761’ [-Woverflow]
    5 |     int a = 56789 * 23456789;
      |             ~~~~~~^~~~~~~~~~
    output: a = 647728761
    actual: a = 1.33209e12
    溢出导致结果错误，int类型最大值是2147483647，超过这个值就会出现溢出
    */
    long long b = 56789LL * 23456789LL;
    std::cout << "b = " << b << std::endl;
    /*
    output: b = 1332090000000
    正确输出，long long类型可以存储更大的整数
    注意：乘数和被乘数类型限定为long long类型，否则以int类型相乘会导致溢出，结果与a相同。
    */
    return 0;
}