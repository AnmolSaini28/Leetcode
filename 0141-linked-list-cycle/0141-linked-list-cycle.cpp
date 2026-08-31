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
        if(head == NULL || head->next == NULL) return false;
        ListNode *temp = head;
        unordered_set <ListNode *> s;
        while(temp != NULL) {
            s.insert(temp);
            for(ListNode *node : s){
                if(node == temp->next){
                    return true;
                }
            }
            temp = temp->next;
        }
        return false;
    }
};