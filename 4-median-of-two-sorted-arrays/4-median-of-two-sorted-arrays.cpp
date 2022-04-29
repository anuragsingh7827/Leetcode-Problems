class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        if(m < n) return findMedianSortedArrays(nums2,nums1);
        
        int low = 0;
        int high = n;
        double ans;
        while(low <= high){
            int mid = (low + high) / 2;
            
            int l1, l2, r1, r2;
            
            int l1idx = mid - 1;
            int l2idx = ((n + m + 1) / 2 ) - mid - 1;
            int r1idx = mid;
            int r2idx = ((n + m + 1) / 2 ) - mid;
            
            if(l1idx < 0) l1 = INT_MIN;
            else l1 = nums1[l1idx];
            
            if(l2idx < 0) l2 = INT_MIN;
            else l2 = nums2[l2idx];
            
            if(r1idx >= n) r1 = INT_MAX;
            else r1 = nums1[r1idx];
            
            if(r2idx >= m) r2 = INT_MAX;
            else r2 = nums2[r2idx];
            
            if(l1 > r2) high = mid - 1;
            else if(l2 > r1) low = mid + 1;
            else if(l1 <= r2 && l2 <= r1){
                if((n + m) % 2 == 0){
                    double x = max(l1,l2);
                    double y = min(r1,r2);
                    ans = (x + y) / 2;
                }else ans = max(l1,l2);
                break;
            }
        }
        return ans;
    }
};