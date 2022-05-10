// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    int solve(vector<int> nums, int n, int k, int** dp, int i, int s){
        
        if(i == n) return dp[i][s] = 0;
        
        
        if(dp[i][s] != -1) return dp[i][s];
        
        if(s == k) return dp[i][s] = solve(nums,n,k,dp,i + 1,s - nums[i]);
        
        else if(s > nums[i]){
            int cost1 = (s * s) + solve(nums,n,k,dp,i,k);
            int cost2 = solve(nums,n,k,dp,i + 1,s - nums[i] - 1);
            
            return dp[i][s] = min(cost1,cost2);
        }
        
        else if(s <= nums[i]) return dp[i][s] = (s * s) + solve(nums,n,k,dp,i,k);
    }
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        
        int** dp = new int*[n + 1];
        for(int i = 0; i < n + 1; i++) dp[i] = new int[k + 1];
        
        for(int i = 0; i < n + 1; i++){
            for(int j = 0; j < k + 1; j++) dp[i][j] = -1;
        }
        
        return solve(nums,n,k,dp,0,k);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends