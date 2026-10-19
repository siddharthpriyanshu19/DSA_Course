
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long solve(int n, vector<int>& arr) {
        vector<int> left(n, 0), right(n, 0);

        // Count elements greater than arr[j] on the left and right
        for (int j = 1; j < n - 1; j++) {
            for (int i = 0; i < j; i++) {
                if (arr[i] > arr[j]) {
                    left[j]++;
                }
            }

            for (int k = j + 1; k < n; k++) {
                if (arr[k] > arr[j]) {
                    right[j]++;
                }
            }
        }

        // Count valid triplets
        long long cnt = 0;

        for (int j = 1; j < n - 1; j++) {
            cnt += 1LL * left[j] * right[j];
        }

        return cnt;
    }
};

int main() {
    int t;
    cout << "Enter no. of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter size of array: ";
        cin >> n;

        vector<int> arr(n);

        cout << "Enter elements of array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        cout << "Number of triplets: "
             << obj.solve(n, arr) << endl;
    }

    return 0;
}
