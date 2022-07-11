// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int mod = 1e9 + 7;
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here
        int posCnt = 0;
        int negCnt = 0;
        int zerCnt = 0;
        long long pos = 1;
        long long neg = 1;
        int negativeLargest = INT_MIN;
        for(int i = 0; i < n; i++){
            if(a[i] > 0){
                posCnt++;
                pos = ((pos % mod) * (a[i] % mod)) % mod;
            }else if(a[i] < 0){
                negCnt++;
                negativeLargest = max(negativeLargest,a[i]);
                neg = ((neg % mod) * (a[i] % mod)) % mod;
            }else zerCnt++;
        }
        
        if(zerCnt == n || (zerCnt > 0 && zerCnt == n - 1 && negCnt == 1)) return 0;
        
        if(negCnt == 1 && zerCnt == 0 && posCnt == 0) return a[0];

        if(negCnt & 1){
            neg = ((neg % mod) / (negativeLargest % mod)) % mod;
        }
        return ((pos % mod) * (neg % mod)) % mod;
        
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends