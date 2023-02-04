#include <vector>
#include <iostream>

using namespace std;

void maxHeapify(vector<int>& heap, int index, int heapSize) {
  int largest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < heapSize && heap[left] > heap[largest])
    largest = left;

  if (right < heapSize && heap[right] > heap[largest])
    largest = right;

  if (largest != index) {
    swap(heap[index], heap[largest]);
    maxHeapify(heap, largest, heapSize);
  }
}

void buildMaxHeap(vector<int>& heap) {
  int heapSize = heap.size();
  for (int i = heapSize / 2 - 1; i >= 0; i--)
    maxHeapify(heap, i, heapSize);
}

int extractMax(vector<int>& heap) {
  int max = heap[0];
  heap[0] = heap.back();
  heap.pop_back();
  maxHeapify(heap, 0, heap.size());
  return max;
}

void insert(vector<int>& heap, int key) {
  heap.push_back(key);
  int i = heap.size() - 1;
  while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
    swap(heap[(i - 1) / 2], heap[i]);
    i = (i - 1) / 2;
  }
}

int main() {
  vector<int> heap = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  buildMaxHeap(heap);

  cout << "Max-Priority Queue: ";
  for (int i = 0; i < heap.size(); i++)
    cout << extractMax(heap) << " ";
  cout << endl;

  return 0;
}
