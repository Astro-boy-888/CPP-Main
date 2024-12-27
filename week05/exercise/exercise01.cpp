#include<stdio.h>
int main()
{
    int a[]={2,4,6,8,10},y=1,*p;
    p=&a[1];
    
    printf("a = %p\np = %p\n",a, p);
    
    for(int i = 0; i < 3; i++)
        y += *(p+i);
    
    printf("y = %d\n\n",y);

    int b[5]={1,2,3,4,5};
    int *ptr=(int*)(&b+1);
    
    printf("b = %p\nb+4 = %p\nptr = %p\n",b,b+4,ptr);
    printf("%d,%d\n",*(b+1),*(ptr-1));
    
    return 0;
}
/*
a = 0x7ffddf393fb0  //a是数组的首地址
p = 0x7ffddf393fb4  //p指向数组的第二个元素，输出的是地址值
y = 19              //y = 1 + 4+6+8 =19 后三个分别是数组的第二、第三、第四个元素

b = 0x7ffddf393fd0  //b是数组的首地址
b+4 = 0x7ffddf393fe0    //b+4指向数组的第五个元素，输出的是地址值
ptr = 0x7ffddf393fe4    //int *ptr=(int*)(&b+1); &b是整个数组的地址 
//&b+1将b的地址跳过整个数组大小，调到末尾之后的位置
//&b 是 int[5] 类型指针
//加 1 会移动 5 * sizeof(int) 字节，因此 ptr 指向数组 b 后一个元素的地址。
2,5


*/