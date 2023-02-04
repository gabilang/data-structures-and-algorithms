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

int main() {
    vector<int> arr = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, n);

    cout << "Max-Heap: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
