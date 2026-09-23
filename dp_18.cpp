/* ## Problem

Pandey needs your help. As you know, he is on the quest to save the princess. After traveling for a number of days, he has finally reached the palace, but one last battle remains to be fought. However, he has only one unit of energy left in him. To win the battle, he needs all the energy he can get. So he is searching for the Wizard of GJ.

GJ agrees to help him if he is willing to play his game. GJ will give him **B balloons**, one at a time. For each balloon, he will ask Pandey if he wants to take the balloon. If Pandey accepts, his energy level will be changed according to the value and type of the balloon. Otherwise, the balloon is lost forever.

GJ is hoping to enjoy seeing Pandey regret his choices after every move because Pandey will only know the current balloon offered to him and will have no knowledge of the following ones. However, unknown to GJ, Pandey's brother Vajpayee had been working undercover as GJ's apprentice and knew in advance the values on each of the balloons and also the order in which he would show them to Pandey. So, Pandey knows all the details, and now he needs you to help him select the balloons so that he can maximize his energy.

Each balloon may be of one of the following types:

* **+ X**: Taking this balloon will add X to the current energy of Pandey.
* **- X**: Taking this balloon will subtract X from the current energy of Pandey.
* *** X**: Taking this balloon will multiply X to the current energy of Pandey.
* ** X**: Taking this balloon will divide (integer division) the current energy of Pandey by X. To simulate this balloon, you can use a standard division operator in most programming languages. E.g. **7 / 4 = 1** and **(-7) / 4 = -1**.
* **N**: Taking this balloon replaces Pandey's energy by its negated value.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cout<<"Enter no of test cases";
    int T;
    cin>>T;
    while(T--){
        cout<<"Enter no. of ballons";
        int b;
        cin>>b;
        vector<int> dp_max(b+1,0);
        vector<int> dp_min(b+1,0);
        dp_max[0]=1;
        dp_min[0]=dp_max[0];


        for(int i=1; i<=b; i++){
            cout<<"enter the type of ballon";
            char g;
            cin>>g;
            if(g=='+'){
                cout<<"Enter value of ballon";
                int x;
                cin>>x;
                dp_max[i] = max(dp_max[i-1]+x,dp_max[i-1]);
                dp_min[i] = min(dp_min[i-1]+x,dp_min[i-1]);
            }
            else if(g=='*'){
                cout<<"Enter value of ballon";
                int x;
                cin>>x;
                dp_max[i] = max(dp_max[i-1]*x,dp_max[i-1]);
                dp_min[i] = min(dp_min[i-1]*x,dp_min[i-1]);
            }
            else if(g=='-'){
                cout<<"Enter value of ballon";
                int x;
                cin>>x;
                dp_max[i] = max(dp_max[i-1]-x,dp_max[i-1]);
                dp_min[i] = min(dp_min[i-1]-x,dp_min[i-1]);
            }
            else if(g=='/'){
                cout<<"Enter value of ballon";
                int x;
                cin>>x;
                dp_max[i] = max(dp_max[i-1]/x,dp_max[i-1]);
                dp_min[i] = min(dp_min[i-1]/x,dp_min[i-1]);
            }
            else if(g=='N'){
                dp_max[i] = max({dp_max[i-1]*(-1),dp_max[i-1],dp_min[i-1]*(-1)});
                dp_min[i] = min({dp_min[i-1]*(-1),dp_min[i-1],dp_max[i-1]*(-1)});
            }
            
        }
        cout<<dp_max[b];


    }
    return 0;
    
}

