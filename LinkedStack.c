#include<stdbool.h>
#include<stddef.h>
#include<malloc.h>
#include"LinkedStack.h"

LinkedStack* InitializeLStack() {
	LinkedStack* newStack = (LinkedStack*)malloc(sizeof(LinkedStack));
	if (!newStack)
		return NULL;
	newStack->_size = 0;
	newStack->_top = (StackNode*)malloc(sizeof(StackNode));
	if (!newStack->_top)
		return NULL;
	newStack->_top->_next = NULL;
	return newStack;
}
bool PushLStack(LinkedStack* stack, LS_DataType value) {
	if (!stack)
		return false;
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	if (!newNode)
		return false;
	newNode->_data = value;
	newNode->_next = stack->_top->_next;
	stack->_top->_next = newNode;
	++stack->_size;
	return true;
}
LS_DataType PopLStack(LinkedStack* stack) {
	if (!stack)
		return false;
	StackNode* to_delete = stack->_top->_next;
	LS_DataType data = to_delete->_data;
	stack->_top->_next = to_delete->_next;
	free(to_delete);
	--stack->_size;
	return data;
}
bool FreeLStack(LinkedStack* stack) {
	StackNode* temp;
	StackNode* index = stack->_top;
	while (index) {
		temp = index->_next;
		free(index);
		index = temp;
	}
	free(stack);
}