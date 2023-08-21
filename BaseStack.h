#pragma once
// Base Virtual class for Stack.
class BaseStack {
public:
	virtual bool IsEmpty() = 0;
	virtual int Top() = 0;
	virtual int Pop() = 0;
	virtual void Push(int value) = 0;
};
