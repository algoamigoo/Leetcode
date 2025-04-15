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
    ListNode* func(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* last = func(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) 
        return head;
        
        ListNode* new_head = head;
        ListNode* before_new_head = NULL;
        int node_count = 1;
        
        while(node_count < left) {
            node_count++;
            before_new_head = new_head;
            new_head = new_head->next;
        }
        
        ListNode* temp = new_head;
        while(node_count < right) {
            temp = temp->next;
            node_count++;
        }
        
        ListNode* rest = temp->next;
        temp->next = NULL;
        
        new_head = func(new_head);
        
        if(before_new_head) {
            before_new_head->next = new_head;
        } else {
            head = new_head;
        }
        
        while(new_head->next) {
            new_head = new_head->next;
        }
        new_head->next = rest;
        
        return head;
    }
};