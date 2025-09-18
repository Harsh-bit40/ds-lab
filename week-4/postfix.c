
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

float st[MAX];
int top = -1;

void push(float st[], float val) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        st[++top] = val;
}

float pop(float st[]) {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else
        return st[top--];
}

float evaluatePostfixExp(char exp[]) {
    int i = 0;
    float op1, op2, value;

    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(st, (float)(exp[i] - '0'));
        } else if (exp[i] != ' ') {  // skip spaces
            op2 = pop(st);
            op1 = pop(st);
            switch (exp[i]) {
                case '+':
                    value = op1 + op2;
                    break;
                case '-':
                    value = op1 - op2;
                    break;
                case '*':
                    value = op1 * op2;
                    break;
                case '/':
                    value = op1 / op2;
                    break;
                case '%':
                    value = (int)op1 % (int)op2;
                    break;
                default:
                    printf("Invalid operator: %c\n", exp[i]);
                    return -1;
            }
            push(st, value);
        }
        i++;
    }
    return pop(st);
}

int main() {
    float val;
    char exp[100];

    printf("\nEnter any postfix expression (e.g., 53+2*): ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';  // Remove newline

    val = evaluatePostfixExp(exp);
    printf("\nValue of the postfix expression = %.2f\n", val);

    return 0;
}

