#include <math.h>

int climbStairs(int n) {
  n = n + 1;
  double r5 = sqrt(5);
  double vA = 1 + r5;
  double pvA = pow(vA, n);
  double vB = 1 - r5;
  double pvB = pow(vB, n);
  double div = pow(2, n) * r5;

  int eqn = (pvA - pvB) / div;
  return eqn;
}
