//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
        int maxi = INT_MIN;
        unordered_map<int,int> mpp;
        for(int i = 0; i < n; i++){
            maxi = max(maxi,a[i]);
            mpp[a[i]]++;
        }
        
        int ans = 0;
        for(int i = maxi; i > 0; i--){
            if(mpp[i] > 0 && mpp[i - 1] > 0){
                int mini = min(mpp[i],mpp[i - 1]);
                ans += (mini * i);
                mpp[i] -= mini;
                mpp[i - 1] -= mini;
                if(mpp[i] > 0) ans += (i * mpp[i]);
            }else if(mpp[i] > 0) ans += (i * mpp[i]);
        }
        
        return ans;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends