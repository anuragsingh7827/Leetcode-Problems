// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
int totalNodes(Node* root){
    if(root == NULL) return 0;
    
    return 1 + totalNodes(root -> left) + totalNodes(root -> right);
}
void solve(Node* root, int &mid, bool &found, int &i, int midIndx){
    if(root == NULL) return;
    
    if(!found) solve(root -> left,mid,found,i,midIndx);
    
    i++;
    if(i == midIndx){
        mid = root -> data;
        found = true;
    }
    
    if(!found) solve(root -> right,mid,found,i,midIndx);
}
float findMedian(struct Node *root)
{
    //Code here
    int n = totalNodes(root);
    
    if(n&1){
        int mid;
        bool found = false;
        int i = 0;
        solve(root,mid,found,i,(n + 1) / 2);
        return mid;
    }else{
        int i = 0;
        bool found1 = false;
        int part1;
        solve(root,part1,found1,i,n / 2);

        int j = 0;
        bool found2 = false;
        int part2;
        solve(root,part2,found2,j,(n / 2) + 1);
        
        float mid = (part1 + part2) / 2.0;
        
        return mid;
    }
}

