// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int n = s1.length();
        int m = s2.length();
        
        int** dp = new int*[n + 1];
        for(int i = 0; i < n + 1; i++) dp[i] = new int[m + 1];
        
        for(int j = 0; j < m + 1; j++) dp[n][j] = 0;
        for(int i = 0; i < n + 1; i++) dp[i][m] = 0;
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(s1[i] == s2[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
                else dp[i][j] = max(dp[i][j + 1],dp[i + 1][j]);
            }
        }
        
        return dp[0][0];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends