class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> v;
        
        for(int i = 0; i < n; i++) v.push_back(make_pair(nums[i],i));
        sort(v.begin(),v.end());
        
        vector<int> ans;
        int i = 0;
        int j = n - 1;
        while(i < j){
            auto x = v[i];
            auto y = v[j];
            if(x.first + y.first < target) i++;
            else if(x.first + y.first > target) j--;
            else{
                ans.push_back(x.second);
                ans.push_back(y.second);
                break;
            }
        }
        return ans;
    }
};