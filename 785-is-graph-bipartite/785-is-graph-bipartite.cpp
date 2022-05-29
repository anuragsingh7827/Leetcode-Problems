class Solution {
public:
    bool isBipartiteDFS(int start, vector<vector<int>> graph, int* &color, int val){
        color[start] = val;
        for(auto &it : graph[start]){
            if(color[it] == -1){
                if(!isBipartiteDFS(it,graph,color,1 - val)) return false;
            }else if(color[it] == color[start]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        int* color = new int[n];
        for(int i = 0; i < n; i++) color[i] = -1;

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(!isBipartiteDFS(i,graph,color,1)) return false;
            }
        }
        return true;
    }
};