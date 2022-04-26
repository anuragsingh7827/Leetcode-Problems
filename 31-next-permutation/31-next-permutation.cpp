class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int k = -1;
        for(int i = size - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                k = i;
                break;
            }
        }
        if(k != -1){
            int start = k + 1;
            int end = size - 1;
            int justGreater = k + 1;
            while(start <= end){
                int mid = (start + end) / 2;
                if(nums[mid] > nums[k]){
                    justGreater = mid;
                    start = mid + 1;
                }
                else end = mid - 1;
            }
            swap(nums[k],nums[justGreater]);
        }
        
        reverse(nums.begin() + k + 1, nums.end());

    }
};