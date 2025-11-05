#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;
    bool isMaxHeap;
    
    void heapifyUp(int i) {
        if (i == 0) return;
        
        int parent = (i - 1) / 2;
        if ((isMaxHeap && heap[i] > heap[parent]) || 
            (!isMaxHeap && heap[i] < heap[parent])) {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }
    
    void heapifyDown(int i) {
        int extreme = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int n = heap.size();
        
        if (isMaxHeap) {
            if (left < n && heap[left] > heap[extreme])
                extreme = left;
            if (right < n && heap[right] > heap[extreme])
                extreme = right;
        } else {
            if (left < n && heap[left] < heap[extreme])
                extreme = left;
            if (right < n && heap[right] < heap[extreme])
                extreme = right;
        }
        
        if (extreme != i) {
            swap(heap[i], heap[extreme]);
            heapifyDown(extreme);
        }
    }
    
public:
    PriorityQueue(bool maxHeap = true) : isMaxHeap(maxHeap) {}
    
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    
    int top() {
        if (heap.empty()) throw runtime_error("Priority queue is empty");
        return heap[0];
    }
    
    void pop() {
        if (heap.empty()) throw runtime_error("Priority queue is empty");
        
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }
    
    bool empty() {
        return heap.empty();
    }
    
    int size() {
        return heap.size();
    }
};

int main() {
    // Max priority queue
    PriorityQueue maxPQ(true);
    maxPQ.push(3);
    maxPQ.push(1);
    maxPQ.push(4);
    maxPQ.push(1);
    maxPQ.push(5);
    
    cout << "Max Priority Queue: ";
    while (!maxPQ.empty()) {
        cout << maxPQ.top() << " ";
        maxPQ.pop();
    }
    cout << endl;
    
    // Min priority queue
    PriorityQueue minPQ(false);
    minPQ.push(3);
    minPQ.push(1);
    minPQ.push(4);
    minPQ.push(1);
    minPQ.push(5);
    
    cout << "Min Priority Queue: ";
    while (!minPQ.empty()) {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }
    cout << endl;
    
    return 0;
}