#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>  // Needed for strcspn
#define MAX 100

float st[MAX];
int top = -1;

void push(float st[], float val);
float pop(float st[]);
float evaluatepostfixexp(char exp[]);

int main() {
    float val;
    char exp[100];



    printf("\n Enter any postfix expression: ");
    fgets(exp, sizeof(exp), stdin); 
    exp[strcspn(exp, "\n")] = '\0';  // Remove trailing newline

    val = evaluatepostfixexp(exp);
    printf("\n Value of the postfix expression = %.2f", val);

    getch();
    return 0;
}

float evaluatepostfixexp(char exp[]) {
    int i = 0;
    float op1, op2, value;

    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(st, (float)(exp[i] - '0'));
        } else if (exp[i] == ' ') {
            // Skip space
        } else {
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
                    printf("\n Invalid operator: %c", exp[i]);
                    return 0;
            }
            push(st, value);
        }
        i++;
    }

    return pop(st);
}

void push(float st[], float val) {
    if (top == MAX - 1)
        printf("\n STACK OVERFLOW");
    else {
        top++;
        st[top] = val;
    }
}

float pop(float st[]) {
    float val = -1;
    if (top == -1)
        printf("\n STACK UNDERFLOW");
    else {
        val = st[top];
        top--;
    }
    return val;
}














