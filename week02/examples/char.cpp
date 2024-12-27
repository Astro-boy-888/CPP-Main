#include <iostream>
using namespace std;

int main()
{
    // char是一个整数
    // char类型可以存储ASCII码值，也可以存储Unicode码值
    char c1 = 'C';
    char c2 = 80; // ASCII码值80对应的字符
    char c3 = 0x50; //ASCII码值0x50(十六进制)对应的字符
    // 中文字符需要使用Unicode编码，
    // 如'于'对应的Unicode码值是20110，可以用char16_t或char32_t类型存储
    char16_t c4 = u'于';
    char32_t c5 = U'于';
    cout << c1 << ":" << c2 << ":"<< c3 << endl;
    // 输出c1、c2、c3的值 在char类型的实参上加上+号可以强制类型转换为对应的整型值
    cout << +c1 << ":" << +c2 << ":" << +c3 << endl;
    cout << c4 << endl;
    cout << c5 << endl;
    
    return 0;
}

