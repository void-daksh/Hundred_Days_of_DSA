/*You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int n) {
    struct Node *head = NULL, *tail = NULL, *newNode;
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

struct Node* add(struct Node* l1, struct Node* l2) {
    int s1[1000], s2[1000];
    int t1 = 0, t2 = 0;

    while (l1) {
        s1[t1++] = l1->data;
        l1 = l1->next;
    }

    while (l2) {
        s2[t2++] = l2->data;
        l2 = l2->next;
    }

    int carry = 0;
    struct Node* head = NULL;

    while (t1 > 0 || t2 > 0 || carry) {
        int sum = carry;

        if (t1 > 0) sum += s1[--t1];
        if (t2 > 0) sum += s2[--t2];

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = sum % 10;
        newNode->next = head;
        head = newNode;

        carry = sum / 10;
    }

    return head;
}

void print(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n1, n2;

    scanf("%d", &n1);
    struct Node* l1 = create(n1);

    scanf("%d", &n2);
    struct Node* l2 = create(n2);

    struct Node* res = add(l1, l2);
    print(res);

    return 0;
}