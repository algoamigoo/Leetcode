class Solution {
public:
    vector<int> arr; //O(N) space
    Solution(ListNode* head) {
        ListNode* temp = head;
        while(temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int n       = arr.size();
        int r_index = rand()%n;
        return arr[r_index]; //O(1) access time
    }
};