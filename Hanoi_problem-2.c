https://www.programiz.com/online-compiler/1JeIF0CHW7rfa

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct { int top, arr[MAX]; } Stack;
void initStack(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
void push(Stack *s, int value) { if (s->top < MAX - 1) s->arr[++(s->top)] = value; }
int pop(Stack *s) { return isEmpty(s) ? -1 : s->arr[(s->top)--]; }

void moveDisk(Stack *src, Stack *dest, char s, char d) {
    int disk1 = pop(src), disk2 = pop(dest);
    if (disk1 == -1) push(src, disk2), printf("Move disk %d from %c to %c\n", disk2, d, s);
    else if (disk2 == -1 || disk1 < disk2) push(dest, disk1), printf("Move disk %d from %c to %c\n", disk1, s, d);
    else push(src, disk1), push(src, disk2), printf("Move disk %d from %c to %c\n", disk2, d, s);
}

void towersOfHanoi(int n, Stack *src, Stack *aux, Stack *dest) {
    char s = 'A', d = 'C', a = 'B';
    if (n % 2 == 0) { char temp = d; d = a; a = temp; }
    for (int i = n; i >= 1; i--) push(src, i);
    for (int i = 1, moves = (1 << n) - 1; i <= moves; i++)
        moveDisk(i % 3 == 1 ? src : i % 3 == 2 ? src : aux, i % 3 == 1 ? dest : i % 3 == 2 ? aux : dest, i % 3 == 1 ? s : i % 3 == 2 ? s : a, i % 3 == 1 ? d : i % 3 == 2 ? a : d);
}

int main() {
    int n; printf("Enter number of disks: ");
    scanf("%d", &n);
    Stack src, aux, dest;
    initStack(&src), initStack(&aux), initStack(&dest);
    towersOfHanoi(n, &src, &aux, &dest);
    return 0;
}
