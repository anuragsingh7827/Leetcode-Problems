// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    bool solve(string s, int n, vector<string> &ans, vector<string> address, int dots, int i){
        
        if((dots == 0 && i < n) || (dots > 0 && i == n)) return false;
        
        if(dots == 0 && i == n){
            int m = address.size();
            string ipAddress = "";
            for(int j = 0; j < m; j++) ipAddress += address[j];
            ipAddress.pop_back();
            ans.push_back(ipAddress);
            return false;
        }
        
        string part = "";
        for(int j = i; j < n; j++){
            // if(part == "0") return false;
            // else{
            //     part.push_back(s[j]);
            //     if(stoi(part) >= 0 && stoi(part) <= 255){
            //         part.push_back('.');
            //         address.push_back(part);
            //         if(solve(s,n,ans,address,dots - 1,j + 1)) return true;
            //         address.pop_back();
            //         part.pop_back();
            //     }else break;
            // }
            
            if(part == "" || part[0] != '0'){
                part.push_back(s[j]);
                if(stoi(part) >= 0 && stoi(part) <= 255){
                    part.push_back('.');
                    address.push_back(part);
                    if(solve(s,n,ans,address,dots - 1,j + 1)) return true;
                    address.pop_back();
                    part.pop_back();
                }else break;
            }else if(part == "0") return false;
        }
        return false;
        
    }
    vector<string> genIp(string &s) {
        // Your code here
        int n = s.length();
        
        vector<string> ans;
        
        vector<string> address;
        
        solve(s,n,ans,address,4,0);
        
        return ans;
    }

};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}  // } Driver Code Ends