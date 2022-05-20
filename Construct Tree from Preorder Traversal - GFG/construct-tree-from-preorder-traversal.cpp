// { Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void printInorder (struct Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}

Node* constructTree(int n, int pre[], char preLN[]);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends


/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
class triplet{
public:
    Node* root;
    bool left;
    bool right;
    triplet(Node* root){
        this -> root = root;
        left = false;
        right = false;
    }
};
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    stack<triplet> s;
    Node* root = new Node(pre[0]);
    
    if(preLN[0] == 'N') s.push(root);
    
    for(int i = 1; i < n; i++){
        if(s.top().left == false){
            s.top().left = true;
            Node* left = new Node(pre[i]);
            s.top().root -> left = left;
            if(preLN[i] == 'N') s.push(left);
        }else if(s.top().right == false){
            s.top().right = true;
            Node* right = new Node(pre[i]);
            s.top().root -> right = right;
            if(preLN[i] == 'N') s.push(right);
        }else{
            while(s.top().left == true && s.top().right == true) s.pop();
            if(s.top().left == false){
                s.top().left = true;
                Node* left = new Node(pre[i]);
                s.top().root -> left = left;
                if(preLN[i] == 'N') s.push(left);
            }else if(s.top().right == false){
                s.top().right = true;
                Node* right = new Node(pre[i]);
                s.top().root -> right = right;
                if(preLN[i] == 'N') s.push(right);
            }
        }
    }
    
    return root;
}