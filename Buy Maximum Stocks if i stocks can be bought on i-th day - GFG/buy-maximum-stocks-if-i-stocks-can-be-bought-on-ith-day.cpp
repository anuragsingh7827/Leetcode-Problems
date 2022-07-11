// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> sortedPrices(n);
        for(int i = 0; i < n; i++) sortedPrices[i] = {price[i],i + 1};
        
        sort(sortedPrices.begin(),sortedPrices.end());
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int amt = sortedPrices[i].first;
            int qt = sortedPrices[i].second;
            int x = min(k / amt,qt);
            cnt += x;
            k -= (x * amt); 
        }
        
        return cnt;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends