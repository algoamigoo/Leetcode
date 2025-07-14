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
    int getDecimalValue(ListNode* head) {
        int ans=0;
        ListNode* s = head;
        if(head==NULL)
        return 0;
        int c=1;
        while(head->next!=NULL){
            c++;
            head=head->next;
        }
        cout<<c<<endl;
        while(c!=0){
            if(s->val==0)
            ans+=0;
            else
            ans+=pow(2,c-1);
            c--;
            s=s->next;
        }
        return ans;
    }
};