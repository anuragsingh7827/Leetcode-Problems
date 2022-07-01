// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int solve(int ind, int k, int arr[], vector<vector<int>> &dp){
        if(k == 0) return 0;
        if(ind == 0) return arr[0] <= k;
        
        if(dp[ind][k] != -1) return dp[ind][k];
        
        int notTake = solve(ind - 1,k,arr,dp);
        int take = 0;
        if(k / arr[ind] > 0) take = 1 + solve(ind - 1,k / arr[ind],arr,dp);
        
        return dp[ind][k] = notTake + take;
    }
    int numOfSubsets(int arr[], int N, int K) {
        // code here
        vector<vector<int>> dp(N, vector<int> (K + 1, -1));
        
        return solve(N - 1,K,arr,dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends