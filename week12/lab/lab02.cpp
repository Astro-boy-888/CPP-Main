#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    string ssn;
public:
    Employee(const string& n, const string& s) : name(n), ssn(s) 
    {
        cout << "The base class constructor is invoked." << endl;
    };

    ~Employee()
    {
        cout << "The base class destructor is invoked." << endl;
    };

    string getName() const{return name;};
    string getSSN() const{return ssn;};

    void setName(const string& n){name = n;};
    void setSSN(const string& s){ssn = s;};

    double earnings() const{};

    virtual void show()
    {
        cout << "Name is: " << name << "SSN is: " << ssn << endl;
    }
};

class SalariedEmployee : public Employee
{
private:
    double salary;

public:
    SalariedEmployee(const string& name, const string& ssn, double s) : Employee(name, ssn), salary(s)
    {
        cout << "The derived class constructor is invoked." << endl;
    };
    ~SalariedEmployee()
    {
        cout << "The derived class destructor is invoked." << endl;
    };

    SalariedEmployee(const Employee& e, double s) :Employee(e), salary(s){}

    double getSalary() const{return salary;};
    void setSalary(double s){salary = s;};

    double earning() const{getSalary();}

    void show()
    {
        cout << "Name is: " << getName() << "SSN is: " << getSSN() << "Salary is: " << salary << endl;
    }
};

// int main()
// {
//     Employee e("Liming", "1000");
//     SalariedEmployee se("Wangfang", "1001", 2000);

//     Employee* pe = &e;
//     pe->show();

//     pe = &se;
//     pe->show();
    
//     return 0;
// }

int main()
{
    Employee *pe = new SalariedEmployee("Wangfang", "1001", 2000);

    pe->show();

    delete pe;

    return 0;
}