#include "stack.h"
#include "expr_assert.h"

void test_createStack_creates_an_empty_stack_by_putting_null_in_top_and_0_in_count(){
	Stack stack = createStack();
	assertEqual(stack.count, 0);
	assertEqual((int)stack.top, 0);
}