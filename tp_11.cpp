#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int i = 0;
        int j = 0;
        int maxlen = 1;
        unordered_map<int, int> temp;
        int len = 0;

        while (j < n) {
            if (temp.find(nums[j]) == temp.end()) {
                temp[nums[j]] = j;
                len = j - i + 1;
                maxlen = max(maxlen, len);
                j++; // Fix 1: Advance j when element is unique
            } 
            else {
                int id = temp[nums[j]];
                while (i <= id) {
                    temp.erase(nums[i]); // Fix 2: Erase nums[i], not nums[j]
                    i++;                 // Fix 3: Increment i to avoid infinite loop
                }
                temp[nums[j]] = j;
                j++;
            }
        }
        return maxlen;
    }
};