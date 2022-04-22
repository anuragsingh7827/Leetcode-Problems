// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way
class node{
public:
    node* next;
    node* prev;
    int key;
    int value;
    node(int k, int v){
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache
{
    private:
        unordered_map<int,node*> h;
        node* head;
        node* tail;
        int capacity;
        void deleteExistingNode(node* &head, node* &tail, node* &n){
            if(n->next == NULL && n->prev == NULL){
                delete n;
                n = NULL;
                head = NULL;
                tail = NULL;
            }else if(n->prev == NULL && n->next != NULL){
                head = head->next;
                delete n;
                n = NULL;
                head->prev = NULL;
            }else if(n->prev != NULL && n->next == NULL){
                tail = tail->prev;
                delete n;
                n = NULL;
                tail->next = NULL;
            }else{
                node* temp1 = n->prev;
                node* temp2 = n->next;
                temp1->next = temp2;
                temp2->prev = temp1;
                delete n;
                n = NULL;
            }
        }
        node* insertAtHead(node* &head, node* &tail, int key, int value){
            node* n = new node(key,value);
            if(head == NULL && tail == NULL){
                head = n;
                tail = n;
            }else{
                n->next = head;
                head->prev = n;
                head = n;
            }
            return n;
        }
        void deleteAtTail(node* &head, node* &tail){
            if(tail->prev == NULL && tail->next == NULL){
                delete tail;
                head = NULL;
                tail = NULL;
            }else{
                node* n = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete n;
                n = NULL;
            }
        }
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        capacity = cap;
        head = NULL;
        tail = NULL;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(h.count(key)){
            int data = h[key]->value;
            node* n = h[key];
            deleteExistingNode(head,tail,n);
            node* insertedNode = insertAtHead(head,tail,key,data);
            h[key] = insertedNode;
            return data;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here
        if(h.count(key)){
            node* n = h[key];
            deleteExistingNode(head,tail,n);
            node* insertedNode = insertAtHead(head,tail,key,value);
            h[key] = insertedNode;
        }else{
            if(h.size() >= capacity){
                h.erase(tail->key);
                deleteAtTail(head,tail);
            }
            node* insertedNode = insertAtHead(head,tail,key,value);
            h[key] = insertedNode;

        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends