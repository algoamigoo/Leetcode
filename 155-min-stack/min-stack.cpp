class MinStack {
public:
    vector<pair<int, int>> arr;
    pair<int, int> p;
    int mini;
    MinStack() {
        p.first = 0;
        p.second = 0;
        mini = INT32_MAX;
    }

    void push(int data) {
        if (arr.empty()) {
            p.first = data;
            p.second = data;
            arr.push_back(p);
            mini = data;
        } else {
            p.first = data;
            mini = min(data, arr.back().second);
            p.second = mini;
            arr.push_back(p);
        }
    }

    void pop() { arr.pop_back(); }

    int top() { return arr.back().first; }

    int getMin() { return arr.back().second; }
};
