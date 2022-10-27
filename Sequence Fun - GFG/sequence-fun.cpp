//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
		int NthTerm(int n){
		    // Code  here
		    int mod = 1e9 + 7;
		    long long ans = 2;
		    long long mul = 2;
		    for(int i = 2; i <= n; i++){
		        long long temp = (ans % mod) * (mul % mod) % mod;
		        ans = (temp + 1) % mod;
		        mul++;
		    }
		    
		    return ans % mod;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends