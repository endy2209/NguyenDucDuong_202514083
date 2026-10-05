//Non-Recursive Hanoi Tower using Stack
//NguyenDucDuong_202514083
#include <stdio.h>
#include <math.h>

#define MAX 100

typedef struct {
    int n;
    char source;
    char target;
    char temp;
} Task;

typedef struct {
    Task data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, Task task) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = task;
    }
}

Task pop(Stack *s) {
    return s->data[(s->top)--];
}

void hanoiTowerNonRecursive(int n, char source, char target, char temp) {
    Stack s;
    initStack(&s);

    Task initialTask = {n, source, target, temp};
    push(&s, initialTask);

    while (s.top != -1) {
        Task current = pop(&s);

        if (current.n == 1) {       //end condition
            printf("Move disk from %c to %c\n", current.source, current.target);
        } else {
            //(n-1) disks from temp to target using source as auxiliary
            Task task3 = {current.n - 1, current.temp, current.target, current.source};
            push(&s, task3);

            //Move disk n from source to target
            Task task2 = {1, current.source, current.target, current.temp};
            push(&s, task2);

            //(n-1) disks from source to temp using target as auxiliary
            Task task1 = {current.n - 1, current.source, current.temp, current.target};
            push(&s, task1);
        }
    }
}

int main() {
    int n; 
    printf("Hanoi Tower Problem with A as source, C as target, and B as temporary.\n");
    printf("Enter the number of disks: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of disks!\n");
        return 1;
    }
    hanoiTowerNonRecursive(n, 'A', 'C', 'B'); 
    printf("Number of moves: %d\n", (int)pow(2, n) - 1); 
    return 0;
}