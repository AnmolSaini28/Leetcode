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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL && n == 1) return NULL;
        int totalNodes = 0;
        for(ListNode* curr = head; curr != NULL; curr = curr->next){
            totalNodes++;
        }
        if(totalNodes == n) return head->next;
        ListNode* temp = head;
        int nthfromEnd = totalNodes-n-1;
        while(nthfromEnd > 0){
            temp = temp->next;
            nthfromEnd--;
        }
        temp->next = temp->next->next;
        return head;
    }
};