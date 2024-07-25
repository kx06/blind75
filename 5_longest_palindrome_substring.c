#include <string.h>

char *longestPalindrome(char *s) {
  int i = 0;
  static char ch[1001];
  int length = strlen(s);
  int pLen = 0;

  while (i < length) {
    int eLeft = i;
    int eRight = i + 1;
    int oLeft = i;
    int oRight = i;
    int ctr = 0;

    while (1) {
      if (eLeft < 0) {
        break;
      }

      if (eRight >= length) {
        break;
      }
      if (s[eLeft] == s[eRight]) {
        ctr += 2;
        if (ctr > pLen) {
          strncpy(ch, s + eLeft, ctr);
          ch[ctr] = '\0';
          pLen = ctr;
        }
        eLeft--;
        eRight++;
      } else {
        break;
      }
    }

    ctr = 0;
    while (1) {
      if (oRight >= length) {
        break;
      }
      if (oLeft < 0) {
        break;
      }
      if (s[oLeft] == s[oRight]) {
        if (oLeft == oRight) {
          ctr += 1;
        } else {
          ctr += 2;
        }
        if (ctr > pLen) {
          pLen = ctr;
          strncpy(ch, s + oLeft, ctr);
          ch[ctr] = '\0';
        }
        oLeft--;
        oRight++;
      } else {
        break;
      }
    }
    i++;
  }
  return ch;
}
