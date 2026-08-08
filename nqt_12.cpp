/*Given an array of integers, count the frequency
of each element and return the element that has
the highest frequency.
If multiple elements have the same highest
frequency, return the smallest element among
them.*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int main(){
    int n ;
    cout << "Enter the size of the array: "; 
    cin>>n;
    cout<<"Enter the elements of the array: ";
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    unordered_map<int, int> freq;

    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }

    int maxfreq = 0;
    int ans = INT_MAX;
    for(int i =0; i<n ;i++){
        if(freq[arr[i]]>maxfreq){
            maxfreq = freq[arr[i]];
            ans = arr[i];
        }
        else if(freq[arr[i]]==maxfreq){
            ans= min(ans,arr[i]);   
        }
        else{
            continue;
        }
    }
    cout<<"Element with highest frequency is: "<<ans;

    return 0;
}