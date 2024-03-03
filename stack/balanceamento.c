#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

char stack[MAX];
int top = -1;

void push(char c) {
    if (top >= MAX-1) {
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top < 0) {
        return ' ';
    } else {
        return stack[top--];
    }
}

int is_balanced(char s[]) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '[') {
            push(s[i]);
        } else if (s[i] == ')' || s[i] == ']') {
            if (top < 0) {
                return 0;
            }
            char c = pop();
            if (s[i] == ')' && c != '(' || s[i] == ']' && c != '[') {
                return 0;
            }
        }
    
    return top == -1;
    
    }
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char s[MAX];
        scanf(" %[^\n]", s);
        printf("%s\n", is_balanced(s) ? "Yes" : "No");
    }

    return 0;
}
