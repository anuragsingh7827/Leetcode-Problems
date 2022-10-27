//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int N) {
        // code here
        vector<int> ans;
        stack<int> s;
        s.push(arr[0]);
        
        for(int i = 1; i < N; i++){
            if(arr[i] < s.top()) s.push(arr[i]);
            else{
                int cnt = 0;
                int temp;
                while(!s.empty() && arr[i] > s.top()){
                    if(cnt == 0) temp = s.top();
                    s.pop();
                    cnt++;
                }
                s.push(arr[i]);
                if(cnt >= 2) ans.push_back(temp);
            }
        }
        ans.push_back(arr[N - 1]);
        
        return ans;
    }
//     10
// 8 3 1 2 5 4 7 13 12 14
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends