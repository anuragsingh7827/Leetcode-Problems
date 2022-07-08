class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        
        sort(pairs.begin(),pairs.end(),comp);
        
        vector<int> dp(n, 1);
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(pairs[i][0] > pairs[j][1]) dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans,dp[i]);
        }
        
        return ans;
    }
};