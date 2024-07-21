#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head) {
  struct ListNode *current = head;
  struct ListNode *prev = NULL;
  while (head != NULL) {
    current = current->next;
    head->next = prev;
    prev = head;
    head = current;
  }
  return prev;
}
