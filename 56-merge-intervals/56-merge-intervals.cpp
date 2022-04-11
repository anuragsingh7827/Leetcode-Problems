class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> v{intervals[0][0],intervals[0][1]};
        
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= v[0] && intervals[i][0] <= v[1]){
                v[1] = max(v[1],intervals[i][1]);
            }else{
                ans.push_back(v);
                v = intervals[i];
            }
        }
        
        ans.push_back(v);
        
        return ans;
    }
};