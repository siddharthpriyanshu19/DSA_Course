/*Question 2: Maximum Subarray Sum (Kadane’s Algorithm)
Problem Statement
Given an integer array (can contain both positive and
negative numbers), find:
1. The maximum subarray sum
2. The subarray itself
Use Kadane’s Algorithm.*/

#include <iostream>
#include <vector>
#include <unordered_map> 

using namespace std;

int main(){
    cout<<"Enter the number of elements in the array: ";
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int start=0, end=0, ts=0;
    int currsum = arr[0];
    int maxsum = arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]>currsum+arr[i]){
            currsum = arr[i];
            ts = i;
        }
        else{
            currsum += arr[i];
        }
        if(currsum>maxsum){
            maxsum = currsum;
            start = ts;
            end = i;
        }
    }
    for(int i=start;i<=end;i++){
        cout<<arr[i]<<" ";
    }


    return 0;

    

    
}