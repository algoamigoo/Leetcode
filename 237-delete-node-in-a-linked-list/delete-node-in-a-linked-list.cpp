class Solution {
public:
    void deleteNode(ListNode* node) {
        // copy value of next node
        node->val = node->next->val;
        // unlink next node
        node->next = node->next->next;
    }
};
