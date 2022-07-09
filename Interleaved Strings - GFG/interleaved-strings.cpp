// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool solve(int i, int j, int k, string a, string b, string c, vector<vector<int>> &dp){
        if(i < 0 && j >= 0){
            while(j >= 0 && k >= 0){
                if(b[j] != c[k]) return false;
                j--;
                k--;
            }
            if(j < 0 && k < 0) return true;
            return false;
        } 
        if(j < 0 && i >= 0){
            while(i >= 0 && k >= 0){
                if(a[i] != c[k]) return false;
                i--;
                k--;
            }
            if(i < 0 && k < 0) return true;
            return false;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(a[i] == c[k] && b[j] == c[k]){
            bool op1 = solve(i - 1,j,k - 1,a,b,c,dp);
            bool op2 = solve(i,j - 1,k - 1,a,b,c,dp);
            
            return dp[i][j] = op1 || op2;
        }
        else if(a[i] == c[k]) return dp[i][j] = solve(i - 1,j,k - 1,a,b,c,dp);
        else if(b[j] == c[k]) return dp[i][j] = solve(i,j - 1,k - 1,a,b,c,dp);
        
        else return dp[i][j] = false;
        
    }
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int n = A.size();
        int m = B.size();
        int l = C.size();
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return solve(n - 1,m - 1,l - 1,A,B,C,dp);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends