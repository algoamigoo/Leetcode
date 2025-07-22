// smallest at top, min heap
// use ladders, add jumps in the q, after ladder exhaust use bricks and
// repalce smallest ladder by bricks
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> q;
        int n = heights.size();
        int i = 0;
        int curr = 0;
        while (i < n - 1) {
            int jump = heights[i + 1] - heights[i];
            if (jump > 0) {
                if (q.size() < ladders)
                    q.push(jump);
                else {
                    int t = jump;
                    if (!q.empty() && q.top() < jump) {
                        t = q.top();
                        q.pop();
                        q.push(jump);
                    }
                    if (curr + t <= bricks)
                        curr += t;
                    else
                        return i;
                }
            }
            i++;
        }
        return i;
    }
};
