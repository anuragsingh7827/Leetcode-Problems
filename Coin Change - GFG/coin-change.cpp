// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long solve(int ind, int n, int arr[], vector<vector<long long>> &dp){
        if(n == 0) return 1;
        if(ind == 0) return n % arr[0] == 0;
        
        if(dp[ind][n] != -1) return dp[ind][n];
        
        long long notTake = solve(ind - 1,n,arr,dp);
        long long take = 0;
        if(n >= arr[ind]) take = solve(ind,n - arr[ind],arr,dp);
        
        return dp[ind][n] = notTake + take;
    }
    long long int count(int S[], int m, int n) {

        // code here.
        vector<vector<long long>> dp(m, vector<long long> (n + 1, -1));
        return solve(m - 1,n,S,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends