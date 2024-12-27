#include <iostream>
using namespace std;
int main()
{

    int num_array1[5] = {0,1}; // fixed length array, initialized to {0,1,0,0,0}  
    cout << "sizeof(num_array1) = " << sizeof(num_array1) << endl;

    // “变长”数组，并不是真正意义上的变长，只是将长度设置为一个未初始化的变量，在循环中进行数组定义
    int len = 1;
    while ( len < 10 )
    {
        int num_array2[len]; //variable-length array
        cout << "len = " << len;
        cout << ", sizeof(num_array2)) = " << sizeof(num_array2) << endl;
        len ++;
    }
}