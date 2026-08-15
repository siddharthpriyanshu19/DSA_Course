/*  During a break in the buffet of the scientific lyceum of the Kingdom of Kremland, there was formed a queue of n
 high school students numbered from 1
 to n
. Initially, each student i
 is on position i
. Each student i
 is characterized by two numbers — ai
 and bi
. Dissatisfaction of the person i
 equals the product of ai
 by the number of people standing to the left of his position, add the product bi
 by the number of people standing to the right of his position. Formally, the dissatisfaction of the student i
, which is on the position j
, equals ai⋅(j−1)+bi⋅(n−j)
.

The director entrusted Stas with the task: rearrange the people in the queue so that minimize the total dissatisfaction.

Although Stas is able to solve such problems, this was not given to him. He turned for help to you.

Input
The first line contains a single integer n
 (1≤n≤105
) — the number of people in the queue.

Each of the following n
 lines contains two integers ai
 and bi
 (1≤ai,bi≤108
) — the characteristic of the student i
, initially on the position i
.

Output
Output one integer — minimum total dissatisfaction which can be achieved by rearranging people in the queue.*/

// intuion is to separate the dissatisfaction into two parts basically constant and variable part and minimise the variable part.


class Student {
public:

Student(vector<int> &a, vector<int> &b){
    int n = a.size();
    vector<int> diff(n+1);
    vector<int> idx(n+1);


    for(int i=1 i<n; i++){
        diff.push_back(a[i]-b[i]);
        idx.push_back(i);
    }

    sort(idx.begin(), idx.end()); //sorting the indices in asc order
    sort(diff.begin(), diff.end(), greater<int>()); //sorting the differences in desc order

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += diff[i]*idx[i]+ b[i]*n-a[i]; //total dissatisfactiuon
    }
    return sum;
}