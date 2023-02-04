#include <iostream>
#include <vector>

using namespace std;

pair<int, int> max_subarray(vector<int> &array) {
  int max_sum = array[0], sum = array[0];
  int max_start = 0, max_end = 0, start = 0, end = 0;
  for (int i = 1; i < array.size(); i++) {
    if (sum < 0) {
      sum = array[i];
      start = i;
      end = i;
    } else {
      sum += array[i];
      end = i;
    }
    if (sum > max_sum) {
      max_sum = sum;
      max_start = start;
      max_end = end;
    }
  }
  return {max_start, max_end};
}

int main() {
  vector<int> array = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  auto result = max_subarray(array);
  cout << "The maximum subarray is from index " << result.first << " to index " << result.second << endl;
  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> findMaxSubarray(vector<int> arr) {
    int maxSum = arr[0], start = 0, end = 0, sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (sum <= 0) {
            sum = arr[i];
            start = i;
        } else {
            sum += arr[i];
        }
        if (sum > maxSum) {
            maxSum = sum;
            end = i;
        }
    }
    return make_pair(start, end);
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    pair<int, int> res = findMaxSubarray(arr);
    cout << "Start: " << res.first << endl;
    cout << "End: " << res.second << endl;
    cout << "Max sum: " << arr[res.first] + arr[res.second] << endl;
    return 0;
}


// #include <iostream>
// #include <vector>

// using namespace std;

// vector<int> max_subarray(vector<int> &nums) {
//   int max_ending_here = nums[0];
//   int max_so_far = nums[0];
//   int start = 0, end = 0, s = 0;
//   for (int i = 1; i < nums.size(); ++i) {
//     if (max_ending_here < 0) {
//       max_ending_here = nums[i];
//       s = i;
//     } else {
//       max_ending_here += nums[i];
//     }
//     if (max_ending_here > max_so_far) {
//       max_so_far = max_ending_here;
//       start = s;
//       end = i;
//     }
//   }
//   return vector<int>(nums.begin() + start, nums.begin() + end + 1);
// }

// int main() {
//   vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//   vector<int> result = max_subarray(nums);
//   cout << "The maximum subarray is: ";
//   for (int x : result) cout << x << " ";
//   cout << endl;
//   return 0;
// }
