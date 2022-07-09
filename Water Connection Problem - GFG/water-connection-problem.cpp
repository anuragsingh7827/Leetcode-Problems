// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<int> v(21, 0), di(21, 0);
        unordered_map<int,int> h;
        
        for(int i = 0; i < p ; i++){
            v[a[i]] = b[i];
            di[a[i]] = d[i];
            h[b[i]] = a[i];
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < 21; i++){
            if(h[i] == 0 && v[i] != 0){
                int j = i;
                vector<int> temp(3);
                temp[0] = j;
                int mini = INT_MAX;
                while(v[j] != 0){
                    mini = min(mini,di[j]);
                    j = v[j];
                }
                temp[1] = j;
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