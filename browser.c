#include <stdio.h>
#include <string.h>

#define MAX 100  // Maximum number of URLs the stack can hold
#define URL_SIZE 256  // Maximum size of each URL

typedef struct {
    char urls[MAX][URL_SIZE];  // Stack to hold URLs
    int top;  // Index of the top element in the stack
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

void push(Stack* stack, const char* url) {
    if (!isFull(stack)) {
        strcpy(stack->urls[++stack->top], url);
    } else {
        printf("Stack is full, cannot push URL: %s\n", url);
    }
}

void pop(Stack* stack, char* url) {
    if (!isEmpty(stack)) {
        strcpy(url, stack->urls[stack->top--]);
    } else {
        printf("Stack is empty, cannot pop URL.\n");
    }
}

void navigate(char* currentURL, const char* newPage) {
    strcpy(currentURL, newPage);
    printf("Navigating to: %s\n", newPage);
}

void visitPage(Stack* backStack, Stack* forwardStack, char* currentURL, const char* newPage) {
    if (*currentURL) {
        push(backStack, currentURL);
    }
    initStack(forwardStack);  // Clear forward history
    navigate(currentURL, newPage);
}

void goBack(Stack* backStack, Stack* forwardStack, char* currentURL) {
    if (!isEmpty(backStack)) {
        push(forwardStack, currentURL);
        pop(backStack, currentURL);
        printf("Back to: %s\n", currentURL);
    } else {
        printf("No previous page to go back to.\n");
    }
}

void goForward(Stack* backStack, Stack* forwardStack, char* currentURL) {
    if (!isEmpty(forwardStack)) {
        push(backStack, currentURL);
        pop(forwardStack, currentURL);
        printf("Forward to: %s\n", currentURL);
    } else {
        printf("No next page to go forward to.\n");
    }
}

int main() {
    Stack backStack, forwardStack;
    char currentURL[URL_SIZE] = "";  // Current URL being viewed
    char inputURL[URL_SIZE];
    char command[10];

    initStack(&backStack);
    initStack(&forwardStack);

    while (1) {
        printf("\nEnter URL (or type 'exit' to quit): ");
        scanf("%s", inputURL);

        if (strcmp(inputURL, "exit") == 0) {
            printf("Exiting browser...\n");
            break;
        }

        visitPage(&backStack, &forwardStack, currentURL, inputURL);

        while (1) {
            printf("\nOptions: \n");
            printf("1. Enter another URL\n");
            printf("2. Go Back\n");
            printf("3. Go Forward\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%s", command);

            if (strcmp(command, "1") == 0) {
                printf("Enter URL: ");
                scanf("%s", inputURL);
                visitPage(&backStack, &forwardStack, currentURL, inputURL);
            } else if (strcmp(command, "2") == 0) {
                goBack(&backStack, &forwardStack, currentURL);
            } else if (strcmp(command, "3") == 0) {
                goForward(&backStack, &forwardStack, currentURL);
            } else if (strcmp(command, "4") == 0) {
                printf("Exiting browser...\n");
                return 0;
            } else {
                printf("Invalid option. Please enter 1, 2, 3, or 4.\n");
            }
        }
    }

    return 0;
}
