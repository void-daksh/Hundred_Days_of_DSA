/*Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int calculate(char *s) {
    int stack[10000];
    int top = -1;
    int num = 0;
    char op = '+';

    for (int i = 0; i <= strlen(s); i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || s[i] == '\0') {
            if (op == '+')
                stack[++top] = num;
            else if (op == '-')
                stack[++top] = -num;
            else if (op == '*')
                stack[top] = stack[top] * num;
            else if (op == '/')
                stack[top] = stack[top] / num;

            op = s[i];
            num = 0;
        }
    }

    int result = 0;
    while (top != -1) {
        result += stack[top--];
    }

    return result;
}

int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);

    printf("%d\n", calculate(s));

    return 0;
}