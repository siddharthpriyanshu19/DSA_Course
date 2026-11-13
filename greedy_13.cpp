#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxsum = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            int val = 1;
            for (int j = i; j < n; j++) {
                sum += nums[j] * val;
                val++;
            }
            maxsum = max(maxsum, sum);

            // Once we include all non-negative dishes, starting further right will only decrease sum
            if (nums[i] >= 0) break;
        }
        return maxsum;
    }
};