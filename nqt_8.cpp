/*Question 1: Total Marks of a Student
Problem Statement
You are given a 2D matrix representing
marks of students. Each row represents a
student, and each column represents marks
in exams:
• Column 0 → Internal exam marks
• Column 1 → External exam marks
You are also given an index (i, j)
representing a student’s position in the
matrix.
Task
Calculate the total marks (internal +
external) of the student at the given index.*/

#include <iostream>
#include <vector>   

using namespace std;

int main(){
    int n,m;
    cout<<"Enter the number of students and exams: ";
    cin>>n>>m;
    vector<vector<int>> marks(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<"Enter marks of student "<<i<<" in exam "<<j<<": ";
            cin>>marks[i][j];
        }
    }


    int i,j;
    cout<<"Enter the index of the student (row and column): ";
    cin>>i>>j;
    cout<<"Total marks of student at index ("<<i<<","<<j<<") is: "<<marks[i][0]+marks[i][1];

    return 0;
}