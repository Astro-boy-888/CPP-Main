#include <iostream>
using namespace std;
int main()
{   
    // 定长数组 注意初始化和溢出
    int num_array1[5]; //uninitialized array, random values 
    int num_array2[5] = {0, 1, 2, 3, 4}; //initialization

    for(int idx = 0; idx < 5; idx++)
        cout << num_array1[idx] << " ";
    cout << endl;

    for(int idx = 0; idx < 5; idx++)
        cout << num_array2[idx] << " ";
    cout << endl;

    return 0;
}
