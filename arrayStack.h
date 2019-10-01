/*
 1. Project
	[COME331006] DataStructure Homework #1

 2. Name 
	arrayStack.h

 3. Purpose
	1. To define STACK data type for array
	2. To define function using STACK with array

 4. Creator
	2017112387 Park Ki hyun ( ¹Ú±âÇö )
 */

// int == Data
typedef int Data;

// make data type named of STACK
typedef struct stk
{
	Data* itemPtr;
	int max_size;
	int top;
} STACK;

// function of createStack
STACK* CreateStack(int size)
{
	STACK* stack = (STACK*)malloc(sizeof(STACK));

	// If there are no space in memory, making STACK failed and the furnction 'malloc' returns NULL
	if (stack == NULL)
		return NULL;

	// Make array named itemPtr.
	stack->itemPtr = malloc(sizeof(Data) * size);

	// If failed, free stack and return NULL
	if (stack->itemPtr == NULL)
	{
		free(stack);
		return NULL;
	}

	stack->top = -1;
	stack->max_size = size;

	return stack;

}

bool IsFullStack(STACK* stack)
{
	if (stack->top == stack->max_size - 1)
		return true;
	
	else
		return false;
	
}

bool IsEmptyStack(STACK* stack)
{
	if (stack->top == -1)
		return true;
	
	else
		return false;
	
}

void Push(STACK* stack, Data* item)
{
	// Error
	if (IsFullStack(stack))
		printf("[Error] The stack has not enough space\n");
	else
		stack->itemPtr[++stack->top] = item;
}

Data Pop(STACK* stack)
{
	// Error
	if (IsEmptyStack(stack))
		printf("[Error] The stack doesn't have a item\n");
	else
		return stack->itemPtr[stack->top--];
}

Data Top(STACK* stack)
{
	if (IsEmptyStack(stack))
		printf("[Error] The stack doesn't have a item. So There is no top number\n");
	else
		return stack->top;
}

// ??
void DestroyStack(STACK* stack)
{
	free(stack->itemPtr);
	free(stack);
}

int CountStackItem(STACK* stack)
{
	printf("[Notice] There are %d items in stack", (stack->top + 1));
	return (stack->top + 1);
}

// Stack items are depends on top. Whatever there are data in stack, if top is -1, it is thinked the stack is cleared.
void ClearStack(STACK* stack)
{
	stack->top = -1;
}