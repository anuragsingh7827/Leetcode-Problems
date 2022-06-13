// DFS solution
class Solution {
public:
    bool solve(int start, unordered_map<int,bool> &visited, int dz[], int total, int targetCapacity){
        visited[start] = true;
        
        if(start == targetCapacity) return true;
        
        for(int i = 0; i < 4; i++){
            int vol = start + dz[i];
            if(!visited[vol] && vol >= 0 && vol <= total){
                if(solve(vol,visited,dz,total,targetCapacity)) return true;
            }
        }
        
        return false;
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x = jug1Capacity;
        int y = jug2Capacity;
        
        int total = x + y;
        
        unordered_map<int,bool> visited;
        
        int dz[4] = {x, -x, y, -y};
        
        return solve(0,visited,dz,total,targetCapacity);
    }
};

//BFS solution:
// class Solution {
// public:
//     bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
//         int x = jug1Capacity;
//         int y = jug2Capacity;
        
//         int total = x + y;
        
//         queue<int> q;
//         q.push(0);
        
//         unordered_map<int,bool> visited;
//         visited[0] = true;
        
//         int dz[4] = {x, -x, y, -y};
        
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
            
//             for(int i = 0; i < 4; i++){
//                 int vol = node + dz[i];
//                 if(!visited[vol] && vol >= 0 && vol <= total){
//                     if(vol == targetCapacity) return true;
//                     visited[vol] = true;
//                     q.push(vol);
//                 }
//             }
//         }
        
//         return false;
//     }
// };