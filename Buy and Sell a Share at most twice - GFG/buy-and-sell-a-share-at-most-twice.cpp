// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

int solve(int ind, int buy, int cap, vector<int> price, int n, vector<vector<vector<int>>> &dp){
    if(cap == 0) return 0;
    if(ind == n) return 0;
    
    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    
    if(buy){
        int op1 = -price[ind] + solve(ind + 1,0,cap,price,n,dp);
        int op2 = solve(ind + 1,1,cap,price,n,dp);
        
        return dp[ind][buy][cap] = max(op1,op2);
    }else{
        int op1 = price[ind] + solve(ind + 1,1,cap - 1,price,n,dp);
        int op2 = solve(ind + 1,0,cap,price,n,dp);
        
        return dp[ind][buy][cap] = max(op1,op2);
    }
}
int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
    
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, 0)));
    
    for(int ind = n - 1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= 2; cap++){
                if(buy){
                    int op1 = -price[ind] + dp[ind + 1][0][cap];
                    int op2 = dp[ind + 1][1][cap];
                    
                    dp[ind][buy][cap] = max(op1,op2);
                }else{
                    int op1 = price[ind] + dp[ind + 1][1][cap - 1];
                    int op2 = dp[ind + 1][0][cap];
                    
                    dp[ind][buy][cap] = max(op1,op2);
                }
            }
        }
    }
    
    return dp[0][1][2];
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends