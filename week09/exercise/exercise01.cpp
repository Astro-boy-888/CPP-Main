#include <iostream>
using namespace std;

class Demo
{
	public :
	inline static int num =0;
	static void display()
	{
    num++;
	cout << "The value of the static member variable num is: " << num <<endl;
	}
};

int main()
{
    Demo::display();
	Demo obj;
	obj.display();
	return 0;
}