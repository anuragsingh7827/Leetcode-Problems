// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1003;
    pair<int,int> solve(int i, int j, string s, vector<vector<pair<int,int>>> &dp){
        if(i == j){
            if(s[i] == 'T') return {1,0};
            if(s[i] == 'F') return {0,1};
        }
        
        
        if(dp[i][j] != make_pair(-1,-1)) return dp[i][j];
        
        int trueWays = 0;
        int falseWays = 0;
        
        for(int k = i + 1; k <= j - 1; k += 2){
            auto left = solve(i,k - 1,s,dp);
            auto right = solve(k + 1,j,s,dp);
            
            int leftTrue = left.first % mod;
            int leftFalse = left.second % mod;
            int rightTrue = right.first % mod;
            int rightFalse = right.second % mod;
            
            if(s[k] == '&'){
                trueWays += ((leftTrue % mod) * (rightTrue % mod)) % mod;
                falseWays += ((leftTrue % mod * rightFalse % mod) % mod + 
                                (leftFalse % mod * rightTrue % mod) % mod + 
                                (leftFalse % mod * rightFalse % mod) % mod) % mod;
            }
            else if(s[k] == '|'){
                trueWays += ((leftTrue % mod * rightFalse % mod) % mod + 
                                (leftFalse % mod * rightTrue % mod) % mod +
                                (leftTrue % mod * rightTrue % mod) % mod) % mod;
                falseWays += (leftFalse % mod * rightFalse % mod) % mod;
            }
                    
            else if(s[k] == '^'){
                trueWays += ((leftTrue % mod * rightFalse % mod) % mod + 
                            (leftFalse % mod * rightTrue % mod) % mod) % mod;
                falseWays += ((leftTrue % mod * rightTrue % mod) % mod + 
                            (leftFalse % mod * rightFalse % mod) % mod) % mod;
            }
        }
        return dp[i][j] = {trueWays % mod,falseWays % mod};
    }
    int countWays(int N, string S){
        // code here
        int n = S.size();
        
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>> (n, {0,0}));
        
        for(int i = 0; i < n; i++){
            if(S[i] == 'T') dp[i][i] = {1,0};
            else if(S[i] == 'F') dp[i][i] = {0,1};
        } 
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                int trueWays = 0;
                int falseWays = 0;
                
                for(int k = i + 1; k <= j - 1; k += 2){
                    auto left = dp[i][k - 1];
                    auto right = dp[k + 1][j];
                    
                    int leftTrue = left.first % mod;
                    int leftFalse = left.second % mod;
                    int rightTrue = right.first % mod;
                    int rightFalse = right.second % mod;
                    
                    if(S[k] == '&'){
                        trueWays += ((leftTrue % mod) * (rightTrue % mod)) % mod;
                        falseWays += ((leftTrue % mod * rightFalse % mod) % mod + 
                                        (leftFalse % mod * rightTrue % mod) % mod + 
                                        (leftFalse % mod * rightFalse % mod) % mod) % mod;
                    }
                    else if(S[k] == '|'){
                        trueWays += ((leftTrue % mod * rightFalse % mod) % mod + 
                                        (leftFalse % mod * rightTrue % mod) % mod +
                                        (leftTrue % mod * rightTrue % mod) % mod) % mod;
                        falseWays += (leftFalse % mod * rightFalse % mod) % mod;
                    }
                            
                    else if(S[k] == '^'){
                        trueWays += ((leftTrue % mod * rightFalse % mod) % mod + 
                                    (leftFalse % mod * rightTrue % mod) % mod) % mod;
                        falseWays += ((leftTrue % mod * rightTrue % mod) % mod + 
                                    (leftFalse % mod * rightFalse % mod) % mod) % mod;
                    }
                }
                dp[i][j] = {trueWays % mod,falseWays % mod};
            }
        }
        
        int ans = dp[0][n - 1].first % mod;
        
        return ans % mod;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends