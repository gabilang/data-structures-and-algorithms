#include <limits.h>
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum = sum + arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum = sum + arr[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }
    return max(left_sum + right_sum, left_sum, right_sum);
}

int maxSubArraySum(int arr[], int low, int high) {

    // Invalid array range
    if (low > high) {
        return INT_MIN;
    }

    // Base case
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high) / 2;

    return max(maxSubArraySum(arr, low, mid - 1), 
                maxSubArraySum(arr, mid + 1, high), 
                maxCrossingSum(arr, low, mid, high));
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; //{12, 14, -2, 23, 7, -39, 15, 16, -14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, size - 1);
    printf("Maximum contiguous sum: %d\n", max_sum);
    return 0;
}


// // Kadane's Algorithm

// #include <iostream>
// #include <vector>

// using namespace std;

// int max_subarray_sum(vector<int> &nums) {
//   int max_ending_here = nums[0];
//   int max_so_far = nums[0];
//   for (int i = 1; i < nums.size(); ++i) {
//     max_ending_here = max(nums[i], max_ending_here + nums[i]);
//     max_so_far = max(max_so_far, max_ending_here);
//   }
//   return max_so_far;
// }

// int main() {
//   vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//   int result = max_subarray_sum(nums);
//   cout << "The sum of the maximum subarray is: " << result << endl;
//   return 0;
// }
