/*A chocolate factory is packing chocolates into the packets. The chocolate packets here represent
an array of N number of integer values. The task is to find the empty packets(0) of chocolate and
push it to the end of the conveyor belt(array).*/


#include <iostream>
#include <vector>


using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    vector<int> aligned_storage;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i =0; i<n; i++){
        if(arr[i]!=0){
            aligned_storage.push_back(arr[i]);
        }

    }
    while(aligned_storage.size()<n){
        aligned_storage.push_back(0);
    }
    for(int i=0;i<n;i++){
        cout<<aligned_storage[i]<<" ";
    }

    return 0;
  
    
}