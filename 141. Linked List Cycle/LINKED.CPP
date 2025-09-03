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
         if (!head || !head->next) return false;

    ListNode* slow = head;  
    ListNode* fast = head; 

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false; 
}


void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;

    ListNode* tail = head;
    ListNode* cycleNode = nullptr;
    int index = 0;

    while (tail->next) {
        if (index == pos) {
            cycleNode = tail;
        }
        tail = tail->next;
        index++;
    }
}
};