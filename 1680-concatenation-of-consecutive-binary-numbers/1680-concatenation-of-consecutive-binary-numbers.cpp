class Solution {
public:
    int mod = 1e9 + 7;
    int concatenatedBinary(int n) {
        
        long long ans = 0;
        for(long long i = 1; i <= n; i++){
            int len = floor(log2(i)) + 1;
            ans = (((ans << len) % mod) + (i % mod)) % mod;
        }
        return ans;
    }
};