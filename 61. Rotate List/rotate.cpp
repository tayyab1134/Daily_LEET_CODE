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
    ListNode* rotateRight(ListNode* head, int k) {
                if (!head || !head->next || k == 0) {
            return head;
        }

        // Calculate the length of the list
        ListNode* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }

        //  Reduce k to avoid unnecessary rotations
        k = k % length;
        if (k == 0) return head; // No rotation needed

        //  Make the list circular by connecting the tail to the head
        temp->next = head;

        //  Find the new tail, which is at position (length - k - 1)
        for (int i = 0; i < length - k - 1; i++) {
            head = head->next;
        }

        //  Set the new head and break the circle
        ListNode* newHead = head->next;
        head->next = nullptr;

        return newHead;
    }


// Helper function to create a linked list
ListNode* createList(vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* temp = nullptr;
    for (int i = 0; i < values.size(); i++) {
    int val = values[i];
        if (!head) {
            head = new ListNode(val);
            temp = head;
        } else {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
    }
    return head;

    }
};