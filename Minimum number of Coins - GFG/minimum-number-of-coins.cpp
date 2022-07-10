// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int ind, int tar, vector<int> den, 
            vector<int> coins, int cur, vector<int> &ans, int &size){
        if(ind == 0){
            cur += tar;
            while(tar > 0){
                coins.push_back(1);
                tar--;
            }
            if(cur < size){
                size = cur;
                ans = coins;
            }
            return;
        }
        
        if(tar >= den[ind]){
            coins.push_back(den[ind]);
            cur++;
            solve(ind,tar - den[ind],den,coins,cur,ans,size);
        }
        else solve(ind - 1,tar,den,coins,cur,ans,size);
    }
    vector<int> minPartition(int N)
    {
        // code here
        //it is a greedy aproach as there is uniformity in the the given denominations array that is 
        // it is sorted and the first denomination is 1. Also its time complexity will be linear 
        //as on each index 'ind' we are making only 1 recursive call.
        
        vector<int> den{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        
        vector<int> ans;
        int size = INT_MAX;
        
        solve(9,N,den,{},0,ans,size);
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends