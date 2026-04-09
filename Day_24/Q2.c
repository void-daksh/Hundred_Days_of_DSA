/*Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int n) {
    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->data = x;
        node->next = NULL;

        if (!head)
            head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

struct Node* removeElements(struct Node* head, int val) {
    struct Node dummy;
    dummy.next = head;

    struct Node *curr = &dummy;

    while (curr->next) {
        if (curr->next->data == val) {
            struct Node* temp = curr->next;
            curr->next = temp->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }

    return dummy.next;
}

int main() {
    int n, val;

    scanf("%d", &n);
    struct Node* head = create(n);

    scanf("%d", &val);

    head = removeElements(head, val);

    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}