/*Atlassian has a text collaborative tool called Confluence; let's assume the text editor gets an array of strings. Each string should be considered as a zero-indexed array of characters. All characters within the strings will fall within the ASCII range of lowercase letters (a-z), with decimal values ranging from 97 to 122. These decimal values are known as ordinal values and will be denoted as ord[97-97], for instance.

Given an array of strings s = [s[0], s[1], ..., s[n-1]] and an integer m, we calculate a value of each s[i] of length len(s[i]) as:

$$ value[i] = ord[s[i][0]]^m \times ord[s[i][1]]^m \times \dots \times ord[s[i][len(s[i])-1]]^m $$

Perform the calculation on each string, sum them up, and determine whether their sum is EVEN or ODD.*/

/*--------------------------------------------------INTUITION-----------------------------------------------------*/

/*calculate ASCII value of each character in the string if even one of them is even then the value will be even else odd, along with it calculate frequency of odd and even sums*/

#include <iostream>
#include <vector>
using namespace std;    

class Solution{
    public:
         string solve(vector<string> &s, int m){
            int odd = 0; int even = 0;
            int n = s.size();
            for(string ch: s){
                int val = (int)ch;
                int e=0; int o=0;
                for(int i=0; i<ch.size(); i++){
                    if((int)ch[i]%2==0){
                        e++;
                    
                    }
                    else{
                        o++;
                    }
                }
                if(e==0) odd++;
                else even++;
            }
            if((odd) % 2 == 0) return "EVEN";
            else return "ODD";
        }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    Solution sol;
    cout << sol.solve(s, m) << endl;
    return 0;
}   