// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
            if(i == 0 || j == 0) return 0;
            
            if(dp[i][j] != -1) return dp[i][j];
            
            if(s1[i - 1] == s2[j - 1] && i != j) return dp[i][j] = 1 + solve(i - 1,j - 1,s1,s2,dp);
            
            return dp[i][j] = max(solve(i,j - 1,s1,s2,dp),solve(i - 1,j,s1,s2,dp));
        }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    vector<int> prev(n + 1, 0);
		    
		    for(int i = 1; i <= n; i++){
		        int temp = prev[0];
		        for(int j = 1; j <= n; j++){
		            int val;
		            if(str[i - 1] == str[j - 1] && i != j) val = 1 + temp;
                    else val = max(prev[j - 1],prev[j]);
                    temp = prev[j];
                    prev[j] = val;
		        }
		    }
		    
		    return prev[n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends