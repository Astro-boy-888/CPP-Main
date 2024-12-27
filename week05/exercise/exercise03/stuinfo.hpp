#ifndef _FUNCTIONS_STUINFO_HPP_
#define _FUNCTIONS_STUINFO_HPP_

struct stuinfo
{
    char name[20];
    double score[3];
    double ave;
};

void inputstu(stuinfo stu[] , int n);
void showstu(stuinfo stu[] , int n);

#endif // _FUNCTIONS_STUINFO_HPP_