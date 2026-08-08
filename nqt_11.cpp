/*Question 2: Find Number of Rotations and Index of Element
in Original Array
A sorted array is rotated k times in a clockwise direction.
Given this rotated array of size N and a target element K:
1. Find the number of rotations performed on the original
sorted array.
2. Find the index of element K in the original (sorted)
array.
If the element is not present, return -1.*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int k;
    cout << "Enter the target element: ";
    cin>>k;
    int rot = 0;
    for(int i=1;i<n; i++){
        if(arr[i]<arr[i-1]){
            rot = i;
        break;
        }
    }
    cout<<"Number of rotations performed on the original sorted array is: "<<rot<<endl;
    for(int i=0; i<n; i++){
        if(arr[i]==k){
    
            if(i-rot<0){
                cout<<"Index of element "<<k<<" in the original sorted array is: "<<n-(rot-i)<<endl;
            }
            else{
                cout<<"Index of element "<<k<<" in the original sorted array is: "<<i-rot<<endl;
            }
        }
    }
}