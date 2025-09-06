class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        
        int lenA = 0;
        ListNode *tempA = headA;
        while (tempA) {
            lenA++;
            tempA = tempA->next;
        }
        
        int lenB = 0;
        ListNode *tempB = headB;
        while (tempB) {
            lenB++;
            tempB = tempB->next;
        }
        
        tempA = headA;
        tempB = headB;
        
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) {
                tempA = tempA->next;
            }
        } else {
            for (int i = 0; i < lenB - lenA; i++) {
                tempB = tempB->next;
            }
        }
        
        while (tempA && tempB) {
            if (tempA == tempB) {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        
        return NULL;
    }
};
