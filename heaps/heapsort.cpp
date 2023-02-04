#include <iostream>
#include <vector>

using namespace std;

void max_heapify(vector<int> &heap, int i, int heap_size) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < heap_size && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < heap_size && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        max_heapify(heap, largest, heap_size);
    }
}

void build_max_heap(vector<int> &heap) {
    int n = heap.size();
    for (int i = n / 2 -1; i >= 0; i--) {
        max_heapify(heap, i, n);
    }
}

void heapsort(vector<int> &arr) {
    build_max_heap(arr);

    for (int i = arr.size() - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i);
    }
}

int main() {
    vector<int> arr = {16, 4, 10, 17, -5, 14, 32, 7, 21, 9, 19, 3, 43, 376, -212, 2, 8, 1};
    heapsort(arr);

    cout << "sorted array: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}
