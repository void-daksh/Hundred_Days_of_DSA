/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, 
increment a counter. After traversal, print the final count.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL;

    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = val;
        new_node->next = NULL;

        if(head == NULL) {
            head = new_node;
            temp = head;
        } else {
            temp->next = new_node;
            temp = new_node;
        }
    }

    return head;
}
int countKey(struct Node* head, int key) {
    int count = 0;

    while(head != NULL) {
        if(head->data == key) {
            count++;
        }
        head = head->next;
    }

    return count;
}

int main() {
    int n, key;
    scanf("%d", &n);

    struct Node* head = createList(n);

    scanf("%d", &key);

    printf("%d", countKey(head, key));

    return 0;
}