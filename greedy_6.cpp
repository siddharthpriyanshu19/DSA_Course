/*In the icy realm of Antarctica, there is an annual gathering of penguins to celebrate the onset of winter. There are N male penguins and N female penguins attending the grand dance party this year.

In choosing their dance partners (partner is always from the opposite gender), penguins give the utmost importance to their partner's height. Some penguins will only dance with a partner who is taller, while the other penguins will only dance with a partner who is shorter. No penguin will dance with a partner who is of the same height as themselves. To indicate this preference, the height of a penguin is mentioned as a positive value if the penguin wishes to have a partner who is taller than themselves, and alternately as a negative value if the penguin wishes to have a partner who is shorter than themselves.

To create harmony and joy at the grand dance, your task is to respect the wishes of each penguin and determine the maximum number of dancing pairs that can be formed. Each penguin can have, at most, one dancing partner. Your goal is to pair as many of them as possible, in a way that fulfills their height preferences.

Read the input from STDIN and print the output to STDOUT. Do not print arbitrary strings anywhere in the program, as these contribute to the output and test cases will fail.

Constraints
1 ≤ N ≤ 100000
1500 ≤ Absolute value of a penguin's height ≤ 2500
Input Format

The first line of input contains N, the number of male and female penguins.

The second input line contains N integers, the height of each of the male penguins, each separated by a single white space.

The third input line contains N integers, the height of each of the female penguins, each separated by a single white space.

Output Format

Single line of output must contain the maximum number of dancing pairs that can be formed.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:

    int match(vector<int>& positive, vector<int>& negative) {
        sort(positive.begin(), positive.end());
        sort(negative.begin(), negative.end());

        int i = 0;
        int j = 0;
        int cnt = 0;

        while (i < positive.size() && j < negative.size()) {

            if (positive[i] < negative[j]) {
                // Valid pair
                cnt++;
                i++;
                j++;
            }
            else {
                // This negative penguin is too short
                j++;
            }
        }

        return cnt;
    }

    int solve(vector<int>& male, vector<int>& female) {

        vector<int> malePositive;
        vector<int> maleNegative;

        vector<int> femalePositive;
        vector<int> femaleNegative;

        for (int x : male) {
            if (x > 0)
                malePositive.push_back(x);
            else
                maleNegative.push_back(abs(x));
        }

        for (int x : female) {
            if (x > 0)
                femalePositive.push_back(x);
            else
                femaleNegative.push_back(abs(x));
        }

        // male positive + female negative
        int ans1 = match(malePositive, femaleNegative);

        // male negative + female positive
        int ans2 = match(femalePositive, maleNegative);

        return ans1 + ans2;
    }
};