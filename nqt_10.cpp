/*Question 1: Problem Statement
Remove Duplicates and Print in Reverse
Order
Given an array of elements, remove all
duplicate elements while preserving the
order of their first occurrence. After
removing duplicates, print the resulting
array in reverse order.*/

#include <iostream>
#include <vector>   
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> ans;

    int i = 1;

    while(i<n){
        if(arr[i] == arr[i-1]){
            while(i<n && arr[i] == arr[i-1]){
                i++;
            }
        }
        else{
            ans.push_back(arr[i-1]);
            i++;
        }

    }
    ans.push_back(arr[n-1]);
    for(int i=ans.size()-1; i>=0; i--){
        cout<<ans[i]<<" ";
    }
    return 0;

}