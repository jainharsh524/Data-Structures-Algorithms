#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* createNode(char val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct Node* push(struct Node* top, char val) {
    struct Node* curr = createNode(val);
    curr->next = top;
    top = curr;
    return top;
}

char pop(struct Node** top_ptr) {
    if (*top_ptr == NULL) {
        exit(EXIT_FAILURE);
    }
    struct Node* temp = *top_ptr;
    char popped_value = temp->data;
    *top_ptr = (*top_ptr)->next;
    free(temp);
    return popped_value;
}

char peek(struct Node* top) {
    if (top == NULL) {
        return '\0';
    }
    return top->data;
}

bool isEmpty(struct Node* top) {
    return top == NULL;
}

void printStack(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack: Empty\n");
        return;
    }
    struct Node* curr = top;
    printf("Stack: TOP -> ");
    while (curr != NULL) {
        printf("%c -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void printIntStack(struct Node* top) {
    if (isEmpty(top)) {
        printf("Int Stack: Empty\n");
        return;
    }
    struct Node* curr = top;
    printf("Int Stack: TOP -> ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void destroyStack(struct Node* top) {
    struct Node* current = top;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(char* infix, char* postfix) {
    struct Node* operatorStack = NULL;
    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        char curr = infix[i];
        if(isalnum(curr)){
            postfix[j] = curr;
            j++;
        }
        else if(curr=='('){
            operatorStack = push(operatorStack, curr);
        }
        else if(curr==')'){
            while(!isEmpty(operatorStack)&&peek(operatorStack)!='('){
                postfix[j] = pop(&operatorStack);
                j++;
            }
            if(!isEmpty(operatorStack)&&peek(operatorStack)=='('){
                pop(&operatorStack);
            }
            else{
                printf("Mismatched Parantheses.\n");
                return;
            }
        }
        else if(isOperator(curr)){
            while (!isEmpty(operatorStack) && peek(operatorStack) != '(' &&
                   (precedence(curr) <= precedence(peek(operatorStack)))) {
                    postfix[j] = pop(&operatorStack);
                    j++;
            }
            operatorStack = push(operatorStack, curr);
        }
        i++;
    }
    while (!isEmpty(operatorStack)) {
        if (peek(operatorStack) == '(') {
            printf("Error: Mismatched parentheses.\n");
            postfix[0] = '\0';
            return;
        }
        postfix[j++] = pop(&operatorStack);
    }
    postfix[j] = '\0';
    destroyStack(operatorStack);   
}

void infixToPrefix(char* infix, char* prefix){
    //reverse the expression
    int i = 0;
    int len = strlen(infix);
    int j = len-1;
    for(i,j;i<j;i++,j--){
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
        else {
            char temp = infix[i];
            infix[i] = infix[j];
            infix[j] = temp;
        }
    }
    struct Node* operatorStack = NULL;
    char temp_postfix[200];
    int k = 0;
    //Use infix to postfix after reversing
    // infixToPostfix(infix, temp_postfix);
    for (int i = 0; infix[i]!='\0'; i++)
    {
        char curr = infix[i];
        if(isalnum(curr)){
            temp_postfix[k] = curr;
            k++;
        }
        else if(curr=='('){
            operatorStack = push(operatorStack, curr);
        }
        else if(curr==')'){
            while(!isEmpty(operatorStack)&&peek(operatorStack)!='('){
                temp_postfix[k] = pop(&operatorStack);
                k++;
            }
            if(!isEmpty(operatorStack) && peek(operatorStack)=='('){
                pop(&operatorStack);
            }
            else{
                printf("Error: Mismatched parentheses in reversed expression.\n");
                prefix[0] = '\0';
                destroyStack(operatorStack);
                return;
            }
        }
        else if(isOperator(curr)){
            while(!isEmpty(operatorStack) && peek(operatorStack) != '('&&precedence(curr)<=precedence(peek(operatorStack))){
                temp_postfix[k] = pop(&operatorStack);
                k++;
            }
            operatorStack = push(operatorStack, curr);
        }
    }
    while (!isEmpty(operatorStack)) {
        if (peek(operatorStack) == '(') {
            printf("Error: Mismatched parentheses in reversed expression.\n");
            prefix[0] = '\0';
            destroyStack(operatorStack);
            return;
        }
        temp_postfix[k++] = pop(&operatorStack);
    }
    temp_postfix[k] = '\0';
    destroyStack(operatorStack);
    len = strlen(temp_postfix);
    //reverse again
    for (i = 0, j = len - 1; i < len; i++, j--) {
        prefix[i] = temp_postfix[j];
    }
    prefix[len] = '\0';
}

//Q.https://leetcode.com/problems/evaluate-reverse-polish-notation/solutions/7010516/c-solution-stack-clean-code-implemented-k1jtp/
//Sol. https://leetcode.com/problems/evaluate-reverse-polish-notation/solutions/7010516/c-solution-stack-clean-code-implemented-k1jtp/
int evaluatePostfix(char* postfix){
    struct Node* operandStack = NULL;
    int res = 0;
    int len = strlen(postfix);
    for (int i = 0; postfix[i]!='\0'; i++)
    {
        char curr = postfix[i];
        if(isdigit(curr)){
            operandStack = push(operandStack, curr-'0');
        }
        else if(isOperator(curr)){
            res = 0;
            if(curr=='/'){
                int a = pop(&operandStack);
                int b = pop(&operandStack);
                if(b==0){
                    printf("Error: Division by zero\n");
                        destroyStack(operandStack);
                        return -1;
                }
                res = b/a;
                operandStack = push(operandStack, res);
            }
            else if(curr=='*'){
                int a = pop(&operandStack);
                int b = pop(&operandStack);
                res = a*b;
                operandStack = push(operandStack, res);
            }
            else if(curr=='+'){
                int a = pop(&operandStack);
                int b = pop(&operandStack);
                res = a+b;
                operandStack = push(operandStack, res);
            }
            else if(curr=='-'){
                int a = pop(&operandStack);
                int b = pop(&operandStack);
                res = b-a;
                operandStack = push(operandStack, res);
            }
            else{
                printf("Error: Invalid operator in postfix: %c\n", curr);
                destroyStack(operandStack);
                return -1;
            }
        }
    }if (!isEmpty(operandStack)) {
        int finalResult = pop(&operandStack);
        if (!isEmpty(operandStack)) {
            printf("Error: Malformed postfix (too many operands).\n");
            destroyStack(operandStack);
            return -1;
        }
        destroyStack(operandStack);
        return finalResult;
    } else {
        printf("Error: Invalid postfix expression or empty expression.\n");
        destroyStack(operandStack);
        return -1;
    }
}

int main() {
    char infix_expr[100];
    char postfix_expr[100];
    char prefix_expr[100];
    int result;

    printf("Enter an infix expression (e.g., A+B*C or (2+3)*4): ");
    fgets(infix_expr, sizeof(infix_expr), stdin);
    infix_expr[strcspn(infix_expr, "\n")] = '\0';

    infixToPostfix(infix_expr, postfix_expr);
    if (postfix_expr[0] != '\0') {
        printf("Postfix expression: %s\n", postfix_expr);
    }

    infixToPrefix(infix_expr, prefix_expr);
    if (prefix_expr[0] != '\0') {
        printf("Prefix expression: %s\n", prefix_expr);
    }

    printf("\n--- Numeric Expression Evaluation ---\n");
    printf("Enter a numeric postfix expression (e.g., 234*+): ");
    fgets(postfix_expr, sizeof(postfix_expr), stdin);
    postfix_expr[strcspn(postfix_expr, "\n")] = '\0';
    result = evaluatePostfix(postfix_expr);
    if (result != -1) {
        printf("Result of postfix evaluation: %d\n", result);
    }

    // printf("Enter a numeric prefix expression (e.g., *+234): ");
    // fgets(prefix_expr, sizeof(prefix_expr), stdin);
    // prefix_expr[strcspn(prefix_expr, "\n")] = '\0';
    // result = evaluatePrefix(prefix_expr);
    // if (result != -1) {
    //     printf("Result of prefix evaluation: %d\n", result);
    // }

    return 0;
}