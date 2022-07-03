// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(int i, int j, vector<int> &a, int k, vector<vector<int>> &dp){
        if(i >= j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(a[j] - a[i] <= k) return dp[i][j] = 0;
        
        return dp[i][j] = min(1 + solve(i + 1,j,a,k,dp),1 + solve(i,j - 1,a,k,dp));
    }
    int removals(vector<int>& a, int k){
        //Code here
        int n = a.size();
        
        sort(a.begin(),a.end());
        
        vector<int> ahead(n + 1, 0), cur(n + 1, 0);
        
        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(a[j] - a[i] > k) cur[j] = min(1 + ahead[j],1 + cur[j - 1]);
            }
            ahead = cur;
        }
        
        return ahead[n - 1];
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}


  // } Driver Code Ends