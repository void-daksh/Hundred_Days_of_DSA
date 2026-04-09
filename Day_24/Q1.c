/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
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

struct Node* deleteKey(struct Node* head, int key) {
    struct Node *curr = head, *prev = NULL;

    while (curr) {
        if (curr->data == key) {
            if (!prev)
                head = curr->next;
            else
                prev->next = curr->next;

            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

int main() {
    int n, key;

    scanf("%d", &n);
    struct Node* head = create(n);

    scanf("%d", &key);

    head = deleteKey(head, key);

    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}