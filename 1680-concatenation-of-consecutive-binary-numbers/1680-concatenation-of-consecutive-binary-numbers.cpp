class Solution {
public:
    int mod = 1e9 + 7;
    int concatenatedBinary(int n) {
        
        long long ans = 0;
        long long len = 0;
        long long mul = 1;
        for(long long i = n; i > 0; i--){
            ans = ((ans % mod) + ((i % mod) * (mul % mod)) % mod) % mod;
            int newLen = (floor(log2(i)) + 1);
            for(int j = 0; j < newLen; j++){
                mul = ((mul % mod) * (2 % mod)) % mod;
            }
        }
        return ans;
    }
};