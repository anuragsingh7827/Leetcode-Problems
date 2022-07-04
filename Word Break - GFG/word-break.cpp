// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool solve(string s, int i, int n, unordered_map<string,bool> exist){
        if(i == n) return true;
        
        string temp = "";
        for(int j = i; j < n; j++){
            temp.push_back(s[j]);
            if(exist[temp] && solve(s,j + 1,n,exist)) return true;
        }
        
        return false;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        int n = A.size();
        int m = B.size();
        
        unordered_map<string,bool> exist;
        for(int i = 0; i < m; i++) exist[B[i]] = true;
        
        return solve(A,0,n,exist);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends