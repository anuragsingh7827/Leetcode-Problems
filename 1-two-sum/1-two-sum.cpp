class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        
        for(int i = 0; i < n; i++) v[i] = {nums[i],i};
        sort(v.begin(),v.end());
        
        vector<int> ans(2);
        int i = 0;
        int j = n - 1;
        while(i < j){
            auto x = v[i];
            auto y = v[j];
            if(x.first + y.first < target) i++;
            else if(x.first + y.first > target) j--;
            else{
                ans[0] = x.second;
                ans[1] = y.second;
                break;
            }
        }
        return ans;
    }
};