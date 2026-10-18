/* Given an integer “N” ; divide it into 3 parts; k1;k2;k3 such that k1 + k2 + k3 ==N and k1<=k,k2<=k,k3<=k
*/

#include<iostream>
#include<algorithm>

using namespace std;



class Solution{
    public:
    int solve(int k, int s){
        int cnt = 0;
        for(int i = 0; i<=k; i++){
            for(int j=0; j<=k; j++){
                int x = s-(i+j);
                if(x<=k && x>=0){
                    cnt++;
                }
            }
        }
        return cnt;
    }

};

int main(){
    cout<<"enter total no of chocolates";
    int s;
    cin>>s;
    cout<<"enter threshold on each chocolate to be given";
    int k;
    cin>>k;
    Solution obj;
    obj.solve(k,s);

    return 0;

}