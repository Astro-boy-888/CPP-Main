#include <iostream>
// #include <cmath>  // 引入 fabs 函数

using namespace std;
int main()
{
    cout << fixed;
    float f1 = 1.0f;
    cout<<"f1 = "<<f1<<endl;

    float a = 0.1f;
    float f2 = a+a+a+a+a+a+a+a+a+a;
    cout<<"f2 = "<<f2<<endl;

    if(f1 == f2)
        cout << "f1 = f2" << endl;
    else
        cout << "f1 != f2" << endl;

    /*
    f1 = 1.000000
    f2 = 1.000000
    f1 != f2
    浮点数运算无法做到完全精确，因此两个浮点数相等的判断并不一定准确。
    需要引入忍耐度来判断两个浮点数是否相等。
    */
   
    // 定义一个小的 epsilon
    // float epsilon = 1e-6f;
    
    // 使用绝对值差进行比较
    // if (std::fabs(f1 - f2) < epsilon)
    //     std::cout << "f1 大致等于 f2" << std::endl;
    // else
    //     std::cout << "f1 不等于 f2" << std::endl;

    return 0;
}

