#include <iostream>
int main()
{
    auto a = 10;
    a = 20.5;
    a += 10.5;

    std::cout << a << std::endl;

    /*
    output: 30
    auto 自动类型推断，a 被推断为 int 类型，之后运行的均为 int加法运算，结果为 30
    */
   
    return 0;
}