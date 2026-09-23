/* You work as a consultant and have clients in cityA and cityB. On a given day,
say i, you can either
work in cityA and make Ai dollars or you can work in cityB and make Bi dollars. You can also spend
the day traveling between cityA and cityB in which case your earnings that day are 0.

 

Given Al,A2, ....An and B1, B2,....., Bn, return a schedule S of N days which maximizes your earnings,
You can start either in cityA or cityB.

You need to print the final maximum earning

Example1: A = [23, 4,5 ,101] B = [21,1,10, 100] The optimal schedule S here would be ->"ATBB"
Example 2:
A[25,10,15,10,70] B = [5,5,50,5,30] The optimal schedule S here would be-> "ATBTA"

Follow up :-> solve the problem for 3 cities A,B,C

All dollars are positive!*/

#include <iostream> 
#include <vector>
using namespace std;

class Solution{
    public:
        int solve(vector<int> &A, vector<int> &B, int n){
            vector<vector<int>> dp(n+1,vector<int>(2,0));
            //dp[i][1]---> max earning if there are only i indices are we for sure end at cityA 
            //dp[i][2]---> max earning if there are only i indices are we for sure end at cityB 
            dp[1][1] = A[1];
            dp[1][2] = B[1];

            for(int i=2; i<=n; i++){
                dp[i][1] = max(A[i]+dp[i-1][1], A[i]+dp[i-2][2]);
                dp[i][2] = max(B[i]+dp[i-1][2],B[i]+dp[i-2][1]);

            }

            return max(dp[n][1],dp[n][2]);




    }
};

int main(){
    cout<<"Enter no of test cases";
    int T;
    cin>>T;
    while(T--){
        cout<<"enter no. of days";
        int n;
        cin>>n;
        vector<int> A(n,0);
        vector<int> B(n,0);
        for(int i=0; i<n; i++){
            cout<<"enter earning in city A on day "<<i+1;
            cin>>A[i];
        }
        for(int i=0; i<n; i++){
            cout<<"enter earning in city B on day "<<i+1;
            cin>>B[i];
        }
        Solution s;
        cout<<s.solve(A,B,n)<<endl;
    }
    return 0;
    
}