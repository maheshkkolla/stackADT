#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack createStack(void) {
	Stack *stack = malloc(sizeof(Stack));
	stack->top = NULL;
	stack->count = 0;
	return *stack;
}

int push(Stack *stack, void *data) {
	NodePtr node = malloc(sizeof(Node));
	node->data = data;
	if(stack->count == 0) node->prev = NULL; 
	else{
		node->prev = stack->top;
		node->prev->next = node;	
	} 
	node->next = NULL;	
	stack->top = node;
	stack->count = stack->count + 1;	
	return 1;
}

void *pop(Stack *stack) {
	NodePtr popedItem = stack->top;
	stack->top = stack->top->prev;
	if(stack->count > 1){
		stack->top->next->prev = NULL;
		stack->top->next = NULL;
	}
	stack->count = stack->count - 1;
	return popedItem;
}



