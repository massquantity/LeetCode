/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

size_t getLen(struct ListNode *node) {
  size_t len = 0;
  while (node) {
    len++;
    node = node->next;
  }
  return len;
}

struct ListNode *split(struct ListNode *node, int step) {
  if (!node) return node;
  struct ListNode *cur = node;
  for (int i = 1; i < step && cur->next; i++) {
    cur = cur->next;
  }
  struct ListNode *tmp = cur->next;
  cur->next = NULL;
  return tmp;
}

struct ListNode *merge(struct ListNode *left, struct ListNode *right) {
  struct ListNode *dummy2 = (struct ListNode*)malloc(sizeof(struct ListNode));
  dummy2->val = -1;
  struct ListNode *cur = dummy2;
  while (left && right) {
    if (left->val < right->val) {
      cur->next = left;
      left = left->next;
    } else {
      cur->next = right;
      right = right->next;
    }
    cur = cur->next;
  }
  cur->next = left ? left : right;
  return dummy2->next;
}

struct ListNode* sortList(struct ListNode* head){
  size_t len = getLen(head);
  struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
  dummy->val = -1;
  dummy->next = head;
  for (int step = 1; step < len; step *= 2) {
    struct ListNode *pre = dummy;
    struct ListNode *cur = dummy->next;
    while (cur) {
      struct ListNode *left  = cur;
      struct ListNode *right = split(left, step);
      cur = split(right, step);
      pre->next = merge(left, right);
      while (pre->next) {
        pre = pre->next;
      }
    }
  }
  return dummy->next;
}
