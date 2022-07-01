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
        //I am able to include arr[ind] in my current subsequence only if the 
        //product after including it still remains less than k and because I've included arr[ind] in
        //current subsequence therefore I got a new subsequence who's arr[ind] recently became a part
        //thats why I am doing 1 + below in take case and then I am making a recursive call to get the
        //number of subsequences that can be formed from the remaining array whose arr[ind] is a part and
        //product is less than k.
        if(k / arr[ind] > 0) take = 1 + solve(ind - 1,k / arr[ind],arr,dp);
        
        return dp[ind][k] = notTake + take;
    }
    int numOfSubsets(int arr[], int N, int K) {
        // code here
        vector<int> prev(K + 1, 0), cur(K + 1, 0);
        
        for(int i = 1; i <= K; i++){
            if(arr[0] <= i) prev[i] = 1;
        }
        
        for(int ind = 1; ind < N; ind++){
            for(int k = 1; k <= K; k++){
                int notTake = prev[k];
                int take = 0;
                if(k / arr[ind] > 0) take = 1 + prev[k / arr[ind]];
                
                cur[k] = notTake + take;
            }
            prev = cur;
        }
        
        
        return prev[K];
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