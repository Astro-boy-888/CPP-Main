#include <iostream>
int main()
{
	double f1 = 1.200;
	std::cout << "f1 = " << f1 << std::endl;
	std::cout << "f1 + 1.0/9.0 = " << f1 + 1.0/9.0 << std::endl;

	double f2 = 1.67E2;
	std::cout << "f2 = " << f2 << std::endl;
	
	double f3 = f2 + 1.0/9.0;
	std::cout << "f3 = " << f3 << std::endl;
	std::cout << "f3 * 1.0e10 + 100 = " << f3 * 1.0e10 + 100 <<std::endl;
	
	double f4 = 2.3e-4;
	std::cout << "f4 = " << f4 << std::endl;
	std::cout << "f4/10 = " << f4/10 <<std::endl;
	
	return 0;
    /*
    f1 = 1.2
    浮点类型不显示尾数0
    f1 + 1.0/9.0 = 1.31111
    总共显示6位有效数字
    f2 = 167
    默认以定点显示法显示
    f3 = 167.111
    f3 * 1.0e10 + 100 = 1.67111e+12
    f4 = 0.00023
    f4/10 = 2.3e-05
    当指数太大超过6或者小于-5时，会自动以E表示法显示
    */
}