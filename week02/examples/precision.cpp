#include <iostream>
using namespace std;

int main()
{
    float f1 = 23400000000; //也可以写成2.34E+10f
    float f2 = f1 + 10;

    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << "f1 - f2 = " << f1 - f2 << endl;
    cout << "(f1 - f2 == 0) = " << (f1 - f2 == 0) << endl;
    // f1 = 23399999488.000000
    // f2 = 23399999488.000000
    // f1 - f2 = 0.000000 -> f2 = f1
    // (f1 - f2 == 0) = 1 -> f2 = f1
    // 浮点数之间进行比较判断时：但依旧存在误差，需要设置精度，相等时广义的相等。
    // if(f1 == f2) //bad
    // if(fabs(f1 - f2) < FLT_EPSILON) //good
    return 0;
}
