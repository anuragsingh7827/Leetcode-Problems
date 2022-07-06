// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    int solve(int i, int j, int arr[], vector<vector<int>> &dp){
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int op1 = solve(i + 2,j,arr,dp);
        int op2 = solve(i + 1,j - 1,arr,dp);
        int op3 = solve(i,j - 2,arr,dp);
        
        return dp[i][j] = max(arr[i] + min(op1,op2), arr[j] + min(op2,op3));
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        return solve(0,n - 1,arr,dp);
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends