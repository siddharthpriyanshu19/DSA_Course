/* Given an array of all integers>=0 -> find the largest subarray whose sum is <= k 
*/

#include <iostream>
#include <vector>

using namespace std;

class solution{
    public :
    int solve(vector<int> &nums,int k)[
        int n = nums.size();
        int sum = 0;
        int maxlen = 0;
        int count = 0;
        for(int i=0, j =0; j<n; j++){
            sum += nums[j];
            while(sum>k){
                sum -= nums[i];
                i++;
            }
            count += j-i+1;
            maxlen = max(maxlen, count);


        }
        return maxlen;

    ]
};

