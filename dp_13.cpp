/*Given two arrays; a and b -> you can start at index 1 from any array and end your journey at index n on an array 

-> If you are at i you can can jump to i+1 on same array or different array 

-> -1000000000 <= a[i],b[i]<= 10000000000 

-> Please output total number of journeys which have even sum and total number of journeys which have odd sum;
*/

class Solution {
public: 
       vector<vector<long long> count(vector<int> &a, vector<int> &b) {
        int n = a.size();
        vector<long long> dpa_even(n+1, 0);
        vector<long long> dpa_odd(n+1, 0);
        vector<long long> dpb_even(n+1, 0);
        vector<long long> dpb_odd(n+1, 0);

        if(a[0] % 2 == 0) {
            dpa_even[1] = 1;
        } else {
            dpa_odd[1] = 1;
        }

        if(b[0] % 2 == 0) {
            dpb_even[1] = 1;
        } else {
            dpb_odd[1] = 1;
        }

        for(int i = 2; i <= n; i++) {
            if(a[i-1] % 2 == 0) { // dpa_even[i] = total number of even journeys ending at index i on array a
                dpa_even[i] = dpa_even[i-1] + dpb_even[i-1];
                dpa_odd[i] = dpa_odd[i-1] + dpb_odd[i-1];
            } else {
                dpa_even[i] = dpa_odd[i-1] + dpb_odd[i-1];
                dpa_odd[i] = dpa_even[i-1] + dpb_even[i-1];
            }

            if(b[i-1] % 2 == 0) {
                dpb_even[i] = dpb_even[i-1] + dpa_even[i-1];
                dpb_odd[i] = dpb_odd[i-1] + dpa_odd[i-1];
            } else {
                dpb_even[i] = dpb_odd[i-1] + dpa_odd[i-1];
                dpb_odd[i] = dpb_even[i-1] + dpa_even[i-1];
            }
        }
        

        return {dpa_even[n] + dpb_even[n], dpa_odd[n] + dpb_odd[n]};
           }; // Return total even and odd journeys  