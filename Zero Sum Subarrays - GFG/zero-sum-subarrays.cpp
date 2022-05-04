// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        ll int* cumm = new ll int[n];
        
        cumm[0] = arr[0];
        for(int i = 1; i < n; i++) cumm[i] = cumm[i - 1] + arr[i];
        
        unordered_map<int,int> freq;
        for(int i = 0; i < n; i++) freq[cumm[i]]++;
        
        ll ans = 0;
        for(auto &node: freq){
            if(node.first == 0){
                ll temp = node.second;
                ll cnt = (temp * (temp + 1)) / 2;
                ans += cnt;
            }else if(node.first != 0 && node.second >= 2){
                ll temp = node.second;
                ll cnt = (temp * (temp - 1)) / 2;
                ans += cnt;
            }
        }
        
        return ans;
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
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends