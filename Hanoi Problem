https://www.programiz.com/online-compiler/8apFTtL6JeZFG

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Stack structure
typedef struct {
    int top;
    int arr[MAX];
} Stack;

// Function to initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Function to move disk from source to destination
void moveDisk(Stack *src, Stack *dest, char s, char d) {
    int disk1 = pop(src);
    int disk2 = pop(dest);

    if (disk1 == -1) {
        push(src, disk2);
        printf("Move disk %d from %c to %c\n", disk2, d, s);
    } else if (disk2 == -1) {
        push(dest, disk1);
        printf("Move disk %d from %c to %c\n", disk1, s, d);
    } else if (disk1 > disk2) {
        push(src, disk1);
        push(src, disk2);
        printf("Move disk %d from %c to %c\n", disk2, d, s);
    } else {
        push(dest, disk2);
        push(dest, disk1);
        printf("Move disk %d from %c to %c\n", disk1, s, d);
    }
}

// Function to solve Tower of Hanoi iteratively
void towersOfHanoi(int n, Stack *src, Stack *aux, Stack *dest) {
    char s = 'A', d = 'C', a = 'B';
    int moves = (1 << n) - 1;

    if (n % 2 == 0) {
        char temp = d;
        d = a;
        a = temp;
    }

    for (int i = n; i >= 1; i--) {
        push(src, i);
    }

    for (int i = 1; i <= moves; i++) {
        if (i % 3 == 1)
            moveDisk(src, dest, s, d);
        else if (i % 3 == 2)
            moveDisk(src, aux, s, a);
        else if (i % 3 == 0)
            moveDisk(aux, dest, a, d);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    Stack src, aux, dest;
    initStack(&src);
    initStack(&aux);
    initStack(&dest);

    towersOfHanoi(n, &src, &aux, &dest);

    return 0;
}
