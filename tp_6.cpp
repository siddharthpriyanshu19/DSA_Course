/*Given two sorted arrays, the task is to merge them in a sorted manner and return a new sorted array containing elements of both Input Arrays.*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
    private :
    vector<int> solve(vector<int> &arr1, vector<int> &arr2){
        int n1 = arr1.size();
        int n2 = arr2.size();

        int i = 0;
        int j = 0;
        vector<int> res;

        while(i<n1 && j<n2){
            if(arr1[i]<arr2[j]){
                res.push_back(arr1[i]);
                i++;
            }
            else if(arr2[j]<arr1[i]){
                res.push_back(arr2[j]);
                j++;
            }
            else{
                res.push_back(arr1[i]);
                i++;
                res.push_back(arr2[j]);
                j++;

            }

        }
        while(i<n1){
            res.push_back(arr1[i]);
            i++;
        }
        while(j<n2){
            res.push_back(arr2[j]);
            j++;
        }
        return res;
    }


};