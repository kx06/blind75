#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
  if (listsSize == 0) {
    return NULL;
  }
  struct ListNode head;
  struct ListNode *h = &head;

  while (1) {
    int min_ptr_index = 0;
    int min_value = +10002;
    for (int i = 0; i < listsSize; i++) {
      if (lists[i] != NULL) {
        if (min_value > lists[i]->val) {
          min_ptr_index = i;
          min_value = lists[i]->val;
        }
      }
      if (i == listsSize - 1) {
      }
    }
    if (lists[min_ptr_index] != NULL) {
      h->next = lists[min_ptr_index];
      lists[min_ptr_index] = lists[min_ptr_index]->next;
      h = h->next;
    } else {
      h->next = NULL;
      return head.next;
    }
  }
}
