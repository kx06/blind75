#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
  if (list1 == NULL) {
    return list2;
  }
  if (list2 == NULL) {
    return list1;
  }
  struct ListNode *current_ptr = NULL;
  struct ListNode *head = NULL;
  while (list1 != NULL && list2 != NULL) {
    if (list1->val <= list2->val) {
      if (current_ptr == NULL) {
        head = list1;
        current_ptr = head;
      } else {
        current_ptr->next = list1;
        current_ptr = current_ptr->next;
      }
      list1 = list1->next;
    } else {
      if (current_ptr == NULL) {
        head = list2;
        current_ptr = head;
      } else {
        current_ptr->next = list2;
        current_ptr = current_ptr->next;
      }
      list2 = list2->next;
    }
    if (list1 == NULL) {
      current_ptr->next = list2;
    } else {
      current_ptr->next = list1;
    }
  }
  return head;
}
