// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        set<vector<int>> allQuads;
        
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                int target = k - (arr[i] + arr[j]);
                
                int first = j + 1;
                int last = n - 1;
                
                while(first < last){
                    if(arr[first] + arr[last] < target) first++;
                    else if(arr[first] + arr[last] > target) last--;
                    else if(arr[first] + arr[last] == target){
                        vector<int> quad;
                        quad.push_back(arr[i]);
                        quad.push_back(arr[j]);
                        quad.push_back(arr[first]);
                        quad.push_back(arr[last]);
                        
                        allQuads.insert(quad);
                        
                        first++;
                        last--;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto &v: allQuads) ans.push_back(v);
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends