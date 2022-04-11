// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
Node* reverse(Node* head){
    Node* n = NULL;
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL){
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    
    return prev;
}
int getNthFromLast(Node *head, int n)
{
    // Your code here
    Node* newHead = reverse(head);
    int cnt = 1;
    Node* temp = newHead;
    while(temp != NULL){
        if(cnt == n) return temp->data;
        temp = temp->next;
        cnt++;
    }
    
    return -1;
}

