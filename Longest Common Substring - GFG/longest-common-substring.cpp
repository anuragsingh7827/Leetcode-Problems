// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<int> prev(m + 1, 0);
        
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = m; j >= 1; j--){
                if(S1[i - 1] == S2[j - 1]) prev[j] = 1 + prev[j - 1];
                else prev[j] = 0;
                ans = max(ans,prev[j]);
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends