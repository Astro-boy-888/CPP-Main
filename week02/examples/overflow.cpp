#include <iostream>
using namespace std;

int main()
{
    int a = 56789;
    int b = 56789;
    int c = a * b;
    cout << "c = " << c << endl;
    // 输出：c = -1069976775
    // 56789 --> 0xDDD5,16位无符号整数
    // 56789 * 56789 --> 0x1B9AC9B3,32位有符号整数
    // int 大部分系统为32位整数，因此溢出了
    // unsigned int c1 = a * b; //danger operation
    // cout << "c1 = " << c1 << endl;
    return 0;
}
