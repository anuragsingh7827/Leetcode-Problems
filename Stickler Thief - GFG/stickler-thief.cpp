// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int helper(int dp[], int n, int arr[], int i){
        
        if(i >= n) return dp[i] = 0;
        
        if(i == n - 1) return arr[i];
        
        if(dp[i] != -1) return dp[i];
        
        int x = arr[i] + helper(dp,n,arr,i + 2);
        int y = helper(dp,n,arr,i + 1);
        
        return dp[i] = max(x,y);
        
    }
    
    
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int dp[n + 1];
        
        for(int i = 0; i < n + 1; i++){
            dp[i] = -1;
        }
        
        return helper(dp,n,arr,0);
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends