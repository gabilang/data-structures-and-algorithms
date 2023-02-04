#include<vector>
#include<iostream>

using namespace std;

void min_heapify(vector<int> &heap, int i, int heap_size) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < heap_size && heap[l] < heap[smallest]) {
        smallest = l;
    }

    if (r < heap_size && heap[r] < heap[smallest]) {
        smallest = r;
    }

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        min_heapify(heap, smallest, heap_size);
    }
}

void build_min_heap(vector<int> &heap) {
    int heap_size = heap.size();
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        min_heapify(heap, i, heap_size);
    }
}

int extract_min(vector<int> &heap) {
    int min = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    min_heapify(heap, 0, heap.size());
    return min;
}

void decrease_key(vector<int> &heap, int i, int key) {
    heap[i] = key;
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void insert(vector<int> &heap, int key) {
    // heap.push_back(__INT_MAX__);
    // decrease_key(heap, heap.size() - 1, key);
    heap.push_back(key);
    int i = heap.size() - 1;
    
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}

int main() {
    vector<int> arr = {12, 3, 5, 2, 9, 16, 32, 45, 37, 21};
    build_min_heap(arr);

    cout << "min-heap: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "insert: 4 => ";
    insert(arr, 4);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "extract-minimum: ";
    for (int i = 0; i < arr.size(); i++)
        cout << extract_min(arr) << " ";
    cout << endl;
    return 0;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>

// class MinHeap {
//  public:
//   MinHeap(const std::vector<int>& elements) : elements_(elements) {
//     BuildHeap();
//   }

//   int GetMin() const {
//     return elements_[0];
//   }

//   int ExtractMin() {
//     int min_element = elements_[0];
//     elements_[0] = elements_.back();
//     elements_.pop_back();
//     HeapifyDown(0);
//     return min_element;
//   }

//   void Insert(int element) {
//     elements_.push_back(element);
//     HeapifyUp(elements_.size() - 1);
//   }

//  private:
//   void BuildHeap() {
//     for (int i = elements_.size() / 2 - 1; i >= 0; --i) {
//       HeapifyDown(i);
//     }
//   }

//   void HeapifyDown(int i) {
//     int left_child_index = 2 * i + 1;
//     int right_child_index = 2 * i + 2;
//     int smallest_index = i;
//     if (left_child_index < elements_.size() && elements_[left_child_index] < elements_[smallest_index]) {
//       smallest_index = left_child_index;
//     }
//     if (right_child_index < elements_.size() && elements_[right_child_index] < elements_[smallest_index]) {
//       smallest_index = right_child_index;
//     }
//     if (i != smallest_index) {
//       std::swap(elements_[i], elements_[smallest_index]);
//       HeapifyDown(smallest_index);
//     }
//   }

//   void HeapifyUp(int i) {
//     int parent_index = (i - 1) / 2;
//     if (parent_index >= 0 && elements_[i] < elements_[parent_index]) {
//       std::swap(elements_[i], elements_[parent_index]);
//       HeapifyUp(parent_index);
//     }
//   }

//   std::vector<int> elements_;
// };

// int main() {
//   MinHeap heap({3, 2, 1, 4, 5});
//   std::cout << "Min element: " << heap.GetMin() << std::endl;
//   heap.Insert(0);
//   std::cout << "Min element: " << heap.GetMin() << std::endl;
//   heap.ExtractMin();
//   std::cout << "Min element: " << heap.GetMin() << std::endl;
//   return 0;
// }
