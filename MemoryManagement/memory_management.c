#include<stdio.h>
#include<stdlib.h>

int stack_count = 0;
int malloc_count = 0;
int stack_overflow_count = 0;


void stack_print_address(){
    if(stack_count <= 0) return;
    
    stack_count--;

    int a;
    printf("%x\n", &a);
    stack_print_address();
}

void heap_print_address(){
    for(int i=0;i<malloc_count;i++){
        printf("%x\n", (int *)malloc(sizeof(int)));
    }
}

void stack_overflow(){
    if (stack_overflow_count % 10000 == 0){
        printf("Stack level: %d\n", stack_overflow_count);
    }

    stack_overflow_count++;

    stack_overflow();
}

void global_print_address(){
    printf("%x\n", &stack_count);
    printf("%x\n", &malloc_count);
    printf("%x\n", &stack_overflow_count);
}

int main(){
    stack_count = 3;
    malloc_count = 3;
    
    printf("Stack address:\n");
    stack_print_address();

    printf("Heap address:\n");
    heap_print_address();

    printf("Global address:\n");
    global_print_address();

    printf("Stack overflow:\n");
    stack_overflow();

    return 0;
}