#include"stddef.h"
#include"malloc.h"
#include"stdbool.h"
#include"stdint.h"
#include"SequenceStack.h"

SequenceStack* InitializeSStack(size_t capacity) {
	SequenceStack* newStack = (SequenceStack*)malloc(sizeof(SequenceStack));
	if (!newStack)
		return NULL;
	newStack->_capacity = capacity;
	newStack->_base = (SS_DataType*)malloc(sizeof(SS_DataType) * capacity);
	newStack->_top = newStack->_base;
	return newStack;
}

bool PushSStack(SequenceStack* stack, SS_DataType value) {
	if (!stack)
		return false;
	if (stack->_top - stack->_base == stack->_capacity) {
		stack->_base = (SequenceStack*)realloc(stack->_base, (stack->_capacity *= 2) * sizeof(SS_DataType));
		if (!stack->_base)
			return false;
		stack->_top = stack->_base + stack->_capacity/2;
	}
	*stack->_top++ = value;
}

SS_DataType PopStack(SequenceStack* stack) {
	if (!stack)
		return INT64_MAX;
	if (stack->_top == stack->_base)
		return -1;
	return *--stack->_top;
}

bool FreeSStack(SequenceStack* stack) {
	if (!stack)
		return false;
	free(stack->_base);
	free(stack);
	return true;
};