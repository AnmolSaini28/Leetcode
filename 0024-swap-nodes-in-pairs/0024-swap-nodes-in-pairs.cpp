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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummyNode = new ListNode(-1,head);
        ListNode* prev = dummyNode;
        while(prev->next != NULL && prev->next->next != NULL) {
            ListNode* firstNode = prev->next;
            ListNode* secondNode = firstNode->next;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;
            prev->next = secondNode;
            prev = firstNode;
        }
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};