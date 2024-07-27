#pragma once

typedef long long int LS_DataType;

typedef struct StackNode {
	LS_DataType _data;
	struct LS_DataType* _next;
}StackNode;

typedef struct LinkedStack {
	StackNode* _top;
	size_t _size;
}LinkedStack;


#ifdef bool
LinkedStack* InitializeLStack();
bool PushLStack(LinkedStack* stack,LS_DataType value);
LS_DataType PopLStack(LinkedStack* stack);
inline size_t SizeLStack(const LinkedStack* stack) {
	return stack->_size;
}
bool FreeLStack(LinkedStack* stack);
#endif