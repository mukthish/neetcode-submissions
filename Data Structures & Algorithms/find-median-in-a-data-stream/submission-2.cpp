class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> large;
    priority_queue<int> small;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        if (small.size() - large.size() > 1) {
            large.push(small.top());
            small.pop();
        }
        while (!small.empty() and !large.empty() and small.top() > large.top()) {
            small.push(large.top());
            large.push(small.top());
            small.pop();
            large.pop();
        }
    }
    
    double findMedian() {
        if (large.size() == small.size()) {
            return (large.top() + small.top()) / 2.0;
        } else {
            return small.top();
        }
    }
};
