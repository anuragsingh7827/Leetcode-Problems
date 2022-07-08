// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
        //Code Here
        int N = a.size();
        int M = a[0].size();
        
        int sr, er, sc, ec;
        int area = 0;
        int len = 0;
        for(int i = 0; i < N; i++){
            vector<int> temp(M, 0);
            for(int j = i; j < N; j++){
                for(int k = 0; k < M; k++) temp[k] += a[j][k];
                
                vector<int> cumm(M);
                cumm[0] = temp[0];
                for(int k = 1; k < M; k++) cumm[k] += cumm[k - 1] + temp[k];
                
                unordered_map<int,vector<int>> indices;
                for(int k = 0; k < M; k++) indices[cumm[k]].push_back(k);
                
                for(auto &it : indices){
                    int startInd = it.second.front();
                    int endInd = it.second.back();
                    
                    int dim1 = j - i + 1;
                    int dim2 = endInd + 1;
                    int dim3 = endInd - startInd;
                    if(it.first == 0 && (dim1 * dim2) >= area){
                        if(dim1 * dim2 > area || dim2 > len){
                            len = dim2;
                            area = dim1 * dim2;
                            sc = 0;
                            ec = endInd;
                            sr = i;
                            er = j;    
                        }
                    }
                    if(it.first != 0 && (dim1 * dim3) >= area){
                        if((dim1 * dim3) > area || dim3 > len){
                            len = dim3;
                            area = dim1 * dim3;
                            sc = startInd + 1;
                            ec = endInd;
                            sr = i;
                            er = j;   
                        }
                    }
                }
            }
        }
        
        if(area == 0) return {};
        
        vector<vector<int>> ans;
        for(int i = sr; i <= er; i++){
            vector<int> row;
            for(int j = sc; j <= ec; j++) row.push_back(a[i][j]);
            ans.push_back(row);
        }
        
        return ans;
    }
};


// { Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}  // } Driver Code Ends