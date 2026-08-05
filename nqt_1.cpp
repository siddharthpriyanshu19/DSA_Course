/*Given a maximum of four digits to the base 17(10 -> A, 11 -> B, 12 -> C, 16 -> G) as
input, output its decimal value.*/


#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int decimal = 0;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        int value;

        if (ch >= '0' && ch <= '9')
            value = ch - '0';
        else
            value = ch - 'A' + 10;

        decimal = decimal * 17 + value;
    }

    cout << decimal;

    return 0;
}