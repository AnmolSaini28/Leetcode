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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0;
        int countB = 0;
        ListNode *tempA = headA;
        while(tempA != NULL){
            countA++;
            tempA = tempA->next;
        }
        ListNode *tempB = headB;
        while(tempB != NULL){
            countB++;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;
        if((countA-countB) > 0){
            for(int i=0 ; i<(countA-countB) ; i++){
                tempA = tempA->next;
            }
        }
        else if((countB-countA) > 0){
            for(int i=0 ; i<(countB-countA) ; i++){
                tempB = tempB->next;
            }
        }
        while((tempA != tempB) && (tempA != NULL) && (tempB != NULL)){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};