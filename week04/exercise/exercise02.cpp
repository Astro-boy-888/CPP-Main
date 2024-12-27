#include <stdio.h>

union data{
    int n;
    char ch;
    short m;
};

int main()
{
    union data a;
    printf("%zu, %zu\n", sizeof(a), sizeof(union data) );
    a.n = 0x40;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
    a.ch = '9';
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
    a.m = 0x2059;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
    a.n = 0x3E25AD54;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
    return 0;
}

/*
warning:
ros2@ros2:~/cpp_ws/CPP-main/week04/exercise$ g++ exercise02.cpp 
exercise02.cpp: In function ‘int main()’:
exercise02.cpp:12:14: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long unsigned int’ [-Wformat=]
   12 |     printf("%d, %d\n", sizeof(a), sizeof(union data) );
      |             ~^         ~~~~~~~~~
      |              |         |
      |              int       long unsigned int
      |             %ld
exercise02.cpp:12:18: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘long unsigned int’ [-Wformat=]
   12 |     printf("%d, %d\n", sizeof(a), sizeof(union data) );
      |                 ~^                ~~~~~~~~~~~~~~~~~~
      |                  |                |
      |                  int              long unsigned int
      |                 %ld

output:
4, 4
40, @, 40
39, 9, 39
2059, Y, 2059
3E25AD54, T, AD54
*/