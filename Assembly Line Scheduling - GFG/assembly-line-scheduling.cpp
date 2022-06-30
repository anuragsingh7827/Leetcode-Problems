// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function Template for C++



class Solution{
 public:
    int solve(int i, int j, vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<vector<int>> &dp){
        if(j == 0){
            if(i == 0) return a[0][0] + e[0];
            return a[1][0] + e[1];
        }
    
        if(dp[i][j] != -1) return dp[i][j];
    
        if(i == 0){
            int st = a[0][j] + solve(i,j - 1,a,T,e,dp);
            int dg = a[0][j] + T[1][j] + solve(i + 1,j - 1,a,T,e,dp);
            return dp[i][j] = min(st,dg);
        }else{
            int st = a[1][j] + solve(i,j - 1,a,T,e,dp);
            int dg = a[1][j] + T[0][j] + solve(i - 1,j - 1,a,T,e,dp);
            return dp[i][j] = min(st,dg);
        }
    }
    int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
          //Code Here
        int ans = INT_MAX;
        int m = a[0].size();
        vector<int> prev(2, 0);
        
        prev[0] = a[0][0] + e[0];
        prev[1] = a[1][0] + e[1];
        
        for(int j = 1; j < m; j++){
            int temp;
            for(int i = 0; i < 2; i++){
                if(i == 0){
                    int st = a[0][j] + prev[i];
                    int dg = a[0][j] + T[1][j] + prev[i + 1];
                    temp = prev[i];
                    prev[i] = min(st,dg);
                }else{
                    int st = a[1][j] + prev[i];
                    int dg = a[1][j] + T[0][j] + temp;
                    prev[i] = min(st,dg);
                }
            }
        }
        
        
        for(int i = 0; i < 2; i++) ans = min(ans,x[i] + prev[i]);
    
        return ans;
    }
};

// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(2,vector<int>(n)), T(2,vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>T[i][j];
            }
        }   
        vector<int> e(2), x(2);
        for(int i=0;i<2;i++){
            cin>>e[i];
        }
        for(int i=0;i<2;i++){
            cin>>x[i];
        }
        
        Solution ob;
        int ans = ob.carAssembly(a,T,e,x);
        
        cout<<ans<<endl;
    }
}  // } Driver Code Ends