// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int minCandies(int candies[], int n, int k){
        int i = 0;
        int j = n - 1;
        int cnt = 0;
        while(i <= j){
            cnt += candies[i];
            i++;
            j -= k;
        }
        
        return cnt;
    }
    int maxCandies(int candies[], int n, int k){
        int i = n - 1;
        int j = 0;
        int cnt = 0;
        while(i >= j){
            cnt += candies[i];
            i--;
            j += k;
        }
        
        return cnt;
    }
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vector<int> ans(2);
        
        sort(candies,candies + N);
        
        ans[0] = minCandies(candies,N,K);
        ans[1] = maxCandies(candies,N,K);
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends