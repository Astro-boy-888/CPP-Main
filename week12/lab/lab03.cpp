#include <iostream>
#include <cstring>
using namespace std;

//基类
class Parent 
{
private:
    int id;
    char* name; //数据字段包含指针 --> 需要动态内存管理
    
public:
    Parent(int i = 0,const char* n = "null");
    Parent(const Parent& p);
    virtual ~Parent();
    Parent& operator=(const Parent& prhs);

    friend ostream& operator<<(ostream& os, const Parent& p);
};

//子类
class Child : public Parent
{
private:
    char* style;//数据字段包含指针 --> 需要动态内存管理
    int age;
public:
    Child(int i = 0,const char* n = "null",const char* s = "null", int a = 0);
    Child(const Child& c);
    ~Child();
    Child& operator=(const Child& crhs);

    friend ostream& operator<<(ostream& os, const Child& c);  
};

//基类的构造函数
Parent::Parent(int i ,const char* n ) 
{
    cout << "calling parent default constructor Parent()\n" ;
    id = i;
    name  =  new char[std::strlen(n) + 1];
    strcpy(name, n);
}

//子类的构造函数 
//--> 基类定义的相关数据直接继承，用基类的构造函数进行定义
Child::Child(int i, const char* n, const char* s, int a) : Parent(i, n)
{
    cout << "calling child default constructor Child()\n" ;
    style = new char[std::strlen(s) + 1];
    strcpy(style,s);
    age = a;
}
//基类的析构函数
Parent::~Parent()
{
    cout << "calling parent destructor\n";
    delete[] name;
}

//子类的析构函数 
//子类析构函数会自动调用基类析构函数，
//基类析构函数的职责就是在子类析构函数执行完操作后进行清理。
Child::~Child()
{
    cout << "calling child destructor\n";
    delete[] style;
}

//基类的拷贝构造函数 
Parent::Parent(const Parent& p)
{
    cout << "calling parent copy constructor Parent(const Parent& p)\n";
    id = p.id;
    name = new char[std::strlen(p.name) + 1];
    strcpy(name, p.name);
}

//派生类的复制构造函数只能访问其自己的数据，
//因此它必须调用基类的复制构造函数来处理基类共享的数据。
//成员初始化列表将 Child 引用传递给 Parent 构造函数。
//Parent 复制构造函数具有 Parent 引用参数，而基类引用可以引用派生类型。
//因此，Parent 复制构造函数使用 Child 参数的 Parent 部分来构造新对象的 Parent 部分。
Child::Child(const Child& c) : Parent(c)
{
    cout << "calling child copy constructor Child(const Child& c)\n";
    style = new char[std::strlen(c.style) + 1];
    strcpy(style, c.style);
    age = c.age;
}

//基类的赋值运算符重构
Parent& Parent::operator=(const Parent& prhs)
{
    cout << "calling parent assignment operator Parent& Parent::operator=(const Parent& prhs)\n";
    if (this == &prhs)
        return *this;
    delete[] name;
    this->id = prhs.id;
    name = new char[std::strlen(prhs.name) + 1];
    strcpy(name,  prhs.name);
    return *this;
}

//子类的赋值运算符重构
//由于 Child 使用动态内存分配，因此需要显式赋值运算符。
//作为 Child 方法，它只能直接访问自己的数据。
//子类的显式赋值运算符还必须负责继承的基类 Parent 对象的赋值。
//您可以通过显式调用基类赋值运算符来完成此操作。
Child& Child::operator=(const Child& crhs)
{
    cout << "calling child assignment operator Child& Child::operator=(const Child& crhs)\n";
    if (this == &crhs)
        return *this;
    Parent::operator=(crhs);
    
    delete[] style;
    style = new char[std::strlen(crhs.style) + 1];
    strcpy(style, crhs.style);
    age = crhs.age;
    return *this;
}
ostream& operator<<(ostream& os, const Parent& p)
{
    os << "ID: " << p.id << ", Name: " << p.name;
    return os;
}

ostream& operator<<(ostream& os, const Child& c)
{
    os << Parent::operator<<(c) 
       << ", Style: " << c.style 
       << ", Age: " << c.age;
    return os;
}

int main()
{
    Parent p1;
    cout << "values in p1: \n" << p1 << endl;
    Parent p2(101, "Liming");
    cout << "values in p2: \n" << p2 << endl;

    Parent p3(p1);
    cout << "values in p3: \n" << p3 << endl;
    p1 = p2;
    cout << "values in p1: \n" << p1 << endl;

    Child c1;
    cout << "values in c1: \n" << c1 << endl;
    Child c2(201, "Wuhong", "teenager", 15);
    cout << "values in c2: \n" << c2 << endl;
    Child c3(c1);
    cout << "values in c3: \n" << c3 << endl;
    c1 = c2;
    cout << "values in c1: \n" << c1 << endl;

    return 0;
}