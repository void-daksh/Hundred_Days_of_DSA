/*Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int n) {
    struct Node *head = NULL, *tail = NULL, *temp;
    for (int i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &temp->data);
        temp->next = NULL;

        if (!head) head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

int hasCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

int main() {
    int n, pos;
    scanf("%d", &n);

    struct Node* head = create(n);

    scanf("%d", &pos);

    if (pos != -1) {
        struct Node *temp = head, *cycleNode = NULL;
        int idx = 0;

        while (temp->next) {
            if (idx == pos) cycleNode = temp;
            temp = temp->next;
            idx++;
        }
        temp->next = cycleNode;
    }

    if (hasCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}