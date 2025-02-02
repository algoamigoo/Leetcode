class MedianFinder {
public:
    priority_queue<int> l; // max ele at the top
    priority_queue<int,vector<int>,greater<int>> r; // min ele at top
    MedianFinder() { }
    
    void addNum(int num) {
        if(l.size()==0 || num<l.top())
        l.push(num);
        else
        r.push(num);

        if(abs((int)r.size()-(int)l.size())>1)
        {r.push(l.top());l.pop();}
        else if(r.size()>l.size())
        {l.push(r.top());r.pop();}


    }
    
    double findMedian() {
        if(r.size()==l.size())
        return (double)(l.top()+r.top())/2;
        
        return l.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */