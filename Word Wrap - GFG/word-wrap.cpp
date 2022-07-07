// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solve(int ind, int x, vector<int> nums, int k, int n, vector<vector<int>> &dp){
        if(ind == n) return 0;
        
        if(dp[ind][x] != -1) return dp[ind][x];
        
        if(x == k) return dp[ind][x] = solve(ind + 1,x - nums[ind],nums,k,n,dp);
        
        int notPlace = (x * x) + solve(ind,k,nums,k,n,dp);
        int place = INT_MAX;
        int wordSpace = 1 + nums[ind];
        if(x >= wordSpace) place = solve(ind + 1,x - wordSpace,nums,k,n,dp);
        
        return dp[ind][x] = min(notPlace,place);
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        
        vector<int> ahead(k + 1, 0), cur(k + 1, 0);
        
        for(int ind = n - 1; ind >= 0; ind--){
            for(int x = k; x >= 0; x--){
                if(x == k) cur[x] = ahead[x - nums[ind]];
                else{
                    int notPlace = (x * x) + cur[k];
                    int place = INT_MAX;
                    int wordSpace = 1 + nums[ind];
                    if(x >= wordSpace) place = ahead[x - wordSpace];
                    
                    cur[x] = min(notPlace,place);
                }
            }
            ahead = cur;
        }
        
        return ahead[k];
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