// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int ans = INT_MIN;
        for(int i = 0; i < R; i++){
            vector<int> row(C, 0);
            for(int j = i; j < R; j++){
                for(int k = 0; k < C; k++) row[k] += M[j][k];
                int cur = 0;
                for(int k = 0; k < C; k++){
                    cur += row[k];
                    ans = max(ans,cur);
                    if(cur < 0) cur = 0;
                }
            }
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends