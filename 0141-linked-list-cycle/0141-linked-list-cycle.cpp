/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false;
        }
        unordered_set <ListNode *> s;
        ListNode* temp = head;
        while(temp != NULL){
            if(s.find(temp->next) != s.end()){
                return true;
            }
            s.insert(temp->next);
            temp = temp->next;
        }

        return false;
    }
};