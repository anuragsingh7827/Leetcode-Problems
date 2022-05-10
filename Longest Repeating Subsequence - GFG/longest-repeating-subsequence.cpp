// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.length();
		    int** dp = new int*[n + 1];
		    for(int i = 0; i < n + 1; i++) dp[i] = new int[n + 1];
		    
            for(int i = 0; i < n + 1; i++) dp[i][n] = 0;
            for(int j = 0; j < n + 1; j++) dp[n][j] = 0;
            
            for(int i = n - 1; i >= 0; i--){
                for(int j = n - 1; j >= 0; j--){
                    if(str[i] != str[j] || (str[i] == str[j] && i == j)) dp[i][j] = max(dp[i][j + 1],dp[i + 1][j]);
                    else if(str[i] == str[j] && i != j) dp[i][j] = 1 + dp[i + 1][j + 1];
                }
            }
            
            return dp[0][0];
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