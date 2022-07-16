class Solution {
public:
    bool isPowerOfTwo(long long n) {
        if(n == 0) return false;
        
        long long no = n & (n - 1);
        if(no == 0) return true;
        return false;
    }
};