//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		deque<pair<int,int>> q;
		q.push_back({0,0});
		
		vector<int> ans;
		while(!q.empty()){
		    auto p = q.front();
		    q.pop_front();
		    
		    int i = p.first;
		    int j = p.second;
		    
		    ans.push_back(A[i][j]);
		    
		    if(j + 1 < N){
		        if(!q.empty()){
		            int oldI = q.back().first;
		            int oldJ = q.back().second;
		            if(i != oldI && j + 1 != oldJ) q.push_back({i,j + 1});
		        }else q.push_back({i,j + 1});
		    }
		    if(i + 1 < N){
		        if(!q.empty()){
		            int oldI = q.back().first;
		            int oldJ = q.back().second;
		            if(i + 1 != oldI && j != oldJ) q.push_back({i + 1,j});
		        }else q.push_back({i + 1,j});
		    }
		}
		
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends