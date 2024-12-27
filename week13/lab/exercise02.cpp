#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Pair {
public:
    T1 key;
    T2 value;
    Pair(T1 k, T2 v) : key(k), value(v) { }

    // 运算符<的成员函数模板特化
    bool operator < (const Pair<T1,T2> & p) const;

    // 友元函数用于输出Pair
    friend ostream& operator << (ostream& os, const Pair<T1,T2>& p);
};

// 只为 Pair<string, int> 特化 operator<
template <>
bool Pair<string, int>::operator < (const Pair<string, int> & p) const {
    return this->key < p.key;
}

ostream& operator << (ostream& os, const Pair<string, int>& p) {
    os << p.key << " " << p.value;
    return os;
}

int main() {
    Pair<string, int> one("Tom", 19);
    Pair<string, int> two("Alice", 20);

    // 比较并输出较小的Pair
    if (one < two)
        cout << one;
    else
        cout << two;

    return 0;
}
