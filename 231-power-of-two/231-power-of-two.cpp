class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        
        int no = n & (n - 1);
        if(no == 0) return true;
        return false;
    }
};