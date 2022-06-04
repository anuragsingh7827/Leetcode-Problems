/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        
        queue<Node*> q;
        q.push(node);
        
        Node** address = new Node*[101];
        for(int i = 0; i < 101; i++) address[i] = NULL;
        address[node -> val] = new Node(node -> val);
        
        while(!q.empty()){
            Node* n = q.front();
            q.pop();
            
            for(Node* &it : n -> neighbors){
                if(address[it -> val] == NULL){
                    address[it -> val] = new Node(it -> val);
                    q.push(it);
                }
                address[n -> val] -> neighbors.push_back(address[it -> val]);
            }
        }

        return address[node -> val];
    }
};