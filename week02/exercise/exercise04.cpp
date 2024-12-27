#include <iostream>
using namespace std;
int main()
{
    int a, b;
    double c, d;

    a = 19.99 + 21.99;
    b = (int)19.99 + (int)21.99;
    c = 23 / 8;
    d = 23 / 8.0;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "0/0= " << 0/0 << endl;
    
    /*
    a = 41  //a 的类型为int 加法运算结果为double，两个double类型相加，再自动转换为int
    b = 40  //b 的类型为int 两个强制转换的int类型相加,加法运算结果为int
    c = 2   //c 的类型为double 单数除法的除数和被除数都是int类型，除法的结果为int
    d = 2.875 //d 的类型为double 被除数是double类型，除法的结果为double
    浮点异常 (核心已转储) //0/0 运算结果为nan，nan是非数值，不能参与数值运算
    */
    return 0;
}