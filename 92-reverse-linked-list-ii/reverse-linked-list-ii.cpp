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
        // Edge case: no reversal needed if left equals right
        if (left == right) return head;

        // Initialize pointers to find the node before 'left'
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int pos = 1;

        // Move to position 'left'
        while (pos < left) {
            prev = curr;
            curr = curr->next;
            pos++;
        }

        // Save the node before the segment and the segment's start
        ListNode* before_segment = prev;
        ListNode* segment_start = curr;

        // Reverse the segment from 'left' to 'right'
        prev = nullptr;
        while (pos <= right && curr) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
            pos++;
        }

        // 'prev' is now the new head of reversed segment
        // 'curr' is the node after the segment (or nullptr)
        // Connect the reversed segment back to the list
        segment_start->next = curr;
        if (before_segment) {
            before_segment->next = prev;
        } else {
            head = prev;
        }

        return head;
    }
};