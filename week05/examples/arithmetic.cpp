#include <iostream>
using namespace std;

// 以下是宏定义，用来打印数组内容，不是函数，实际上是一行代码 
// 中间的\是转义符,
// n加括号和array处加括号是
// 防止如果在n处和array处进行运算，要写其他的表达式，其优先级低于<判断，会导致错误
// 宏定义中的参数常加括号这是一个技巧。
#define PRINT_ARRAY(array, n) \
for (int idx = 0; idx < (n); idx++) \
    cout << "array[" << idx << "] = " << (array)[idx] << endl;

int main()
{
    int numbers[4] = {0, 1, 2, 3};
    PRINT_ARRAY(numbers, 4)

    int * p = numbers + 1; // point to the element with value 1
    p++; // point to the element with value 2

    cout << "numbers = " << numbers << endl;
    cout << "p = " << p << endl;

    *p = 20; //change number[2] from 2 to 20
    *(p-1) = 10; //change number[1] from 1 to 10
    p[1] = 30; //change number[3] from 3 to 30

    PRINT_ARRAY(numbers, 4)

    return 0;
}