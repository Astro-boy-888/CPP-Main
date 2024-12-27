#include <iostream>
using namespace std;

int main()
{   
    int num_int1 = 9; // 初始化类型相同无需转换
    int num_int2 = 'C'; //  'C' ->char -> 8位ASCII码 -> int -> 32位整型 隐式类型转换
    int num_int3 = (int)'C'; // 显式类型转换 C-style 
    int num_int4 = int('C'); // 与上面等价 function style
    int num_int5 = 2.8; //舍弃小数部分，只保留整数部分，隐式类型转换
    float num_float = 2.3; // 常量是double类型，隐式类型转换
    short num_short = 650000; //650000 超出short范围，自动截断，结果为-5360

    cout << "num_short = " << num_short << endl;

    return 0;
}
