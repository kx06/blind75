#include <stdio.h>

int missingNumber(int *nums, int numsSize) {
  int sum = (numsSize * (numsSize + 1)) / 2;
  for (int i = 0; i < numsSize; i++) {
    sum = sum - nums[i];
  }
  return sum;
}

int main() {}
