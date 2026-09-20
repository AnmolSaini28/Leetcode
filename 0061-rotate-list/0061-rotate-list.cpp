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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int n = 0;
        ListNode* tail = head;
        for(ListNode* curr = head ; curr != NULL ; curr = curr->next) {
            n++;
            tail = curr;
        }
        k = k % n;
        if(n == k) return head;
        ListNode* curr = head;
        for(int i=0 ; i<(n-k-1) ; i++){
            curr = curr->next;
        }
        tail->next = head;
        head = curr->next;
        curr->next = NULL;

        return head;
    }
};