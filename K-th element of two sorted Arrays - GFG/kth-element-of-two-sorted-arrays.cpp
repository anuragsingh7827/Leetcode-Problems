// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        
        // if(m < n) return kthElement(arr2,arr1,m,n,k);
        
        //slight trickiness in finding lo and hi variables
        int lo;
        if(k - m >= 0) lo = k - m;
        else lo = 0;
        
        int hi;
        if(k - n >= 0) hi = n;
        else hi = k;
        
        
        while(lo <= hi){
            int mid = lo + ((hi - lo) / 2);
            
            int l1Idx = mid - 1;
            int l2Idx = k - mid - 1;
            int r1Idx = mid;
            int r2Idx = k - mid;
            
            int l1 = INT_MIN;
            if(l1Idx >= 0) l1 = arr1[l1Idx];
            
            int l2 = INT_MIN;
            if(l2Idx >= 0) l2 = arr2[l2Idx];
            
            int r1 = INT_MAX;
            if(r1Idx < n) r1 = arr1[r1Idx];
            
            int r2 = INT_MAX;
            if(r2Idx < m) r2 = arr2[r2Idx];
            
            if(l1 <= r2 && l2 <= r1) return max(l1,l2);
            else if(l1 > r2) hi = mid - 1;
            else if(l2 > r1) lo = mid + 1;
            
        }
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends