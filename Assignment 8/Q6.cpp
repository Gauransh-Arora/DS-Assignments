/*
Implement priority queues using heaps.
*/

#include<bits/stdc++.h>
using namespace std;

class PriorityQueue{
    vector<int> heap;

    void heapifyUp(int index){
        while(index > 0){
            int parent = (index - 1) / 2;
            if(heap[parent] < heap[index]){
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index){
        int n = heap.size();
        while(true){
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if(left < n && heap[left] > heap[largest]){
                largest = left;
            }
            if(right < n && heap[right] > heap[largest]){
                largest = right;
            }
            if(largest != index){
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }
    public:
        void insert(int key){
            heap.push_back(key);
            heapifyUp(heap.size() - 1);
        }
        int extractMax(){
            if(heap.empty()){
                throw runtime_error("Priority Queue is empty");
            }
            int maxVal = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
            return maxVal;
        }
        int getMax(){
            if(heap.empty()){
                throw runtime_error("Priority Queue is empty");
            }
            return heap[0];
        }
        bool isEmpty(){
            return heap.empty();
        }
        int size(){
            return heap.size();
        }
};

int main(){
    PriorityQueue pq;
    pq.insert(10);
    pq.insert(20);
    pq.insert(5);
    pq.insert(30);

    cout << "Max element: " << pq.getMax() << endl;

    while(!pq.isEmpty()){
        cout << "Extracted: " << pq.extractMax() << endl;
    }

    return 0;
}