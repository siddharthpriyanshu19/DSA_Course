/*Airport security officials have confiscated several item of the passengers at the security check
point. All the items have been dumped into a huge box (array). Each item possesses a certain
amount of risk[0,1,2]. Here, the risk severity of the items represent an array[] of N number of
integer values. The task here is to sort the items based on their levels of risk in the array. The risk
values range from 0 to 2.
*/

#include <iostream>
#include <vector>   
#include <algorithm>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<int> risk(n);
    cout << "Enter the risk values (0, 1, or 2) for each item: ";
    for(int i = 0; i < n; i++){
        cin >> risk[i];
    }

    // Sort the risk values
    sort(risk.begin(), risk.end());

    cout << "Sorted risk values: ";
    for(int i = 0; i < n; i++){
        cout << risk[i] << " ";
    }
    cout << endl;

    return 0;
}