int recursive_min(int *nums, int left, int right) {
  if (left - right == -1) {
    if (nums[left] < nums[right]) {
      return nums[left];
    } else {
      return nums[right];
    }
  }
  int middle = (left + right) / 2;
  if (nums[left] < nums[middle]) {
    return recursive_min(nums, middle, right);
  } else {
    return recursive_min(nums, left, middle);
  }
}

int findMin(int *nums, int numsSize) {
  int middle = (numsSize - 1) / 2;
  if (nums[0] > nums[middle]) {
    return recursive_min(nums, 0, middle);
  } else if (nums[middle] > nums[numsSize - 1]) {
    return recursive_min(nums, middle, numsSize - 1);
  } else {
    return nums[0];
  }
}
