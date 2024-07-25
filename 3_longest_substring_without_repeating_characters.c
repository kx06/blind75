
#include <string.h>

int lengthOfLongestSubstring(char *s) {

  // length of the longest substring
  int len = 0;
  // boolean array for all ACII elements
  int boolArr[128] = {0};

  int i = 0;
  char ch;
  int temp = 0;
  int ref = 0;

  int stringLength = strlen(s);

  while (i < stringLength) {
    if (boolArr[s[i]] == 1) {
      if (temp > len) {
        len = temp;
      }
      temp = 0;
      memset(boolArr, 0, sizeof(boolArr));
      ref++;
      i = ref;
    }
    boolArr[s[i]] = 1;
    temp++;
    if (s[++i] == '\0') {
      if (temp > len) {
        len = temp;
      }
    }
  }
  return len;
}
