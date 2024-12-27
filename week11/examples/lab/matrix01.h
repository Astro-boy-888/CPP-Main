#pragma once
#include <iostream>
#include <memory>

class Matrix
{
private:
    size_t rows;
    size_t cols;
    float data[];

public:
    // 构造函数
    Matrix(size_t r, size_t c)
    {
        
    }

    // 拷贝构造函数
    Matrix(const Matrix &m) 
    {
    }
    
    // 赋值运算
    Matrix & operator=(Matrix & m)
		{
		}
		
    // 矩阵加法运算符
    Matrix operator+(const Matrix &m) const
    {
    }

    // 设置元素
    Matrix &setElement(size_t r, size_t c, float value)
    {
    }

    // 获取元素
    float getElement(size_t r, size_t c) const
    {
    }

    // 输出矩阵
    friend std::ostream &operator<<(std::ostream &os, const Matrix &m)
    {

    }
};
