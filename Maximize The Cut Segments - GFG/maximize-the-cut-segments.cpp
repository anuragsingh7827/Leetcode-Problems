// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solve(int ind, int n, vector<int> &seg, vector<vector<int>> &dp){
        if(n == 0) return 0;
        if(ind == 0){
            if(n % seg[0] == 0) return n / seg[0];
            return -1e9;
        }
        
        if(dp[ind][n] != -1) return dp[ind][n];
        
        int notTake = solve(ind - 1,n,seg,dp);
        int take = INT_MIN;
        if(n >= seg[ind]) take = 1 + solve(ind,n - seg[ind],seg,dp);
        
        return dp[ind][n] = max(notTake,take);
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> seg(3);
        seg[0] = x;
        seg[1] = y;
        seg[2] = z;
        
        vector<vector<int>> dp(3, vector<int> (n + 1, 0));
        
        for(int i = 1; i <= n; i++){
            if(i % seg[0] == 0) dp[0][i] = i / seg[0];
            else dp[0][i] = -1e9;
        }
        
        for(int ind = 1; ind <= 2; ind++){
            for(int tar = 1; tar <= n; tar++){
                int notTake = dp[ind - 1][tar];
                int take = INT_MIN;
                if(tar >= seg[ind]) take = 1 + dp[ind][tar - seg[ind]];
                
                dp[ind][tar] = max(notTake,take);
            }
        }
        
        int ans = dp[2][n];
        
        if(ans > 0) return ans;
        return 0;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends