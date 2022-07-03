// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
long long solve(int ind, int tar, vector<int> &scores, vector<vector<int>> &dp){
    if(tar == 0) return 1;
    if(ind == 0) return tar % scores[ind] == 0;

    if(dp[ind][tar] != -1) return dp[ind][tar];

    long long notTake = solve(ind - 1,tar,scores,dp);
    long long take = 0;
    if(tar >= scores[ind]) take = solve(ind,tar - scores[ind],scores,dp);
    
    return dp[ind][tar] = notTake + take;
}
long long int count(long long int n)
{
    vector<int> scores{3,5,10};
    
    vector<vector<int>> dp(3, vector<int> (n + 1, -1));
    
    long long ans = solve(2,n,scores,dp);
    return ans;
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends