#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
  if (head == NULL)
    return NULL;

  struct ListNode *slow_pointer = head;
  struct ListNode *fast_pointer = head->next;
  int power = 1;
  int length = 1;

  while (fast_pointer != NULL && fast_pointer != slow_pointer) {

    if (length == power) {
      power *= 2;
      length = 0;
      slow_pointer = fast_pointer;
    }

    fast_pointer = fast_pointer->next;
    ++length;
  }

  if (fast_pointer == NULL)
    return NULL;
  return true;
}
