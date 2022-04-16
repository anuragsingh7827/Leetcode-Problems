// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int arr[], int N, int target, int i, int** dp){
        
        if(target == 0) return 1;
        if(i == N){
            if(target == 0) return 1;
            return 0;
        }
        
        
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int op1 = solve(arr,N,target,i + 1,dp);
        
        int op2 = 0;
        if(target >= arr[i]) op2 = solve(arr,N,target - arr[i],i + 1,dp);
        
        if(op1 == 1) return dp[i][target] = op1;
        else if(op2 == 1) return dp[i][target] = op2;
        else return dp[i][target] = 0;
        
        
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i < N; i++) sum += arr[i];
        
        if(sum % 2 != 0) return 0;
        
        int** dp = new int*[N + 1];
        for(int i = 0; i < N + 1; i++) dp[i] = new int[sum + 1];
        
        for(int i = 0; i < N + 1; i++){
            for(int j = 0; j < sum + 1; j++) dp[i][j] = -1;
        }
        
        int ans = solve(arr,N,sum / 2,0,dp);
        
        for(int i = 0; i < N + 1; i++) delete[] dp[i];
        
        delete[] dp;
        
        return ans;
        
        
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