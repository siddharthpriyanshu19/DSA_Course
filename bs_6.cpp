/*P0 :- Given a sorted array of 0’s and 1’s find the first occurrence of 1 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
      int solve(vector<int> &nums){

        int n = nums.size();

        if(nums[0]==1) return 0;

        int low = 1;
        int high = n-1;


        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==1 && nums[mid-1]==0){
                return mid;
            }
            else if(nums[mid]==0){
                low = mid+1;
            }
            else{
                high = mid-1;
            }

        }

    }
};

      
