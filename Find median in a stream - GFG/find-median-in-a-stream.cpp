// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    
    void insertHeap(int &x)
    {
        if(maxHeap.empty() && minHeap.empty()) maxHeap.push(x);
        else if(!maxHeap.empty() && minHeap.empty()){
            maxHeap.push(x);
            balanceHeaps();
        }else if(!maxHeap.empty() && !minHeap.empty()){
            if(x <= maxHeap.top()) maxHeap.push(x);
            else if(x > minHeap.top()) minHeap.push(x);
            else maxHeap.push(x);
            balanceHeaps();
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {   
        int maxSize = maxHeap.size();
        int minSize = minHeap.size();
        if(maxSize > minSize){
            while(maxSize - minSize != 1 && maxSize - minSize != 0){
                int maxTop = maxHeap.top();
                maxHeap.pop();
                minHeap.push(maxTop);
                maxSize--;
                minSize++;
            }
        }else if(maxSize < minSize){
            while(maxSize - minSize != 1 && maxSize - minSize != 0){
                int minTop = minHeap.top();
                minHeap.pop();
                maxHeap.push(minTop);
                minSize--;
                maxSize++;
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {   
        if(maxHeap.size() == minHeap.size()) return (minHeap.top() + maxHeap.top()) / 2;
        else if(maxHeap.size() > minHeap.size()) return maxHeap.top();
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends