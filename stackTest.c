#include "stack.h"
#include "expr_assert.h"

void test_createStack_creates_an_empty_stack_by_putting_null_in_top_and_0_in_count(){
	Stack stack = createStack();
	assertEqual(stack.count, 0);
	assertEqual((int)stack.top, 0);
}

void test_push_puts_an_item_in_top_of_the_stack_and_returns_1(){
	int a =5, result;
	Stack stack = createStack();
	result = push(&stack, &a);
	assertEqual(result, 1);
	assertEqual(stack.count, 1);
}

void test_pop_returns_the_top_of_the_stack(){
	int a =5;
	NodePtr popedItem;
	Stack stack = createStack();
	push(&stack, &a);
	popedItem = pop(&stack);
	assertEqual((int)popedItem->data, (int)&a);
	assertEqual(stack.count,0);
	assertEqual((int)stack.top, 0);
}

void test_pop_returns_the_top_of_the_stack_and_puts_top_to_prev_item(){
	int a = 5, b = 10;
	NodePtr popedItem;
	Stack stack = createStack();
	push(&stack, &a);
	push(&stack, &b);
	popedItem = pop(&stack);
	assertEqual((int)popedItem->data, (int)&b);
	assertEqual(stack.count,1);
	assertEqual(stack.top->data, &a);
}