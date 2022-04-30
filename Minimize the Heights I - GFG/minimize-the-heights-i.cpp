// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class pairs{
public:
    int height;
    int idx;
    pairs(int height, int idx){
        this->height = height;
        this->idx = idx;
    }
};
class Solution{   
public:
    static bool comp(pairs a, pairs b){
        return a.height < b.height;
    }
    int getMinDiff(int arr[], int n, int k) {
        // code here
        vector<pairs> v;
        for(int i = 0; i < n; i++){
            v.push_back(pairs(arr[i] + k,i));
            v.push_back(pairs(arr[i] - k,i));
        }
        
        sort(v.begin(),v.end(),comp);
        
        int towers = 0;
        unordered_map<int,int> counts;
        int ans = INT_MAX;
        int i = 0;
        int j = 0;
        while(j < v.size()){
            counts[v[j].idx]++;
            if(counts[v[j].idx] == 1) towers++;
            if(towers < n) j++;
            else if(towers == n){
                while(towers == n){
                    ans = min(ans,v[j].height - v[i].height);
                    counts[v[i].idx]--;
                    if(counts[v[i].idx] == 0) towers--;
                    i++;
                }
                j++;
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
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends