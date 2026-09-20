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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummyNode = new ListNode(-1,NULL);
        ListNode* curr = dummyNode;
        int carry = 0;
        while(temp1 != NULL || temp2 != NULL){
            int sum = 0;
            if(temp1) sum += temp1->val;
            if(temp2) sum += temp2->val;
            ListNode* newNode = new ListNode((sum+carry)%10,NULL);
            curr->next = newNode;
            curr = newNode;
            carry = (sum+carry)/10;
            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry,NULL);
            curr->next = newNode;
            curr = newNode;
        }
        return dummyNode->next;
    }
};