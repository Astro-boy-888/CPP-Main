#include <iostream>
using namespace std;

int main()
{
    // size_ts是一种用于表示大小或计数的无符号整数类型，通常用于表示对象的大小（例如数组或容器的大小）。
    // size_t 的实际大小取决于具体的系统和编译器，通常为 32 位或 64 位。
    for(size_t n = 2; n >= 0; n--)
    cout << "n = " << n << " ";
    return 0;
}