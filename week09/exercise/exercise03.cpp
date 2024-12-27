#include <iostream>
using namespace std;

class Complex {
private:
    double realPart;       // 实部
    double imaginaryPart;  // 虚部

public:
    // 默认构造函数
    Complex() : realPart(0), imaginaryPart(0) {}

    // 带参构造函数
    Complex(double realPart, double imaginaryPart) 
        : realPart(realPart), imaginaryPart(imaginaryPart) {}

    // 加法：对当前对象与另一个复数进行相加，返回结果
    Complex add(const Complex& other) const {
        return Complex(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
    }

    // 减法：对当前对象与另一个复数进行相减，返回结果
    Complex subtract(const Complex& other) const {
        return Complex(realPart - other.realPart, imaginaryPart - other.imaginaryPart);
    }

    // 显示当前复数
    void display() const {
        if (imaginaryPart > 0)
            cout << realPart << " + " << imaginaryPart << "i" << endl;
        else if (imaginaryPart < 0)
            cout << realPart << " - " << -imaginaryPart << "i" << endl;
        else
            cout << realPart << endl;
    }

    // 析构函数
    ~Complex() {
        // 无动态资源分配，不需要特殊处理
    }
};

int main() {
    // 创建两个复数对象
    Complex c1(3.5, 4.2);
    Complex c2(1.1, -2.3);

    // 加法操作
    Complex c3 = c1.add(c2);
    cout << "c1 + c2 = ";
    c3.display();

    // 减法操作
    Complex c4 = c1.subtract(c2);
    cout << "c1 - c2 = ";
    c4.display();

    return 0;
}
