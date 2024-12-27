#pragma once
#include <iostream>
#include <memory>

class Matrix
{
private:
    size_t rows;
    size_t cols;
    std::shared_ptr<float[]> data;

public:
    // 构造函数
    Matrix(size_t r, size_t c)
    {
        if (r * c == 0)
        {
            rows = 0;
            cols = 0;
            data = nullptr;
        }
        else
        {
            rows = r;
            cols = c;
            data = std::shared_ptr<float[]>(new float[r * c]());
        }
    }

    // 拷贝构造函数
    Matrix(const Matrix &m) : rows(m.rows), cols(m.cols), data(m.data) {}

    // 矩阵加法运算符
    Matrix operator+(const Matrix &m) const
    {
        if (rows != m.rows || cols != m.cols)
        {
            throw std::invalid_argument("Matrix dimensions must match for addition.");
        }

        Matrix result(rows, cols);
        for (size_t i = 0; i < rows * cols; ++i)
        {
            result.data[i] = data[i] + m.data[i];
        }
        return result;
    }

    // 设置元素
    Matrix &setElement(size_t r, size_t c, float value)
    {
        if (r >= rows || c >= cols)
        {
            throw std::out_of_range("Index out of bounds.");
        }
        data[r * cols + c] = value;
        return *this;
    }

    // 获取元素
    float getElement(size_t r, size_t c) const
    {
        if (r >= rows || c >= cols)
        {
            throw std::out_of_range("Index out of bounds.");
        }
        return data[r * cols + c];
    }

    // 输出矩阵
    friend std::ostream &operator<<(std::ostream &os, const Matrix &m)
    {
        os << "size (" << m.rows << "x" << m.cols << ")" << std::endl;
        os << "[" << std::endl;
        for (size_t r = 0; r < m.rows; ++r)
        {
            for (size_t c = 0; c < m.cols; ++c)
            {
                os << m.data[r * m.cols + c];
                if (c < m.cols - 1) os << ", ";
            }
            os << std::endl;
        }
        os << "]";
        return os;
    }
};
