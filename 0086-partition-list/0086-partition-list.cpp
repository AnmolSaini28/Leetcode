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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(-1,NULL);
        ListNode* temp = dummy; 
        for(ListNode* curr = head ; curr != NULL ; curr = curr->next){
            if(curr->val < x){
                ListNode* newNode = new ListNode(curr->val,NULL);
                temp->next = newNode;
                temp = newNode;
            }
        }
        for(ListNode* curr = head ; curr != NULL ; curr = curr->next){
            if(curr->val >= x){
                ListNode* newNode = new ListNode(curr->val,NULL);
                temp->next = newNode;
                temp = newNode;
            }
        }
        ListNode* newHead = dummy->next;
        return newHead;
    }
};