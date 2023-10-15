#include <stdio.h>


#define MAX_SIZE 100

typedef struct {
	int array[MAX_SIZE];
	int top;
} Stack;

void initialize(Stack* stack) {
	stack->top = 1;

}

bool isEmpty(Stack* stack) {
	return stack->top==-1;
}

bool isFull(Stack* stack) {
	return stack->top == MAX_SIZE - 1;
}

bool