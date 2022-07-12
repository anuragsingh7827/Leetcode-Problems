// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        sort(Arr.begin(),Arr.end());
        
        long long totalSum = 0;
        for(int i = 0; i < N; i++) totalSum += Arr[i];
        
        long long subsetSum = 0;
        int cnt = 0;
        for(int i = N - 1; i >= 0; i--){
            subsetSum += Arr[i];
            totalSum -= Arr[i];
            cnt++;
            if(subsetSum > totalSum) break;
        }
        
        return cnt;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}  // } Driver Code Ends