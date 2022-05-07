class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,pair<int,int>> h;
        
        for(int i = 0; i < n; i++){
            h[nums[i]].first++;
            h[nums[i]].second = i;
        }
        
        vector<int> ans(2);
        for(int i = 0; i < n; i++){
            int x = nums[i];
            h[x].first--;
            if(h[target - x].first > 0){
                ans[0] = i;
                ans[1] = h[target - x].second;
                break;
            }
        }
        
        return ans;
    }
};