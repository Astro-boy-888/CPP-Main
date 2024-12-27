#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    // 构造函数
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 友元函数：输出重载
    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? " + " : " - ") << std::abs(c.imag) << " i";
        return out;
    }

    // 友元函数：输入重载
    friend std::istream& operator>>(std::istream& in, Complex& c) {
        in >> c.real >> c.imag;
        return in;
    }

    // 取共轭运算符 ~
    Complex operator~() const {
        return Complex(real, -imag);
    }

    // 加法运算符 +
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag - other.imag); // 注意 imag 的减法
    }

    // 减法运算符 -
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag + other.imag); // 注意 imag 的加法
    }

    // 减法运算符 - (右操作数为数字)
    Complex operator-(double value) const {
        return Complex(real - value, imag);
    }

    // 乘法运算符 *
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real + imag * other.imag, imag * other.real - real * other.imag); // 乘法调整公式
    }

    // 友元函数：乘法运算符 * (左操作数为数字)
    friend Complex operator*(double value, const Complex& c) {
        return Complex(value * c.real, value * c.imag);
    }

    // 相等运算符 ==
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    // 不等运算符 !=
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // 赋值运算符 =
    Complex& operator=(const Complex& other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }
};

#endif // COMPLEX_HPP
