//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string maxSum(string w,char x[], int b[],int n){
        int m = w.size();
          
        unordered_map<char,int> mpp;
          
        for(int i = 0; i < n; i++) mpp[x[i]] = b[i];
        
        vector<int> ascii;
        for(int i = 0; i < m; i++){
            if(mpp.count(w[i])) ascii.push_back(mpp[w[i]]);
            else ascii.push_back(int(w[i]));
        }
		
	    int cur = 0;
		int ms = INT_MIN;
		int p1 = 0;
		int p2 = 0;
		int start = 0;
		int end = 0;
		for(int i = 0; i < m; i++){
			cur += ascii[i];
			if(cur > ms){
				ms = cur;
				start = p1;
				end = p2;
			}
			p2++;
			if(cur < 0){
				cur = 0;
				p1 = p2;
			}
		}
		
		string ans;
		for(int i = start; i <= end; i++) ans.push_back(w[i]);
		
		return ans;
          
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends