/*Given an integer array Arr of size N the task is to find the count of elements whose value is greater
than all of its prior elements.
Note : 1st element of the array should be considered in the count of the result.*/



#include <iostream>
#include <vector>

using namespace std;
 
int main(){
    int n ;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int cnt = 1;
    int maxele = INT_MIN;


    for(int i =1; i<n; i++){
        if(arr[i]>maxele){
            maxele = INT_MIN;
            cnt++;
        }
        else{
            maxele = max(maxele, arr[i]);
        }
    }

    cout<<"no of such elements are :"<< cnt;

    return 0;

    
}