/*  A restaurant has N food items represented by an array arr[],
where each element denotes the preparation time of a food
item in minutes.
A threshold value T is given.
An item is considered a Quick Order Item if:
preparation_time <= T

Your task is to find the longest continuous streak of quick-
order items.

If multiple streaks have the same maximum length, choose
the first occurring streak.
Print:
1. The first value of the longest streak
2. The number of quick-order items in that streak
3. The last index (0-based) of that streak

Input Format
• The first line contains an integer N — the number of
food items.
• The second line contains N space-separated integers
representing preparation times.
• The third line contains an integer T — the threshold
value.

Output Format
Print three space-separated values:
first_value_of_streak streak_length last_index*/


#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    string prepTime;
    vector<int> arr;
    while(getline(ss, prepTime, ' ')){
        arr.push_back(stoi(prepTime));
    }

    int T;
    cout<<"Enter the threshold value: ";
    cin>>T;

    int n = arr.size();
    int maxLength = 0;  
    int length = 0;
    int currstart = 0;
    int beststart = 0; // map to store the first value and its index

    for(int i =0; i<n; i++){
        if(arr[i] <= T){
            length++;

            if(length == 1){
                currstart = i; // start of the current streak
            }   

        }
        else{
            if(length > maxLength){
                maxLength = length;
                beststart = currstart;
            }
            length = 0;
        }
    }

    // printing the elements

    cout<<arr[beststart]<<" "<<maxLength<<" "<<beststart +maxLength-1<<endl;

return 0;

    



}