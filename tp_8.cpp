/* Microsoft OA*/
/*Given the initial setup of a match between two players, evaluate the match's outcome.

There are two players, and there is a number sequence of size n. Players alternate turns for n rounds. Each round, a player removes the first number from the sequence and adds its value to their score. After that, if the removed number is even, the remaining sequence is reversed.

Determine the difference in scores between the two players after the game.

More precisely, suppose first_score and second_score are the final scores of the first and second player, respectively. The goal is to calculate the value of:

first_score - second_score*/


#include <iostream>
#include <vector>

using namespace std;

class Solution{
 public:
       int solve(vector<int> &nums){
        int n = nums.size();
        if(n==0 || n==1) return nums[0];
        int p1=0;int p2=0;
        int start=0;
        int end=n-1;
        int turn=1;
        bool reverse=false;
        int selected=0;
        while(start<end){
            if(turn%2 != 0){
                if(reverse){
                    p1 += nums[end];
                    selected = nums[end];
                    end--;;
                }
                else{
                    p1 += nums[start];
                    selected = nums[start];
                    start++;
                }
            }
            else{
                if(reverse){
                    p2 += nums[end];
                    selected = nums[end];
                    end--;
                }
                else{
                    p2 += nums[start];
                    selected = nums[start];
                   start++;
                }
            }

            if(selected%2==0){
                reverse = !reverse;
            }
            turn ++;

        }
        return p1-p2;
    }
};

int main(){
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    Solution s;
    cout<<s.solve(nums);    
    return 0;
}