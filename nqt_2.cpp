/*Our hoary culture had several great persons since time immemorial and king
Vikramaditya’s nava ratnas (nine gems) belongs to this ilk. They are named in the
following shloka:
Among these, Varahamihira was an astrologer of eminence and his book Brihat
Jataak is recokened as the ultimate authority in astrology. He was once talking
with Amarasimha, another gem among the nava ratnas and the author of the
Sanskrit thesaurus, Amarakosha. Amarasimha wanted to know the final position
of a person, who starts from the origin 0 0 and travels per the following scheme.
• He first turns and travels 10 units of distance
• His second turn is upward for 20 units
• The third turn is to the left for 30 units
• The fourth turn is downward for 40 units
• The fifth turn is to the right(again) for 50 units
... And thus he travels, every time increasing the travel distance by 10 units.*/


#include <iostream>
#include <vector>   
#include <string>
using namespace std;


int main(){
    
    int n;
    cin>>n;
    int x=0,y=0;
    int step = 10;
    vector<char> directions = {'R', 'U', 'L', 'D'};
    while(n>0){
        for(char ch : directions){
            if(n<=0) break;
            if(ch=='R'){
                x+=step;
                step+=10;
            }
            else if(ch=='U'){
                y+=step;
                step+=10;
            }
            else if(ch=='L'){
                x-=step;
                step+=10;
            }
            else if(ch=='D'){
                y-=step;
                step+=10;
            }
            n--;
        }
    }
    cout << x << " " << y << endl;


}