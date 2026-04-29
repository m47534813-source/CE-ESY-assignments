#include <stdio.h>
#include <string.h>

#define N 10   

typedef struct {
    char arr[N];
    int h;
    int t;
    int c;
} CB;


void init(CB *x) {
    x->h = 0;
    x->t = 0;
    x->c = 0;
}


int empty(CB *x) {
    if (x->c == 0)
        return 1;
    return 0;
}


int full(CB *x) {
    if (x->c == N)
        return 1;
    return 0;
}


void push(CB *x, char d) {
    if (full(x)) {
        printf("overflow!\n");
        return;
    }

    x->arr[x->t] = d;
    x->t = (x->t + 1) % N;
    x->c++;
}

char pop(CB *x) {
    if (empty(x)) {
        printf("underflow!\n");
        return '\0';
    }

    char d = x->arr[x->h];
    x->h = (x->h + 1) % N;
    x->c--;

    return d;
}

int main() {
    CB b;
    init(&b);

    char name[50];

    printf("enter name: ");
    scanf("%s", name);

    
    strcat(name, "CE-ESY");

    
    for (int i = 0; i < strlen(name); i++) {
        push(&b, name[i]);
    }

    
    printf("result: ");
    while (!empty(&b)) {
        printf("%c", pop(&b));
    }

    printf("\n");

    return 0;
}
