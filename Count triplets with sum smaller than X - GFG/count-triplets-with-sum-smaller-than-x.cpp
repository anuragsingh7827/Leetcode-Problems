// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr,arr + n);
	    
	    long long cnt = 0;
	    for(int i = 0; i < n - 2; i++){
	        long long target = sum - arr[i];
	        
	        long long first = i + 1;
	        long long last = n - 1;
	        
	        while(first < last){
	            if(arr[first] + arr[last] < target){
	                cnt += (last - first);
	                first++;
	            }else if(arr[first] + arr[last] == target){
	                cnt += (last - first - 1);
	                first++;
	            }else last--;
	        }
	    }
	    
	    return cnt;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends