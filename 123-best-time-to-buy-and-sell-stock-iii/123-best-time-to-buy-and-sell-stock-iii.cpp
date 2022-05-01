class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int* ftmp = new int[n];
        
        int firstTranCurr = 0;
        int tillToday = 0;
        ftmp[0] = tillToday;
        int mn = prices[0];
        
        for(int i = 1; i < n; i++){
            firstTranCurr = max(firstTranCurr,prices[i] - mn);
            ftmp[i] = max(ftmp[i - 1],firstTranCurr);
            mn = min(mn,prices[i]);
        }
        
        int* stmp = new int[n];
        
        int secondTranCurr = 0;
        int tillTomorrow = 0;
        stmp[n - 1] = 0;
        int mx = prices[n - 1];
        
        for(int i = n - 2; i >= 0; i--){
            secondTranCurr = max(secondTranCurr,mx - prices[i]);
            stmp[i] = max(stmp[i + 1],secondTranCurr);
            mx = max(mx,prices[i]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) ans = max(ans,ftmp[i] + stmp[i]);
        
        return ans;
        
        
    }
};