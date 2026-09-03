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
    private:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* curr) {
        ListNode* prev = NULL;
        ListNode* next = curr->next;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)  return head;
        ListNode* middle = middleNode(head);
        middle = reverseList(middle);
        ListNode* temp = head;
        while(head != NULL && middle != NULL){
            if(temp->val != middle->val){
                return false;
            }
            temp = temp->next;
            middle = middle->next;
        }
        return true;
    }
};