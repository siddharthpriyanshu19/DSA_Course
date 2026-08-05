/*Given an integer “N” ; find the minimum cost to reduce it to 1
The operations you can do are as follows.->

i) Reduce the number by 1 in “y” dollars; 

ii) Reduce the number by /7 in “x” dollars.(if number is divisible by 7)

iii) Reduce the number by /3 in “z” dollars;(if number is divisible by 3)

iv) Reduce the number by /5 in “b” dollars;(if number is divisible by 5) 
*/

class Solution {
public:
    int minCost(int N, int y, int x, int z, int b) {
        vector<int> dp(N + 1, 0); // dp[i] will store the minimum cost to reduce i to 1
        dp[1] = 0; // Cost to reduce 1 to 1 is 0

        for (int i = 2; i <= N; i++) {
            // Reduce by 1
           int v1 = dp[i-1] + y;

            // Reduce by 7
            int v2 = (i % 7 == 0) ? dp[i / 7] + x : 0;

            // Reduce by 3
            int v3 = (i % 3 == 0) ? dp[i / 3] + z : 0;

            // Reduce by 5
            int v4 = (i % 5 == 0) ? dp[i / 5] + b : 0;

            // Take the minimum of all possible operations
            dp[i] = min({v1, v2, v3, v4});
        }

        return dp[N];
    }
};