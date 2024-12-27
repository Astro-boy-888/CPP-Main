#pragma once
#include <iostream>

using namespace std;

class Complex {
private:
    int realPart;       // 实部
    int imaginaryPart;  // 虚部

public:
    // 默认构造函数
    Complex() : realPart(0), imaginaryPart(0) {}

    // 带参构造函数
    Complex(int realPart, int imaginaryPart) 
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
            std::cout << realPart << " + " << imaginaryPart << "i" << std::endl;
        else if (imaginaryPart < 0)
            std::cout << realPart << " - " << -imaginaryPart << "i" << std::endl;
        else
            std::cout << realPart << std::endl;
    }

    // 友元函数：重载输出流<<运算符
    friend std::ostream & operator<<(std::ostream & os, const Complex & a)
    {   
        std::string str = std::to_string(a.realPart); 
        if (a.imaginaryPart > 0)
            str = std::to_string(a.realPart) + " + " 
                + std::to_string(a.imaginaryPart) + " i";
        if (a.imaginaryPart < 0)
        {
            str = std::to_string(a.realPart) + " - " 
                + std::to_string(-a.imaginaryPart) + " i";
        }              
        os << str;
        return os;
    }

    // 友元函数：重载输入流>>运算符
    friend std::istream & operator>>(std::istream & is, Complex & a)
    {
        is >> a.realPart >> a.imaginaryPart;
        return is;
    }

    //重载~运算符用于析构对象
    Complex& operator~()
    {
        this->imaginaryPart = -this->imaginaryPart;
        return *this;
    }

    //重载+运算符用于复数的相加
    Complex operator+(const Complex & b) const
    {
        Complex sum;
        sum.realPart = this->realPart + b.realPart;
        sum.imaginaryPart = this->imaginaryPart + b.imaginaryPart;
        
        return sum;
    }

    //重载-运算符用于复数的相减
    Complex operator-(const Complex & b) const
    {
        Complex dif;
        dif.realPart = this->realPart - b.realPart;
        dif.imaginaryPart = this->imaginaryPart - b.imaginaryPart;
        
        return dif;
    }

    //重载-运算符用于复数减去int
    Complex operator-(int m) const
    {
        Complex dif;
        dif.realPart = this->realPart - m;
        dif.imaginaryPart = this->imaginaryPart;
        return dif;
    }

    //重载*运算符用于复数的相乘
    Complex operator*(const Complex & b) const
    {
        Complex pro;
        pro.realPart = (this->realPart * b.realPart)
                     - (this->imaginaryPart * b.imaginaryPart);  
        pro.imaginaryPart = (this->realPart * b.imaginaryPart)
                          + (this->imaginaryPart * b.realPart);
        return pro;
    }

    //友元函数：重载*运算符用于int与复数的相乘
    friend Complex operator*(int m, const Complex & b)
    {
        Complex cm;
        cm.realPart = m;
        cm.imaginaryPart = 0;
        return cm * b;
    }

    //重载==运算符用于判断两个复数是否相等
    bool operator==(const Complex & b) const
    {
        if (this->realPart == b.realPart && this->imaginaryPart == b.imaginaryPart)
        {
            return true;
        }
        return false;
    }

    //重载!=运算符用于判断两个复数是否不相等
    bool operator!=(const Complex & b) const
    {
        if (this->realPart != b.realPart || this->imaginaryPart != b.imaginaryPart)
        {
            return true;
        }
        return false;
    }

    //重载=运算符用于复数的赋值
    Complex& operator=(const Complex & b)
    {
        this->realPart = b.realPart;
        this->imaginaryPart = b.imaginaryPart;
        return *this;
    }

    // 析构函数
    ~Complex() {
        // 无动态资源分配，不需要特殊处理
    }
};