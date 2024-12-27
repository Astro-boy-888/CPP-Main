#include <iostream>
#include "vabs.h"

using namespace std;

int main()
{
    int *pa1 = new int[20]{1,2,3,4,-1,-2,-3,-4};
    float *pa2 = new float[20]{1.0f,2.0f,3.0f,4.0f,-1.0f,-2.0f,-3.0f,-4.0f};
    double *pa3 = new double[20]{1,2,3,4,-1,-2,-3,-4};

    if (vabs(pa1,8))
    {
        cout << "int 数组全部元素已转换为正值" <<endl;
        for (int i = 0; i < 8; i++)
        {
            cout << "pa1["<< i <<"]" <<"的值为：" << *(pa1 + i) <<endl;
        }
    }
    else
    {
        cout << "int 数组绝对值转换失败" <<endl;
    }

    if (vabs(pa2,8))
    {
        cout << "float 数组全部元素已转换为正值" <<endl;
        for (int i = 0; i < 8; i++)
        {
            cout << "pa2["<< i <<"]" <<"的值为：" << *(pa2 + i) <<endl;
        }
    }
    else
    {
        cout << "float 数组绝对值转换失败" <<endl;
    }

    if (vabs(pa3,8))
    {
        cout << "double 数组全部元素已转换为正值" <<endl;
        for (int i = 0; i < 8; i++)
        {
            cout << "pa3["<< i <<"]" <<"的值为：" << *(pa3 + i) <<endl;
        }
    }
    else
    {
        cout << "double 数组绝对值转换失败" <<endl;
    }

    delete []pa1;
    delete []pa2;
    delete []pa3;

    return 0;
}