class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        Node* curr = root;

        while (curr != NULL) {
            Node dummy;
            Node* tail = &dummy;

            while (curr != NULL) {
                if (curr->left != NULL) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right != NULL) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next;
            }

            curr = dummy.next;
        }

        return root;
    }
};
