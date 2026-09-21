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
        vector <int> temp;
        for(ListNode* curr = head ; curr != NULL ; curr = curr->next){
            temp.push_back(curr->val);
        }
        left -= 1;
        right -= 1;
        while(left<=right){
            swap(temp[left],temp[right]);
            left++;
            right--;
        }
        ListNode* curr = head;
        for(int i=0 ; i<temp.size() ; i++){
            curr->val = temp[i];
            curr = curr->next;
        }
        return head;
    }
};