// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    void solve(int a[], int i, int n, int target, unordered_map<int,bool> &h, vector<int> subset){
        
        if(i == n){
            if(target == 0){
                for(int j = 0; j < subset.size(); j++) h[subset[j]] = true;
            }
            return;
        }
        
        solve(a,i + 1,n,target,h,subset);
   
        if(target >= a[i]){
            subset.push_back(a[i]);
            solve(a,i + 1,n,target - a[i],h,subset);
        }
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        //Your code here
        int sum = 0;
        for(int i = 0; i < n; i++) sum += a[i];
        
        if(sum % k != 0) return false;
        
        unordered_map<int,bool> h;
        vector<int> subset;
        solve(a,0,n,sum / k,h,subset);
        
        for(int i = 0; i < n; i++) if(!h[a[i]]) return false;
        
        return true;
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
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends