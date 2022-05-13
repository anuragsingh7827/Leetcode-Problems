// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
        //Your code here
        long long n = str.length();
        const long long m = 1000000007;
        
        long long** dp = new long long*[n];
        for(long long i = 0; i < n; i++) dp[i] = new long long[n];
        
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < n; j++) dp[i][j] = 0;
        }
        
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < n; j++){
                if(i == j) dp[i][j] = 1;
                else if(i == j - 1){
                    if(str[i] == str[j]) dp[i][j] = 3;
                    else dp[i][j] = 2;
                }
            }
        }
        
        for(long long i = n - 3; i >= 0; i--){
            for(long long j = i + 2; j < n; j++){
                long long x = dp[i][j - 1] % m;
                long long y = dp[i + 1][j] % m;
                long long z = dp[i + 1][j - 1] % m;
                if(str[i] == str[j]) dp[i][j] = (x + y + (1 % m)) % m;
                else dp[i][j] = (x + y - z + m) % m;
            }
        }
        
        long long ans = dp[0][n - 1] % m;
        
        return ans;
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends