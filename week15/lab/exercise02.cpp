#include <iostream>
#include <typeinfo>
using namespace std;

// 基类
class Base {
protected:
    int bvalue; // 基类的成员变量

public:
    // 构造函数
    Base(int i) : bvalue(i) {}

    // 虚函数，用于比较基类对象是否相等
    virtual bool equal(const Base& b) const {
        return bvalue == b.bvalue;
    }

    // 友元函数，重载 == 操作符
    friend bool operator==(const Base& lhs, const Base& rhs) {
        // 如果类型不同，则抛出异常
        if (typeid(lhs) != typeid(rhs)) {
            throw "The two objects have different types, they cannot be compared.";
        }
        // 如果类型相同，调用 virtual equal 函数进行比较
        return lhs.equal(rhs);
    }
};

// 派生类，继承自 Base 类
class Derived : public Base {
private:
    int dvalue; // 派生类的额外成员变量

public:
    // 构造函数
    Derived(int a, int b) : Base(a), dvalue(b) {}

    // 重写虚函数，用于比较派生类对象是否相等
    virtual bool equal(const Base& b) const override {
        // 使用 dynamic_cast 将 Base 类型转换为 Derived 类型
        const Derived* d = dynamic_cast<const Derived*>(&b);
        if (d) {
            // 如果转换成功，比较 bvalue 和 dvalue
            return bvalue == d->bvalue && dvalue == d->dvalue;
        }
        return false;
    }
};

// 普通函数，比较两个 Base 类型的对象并处理异常
void process(const Base& obj1, const Base& obj2) {
    try {
        if (obj1 == obj2) {
            cout << "The objects are equal." << endl;
        } else {
            cout << "The objects are not equal." << endl;
        }
    } catch (const char* msg) {
        cout << "Exception: " << msg << endl;
    }
}

// 测试代码
int main() {
    Base b1(2);
    Base b2(2);
    Derived d1(1, 2);
    Derived d2(2, 2);

    // 比较两个 Base 对象
    process(b1, b2);

    // 比较两个 Derived 对象
    process(d1, d2);

    // 比较 Base 对象和 Derived 对象
    process(b1, d1);

    return 0;
}
