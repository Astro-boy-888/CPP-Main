/*

    Exercise 1:
    Write a program to initialize three variables which equal to 0.1, 0.2, 0.3, 
    then print them with two decimal points.

*/

#include <iostream>
#include <iomanip>

using namespace std;
int main() 
{
    float a = 0.1;
    float b = 0.2;
    float c = 0.3;
    // 设置浮点数以固定的小数位数显示 精度为2
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    return 0;
}