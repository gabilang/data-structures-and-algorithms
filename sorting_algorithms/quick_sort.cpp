#include<vector>
#include<iostream>

using namespace std;

int partition(vector<int> &arr, int p, int r) {
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quicksort(vector<int> &arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}

int main() {
    vector<int> arr = {4, 5, 1, 6, 2, 7, 3, 8};
    int n = arr.size();
    
    quicksort(arr, 0, n - 1);
    
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
