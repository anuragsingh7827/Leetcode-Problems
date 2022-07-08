// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        vector<int> cumm(n);
        cumm[0] = A[0];
        for(int i = 1; i < n; i++) cumm[i] += cumm[i - 1] + A[i];
        
        unordered_map<int,vector<int>> indices;
        for(int i = 0; i < n; i++) indices[cumm[i]].push_back(i);
        
        int len = 0;
        for(auto &it : indices){
            int startInd = it.second.front();
            int endInd = it.second.back();
            
            if(it.first == 0) len = max(len,endInd + 1);
            
            else len = max(len,endInd - startInd);
        }
        
        return len;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends