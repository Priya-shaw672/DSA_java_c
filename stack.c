#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX], top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("\nStack Overflow\n");
    } else {
        top++;
        stack[top] = val;
        printf("%d inserted into stack.\n", val);
    }
}

int pop() {
    if (top == -1) {
        printf("\nStack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int peek() {
    if (top == -1) {
        printf("\nStack is Empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

void display() {
	int i;
    if (top == -1) {
        printf("\nStack is Empty\n");
    } else {
        printf("\nStack elements:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int ch, val;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                val = pop();
                if (val != -1)
                    printf("Popped value: %d\n", val);
                break;
            case 3:
                val = peek();
                if (val != -1)
                    printf("Top of stack: %d\n", val);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
