// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int studentsAllocatedMidNoOfPages(int A[], int N, int mid, int M){
        int cnt = 1;
        int totalPages = 0;
        for(int i = 0; i < N; i++){
            if(A[i] > mid) return M + 1;
            totalPages += A[i];
            if(totalPages > mid){
                cnt++;
                totalPages = A[i];
            }
        }
        
        return cnt;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M > N) return -1;
        int lo = INT_MAX;
        int hi = 0;
        for(int i = 0; i < N; i++){
            lo = min(lo,A[i]);
            hi += A[i];
        }
        int ans = INT_MAX;
        while(lo <= hi){
            int mid = lo + ((hi - lo) / 2);
            if(studentsAllocatedMidNoOfPages(A,N,mid,M) <= M){
                ans = mid;
                hi = mid - 1;
            }else lo = mid + 1;
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends