#include <stdio.h>

int normal_binary_search(int *arr, int low, int high, int x) {
  if (high >= low) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == x)
      return mid;

    if (arr[mid] > x)
      return normal_binary_search(arr, low, mid - 1, x);

    else
      return normal_binary_search(arr, mid + 1, high, x);
  }

  return -1;
}

int jumbled_binary_search(int *nums, int low, int high, int target) {
  int middle = low + high;
  middle = middle / 2;
  if (target == nums[middle]) {
    return middle;
  } else if (nums[low] <= nums[middle]) {
    if (target >= nums[low] && target <= nums[middle]) {
      return normal_binary_search(nums, low, middle, target);
    } else {
      return jumbled_binary_search(nums, middle + 1, high, target);
    }
  } else {
    if (target >= nums[middle] && target <= nums[high]) {
      return normal_binary_search(nums, middle, high, target);
    } else {
      return jumbled_binary_search(nums, low, middle - 1, target);
    }
  }
}

int search(int *nums, int numsSize, int target) {
  if (numsSize == 1) {
    if (target == nums[0]) {
      return 0;
    } else {
      return -1;
    }
  }
  int middle = (numsSize - 1) / 2;
  if (nums[0] <= nums[middle] && nums[numsSize - 1] < nums[middle]) {
    if (target >= nums[0] && target <= nums[middle]) {
      return normal_binary_search(nums, 0, middle, target);
    } else {
      return jumbled_binary_search(nums, middle + 1, numsSize - 1, target);
    }
  } else if (nums[middle] <= nums[numsSize - 1] && nums[middle] < nums[0]) {
    if (target >= nums[middle] && target <= nums[numsSize - 1]) {
      return normal_binary_search(nums, middle, numsSize - 1, target);
    } else {
      return jumbled_binary_search(nums, 0, middle - 1, target);
    }
  } else {
    return normal_binary_search(nums, 0, numsSize - 1, target);
  }
}

int main() {
  int array[1] = {1};
  int res = search(array, 1, 0);
  printf("%d", res);
}
