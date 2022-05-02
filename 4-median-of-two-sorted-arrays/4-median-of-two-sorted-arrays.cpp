class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int cnt = 1;
        int i = 0;
        int j = 0;
        int mid = (n + m + 2) / 2;
        int first = 0;
        int second = 0;
        double ans;
        
        while(i < n && j < m){
            if(cnt == mid - 1) first = min(nums1[i],nums2[j]);
            else if(cnt == mid){
                if((n + m) % 2 == 0){
                    second = min(nums1[i],nums2[j]);
                    ans = (first + second) / 2.0;
                }else ans = min(nums1[i],nums2[j]);
            }
            
            if(nums1[i] <= nums2[j]) i++;
            else j++;
            cnt++;
        }
        
        while(i < n){
            if(cnt == mid - 1) first = nums1[i];
            if(cnt == mid){
                if((n + m) % 2 == 0){
                    second = nums1[i];
                    ans = (first + second) / 2.0;
                }else ans = nums1[i];
            }
            i++;
            cnt++;
        }
        
        while(j < m){
            if(cnt == mid - 1) first = nums2[j];
            if(cnt == mid){
                if((n + m) % 2 == 0){
                    second = nums2[j];
                    ans = (first + second) / 2.0;
                }else ans = nums2[j];
            }
            j++;
            cnt++;
        }
        
        return ans;
    }
};