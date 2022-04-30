// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int gap = ceil((n + m) / 2.0);
	    
	    while(gap > 0){
	        int i = 0;
	        int j = gap;
	        int flag1 = 0;
	        int flag2 = 0;
	        while(flag2 == 0 || j < m){
	            if(flag1 == 0 && i >= n){
	                i -= n;
	                flag1 = 1;
	            }
	            if(flag2 == 0 && j >= n){
	                j -= n;
	                flag2 = 1;
	            }
	            if(flag1 == 0 && flag2 == 0){
	                if(arr1[i] > arr1[j]) swap(arr1[i],arr1[j]);
	            }else if(flag1 == 0 && flag2 == 1){
	                if(arr1[i] > arr2[j]) swap(arr1[i],arr2[j]);
	            }else if(flag1 == 1 && flag2 == 1){
	                if(arr2[i] > arr2[j]) swap(arr2[i],arr2[j]);
	            }
	            i++;
	            j++;
	        }
	        if(gap == 1) gap /= 2;
	        else gap = ceil(gap / 2.0);
	    }
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends