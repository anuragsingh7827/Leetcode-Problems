class triplet{
public:
    int start;
    int end;
    int profit;
    triplet(int start, int end, int profit){
        this->start = start;
        this->end = end;
        this->profit = profit;
    }
};
class Solution {
public:
    static bool comp(triplet a, triplet b){
        return a.end < b.end;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<triplet> arr;
        for(int i = 0; i < n; i++){
            int s = startTime[i];
            int e = endTime[i];
            int p = profit[i];
            arr.push_back(triplet(s,e,p));
        }
        
        sort(arr.begin(),arr.end(),comp);
        
        int* dp = new int[n];
        dp[0] = arr[0].profit;
        
        for(int i = 1; i < n; i++){
            int lo = 0;
            int hi = i - 1;
            int last = -1;
            while(lo <= hi){
                int mid = lo + ((hi - lo) / 2);
                if(arr[mid].end <= arr[i].start){
                    last = mid;
                    lo = mid + 1;
                }else  hi = mid - 1;
            }
            int inc = arr[i].profit;
            if(last != -1) inc += dp[last];
            
            int exc = dp[i - 1];
            
            dp[i] = max(inc,exc);
            
        }
        
        return dp[n - 1];
        
    }
};