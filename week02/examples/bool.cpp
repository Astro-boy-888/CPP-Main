#include <iostream>
using namespace std;

int main()
{
    // bool是c++类型之一 占1个字节  true(1) or false(0) 
    // c语言中没有bool类型 需要引用头文件#include <stdbool.h>
    bool b1 = true;
    int i = b1;
    bool b2 = -256; //只要不是0 就是true(1) 但是不推荐这么写
    cout << "i=" << i << endl;
    cout << "b1=" << b1 << endl;
    cout << "b2=" << b2 << endl;
    cout << true << endl;
    return 0;
}