class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: if empty or single node, return as is
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        // Save head for return, as it will change after first swap
        ListNode* newHead = head->next;
        
        while (curr && curr->next) {
            ListNode* p1 = curr;           // First node
            ListNode* p2 = curr->next;     // Second node
            ListNode* p3 = p2->next;       // Node after pair
            
            // Swap the pair
            p1->next = p3;      // First node points to rest
            p2->next = p1;      // Second node points to first
            
            // Connect to previous pair
            if (prev) {
                prev->next = p2;
            }
            
            // Move to next pair
            prev = p1;
            curr = p3;
        }
        
        return newHead;
    }
};