/* Context: You’re working on a simulation tool at Atlassian that manages a network of islands connected by bridges. Initially, every island is connected to every other island. Each island has an "importance value" associated with it.
A malicious agent, Alex (an Atlassian engineer), can destroy some bridges between islands, but only if the total destruction cost remains within a given budget. The cost to destroy the bridge between island i and island j is importance[i] * importance[j].
Your colleague Jordan (an Atlassian employee) lives on island 1 and enjoys visiting other islands. After Alex destroys some bridges optimally to disconnect the network, we want to determine how many islands Jordan can still access, including his own. Alex wants to minimize this number 
🧩 Problem Statement: You are given:
An integer N — the number of islands.


An array A of length N, where A[i] is the importance of the i-th island (1-indexed).


A long integer C — the maximum total cost Alex can spend to destroy bridges.


Each island is initially connected to every other island. Your task is to compute the minimum number of islands (including island 1) that Jordan can access after Alex destroys bridges optimally (to minimize the size of the connected component that contains island 1).
*/

/* Basic intuition is to first check for N-1 edges then check for N-2 edges and then so on , for checking N-2 edges, we check if it is less than cost or not, if it is less than cost, we include it in our solution and at last return n-answer ,*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

class Solution {
    public :
           int solve(int n, vector<int> &imp , int cost){//greedy solution, just minimising (y)(sum-y) where y is sum of nodes selected
            for(int i=0; i<n; i++){
                ll sum += imp[i];
            }
            sort(imp.begin(), imp.end());     
            for(int nodes_selected = 1; nodes_selected <n ; nodes_selected++){
                ll sum2 = 0;
                // checking for first nodes for maximum deleted nodes
                for(int i=0; i<nodes_selected; i++){
                   ll sum2 += imp[i];
                }
                ll u1 = min(sum2*(sum-sum2), u1);
                sum2=0;
                for(int i=n-1; i>=n-nodes_selected; i--){
                   ll sum2 += imp[i];
                }
                ll u1 = min(sum2*(sum-sum2), u1);

                if(u1<=cost){
                    answer = nodes_selected;

                }

                
            }

            return n-answer;


        }

           
};

int main(){
    cout<<"Enter no. of test cases : ";
    int t;
    cin>>t;
    while(t--){
        cout<<"Enter no. of islands : ";
        int n;  
        cin>>n;
        vector<int> imp(n);
        cout<<"Enter importance of islands : "; 
        for(int i=0; i<n; i++){
            cin>>imp[i];
        }
        Solution obj;
        cout<<"Enter maximum cost : ";
        int cost;
        cin>>cost;
        cout<<"Minimum number of islands Jordan can access : "<<obj.solve(n, imp, cost)<<endl;  
    }
    return 0;
}