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
    // bool exist(string word, vector<string> B){
    //     int m = B.size();
    //     for(int i = 0; i < m; i++){
    //         if(B[i] == word) return true;
    //     }
    //     return false;
    // }
    int solve(string A, int i, vector<string> B, int n, unordered_map<string,bool> h){
        
        if(A[i] == '\0') return true;
        
        
        string word = "";
        for(int j = i; j < n; j++){
            word.push_back(A[j]);
            if(h[word] && solve(A,j + 1,B,n,h)) return true;
        }
        return false;
    }
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        int n = A.length();
        int m = B.size();
        
        unordered_map<string,bool> h;
        for(int i = 0; i < m; i++) h[B[i]] = true;
        
        if(solve(A,0,B,n,h)) return 1;
        return 0;
        
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