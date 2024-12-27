#include <iostream>
#include "stuinfo.hpp"

using namespace std;

void inputstu(stuinfo stu[] , int n)
{   
    // TODO:
    // Asks the user to enter each of the preceding items of
    // information to set the corresponding members of the structure 
    // and compute the average score for each student.

    for (int i = 0; i < n; i++)
    {   
        cout << "Enter the name of student " << i+1 << ": "<< endl;
        cin >> stu[i].name ;
        cout << "Enter the scores of student " << i+1 << ": "<< endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "Subject " << j+1 << ": ";
            cin >> stu[i].score[j];
        }
        stu[i].ave = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2])/3.0;
    }
}

void showstu(stuinfo stu[] , int n)
{   
    // TODO:
    // Displays the contents of the structure, one student one line.

    for (int i = 0; i < n; i++)
    {
        cout << "Name: " << stu[i].name;
        cout << " Scores: " << stu[i].score[0] << " " << stu[i].score[1] << " " << stu[i].score[2] ;
        cout << " Ave: " << stu[i].ave << endl;
    }
    
}