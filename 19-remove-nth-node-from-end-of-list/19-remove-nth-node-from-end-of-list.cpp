/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* tailNode(ListNode* head){
        ListNode* tail = head;
        while(tail -> next) tail = tail -> next;
        
        return tail;
    }
    int length(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head -> next;
        }
        
        return len;
    }
    void deletionAtHead(ListNode* &head, ListNode* &tail){
        ListNode* temp = head;
        head = head -> next;
        delete temp;
        temp = NULL;
    }
    void deletionAtTail(ListNode* &head, ListNode* &tail){
        ListNode* temp = head;
        while(temp -> next != tail) temp = temp -> next;
        delete tail;
        tail = temp;
        tail -> next = NULL;
    }
    void solve(ListNode* &head, ListNode* &tail, int n, int len){
        if(n == 1) deletionAtHead(head,tail);
        else if(n == len) deletionAtTail(head,tail);
        else{
            ListNode* temp = head;
            for(int i = 1; i < n - 1; i++) temp = temp -> next;
            ListNode* node = temp -> next;
            temp -> next = node -> next;
            delete node;
            node = NULL;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail = tailNode(head);
        int len = length(head);
        
        solve(head,tail,len - n + 1,len);
        
        return head;
    }
};