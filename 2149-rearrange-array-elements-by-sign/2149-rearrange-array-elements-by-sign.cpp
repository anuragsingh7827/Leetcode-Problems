class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        
        int a = 0, b = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                nums[i] = pos[a];
                a++;
            }else{
                nums[i] = neg[b];
                b++;
            }
        }
        
        return nums;
    }
};