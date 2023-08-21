 #include "BaseStack.h"

// BaseStack implementation
class Stack : public BaseStack {
private:
		int* items; // the integers pushed into the stack
		int count; // the number of items in the stack, after the last pop
public:
		Stack();  // Stack constructor
		~Stack(); // .. and destructor
		bool IsEmpty(); // is the stack's count zero?
		int Top(); // which item is at the top of the stack?
		int Pop(); // returns the current top, and removes it from the stack
		void Push(int item); // Inserts a new item, at the top of the stack
};
