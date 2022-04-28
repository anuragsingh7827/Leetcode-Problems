class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int cnt = 0;
        int curr = nums[0];
        for(int i = 0; i < n; i++){
            if(curr == nums[i]) cnt++;
            else{
                if(cnt > n / 3) ans.push_back(curr);
                curr = nums[i];
                cnt = 1;
            }
        }
        if(cnt > n / 3) ans.push_back(curr);
        
        return ans;
    }
};