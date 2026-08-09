/* You are given a sorted array of integers of size N and a
target value X.
Your task is to:
1. Find the first occurrence of X
2. Find the last occurrence of X
3. Find the difference between the last and first
occurrence
If the target element is not present in the array, print -
1.
The solution should be implemented using Binary
Search.*/

#include <iostream>
#include <vector>
using namespace std;    

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n; 
    int target;
    cin>>target;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int low = 0;
    int high = n-1;
    int first = -1; 

    //first occurrence  

    while(low<=high){
        int mid = (low+high)/2;  
        if(arr[mid]==target){
            first = mid;
            high = mid-1; //search left side for first occurrence
        } 
        else if(arr[mid]<target){
            low = mid+1;
        } 
        else{
            high = mid-1;
        }   

    }
    int low = 0;
    int high = n-1;
    int last = -1; 

    //first occurrence  

    while(low<=high){
        int mid = (low+high)/2;  
        if(arr[mid]==target){
            last = mid;
            low = mid+1; //search right side for last occurrence
        } 
        else if(arr[mid]<target){
            low = mid+1;
        } 
        else{
            high = mid-1;
        }   

    }

    if(first==-1 || last==-1){
        cout<<-1;
    }
    else{
        cout<<last-first;
    }

    return 0;

}