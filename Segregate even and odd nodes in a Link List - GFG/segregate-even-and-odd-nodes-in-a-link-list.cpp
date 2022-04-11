// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* prev = NULL;
        Node* curr = head;
        Node* evenHead = NULL;
        Node* evenTail = NULL;
        
        while(curr != NULL){
            if(curr->data % 2 != 0){
                prev = curr;
                curr = curr->next;
            }else{
                if(curr == head){
                    head = head->next;
                    if(evenHead == NULL && evenTail == NULL){
                        evenHead = curr;
                        evenTail = curr;
                    }else{
                        evenTail->next = curr;
                        evenTail = curr;
                    }
                    evenTail->next = NULL;
                    curr = head;
                }else{
                    prev->next = curr->next;
                    if(evenHead == NULL && evenTail == NULL){
                        evenHead = curr;
                        evenTail = curr;
                    }else{
                        evenTail->next = curr;
                        evenTail = curr;
                    }
                    evenTail->next = NULL;
                    curr = prev->next;
                }
                
            }
        }
        
        if(evenTail != NULL){
            evenTail->next = head;
            return evenHead;
        }else return head;
        
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends