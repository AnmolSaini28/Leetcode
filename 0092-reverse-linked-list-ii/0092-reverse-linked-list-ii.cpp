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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* dummyNode = new ListNode(-1,head);
        ListNode* prevleft = dummyNode;
        for(int i=1 ; i<left ; i++){
            prevleft = prevleft->next;
        }
        ListNode* curr = prevleft->next;
        ListNode* prev = NULL;
        for(int i=0 ; i<=right-left ; i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* leftNode = prevleft->next;
        prevleft->next = prev;
        leftNode->next = curr;
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};