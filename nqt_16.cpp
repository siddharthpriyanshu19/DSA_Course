/* A teacher assigns grades to students based on their
marks using the following grading system:
Marks RangeGrade
90 – 100 A
80 – 89 B
70 – 79 C
60 – 69 D
50 – 59 E
0 – 49 F
< 0 or > 100 X (Invalid marks)
Your task is to:
1.Count the number of students in each grade
band.
2.Print the grade band having the maximum
number of students.

3.If all students have invalid marks, print X.
4.If multiple bands have the same maximum count,
print the higher-priority band using the following
priority:
A > B > C > D > E > F > X

Input Format
• The first line contains an integer N — the number
of students.
• The second line contains N space-separated
integers representing student marks.

Output Format
• Print the grade band with the maximum number
of students.

Constraints
1 ≤ N ≤ 10^5
-10^5 ≤ marks ≤ 10^5

Example 1
Input

7
95 87 92 45 55 78 82
Explanation
95 → A
87 → B
92 → A
45 → F
55 → E
78 → C
82 → B
Band counts:
A = 2
B = 2
C = 1
D = 0
E = 1
F = 1
X = 0
A and B both have the maximum count 2.
According to priority:
A > B
So output is:
Output

A */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> marks;
    string mark;
    while(getline(ss, mark, ' ')){
        marks.push_back(stoi(mark));
    }

    unordered_map<string, int> gradeCount;
    int maxele = 0;
    for(int i =0; i<n; i++){
        if(marks[i]>=90 && marks[i]<=100){
            gradeCount["A"]++;
            maxele = max(maxele, gradeCount["A"]);
        }
        else if(marks[i]>=80 && marks[i]<=89){
            gradeCount["B"]++;
            maxele = max(maxele, gradeCount["B"]);
        }
        else if(marks[i]>=70 && marks[i]<=79){
            gradeCount["C"]++;
            maxele = max(maxele, gradeCount["C"]);
        }
        else if(marks[i]>=60 && marks[i]<=69){
            gradeCount["D"]++;
            maxele = max(maxele, gradeCount["D"]);
        }
        else if(marks[i]>=50 && marks[i]<=59){
            gradeCount["E"]++;
            maxele = max(maxele, gradeCount["E"]);
        }
        else if(marks[i]>=0 && marks[i]<=49){
            gradeCount["F"]++;
            maxele = max(maxele, gradeCount["F"]);
        }
        else{
            gradeCount["X"]++;
        }
    }

    if(maxele == 0){
        cout<<"X";
    }
    else{
        vector<string> grades = {"A", "B", "C", "D", "E", "F"};
        for(string grade: grades){
            if(gradeCount[grade] == maxele){
                cout<<grade;
                break;
            }
        }
    }

    return 0;





}