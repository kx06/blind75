
int maxArea(int *height, int heightSize) {
  int max = 0;
  int i = 0;
  int ii = heightSize - 1;
  while (ii != i) {
    if (ii >= heightSize) {
      break;
    }
    // processing
    int selHeight = 0;
    int area = 0;
    if (height[i] < height[ii]) {
      selHeight = height[i];
      area = selHeight * (ii - i);
      i++;
    } else {
      selHeight = height[ii];
      area = selHeight * (ii - i);
      ii--;
    }
    if (area > max) {
      max = area;
    }
  }
  return max;
}
