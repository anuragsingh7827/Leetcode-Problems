//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    // Code here
	    vector<long long> dp(n + 1,0);
	    dp[0] = 0;
	    dp[1] = 1;
	    
	    for(int i = 2; i <= n; i++){
	        if(i < 7) dp[i] = 3 * dp[i - 1];
	        else if(i == 7) dp[i] = (3 * dp[i - 1]) - dp[2];
	        else{
	            long long x = 3 * dp[i - 1];
	            long long y = 2 * dp[i - 6];
	            dp[i] = x - y;
	        }
	    }
	    
	    return dp[n];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends