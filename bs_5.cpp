/* Find Nth root of a number in O(logN) Time complexity*/

#include <iostream>
#include <cmath>
using namespace std;    

class Solution {    
    public:
          double solve(double x, int n){
            double low = 1; 
            double high = x;
            double diff = 1e-6;
            while((low-high)>diff){
                double mid = (low+high)/2;
                double mid_pow   = pow(mid,n);
                if(mid_pow==x){
                    return mid;
                }
                else if(mid_pow>x){
                    high = mid;

                }
                else{
                    low=mid;
                }
                
            }
            return low;
        }


};

int main(){
    cout<<"Enter the number and the root to find: ";
    double x; 
    cin>> x;
    int n;
    cin>>n;

    Solution s;
    cout<<s.solve(x,n);
}