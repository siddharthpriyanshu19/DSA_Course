/*  A society maintains a list of registered vendors who are
allowed to enter the premises.
You are given:
• A list of registered vendor IDs
• A sequence of gate operations
The system must process the following operations:
Operations
1. ENTRY X
o If vendor X is registered, allow entry and add the
vendor to active vendors.
o Otherwise, count it as a blocked attempt.
2. CHECK X
o Count the check request.
3. EXIT X
o Remove vendor X from active vendors if present.

At the end, print:
• Total Active Vendors
• Total Blocked Attempts
• Total Checked Requests*/

#include <iostream>
#include <vector>
#include <unordered_set>  
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;    

int main(){
    int n;
    cout<<"Enter the number of registered vendors: ";
    cin>>n;
    string s;
    cout<<"Enter the registered vendor IDs: ";
    getline(cin, s); // consume the newline character
    stringstream ss(s);
    unordered_set<string> registeredVendors;

    string vendorId;
    while (getline(ss, vendorId, ' ')) {
        registeredVendors.insert(stoi(vendorId));
    }

    int m;
    cout<<"Enter the number of gate operations: ";
    cin>>m;
    cin.ignore(); // consume the newline character after reading m

    int activeVendors = 0;
    int blockedAttempts = 0;
    int checkedRequests = 0;

    unordered_set<int> activeVendorSet;

    for (int i=0; i<m; i++){
        string op;
        int x;
        cout<<"Enter the operation: ";
        getline(cin, op);
        if(op.substr(0,5) == "ENTRY"){
            x = stoi(op.substr(6));
            if (registeredVendors.find(x) != registeredVendors.end()) {
             if (activeVendorSet.find(x) == activeVendorSet.end()) {
                activeVendorSet.insert(x);
                activeVendors++;
            }
        } else {
                blockedAttempts++;  
            }
        
        }
        else if(op.substr(0,5) == "CHECK"){
            x = stoi(op.substr(6));
            checkedRequests++;
        }
        else if(op.substr(0,4) == "EXIT"){
            x = stoi(op.substr(5));
            if(activeVendorSet.find(x) != activeVendorSet.end()){
                activeVendorSet.erase(x);
                activeVendors--;
            }
        }
        
    }

    cout << "Total Active Vendors: " << activeVendors << endl;
    cout << "Total Blocked Attempts: " << blockedAttempts << endl;
    cout << "Total Checked Requests: " << checkedRequests << endl;

}