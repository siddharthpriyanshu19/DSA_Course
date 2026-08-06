/*Jack is always excited about sunday. It is favourite day, when he gets to play all day. And goes to
cycling with his friends.
So every time when the months starts he counts the number of sundays he will get to enjoy.
Considering the month can start with any day, be it Sunday, Monday.... Or so on.
Count the number of Sunday jack will get within n number of days.
*/

#include <iostream> 
#include <string>
#include <unordered_map>


using namespace std;

int main(){
    string day;
    cout << "Enter start of the month: ";
    cin >> day;
    int n;
    unordered_map<string,int> days;
    days["sunday"]=7;
    days["monday"]=6;
    days["tuesday"]=5;
    days["wednesday"]=4;    
    days["thursday"]=3;
    days["friday"]=2;
    days["saturday"]=1;

    cout << "Enter number of days: ";
    cin >> n;
    int cnt=0;
    
    n= n-days[day];
    if(n>0){
        cnt++;
    }
    n= n/7;
    cnt = cnt + n;

    cout<<"No of Sundays Jack will get to enjoy: "<<cnt<<endl; 
    
    return 0;

    
}

