#include "StackOfInt.h"
#define MAX_SIZE 10
#define INDEX_OUT_OF_BOUNDS_EXCEPTION 1
#define EMPTY_STACK 2

// Stack constructor
Stack::Stack() {
	count = 0;
	items = new int[MAX_SIZE];
}

// Stack destructor
Stack::~Stack() {
	delete[]items;
}

// Returns the top of the stack
int Stack::Top() {
	if (count < 1) {
		throw EMPTY_STACK;
	}
	return items[count - 1];
}

// Returns the current top and removes the element from the stack
int Stack::Pop() {
	if (count < 1) {
		throw EMPTY_STACK;
	}
	return items[--count];
}

// Checks whether the stack is empty
bool Stack::IsEmpty() {
	if (count == 0) {
		return true;
	}
	return false;
}

// Inserts <code>item</code> into the stack
void Stack::Push(int item) {
	if (count >= 0 && count < MAX_SIZE) {
		items[count++] = item;
	}
	else {
		throw INDEX_OUT_OF_BOUNDS_EXCEPTION;
	}
}
