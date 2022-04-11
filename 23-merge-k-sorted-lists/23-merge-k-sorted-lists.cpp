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
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val <= temp2->val){
                if(temp1->next != NULL && temp1->next->val <= temp2->val){
                    temp1 = temp1->next;
                }else{
                    ListNode* n = temp1->next;
                    temp1->next = temp2;
                    temp1 = n;
                }
            }else{
                if(temp2->next != NULL && temp2->next->val < temp1->val){
                    temp2 = temp2->next;
                }else{
                    ListNode* n = temp2->next;
                    temp2->next = temp1;
                    temp2 = n;
                }
            }
            
            
        }
        
        if(head1->val <= head2->val) return head1;
        else return head2;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int K = lists.size();
        if(K == 0) return NULL;
        ListNode* ans = NULL;
        int indx = -1;
        for(int i = 0; i < K; i++){
            if(lists[i] != NULL){
                ans = lists[i];
                indx = i;
                break;
            }
        }
        for(int i = indx + 1; i < K; i++){
            if(lists[i] != NULL) ans = merge(ans,lists[i]);
        }
        return ans;
    }
};