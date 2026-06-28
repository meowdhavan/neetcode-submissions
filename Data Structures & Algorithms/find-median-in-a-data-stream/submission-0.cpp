class MedianFinder {
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;

public:
    MedianFinder() {
        // maxHeap: 1 2 3
        // minHeap: 4 5 6
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);

            if (maxHeap.size() - minHeap.size() >= 2) {
                int extra = maxHeap.top();
                maxHeap.pop();
                minHeap.push(extra);
            }
        } else {
            minHeap.push(num);

            if (minHeap.size() > maxHeap.size()) {
                int extra = minHeap.top();
                minHeap.pop();
                maxHeap.push(extra);
            }
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            int left = maxHeap.top();
            int right = minHeap.top();

            return (left + right) / (double) 2;
        }
    }
};
