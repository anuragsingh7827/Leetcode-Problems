// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> ans;
        deque<int> q;
        int i = 0;
        int j = 0;
    
        while(j < n){
            //calculations
            while(!q.empty() && q.back() < arr[j]) q.pop_back();
            q.push_back(arr[j]);
            
            //expand the window upto the size k
            if(j - i + 1 < k) j++;
            //window hits the size k
            else if(j - i + 1 == k){
                //calculate answer from calculations
                ans.push_back(q.front());
                // cout << q.front() << " ";
    
                // remove calculations for ith element
                if(arr[i] == q.front()) q.pop_front();
    
                //slide the window
                i++;
                j++;
            }
        }
    
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends