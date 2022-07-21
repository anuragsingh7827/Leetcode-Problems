class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;
        int ans = n;
        while(i < n){
            if(nums[i] < n && i != nums[i]) swap(nums[i],nums[nums[i]]);
            else if(nums[i] >= n){
                ans = i;
                i++;
            }else i++;
        }
        
        return ans;
    }
};