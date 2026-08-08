/*You are given:
• An integer n
• An array cost[] of size n
• An n × n symmetric matrix where diagonal elements
are 0
For each row:
• Replace the diagonal element (0) with cost[i]
• Compute the sum of that row
Return the minimum row sum among all rows.*/


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int n ;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> cost(n);
    cout<<"Enter the elements of the cost array: ";
    for(int i= 0; i<n; i++){
        cin>>cost[i];
    }
    cout<<"Enter the elements of the symmetric matrix: ";
    int minsum = INT_MAX;
    for(int i=0; i<n; i++){
        int sum =0;
        for(int j=0; j<n; j++){
            int x;
            cin>>x;
            if(i==j){
                sum += cost[i];  
                
            }
            else{
                sum += x;
            }

        }
        minsum = min(minsum, sum);
    }
    cout << "Minimum row sum is: " << minsum;
    return 0;
}