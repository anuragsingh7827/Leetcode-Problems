class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> h;
        for(int i = 0; i < n; i++) h[nums[i]]++;
        
        vector<int> ans;
        for(auto x: h){
            if(x.second > n / 3) ans.push_back(x.first);
        }
        
        return ans;
    }
};