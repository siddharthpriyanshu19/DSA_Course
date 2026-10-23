/* Harry Potter and the Goblet of FireA wizard tournament is being held at Hogwarts, and $\mathbf{N}$ wizards are auditioning for it. The Goblet of Fire will choose the wizards according to their primary and secondary spell skills. A wizard will advance to the tournament if there is no other wizard with strictly both higher primary and secondary spell skills at the same time than this one.   Your task is to calculate the number of wizards that will advance in the tournament.   InputThe first line of input contains $\mathbf{N}$, representing the number of wizards at the qualification stage.   The second line contains $\mathbf{a_1, a_2 \dots a_N}$, where $\mathbf{a_i}$ represents the primary spell skill level of the $i^{\text{th}}$ wizard.   The third line of input contains $\mathbf{N}$, representing the number of wizards at the qualification stage.   */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution{
    public:
    int solve(vector<int> &a, vector<int> &b){
        vector<pair<int,int>> combined;
        int n = a.size();
        for(int i = 0; i<n; i++){
            combined.push_back({a[i], b[i]});

        }
        sort(combined.begin(), combined.end());
        int cnt = 0;
        vector<int> max_b(n);
        max_b[n-1] = combined[n-1].second;
        for(int i = n-2; i>=0; i--){
            max_b[i] = max(combined[i].second, max_b[i+1]);
        }
        for(int i = 0; i<n; i++){
            if(combined[i].second == max_b[i]){
                cnt++;
            }
        }
        return cnt;
    }
};