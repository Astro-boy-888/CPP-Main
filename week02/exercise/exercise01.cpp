#include <stdio.h>

int main()
{
    signed char a = 127;
    unsigned char b = 0xff;
    unsigned char c = 0;
    a++;
    b++;
    c--;
    printf("a=%d\nb=%d\nc=%d\n",a,b,c);
    return 0;
    /*
    a=-128 char的范围是-128~127，a++后溢出
    b=0 unsigned char的范围是0~255，b的值为0xff，十六进制的ff，15*16+15=255，b++后溢出
    c=255 unsigned char的范围是0~255，c的值为0，c--后溢出
    */
}
