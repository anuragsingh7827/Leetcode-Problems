// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int n = s.length();
	    vector<int> ans(n);
	    
	    ans[0] = 0;
	    int i = 0;
	    int j = 1;
	    while(j < n){
	        if(s[i] == s[j]){
	            ans[j] = i + 1;
	            i++;
	            j++;
	        }else{
	            i = ans[i - 1];
	            if(s[i] != s[j]){
	                ans[j] = 0;
	                j++;
	            }
	        }
	    }
	    return ans[n - 1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends