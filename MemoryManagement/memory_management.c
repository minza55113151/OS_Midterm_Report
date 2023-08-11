#include<stdio.h>
#include<stdlib.h>

int stack_count = 0;
int malloc_count = 0;
int stack_overflow_count = 0;

void stack_overflow(){
    if (stack_overflow_count % 10000 == 0){
        printf("Stack level: %d\n", stack_overflow_count);
    }

    stack_overflow_count++;

    stack_overflow();
}

void stack_print_address(){
    if(stack_count <= 0) return;
    
    stack_count--;

    int a;
    printf("%x\n", &a);
    stack_print_address();
}

void malloc_print_address(){
    if(malloc_count <= 0) return;

    malloc_count--;

    printf("%x\n", (int *)malloc(sizeof(int)));
    malloc_print_address();
}

int main(){
    stack_count = 3;
    malloc_count = 3;
    
    printf("Stack address:\n");
    stack_print_address();

    printf("Malloc address:\n");
    malloc_print_address();

    printf("Stack overflow:\n");
    stack_overflow(0);

    return 0;
}