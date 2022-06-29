// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int ind, int tar, int arr[],vector<vector<int>> &dp){
        if(tar == 0) return 1;
        if(ind == 0) return tar == arr[0];
        
        if(dp[ind][tar] != -1) return dp[ind][tar];
        
        int notTake = solve(ind - 1,tar,arr,dp);
        
        int take = 0;
        if(tar >= arr[ind]) take = solve(ind- 1,tar - arr[ind],arr,dp);
        
        return dp[ind][tar] = notTake || take;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i < N; i++) sum += arr[i];
        
        if(sum & 1) return 0;
        
        int target = sum / 2;
        
        vector<int> prev(target + 1, 0), cur(target + 1, 0);
        
        prev[0] = 1;
        for(int tar = 1; tar <= target; tar++){
            if(tar == arr[0]) prev[tar] = 1;
        }
        
        for(int ind = 1; ind < N; ind++){
            cur[0] = 1;
            for(int tar = 1; tar <= target; tar++){
                int notTake = prev[tar];
        
                int take = 0;
                if(tar >= arr[ind]) take = prev[tar - arr[ind]];
                
                cur[tar] = notTake || take;
            }
            prev = cur;
        }
        
        return prev[target];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends