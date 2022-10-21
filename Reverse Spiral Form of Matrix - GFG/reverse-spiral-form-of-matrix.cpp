//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        int sr = 0;
        int sc = 0;
        int er = R - 1;
        int ec = C - 1;
        vector<int> ans;
        
        while(sr <= er && sc <= ec){
            for(int i = sc; i <= ec; i++) ans.push_back(a[sr][i]);
            sr++;
            for(int i = sr; i <= er; i++) ans.push_back(a[i][ec]);
            ec--;
            if(sr <= er){
                for(int i = ec; i >= sc; i--) ans.push_back(a[er][i]);
                er--;
            }
            if(sc <= ec){
                for(int i = er; i >= sr; i--) ans.push_back(a[i][sc]);
                sc++;
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends