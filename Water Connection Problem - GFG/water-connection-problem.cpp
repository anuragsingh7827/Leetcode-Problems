// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    void dfs(int start, vector<pair<int,int>>* adj, vector<int> &vis, int &last, int &mini){
        vis[start] = 1;
        for(auto &it : adj[start]){
            if(vis[it.first] == 0){
                mini = min(mini,it.second);
                dfs(it.first,adj,vis,last,mini);
            }
        }
        if(last == -1) last = start;
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<pair<int,int>>* adj = new vector<pair<int,int>> [n + 1];
        for(int i = 0; i < p; i++){
            adj[a[i]].push_back({b[i],d[i]});
            adj[b[i]].push_back({a[i],d[i]});
        }
        
        unordered_map<int,bool> h;
        for(int i = 0; i < p; i++) h[a[i]] = true;
        
        unordered_map<int,int> par;
        for(int i = 0; i < p; i++) par[b[i]] = a[i];
        
        vector<vector<int>> ans;
        vector<int> vis(n + 1, 0);
        for(int i = 1; i <= n; i++){
            if(vis[i] == 0 && par[i] == 0 && h[i]){
                int last = -1;
                int mini = INT_MAX;
                dfs(i,adj,vis,last,mini);
                
                vector<int> temp(3); 
                temp[0] = i;
                temp[1] = last;
                temp[2] = mini;
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends