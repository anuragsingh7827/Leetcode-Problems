class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> dp(n);
        dp = nums;
        
        deque<int> q;
        q.push_back(dp[0]);
        
        int i = 0;
        int j = 1;
        int ans = dp[0];
        while(j < n){
            dp[j] = max(dp[j],nums[j] + q.front());
            ans = max(ans,dp[j]);
            
            while(!q.empty() && q.back() < dp[j]) q.pop_back();
            q.push_back(dp[j]);
            
            if(j - i < k) j++;
            else if(j - i == k){
                if(dp[i] == q.front()) q.pop_front();
                i++;
                j++;
            }
        }
        
        return ans;
    }
};