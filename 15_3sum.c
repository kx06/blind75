
#include <stdio.h>
#include <stdlib.h>

void swap(int *p1, int *p2) {
  int temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int **threeSum(int *nums, int numsSize, int *returnSize,
               int **returnColumnSizes) {
  // when the number of elements is less than 3
  if (numsSize < 3) {
    returnSize = 0;
    returnColumnSizes = NULL;
    return NULL;
  }
  // sorting the elements
  quickSort(nums, 0, numsSize - 1);

  // when all the elements are greater than 0
  if (nums[0] > 0) {
    returnSize = 0;
    returnColumnSizes = NULL;
    return NULL;
  }

  // general case
  for (int i = 0; i < numsSize; i++) {
    int firstPointer = i + 1;
    int lastPointer = numsSize - 1;
    int targetSum = 0 - nums[i];
    if (nums[lastPointer - 1] + nums[lastPointer] < targetSum) {
      continue;
    }
    if (nums[lastPointer - 1] + nums[lastPointer] == targetSum) {
      // make one array and break
      break;
    }
    if (nums[firstPointer] + nums[firstPointer + 1] > targetSum) {
      continue;
    }
    if (nums[firstPointer] + nums[firstPointer + 1] == targetSum) {
      // make one array and break
      break;
    }
    while (firstPointer != lastPointer && firstPointer < lastPointer) {
      if (nums[firstPointer] + nums[lastPointer] == targetSum) {
        // make the array
        firstPointer++;
        while (nums[firstPointer - 1] == nums[firstPointer]) {
          firstPointer++;
        }
        continue;
      }

      if (nums[firstPointer] + nums[lastPointer] < targetSum) {
        // make the array
        firstPointer++;
        while (nums[firstPointer - 1] == nums[firstPointer]) {
          firstPointer++;
        }
        continue;
      }

      if (nums[firstPointer] + nums[lastPointer] > targetSum) {
        // make the array
        lastPointer--;
        while (nums[lastPointer] == nums[lastPointer + 1]) {
          lastPointer--;
        }
        continue;
      }
    }
  }
}
