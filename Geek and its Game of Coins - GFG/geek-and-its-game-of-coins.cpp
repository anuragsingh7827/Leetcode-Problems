// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int solve(int n, int x, int y, vector<int> &dp){
	    if(n == 0) return 0;
	    if(n == 1) return 1;
	    
	    if(dp[n] != -1) return dp[n];
	    
	    if(n - 1 >= 0 && solve(n - 1,x,y,dp) == 0) return dp[n] = 1;
	    else if(n - x >= 0 && solve(n - x,x,y,dp) == 0) return dp[n] = 1;
	    else if(n - y >= 0 && solve(n - y,x,y,dp) == 0) return dp[n] = 1;
	    return dp[n] = 0;
	}
	int findWinner(int N, int X, int Y)
	{
		// Your code goes here
		vector<int> dp(N + 1, 0);
		
		dp[0] = 0;
		dp[1] = 1;
		
		for(int i = 2; i <= N; i++){
		    if(i - 1 >= 0 && dp[i - 1] == 0) dp[i] = 1;
    	    else if(i - X >= 0 && dp[i - X] == 0) dp[i] = 1;
    	    else if(i - Y >= 0 && dp[i - Y] == 0) dp[i] = 1;
    	    else dp[i] = 0;
		}
		
		return dp[N];
	}

};
	

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends