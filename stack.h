typedef struct stack Stack;
typedef struct node Node;
typedef Node * NodePtr;

struct stack {
	NodePtr top;
	int count;
};
struct node {
	void *data;
	NodePtr prev;
	NodePtr next;

};

Stack createStack(void);
int push(Stack *, void *);
void * pop(Stack *);