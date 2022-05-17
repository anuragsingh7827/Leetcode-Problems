// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    int longestPrefix(string s){
        int n = s.length();
        
        vector<int> pi(n,0);
        for(int i = 1; i < n; i++){
            int j = pi[i - 1];
            
            while(j > 0 && s[i] != s[j]) j = pi[j - 1];
            
            if(s[i] == s[j]) pi[i] = j + 1;
        }
        
        return pi[n - 1];
    }
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int n = s1.length();
        int m = s2.length();
        
        if(n != m) return false;
        
        if(s1 == s2) return true;
        
        int lps = longestPrefix(s1 + s2);
        
        if(s1.substr(lps,n - lps) == s2.substr(0,m - lps)) return true;
        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}
  // } Driver Code Ends