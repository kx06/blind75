#include <stdio.h>

int even_substring_counter(char *s, int even_string_index) {
  int even_res = 0;
  char even_ch;
  char even_second_ch;
  int even_left_index = even_string_index;
  int even_right_index = even_string_index + 1;
  while ((even_ch = s[even_left_index]) != '\0' &&
         (even_second_ch = s[even_right_index]) != '\0') {
    if (even_ch == even_second_ch) {
      even_res += 1;
    } else {
      return even_res;
    }
    even_left_index = even_left_index - 1;
    even_right_index = even_right_index + 1;
    if (even_left_index < 0) {
      return even_res;
    }
    if (s[even_right_index] == '\0') {
      return even_res;
    }
  }
  return even_res;
}

int odd_substring_counter(char *s, int odd_string_index) {
  int odd_res = 0;
  char odd_ch;
  char odd_second_ch;
  int odd_left_index = odd_string_index;
  int odd_right_index = odd_string_index;
  while ((odd_ch = s[odd_left_index]) != '\0' &&
         (odd_second_ch = s[odd_right_index]) != '\0') {
    if (odd_ch == odd_second_ch) {
      odd_res += 1;
    } else {
      return odd_res;
    }
    odd_left_index = odd_left_index - 1;
    odd_right_index = odd_right_index + 1;
    if (odd_left_index < 0) {
      return odd_res;
    }
    if (s[odd_right_index] == '\0') {
      return odd_res;
    }
  }
  return odd_res;
}

int countSubstrings(char *s) {
  int res = 0;
  char ch;
  int string_index = 0;
  while ((ch = s[string_index]) != '\0') {
    res += even_substring_counter(s, string_index);
    res += odd_substring_counter(s, string_index);
    string_index += 1;
  }
  return res;
}

int main() {
  char target_string[] = "\0";
  int result = countSubstrings(target_string);
  printf("%d is the result", result);
}
