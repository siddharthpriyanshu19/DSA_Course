/*Group Formation Based on Efficiency
Problem Statement
You are given efficiencies of n people. You need to form
groups of size t.
If some people are left (i.e., n is not divisible by t), those
extra people are removed.
For each group:

• Find the difference between the highest and lowest
efficiency.
Task
Return the maximum difference among all groups.*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,t;
    cout<<"Enter the number of people and group size: ";
    cin>>n>>t;
    vector<int> arr(n);
    cout<<"Enter the efficiencies of the people: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //sorting 

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    int maxdiff = 0;
    int i = 0;
    int j = i+t-1;
    while(j<n){{
        cout<<("<<arr[i]<<","<<arr[j]<<")<< "diff->"<<arr[j]-arr[i]<<endl;
        maxdiff = max(maxdiff, arr[j]-arr[i]);
        i += t;
        j += t;
    }
return 0;

}