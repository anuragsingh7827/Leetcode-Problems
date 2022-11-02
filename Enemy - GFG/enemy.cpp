//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            if(k == 0) return n * m;
            
            vector<int> x(k);
            vector<int> y(k);
            
            for(int i = 0; i < k; i++){
                x[i] = enemy[i][0];
                y[i] = enemy[i][1];
            }
            
            sort(x.begin(),x.end());
            sort(y.begin(),y.end());
            
            int len1 = x[0] - 1;
            int len2 = y[0] - 1;

            for(int i = 1; i < k; i++){
                len1 = max(len1,x[i] - x[i - 1] - 1);
                len2 = max(len2,y[i] - y[i - 1] - 1);
            }

            len1 = max(len1,n - x[k - 1]);
            len2 = max(len2,m - y[k - 1]);
            
            return len1 * len2;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends