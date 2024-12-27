#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float f1 = 1.2f;
    float f2 =  f1 * 1000000000000000;
    cout << std::fixed << std::setprecision(15) << f1 << endl;
    cout << std::fixed << std::setprecision(1) << f2 << endl;
    /*
    输出：
    1.200000047683716
    1200000038076416.0
    出现两个问题：
    1. f1输出结果怎么会不是准确的1.2？
    2. f2输出结果怎么会和预期不符？
    思考一下问题：
    1.[0,1]区间内有多少数？ -> 无数个！
    2.32位能代表多少个数字？ -> 2^23 
    那1.2在32位内能表示很多值。
    float始终不是精确的，所以输出结果可能不准确。->需要设置精度 -> precision.cpp
    */
    return 0;
}
