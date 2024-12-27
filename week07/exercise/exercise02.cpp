#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T>
int Compare(const T &a, const T &b)
{
    if (a > b)
    {
        return 1;
    }
    else if (a == b)
    {
        return 0;
    }
    else if (a < b)
    {
        return -1;
    }
    return 0; // Add return value for cases when no condition matches
}

// 实例化函数模板
template int Compare<int>(const int&, const int&);
template int Compare<float>(const float&, const float&);
template int Compare<char>(const char&, const char&);

struct stuinfo {
    string name;
    int age;
};

// 特化模板用于 stuinfo 类型的比较
template<>
int Compare(const stuinfo &a, const stuinfo &b)
{
    if (a.age > b.age)
    {
        return 1;
    }
    else if (a.age == b.age)
    {
        return 0;
    }
    else if (a.age < b.age)
    {
        return -1;
    }
    return 0; // Add return value for cases when no condition matches
}

int main()
{
    auto a1 = Compare(2, 3);
    cout << "Compare of the two integers: " << a1 << endl;  

    auto a2 = Compare(3.0f, 2.0f);
    cout << "Compare of the two floats: " << a2 << endl;

    auto a3 = Compare('c', 'b');
    cout << "Compare of the two characters: " << a3 << endl;

    stuinfo a{"xiaoming", 10};
    stuinfo b{"xiaozhu", 8};
    auto a4 = Compare(a, b);
    cout << "Compare of the two structs: " << a4 << endl;

    return 0;
}
