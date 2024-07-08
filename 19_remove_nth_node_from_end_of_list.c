#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
  if (head == NULL) {
    return head;
  }
  struct ListNode *dummy_node = malloc(sizeof(struct ListNode));
  dummy_node->next = head;
  struct ListNode *last_pointer = head;
  struct ListNode *prev_pointer = dummy_node;
  for (int i = 1; i < n; i++) {
    last_pointer = last_pointer->next;
  }
  while (last_pointer->next != NULL) {
    last_pointer = last_pointer->next;
    prev_pointer = prev_pointer->next;
  }

  if (head == prev_pointer->next) {
    head = head->next;
  }
  prev_pointer->next = (prev_pointer->next)->next;
  return head;
}
