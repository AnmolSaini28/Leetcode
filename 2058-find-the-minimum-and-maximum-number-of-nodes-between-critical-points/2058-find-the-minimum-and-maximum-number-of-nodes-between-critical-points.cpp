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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return {-1,-1};
        }
        ListNode* temp = head->next;
        int prevValue = head->val;
        int count = 2;
        int firstCriticalPoint = -1;
        int lastCriticalPoint = -1;
        int cp = -1;
        int minDis = INT_MAX;
        while(temp->next != NULL){
            if((temp->val > prevValue && temp->val > temp->next->val) || (temp->val < prevValue && temp->val < temp->next->val)){
                if(firstCriticalPoint == -1) {
                    firstCriticalPoint = count;
                }

    if(lastCriticalPoint != -1) {
        minDis = min(minDis, count - lastCriticalPoint);
    }

    lastCriticalPoint = count;
            }
            count++;
            prevValue = temp->val;
            temp = temp->next;
        }
        int maxDis = lastCriticalPoint-firstCriticalPoint;
        if(lastCriticalPoint == firstCriticalPoint) return {-1,-1};
        return {minDis,maxDis};
    }
};