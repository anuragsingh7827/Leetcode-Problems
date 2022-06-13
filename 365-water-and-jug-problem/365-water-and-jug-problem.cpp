class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x = jug1Capacity;
        int y = jug2Capacity;
        
        int total = x + y;
        
        queue<int> q;
        q.push(0);
        
        unordered_map<int,bool> visited;
        visited[0] = true;
        
        int dz[4] = {x, -x, y, -y};
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int vol = node + dz[i];
                if(!visited[vol] && vol >= 0 && vol <= total){
                    if(vol == targetCapacity) return true;
                    visited[vol] = true;
                    q.push(vol);
                }
            }
        }
        
        return false;
    }
};