/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
} MinStack;

void init(MinStack* obj) {
    obj->top = -1;
}

void push(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;

    if (obj->top == 0 || val < obj->minStack[obj->top - 1])
        obj->minStack[obj->top] = val;
    else
        obj->minStack[obj->top] = obj->minStack[obj->top - 1];
}

void pop(MinStack* obj) {
    if (obj->top >= 0)
        obj->top--;
}

int top(MinStack* obj) {
    return obj->stack[obj->top];
}

int getMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

int main() {
    MinStack s;
    init(&s);

    push(&s, -2);
    push(&s, 0);
    push(&s, -3);

    printf("%d\n", getMin(&s)); // -3
    pop(&s);
    printf("%d\n", top(&s));    // 0
    printf("%d\n", getMin(&s)); // -2

    return 0;
}