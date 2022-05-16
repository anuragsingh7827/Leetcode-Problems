// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int longestPrefixSuffix(string temp){
        int n = temp.length();
        
        vector<int> pi(n,0);
        
        for(int i = 1; i < n; i++){
            int j = pi[i - 1];
            
            while(j > 0 && temp[i] != temp[j]) j = pi[j - 1];
            
            if(temp[i] == temp[j]) pi[i] = j + 1;
        }
        
        return pi[n - 1];
    }
    int minChar(string str){
        //Write your code here
        int n = str.length();
        
        string strCopy = str;
        
        reverse(strCopy.begin(),strCopy.end());
        
        string temp = str + strCopy;
        
        int lps = longestPrefixSuffix(temp);
        
        
        if(n - lps > 0) return n - lps;
        return 0;
        
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends