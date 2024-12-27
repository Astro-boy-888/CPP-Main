#include <iostream>
#include <string>
using namespace std;

class Parent
{
private:
    int id;
    string name;
    
public:
    Parent():id(1),name("null")
    {
        cout << "callling default constructor Parent()" << endl;
    }
    Parent(int id, string name):id(id),name(name)
    {
        cout << "callling constructor Parent(int, string)" << endl;
    }

    friend ostream& operator<<(ostream& os, const Parent& p)
    {
        return os << "Parent: " << p.id << ", " << p.name<< endl;
    }
};

class Child : public Parent
{
private:
    int age;
public:
    Child():age(0)
    {
        cout << "callling Child default constructor Child()" << endl;
    }
    Child(int age):age(age)
    {
        cout << "callling Child default constructor Child(int)" << endl;
    }
    Child(const Parent& p, int age):Parent(p),age(age)
    {
        cout << "callling Child constructor Child(const Parent&, int)" << endl;
    }
    Child(const Child& c):Parent(c),age(c.age)
    {
        cout << "calling Child copy constructor Child(const Child&)" << endl;
    }

    friend ostream& operator<<(ostream& os, const Child& c)
    {
        return os << (Parent&)c << "Child: " << c.age << endl;  
    }

};

int main()
{
    Parent p(101,"Liming");
    Child c1(19);
    cout << "values in c1: \n" << c1 << endl;

    Child c2(p,20);
    cout << "values in c2: \n" << c2 << endl;

    Child c3 = c2;
    cout << "values in c3: \n" << c3 << endl;

    Child c4;
    cout << "Before assignment, values in c4: \n" << c4 << endl;

    c4 = c2;
    cout << "After assignment, values in c4: \n" << c4 << endl;
    
    return 0;

}