class KthLargest {
public:

    priority_queue<int,vector<int>,greater<int>> pq; // min heap, stores smallest at top
    int queue_size=0;
    KthLargest(int k, vector<int>& nums) {
        queue_size=k;
        for(int i=0;i<nums.size();i++)
        pq.push(nums[i]);   

    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size()<=queue_size)
        return pq.top();

        while(pq.size()>queue_size)
        pq.pop();

        return pq.top();
    }
};