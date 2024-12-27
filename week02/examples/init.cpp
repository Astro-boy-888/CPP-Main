#include <iostream>
using namespace std;
int main()
{
    // 每次都要初始化变量
    int num1; //bad: uninitialized variable
    int num2; //bad: uninitialized variable
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
}
