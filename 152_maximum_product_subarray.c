int maxProduct(int *nums, int numsSize) {
  if (numsSize == 1) {
    return nums[0];
  }

  double prefix = 1;
  int max = -11;

  // for prefix
  for (int i = 0; i < numsSize; i++) {
    if (prefix == 0) {
      prefix = 1;
    }
    prefix *= nums[i];
    if (max < prefix) {
      max = prefix;
    }
  }

  double suffix = 1;

  // for suffix
  for (int i = numsSize - 1; i >= 0; i--) {
    if (suffix == 0) {
      suffix = 1;
    }
    suffix *= nums[i];
    if (max < suffix) {
      max = suffix;
    }
  }
  return max;
}
