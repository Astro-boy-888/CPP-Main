#include <iostream>
using namespace std;

void create_array(int size, int* &arr) {
    arr = new int[size];  // 使用 new 动态分配内存

    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }
}

int main() {
    int len = 16;
    int* ptr = nullptr;  // 声明一个指针变量
    create_array(len, ptr);

    for (int i = 0; i < len; i++) {
        cout << ptr[i] << " ";
    }

    delete[] ptr;  // 释放动态分配的内存
    return 0;
}
