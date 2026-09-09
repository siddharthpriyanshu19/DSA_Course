/* An array of costs was given. 
You always start at index 1. 
You can either take two jumps forward or one jump backward. If you land on a particular index, you have to add the cost to your total. 
Find the minimum cost needed to cross the array or reach the end of the array.
You can visit any index for only 1 time.*/


#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
           int solve(vector<int> &nums){
            int n = nums.size();    
            vector<vector<int>> dp(n+2, vector<int>(3, -1));
            //dp[i][1] -> backward jump 
            //dp[i][2] -> forward jump

            dp[1][1] = INT_MAX;
            dp[1][2] = nums[1];
            dp[2][2] = INT_MAX;
            dp[2][1] = dp[1][2] + nums[3]+nums[2];

            int i = 3;
            while(i<=n){
                dp[i][1] = dp[i-1][2] + nums[i+1]+nums[i];
                dp[i][2] = nums[i]+min(dp[i-2][1], dp[i-2][2]); 
                i++;
            }

            return min({dp[n][1], dp[n-1][2], dp[n-1][1]});   

        }
};

int main(){
    Solution s;
    cout<<"Enter the size of the array: ";  
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i=1; i<=n; i++){
        cin>>nums[i];
    }
    cout<<s.solve(nums);


    return 0;
}