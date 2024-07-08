#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  struct ListNode *next_node = head->next;
  struct ListNode *prev_node = NULL;
  while (next_node != NULL) {
    head->next = prev_node;
    prev_node = head;
    head = next_node;
    next_node = next_node->next;
  }
  head->next = prev_node;
  return head;
}

void reorderList(struct ListNode *head) {
  struct ListNode *mainHead = head;
  // finding middle
  struct ListNode *middle_node = head;
  struct ListNode *last_node = head;
  while (last_node != NULL) {
    last_node = last_node->next;
    if (last_node == NULL) {
      break;
    }
    last_node = last_node->next;
    middle_node = middle_node->next;
  }
  struct ListNode *second_head = middle_node->next;
  second_head = reverseList(second_head);
  middle_node->next = NULL;
  struct ListNode *aux_node = head->next;
  if (second_head == NULL) {
    return;
  }
  struct ListNode *second_aux_node = second_head->next;
  while (1) {
    head->next = second_head;
    second_head->next = aux_node;
    if (aux_node == NULL) {
      break;
    }
    head = aux_node;
    aux_node = aux_node->next;
    if (second_aux_node == NULL) {
      break;
    }
    second_head = second_aux_node;
    second_aux_node = second_aux_node->next;
  }
  head = mainHead;
}
