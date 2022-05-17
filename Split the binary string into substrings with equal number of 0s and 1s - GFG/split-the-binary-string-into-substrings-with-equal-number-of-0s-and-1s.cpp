// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int n = str.length();
        
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == '1') sum++;
            else if(str[i] == '0') sum--;
            if(sum == 0) cnt++;
        }
        
        if(sum == 0) return cnt;
        return -1;
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
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends