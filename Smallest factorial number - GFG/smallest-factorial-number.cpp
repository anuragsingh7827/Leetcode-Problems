// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int trailingZeroes(int n){
            int cnt = 0;
            int i = 1;
            while(n / 5 > 0){
                cnt += n / 5;
                n /= 5;
                i++;
            }
            
            return cnt;
        }
        int findNum(int n)
        {
            //complete the function here
            int lo = 0;
            int hi = INT_MAX;
            int ans;
            while(lo <= hi){
                int mid = lo + ((hi - lo) / 2);
                if(trailingZeroes(mid) >= n){
                    ans = mid;
                    hi = mid - 1;
                }else lo = mid + 1;
            }
            
            return ans;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends