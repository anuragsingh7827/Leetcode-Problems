// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(pair<double,Item> a, pair<double,Item> b){
        return a.first > b.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,Item>> ratios(n);
        for(int i = 0; i < n; i++){
            double ratio = arr[i].value / (arr[i].weight * 1.0);
            Item x;
            x.value = arr[i].value;
            x.weight = arr[i].weight;
            ratios[i] = {ratio,x};
        }
        
        sort(ratios.begin(),ratios.end(),comp);
        
        double ans = 0;
        for(int i = 0; i < n; i++){
            double ratio = ratios[i].first;
            int val = ratios[i].second.value;
            int wt = ratios[i].second.weight;
            if(W >= wt){
                ans += val;
                W -= wt;
            }else{
                ans += (W * ratio * 1.0);
                break;
            }
        }
        return ans;
        
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends