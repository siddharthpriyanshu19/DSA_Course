/*You are given an array A of N integers. You have to find the number of special pairs in array A. A pair of two indexes i and j are called special if the following 2 conditions are satisfied:

i < j
A[A[i]] = A[A[j]]

Find out the number of special pairs present in array A.

Note: 1-based indexing is used.*/

#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>
class Solution {
    public:
    long long countSpecialPairs(int N, vector<int> &A) {
        unordered_map<int, long long> freq;
        long long count = 0;
        int n  = A.size();

        for (int i = 0; i < N; ++i) {
            int ele  = A[A[i-1]]; 
            if(freq.find(ele) != freq.end()) {
                count += freq[ele];
            }
            freq[ele]++;
        }

        return count;
    }
};