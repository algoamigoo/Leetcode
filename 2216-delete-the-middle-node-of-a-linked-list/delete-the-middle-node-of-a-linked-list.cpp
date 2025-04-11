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
    ListNode* deleteMiddle(ListNode* head) {
        // Handle empty or single node case
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        int c = 0;
        ListNode* nxt = nullptr;
        ListNode* start = head;
        // Count all nodes
        while (head != nullptr) {
            nxt = head->next;
            head = nxt;
            c++;
        }
        
        // Reset head to start of list
        head = start;
        // Go to node before middle
        c = c / 2 - 1;
        while (c--) {
            nxt = start->next;
            start = nxt;
        }
        
        // Delete middle node
        nxt = start->next;
        start->next = nxt->next;
        delete nxt;
        
        return head;
    }
};