class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int a = -1, b = -1;
        // for(int i = size - 1; i >= 0; i--){
        //     for(int j = i - 1; j >= 0; j--){
        //         if(nums[j] < nums[i]){
        //             if(j > a){
        //                 a = j;
        //                 b = i;
        //             }
        //         }
        //     }
        // }
        stack<int> s;
        for(int i = size - 1; i >= 0; i--){
            if(s.empty()) s.push(i);
            else if(nums[i] > nums[s.top()]) s.push(i);
            else if(nums[i] < nums[s.top()]){
                a = i;
                while(!s.empty() && nums[i] < nums[s.top()]){
                    b = s.top();
                    s.pop();
                }
                break;
            }
        }
        
        if(a == -1) sort(nums.begin(),nums.end());
        else{
            swap(nums[a],nums[b]);
            sort(nums.begin() + a + 1, nums.end());
        }
        
    }
};