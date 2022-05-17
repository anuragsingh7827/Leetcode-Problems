// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	// Your code goes here
    	int n = A.length();
    	int m = B.length();
    	
    	int i = n - 1;
    	int j = m - 1;
    	
    	int ans = 0;
    	unordered_map<char,int> h;
    	while(i >= 0 && j >= 0){
    	    if(A[i] != B[j]){
    	        h[A[i]]++;
    	        ans++;
    	        i--;
    	    }else{
    	        i--;
    	        j--;
    	    }
    	}
    	
    	while(j >= 0){
    	    if(h[B[j]] > 0){
    	        h[B[j]]--;
    	        j--;
    	    }else return -1;
    	}
    	
    	return ans;
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends