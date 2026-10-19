/*Given 5 arrays :- A,B,C,D,E  all of size “N” 

Element in the array can range from [-10^9……….10^9]

Find the number of tuplets (i,j,k,l,m) such that  - 

a[i] + b[j] + c[k] + d[l] + e[m] = 0
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        long long solve(int n, vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d, vector<int>& e) {
            unordered_map<long long, long long> sumAB;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    sumAB[a[i] + b[j]]++;
                }
            }

            long long count = 0;
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    for (int m = 0; m < n; m++) {
                        long long target = -(c[k] + d[l] + e[m]);
                        if (sumAB.find(target) != sumAB.end()) {
                            count += sumAB[target];
                        }
                    }
                }
            }

            return count;
        }
};