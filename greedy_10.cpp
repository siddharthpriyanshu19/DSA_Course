#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solve(vector<int>& ids, int n, int m) {

        unordered_map<int, int> freq;

        // Count frequency of each ID
        for(int i = 0; i < n; i++) {
            freq[ids[i]]++;
        }

        // Extract frequencies
        vector<int> frequencies;

        for(auto x : freq) {
            frequencies.push_back(x.second);
        }

        // Smallest frequency first
        sort(frequencies.begin(), frequencies.end());

        int distinct = frequencies.size();

        for(int f : frequencies) {

            if(f <= m) {
                m -= f;
                distinct--;
            }
            else {
                break;
            }
        }

        return distinct;
    }
};

int main() {

    int n, m;

    cout << "Enter no of items in bag: ";
    cin >> n;

    cout << "Enter no of items to be removed: ";
    cin >> m;

    vector<int> ids(n);

    cout << "Enter the IDs of the items: ";

    for(int i = 0; i < n; i++) {
        cin >> ids[i];
    }

    Solution s;

    cout << s.solve(ids, n, m) << endl;
    return 0;
}